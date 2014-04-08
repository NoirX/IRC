#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include <QTextEdit>
#include <QKeyEvent>
#include <QUrl>
#include <QScrollBar>
#include <QObject>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->text->installEventFilter(this);

    // Create socket
    socket = new QTcpSocket(this);

    // Connect signals and slots!
    connect(socket, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(ui->connectButton, SIGNAL(clicked()), this, SLOT(connectToServer()));
    connect(ui->disconnectButton, SIGNAL(clicked()), this, SLOT(disconnectFromServer()));

    }

void MainWindow::connectToServer() {
    socket->connectToHost(QString("irc.freenode.net"), 6667);
    // USER, NICK and JOIN commands
    ui->user->setReadOnly(true);
    QString foo = ui->user->toPlainText();
    QString nick = "NICK "+foo+"\r\n";
    socket->write(nick.toAscii());
    socket->write("USER "+foo.toAscii()+" "+foo.toAscii()+" "+foo.toAscii()+" :"+foo.toAscii()+"qt \r\n");
    socket->write("JOIN #NoirInvestmentGroup \r\n");
    // Now we are successfully connected to IRC SERVER...
}

void MainWindow::readData() {
    QString foo = ui->user->toPlainText();
    QString readLine = socket->readLine();
    if(readLine.contains("PING")){
        socket->write("PONG\r\n");
    } else {
    // Add to ouput
    ui->textEdit->append(readLine);
    }
    // Next data??
   if(socket->canReadLine()) readData();
}

bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
    if (object == ui->text && event->type() == QEvent::KeyPress)
       {
           QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
           if (keyEvent->key() == Qt::Key_Return)
           {
               on_text_returnPressed();
               return true;
           }
           else
           {
               return QMainWindow::eventFilter(object, event);
           }
       }
       else
       {
           return QMainWindow::eventFilter(object, event);
       }
}

void MainWindow::on_text_returnPressed()
{
    QString cmd = ui->text->toPlainText();
    QString foo = ui->user->toPlainText();

    if(!cmd.isEmpty())
    {if(!cmd.contains("PRIVMSG")){
            QString cmd2 = "PRIVMSG #NoirInvestmentGroup : "+cmd+"\r\n";
        socket->write(cmd2.toAscii());
        ui->text->clear();
        ui->textEdit->append(foo+": "+cmd);
        } else {
            socket->write(cmd.toAscii()+"\r\n");
            ui->textEdit->append(foo=": "+cmd);
            ui->text->clear();
        }
    }
}


void MainWindow::disconnectFromServer() {
    // Disconnect from IRC server
    socket->write("QUIT Good bye \r\n"); // Good bye is optional message
    socket->flush();
    socket->disconnect(); // Now we can try it :-)
    ui->user->setReadOnly(false);
    ui->textEdit->clear();
    ui->text->clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}

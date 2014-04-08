#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QTcpSocket>
#include <QThread>
#include <QTextEdit>
#include <QKeyEvent>
#include <QUrl>
#include <QScrollBar>
#include <QObject>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    bool eventFilter(QObject *object, QEvent *event);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTcpSocket * socket;

private slots:
    void readData();
    void connectToServer();
    void disconnectFromServer();
    void on_text_returnPressed();
};

#endif // MAINWINDOW_H

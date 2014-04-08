/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *connectButton;
    QPushButton *disconnectButton;
    QTextEdit *textEdit;
    QPlainTextEdit *user;
    QPlainTextEdit *blah;
    QTextEdit *text;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(574, 402);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        connectButton = new QPushButton(centralWidget);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));
        connectButton->setGeometry(QRect(0, 0, 75, 23));
        disconnectButton = new QPushButton(centralWidget);
        disconnectButton->setObjectName(QString::fromUtf8("disconnectButton"));
        disconnectButton->setGeometry(QRect(330, 0, 75, 23));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(0, 40, 571, 321));
        textEdit->setMinimumSize(QSize(571, 321));
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        textEdit->setReadOnly(true);
        user = new QPlainTextEdit(centralWidget);
        user->setObjectName(QString::fromUtf8("user"));
        user->setGeometry(QRect(150, 10, 104, 21));
        user->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        user->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        blah = new QPlainTextEdit(centralWidget);
        blah->setObjectName(QString::fromUtf8("blah"));
        blah->setEnabled(false);
        blah->setGeometry(QRect(90, 10, 61, 21));
        blah->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        blah->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text = new QTextEdit(centralWidget);
        text->setObjectName(QString::fromUtf8("text"));
        text->setGeometry(QRect(0, 360, 571, 21));
        text->setMinimumSize(QSize(571, 21));
        text->setMaximumSize(QSize(16777215, 21));
        text->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        connectButton->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
        disconnectButton->setText(QApplication::translate("MainWindow", "Disconnect", 0, QApplication::UnicodeUTF8));
        blah->setPlainText(QApplication::translate("MainWindow", "Username", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

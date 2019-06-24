#include "mainwindow.h"
#include "logindialog.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    LoginDialog login;

    int ret = login.exec();

    if (ret == QDialog::Accepted) {
        w.show();
    } else if(ret == QDialog::Rejected) {
        a.exit(0);
    }

    return a.exec();
}

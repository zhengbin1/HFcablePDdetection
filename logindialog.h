#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QPainter>
#include <QPushButton>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

    void paintEvent(QPaintEvent *);
    void closeEvent(QCloseEvent *);

private:
    Ui::LoginDialog *ui;

    QPushButton *loginButton;
    QPushButton *exitButton;

private slots:
    void on_login_click();
    void on_exit_click();
};

#endif // LOGINDIALOG_H

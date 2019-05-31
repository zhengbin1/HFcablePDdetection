#include "logindialog.h"
#include "ui_logindialog.h"
#include <QDebug>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    setWindowTitle("HF电缆局放检测系统");

    Qt::WindowFlags flags = Qt::Dialog;
    flags |= Qt::WindowMinimizeButtonHint;
    flags |= Qt::WindowCloseButtonHint;
    flags &= ~Qt::WindowMaximizeButtonHint;
    flags &= ~Qt::WindowContextHelpButtonHint;

    setWindowFlags(flags);

    QImage background;
    background.load(":/resource/images/login_background.png");

    resize(background.width(), background.height());

    loginButton = new QPushButton(this);
    exitButton = new QPushButton(this);

    QImage loginImage;
    QImage exitImage;

    loginImage.load(":/resource/images/Logon_studio_72px_1071387_easyicon.net.png");
    exitImage.load(":/resource/images/stock_exit_72px_1078470_easyicon.net.png");

    loginButton -> resize(loginImage.width() + 3, loginImage.height() + 3);
    exitButton -> resize(exitImage.width(), exitImage.height());

    loginButton -> setStyleSheet("background-image: url(:/resource/images/Logon_studio_72px_1071387_easyicon.net.png);");
    exitButton -> setStyleSheet("background-image: url(:/resource/images/stock_exit_72px_1078470_easyicon.net.png);");

    loginButton -> move(1000, 500);
    exitButton -> move(1100, 500);

    connect(loginButton, SIGNAL(clicked()), this, SLOT(on_login_click()));
    connect(exitButton, SIGNAL(clicked()), this, SLOT(on_exit_click()));
}

LoginDialog::~LoginDialog()
{
    delete ui;

    delete loginButton;
    delete exitButton;
}


void LoginDialog::paintEvent(QPaintEvent *)
{
    QPixmap pixmap = QPixmap(":/resource/images/login_background.png").scaled(this -> size());
    QPainter painter(this);
    painter.drawPixmap(this -> rect(), pixmap);
}

void LoginDialog::closeEvent(QCloseEvent *)
{
    QApplication::exit();
}

void LoginDialog::on_login_click()
{
    accept();
}

void LoginDialog::on_exit_click()
{
    reject();
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("HF电缆局放检测系统");

    QLabel *company = new QLabel(this);
    company -> setText("高频局放检测系统,Copyright(C)2019 北京华电智成电气设备有限公司,All rights reserved.");

    QLabel *text1 = new QLabel(ui -> statusBar);
    QLabel *text2 = new QLabel(ui -> statusBar);
    text2 -> setText("相位:50.00Hz");
    text3 = new QLabel(ui -> statusBar);

    company -> setMinimumWidth(500);
    text1 -> setMinimumWidth(200);
    text2 -> setMinimumWidth(100);
    text3 -> setMinimumWidth(100);

    ui -> statusBar -> addWidget(company);
    ui -> statusBar -> addWidget(text1);
    ui -> statusBar -> addWidget(text2);
    ui -> statusBar -> addWidget(text3);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
    timer -> start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;

    delete text3;
}

void MainWindow::timerUpdate()
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss");
    text3 -> setText(str);
}

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

    amplitudeMainWidget1 = new AmplitudeMainWidget(this);
    amplitudeMainWidget2 = new AmplitudeMainWidget(this);
    amplitudeMainWidget3 = new AmplitudeMainWidget(this);
    amplitudeMainWidget4 = new AmplitudeMainWidget(this);

    pGridLayout = new QGridLayout(this);

    pGridLayout -> addWidget(amplitudeMainWidget1, 0 ,0, 1, 1);
    pGridLayout -> addWidget(amplitudeMainWidget2, 0 ,1, 1, 1);
    pGridLayout -> addWidget(amplitudeMainWidget3, 0 ,2, 1, 1);
    pGridLayout -> addWidget(amplitudeMainWidget4, 0 ,3, 1, 1);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete pGridLayout;
    delete text3;

    delete amplitudeMainWidget1;
    delete amplitudeMainWidget2;
    delete amplitudeMainWidget3;
    delete amplitudeMainWidget4;
}

void MainWindow::timerUpdate()
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss");
    text3 -> setText(str);
}

void MainWindow::paintEvent(QPaintEvent *)
{
    int width = this -> geometry().width();  // 窗口宽度
    int height = this -> geometry().height();  // 窗口高度

    amplitudeMainWidget1 -> setSize(width / 4, height / 6);
    amplitudeMainWidget2 -> setSize(width / 4, height / 6);
    amplitudeMainWidget3 -> setSize(width / 4, height / 6);
    amplitudeMainWidget4 -> setSize(width / 4, height / 6);

   // ui -> gridLayout ->setGeometry(QRect(0, 0, width, height));
}

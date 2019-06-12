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

    pCentralWidget = new QWidget(this);
    setCentralWidget(pCentralWidget);

    pScatterPlot1 = new ScatterPlot(pCentralWidget);
    pScatterPlot2 = new ScatterPlot(pCentralWidget);
    pScatterPlot3 = new ScatterPlot(pCentralWidget);
    pScatterPlot4 = new ScatterPlot(pCentralWidget);

    typeDiagnosisCH1 = new TypeDiagnosisWidget(pCentralWidget);
    typeDiagnosisCH2 = new TypeDiagnosisWidget(pCentralWidget);
    typeDiagnosisCH3 = new TypeDiagnosisWidget(pCentralWidget);
    typeDiagnosisCH4 = new TypeDiagnosisWidget(pCentralWidget);

    typeDiagnosisCH1 -> setTitleName("类型诊断-CH1");
    typeDiagnosisCH2 -> setTitleName("类型诊断-CH2");
    typeDiagnosisCH3 -> setTitleName("类型诊断-CH3");
    typeDiagnosisCH4 -> setTitleName("类型诊断-CH4");

    typeDiagnosisCH1 -> setTypeName("CH1");
    typeDiagnosisCH2 -> setTypeName("CH2");
    typeDiagnosisCH3 -> setTypeName("CH3");
    typeDiagnosisCH4 -> setTypeName("CH4");

    pGridLayout = new QGridLayout(pCentralWidget);
    pGridLayout -> setMargin(0);

    pGridLayout -> addWidget(pScatterPlot1, 0 ,0, 1, 1);
    pGridLayout -> addWidget(pScatterPlot2, 0 ,1, 1, 1);
    pGridLayout -> addWidget(pScatterPlot3, 0 ,2, 1, 1);
    pGridLayout -> addWidget(pScatterPlot4, 0 ,3, 1, 1);

    pGridLayout -> addWidget(typeDiagnosisCH1, 1 ,0, 1, 1);
    pGridLayout -> addWidget(typeDiagnosisCH2, 1 ,1, 1, 1);
    pGridLayout -> addWidget(typeDiagnosisCH3, 1 ,2, 1, 1);
    pGridLayout -> addWidget(typeDiagnosisCH4, 1 ,3, 1, 1);


    pCentralWidget -> setLayout(pGridLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete pGridLayout;
    delete text3;

    delete pScatterPlot1;
    delete pScatterPlot2;
    delete pScatterPlot3;
    delete pScatterPlot4;

    delete typeDiagnosisCH1;
    delete typeDiagnosisCH2;
    delete typeDiagnosisCH3;
    delete typeDiagnosisCH4;
}

void MainWindow::timerUpdate()
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss");
    text3 -> setText(str);
}

void MainWindow::paintEvent(QPaintEvent *)
{
    int centralWidth = pCentralWidget -> width();  // 窗口宽度
    int centralHeight = pCentralWidget -> height();  // 窗口高度

    pScatterPlot1 -> resize(centralWidth / 4, centralHeight / 3);
    pScatterPlot2 -> resize(centralWidth / 4, centralHeight / 3);
    pScatterPlot3 -> resize(centralWidth / 4, centralHeight / 3);
    pScatterPlot4 -> resize(centralWidth / 4, centralHeight / 3);

    typeDiagnosisCH1 -> setSize(centralWidth / 4 - 5, centralHeight / 3);
    typeDiagnosisCH2 -> setSize(centralWidth / 4 - 5, centralHeight / 3);
    typeDiagnosisCH3 -> setSize(centralWidth / 4 - 5, centralHeight / 3);
    typeDiagnosisCH4 -> setSize(centralWidth / 4 - 5, centralHeight / 3);

    pGridLayout -> setGeometry(QRect(0, 0, centralWidth, centralHeight - 220));
}

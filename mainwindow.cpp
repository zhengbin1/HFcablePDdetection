#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("HF电缆局放检测系统");
    setStyleSheet("background-color: #C9C9C9;");

    QLabel *company = new QLabel(this);
    company -> setText("高频局放检测系统,Copyright(C)2019 北京华电智成电气设备有限公司,All rights reserved.");

    QLabel *text1 = new QLabel(ui -> statusBar);
    QLabel *text2 = new QLabel(ui -> statusBar);
    text2 -> setText("相位:50.00Hz");
    text3 = new QLabel(ui -> statusBar);

    OperationFile::isDirExist(OperationFile::strRootPath);
    text1 -> setText(OperationFile::strRootPath);

    company -> setMinimumWidth(600);
    text1 -> setMinimumWidth(300);
    text2 -> setMinimumWidth(150);
    text3 -> setMinimumWidth(150);

    ui -> statusBar -> addWidget(company);
    ui -> statusBar -> addWidget(text1);
    ui -> statusBar -> addWidget(text2);
    ui -> statusBar -> addWidget(text3);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
    timer -> start(1000);

    pCentralWidget = new QWidget(this);
    setCentralWidget(pCentralWidget);

    pScatterPlot1 = new ScatterPlot();
    pScatterPlot2 = new ScatterPlot();
    pScatterPlot3 = new ScatterPlot();
    pScatterPlot4 = new ScatterPlot();

    typeDiagnosisCH1 = new TypeDiagnosisWidget();
    typeDiagnosisCH2 = new TypeDiagnosisWidget();
    typeDiagnosisCH3 = new TypeDiagnosisWidget();
    typeDiagnosisCH4 = new TypeDiagnosisWidget();

    typeDiagnosisCH1 -> setTitleName("类型诊断-CH1");
    typeDiagnosisCH2 -> setTitleName("类型诊断-CH2");
    typeDiagnosisCH3 -> setTitleName("类型诊断-CH3");
    typeDiagnosisCH4 -> setTitleName("类型诊断-CH4");

    typeDiagnosisCH1 -> setTypeName("CH1");
    typeDiagnosisCH2 -> setTypeName("CH2");
    typeDiagnosisCH3 -> setTypeName("CH3");
    typeDiagnosisCH4 -> setTypeName("CH4");

    trendChannelWidget = new TrendChannelWidget();

    pGridLayout = new QGridLayout(pCentralWidget);
    pGridLayout -> setMargin(0);

    pGridLayout -> addWidget(pScatterPlot1, 0, 0, 1, 1);
    pGridLayout -> addWidget(pScatterPlot2, 0, 1, 1, 1);
    pGridLayout -> addWidget(pScatterPlot3, 0, 2, 1, 1);
    pGridLayout -> addWidget(pScatterPlot4, 0, 3, 1, 1);

    pGridLayout -> addWidget(typeDiagnosisCH1, 1, 0, 1, 1);
    pGridLayout -> addWidget(typeDiagnosisCH2, 1, 1, 1, 1);
    pGridLayout -> addWidget(typeDiagnosisCH3, 1, 2, 1, 1);
    pGridLayout -> addWidget(typeDiagnosisCH4, 1, 3, 1, 1);

    pGridLayout -> addWidget(trendChannelWidget, 2, 0, 1, 4);

    pGridLayout -> setRowStretch(0, 1);
    pGridLayout -> setRowStretch(1, 1);
    pGridLayout -> setRowStretch(2, 1);

    pCentralWidget -> setLayout(pGridLayout);

    pNewProductDialog = new NewProductDialog(this);
    pNewProductDialog -> hide();
    connect(ui -> menu_1, SIGNAL(triggered(QAction *)), this, SLOT(triggerMenu(QAction *)));
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

    delete trendChannelWidget;

    delete pNewProductDialog;
}

void MainWindow::timerUpdate()
{
    QDateTime datetime = QDateTime::currentDateTime();
    QString str = datetime.toString("yyyy-MM-dd hh:mm:ss");
    text3 -> setText(str);
}

void MainWindow::triggerMenu(QAction *a)
{
    if(a -> objectName() == "action_1")
    {
        pNewProductDialog -> show();
    }
}

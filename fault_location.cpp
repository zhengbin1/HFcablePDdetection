#include "fault_location.h"


CLineGraph1::CLineGraph1(QWidget *parent): QChartView(new QChart(), parent)
{
    m_AxisX = new QValueAxis;
    m_AxisX -> setTitleText("<span style=\"color:#FFFFFF;\">时间(us)</span>");
    m_AxisX -> setLabelsBrush(QBrush(QColor(255, 255, 255)));
    m_AxisX -> setTickCount(10);
    m_AxisX -> setRange(0, 20);
    m_AxisX -> setLabelFormat("%d");

    m_AxisY = new QValueAxis;
    m_AxisY -> setTitleText("<span style=\"color:#FFFFFF;\">幅值V</span>");
    m_AxisY -> setLabelsBrush(QBrush(QColor(255, 255, 255)));
    m_AxisY -> setTickCount(7);
    m_AxisY -> setRange(-1, 1);
    m_AxisY -> setLabelFormat("%.1f");

    chart() -> legend() -> setVisible(false);
    chart() -> setBackgroundBrush(QBrush(QColor(0, 0, 0)));
    chart() -> addAxis(m_AxisX, Qt::AlignBottom);
    chart() -> addAxis(m_AxisY, Qt::AlignLeft);
}

CLineGraph1::~CLineGraph1()
{
    delete m_AxisX;
    delete m_AxisY;
}

CFaultLocation::CFaultLocation(QWidget *parent) : QDialog(parent)
{
    Qt::WindowFlags flags = Qt::Dialog;

    flags &= ~Qt::WindowContextHelpButtonHint;
    flags |= Qt::WindowMinMaxButtonsHint;
    flags |= Qt::WindowCloseButtonHint;

    setWindowFlags(flags);
    setWindowTitle("故障定位");
    setStyleSheet("background-color: #999999;");

    // 获取桌面屏幕大小
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect rect = screen -> availableGeometry();
    m_screen_width = rect.width();
    m_screen_height = rect.height();

    resize(m_screen_width / 2, m_screen_height / 2);

    pTextTitle = new QLabel(this);
    pTextTitle -> setText("<p style=\"color:#00FF00;font-size:20px;text-align:center;\">故 障 定 位</p>");

    pText1 = new QLabel;
    pText1 -> setText("<span style=\"color:#000000;font-size:12px;\">电线长度(m)</span>");
    pText2 = new QLabel;
    pText2 -> setText("<span style=\"color:#000000;font-size:12px;\">采样时间(us)</span>");
    pText3 = new QLabel;
    pText3 -> setText("<span style=\"color:#000000;font-size:12px;\">通道号</span>");

    pLineEdit1 = new QLineEdit(this);
    pLineEdit2 = new QLineEdit(this);

    pLineEdit1 -> setStyleSheet("background-color:#FFFFFF;");
    pLineEdit2 -> setStyleSheet("background-color:#FFFFFF;");

    pLineEdit1 -> setText("2000");
    pLineEdit2 -> setText("20");

    QCheckBox *pCheckBox1 = new QCheckBox;
    pCheckBox1 -> setText("通道1");
    QCheckBox *pCheckBox2 = new QCheckBox;
    pCheckBox2 -> setText("通道2");
    QCheckBox *pCheckBox3 = new QCheckBox;
    pCheckBox3 -> setText("通道3");
    QCheckBox *pCheckBox4 = new QCheckBox;
    pCheckBox4 -> setText("通道4");

    m_ButtonGroup = new QButtonGroup(this);
    m_ButtonGroup -> addButton(pCheckBox1, 0);
    m_ButtonGroup -> addButton(pCheckBox2, 1);
    m_ButtonGroup -> addButton(pCheckBox3, 2);
    m_ButtonGroup -> addButton(pCheckBox4, 3);

    pButton1 = new QPushButton;
    pButton2 = new QPushButton;
    pButton3 = new QPushButton;

    pButton1 -> setStyleSheet("background-color:#FFFFFF;");
    pButton2 -> setStyleSheet("background-color:#FFFFFF;");
    pButton3 -> setStyleSheet("background-color:#FFFFFF;");

    pButton1 -> setText("运 行");
    pButton2 -> setText("触 发");
    pButton3 -> setText("保 存");

    pGridLayout = new QGridLayout;
    pGridLayout -> addWidget(pCheckBox1, 0, 0, 1, 1);
    pGridLayout -> addWidget(pCheckBox2, 0, 1, 1, 1);
    pGridLayout -> addWidget(pCheckBox3, 1, 0, 1, 1);
    pGridLayout -> addWidget(pCheckBox4, 1, 1, 1, 1);

    pVBoxLayout1 = new QVBoxLayout;
    pVBoxLayout1 -> addWidget(pText1, 1);
    pVBoxLayout1 -> addWidget(pLineEdit1, 1);
    pVBoxLayout1 -> addWidget(pText2, 1);
    pVBoxLayout1 -> addWidget(pLineEdit2, 1);
    pVBoxLayout1 -> addWidget(pText3, 1);
    pVBoxLayout1 -> addLayout(pGridLayout, 3);
    pVBoxLayout1 -> addStretch(1);
    pVBoxLayout1 -> addWidget(pButton1, 1);
    pVBoxLayout1 -> addWidget(pButton2, 1);
    pVBoxLayout1 -> addWidget(pButton3, 1);
    pVBoxLayout1 -> addStretch(10);

    pLineGraph1 = new CLineGraph1;
    pHBoxLayout1 = new QHBoxLayout;
    pHBoxLayout1 -> addWidget(pLineGraph1, 10);
    pHBoxLayout1 -> addLayout(pVBoxLayout1, 1);

    pVBoxLayoutMain = new QVBoxLayout(this);
    pVBoxLayoutMain -> addWidget(pTextTitle, 1);
    pVBoxLayoutMain -> addLayout(pHBoxLayout1, 10);

    setLayout(pVBoxLayoutMain);
}

CFaultLocation::~CFaultLocation()
{
    delete pTextTitle;
    delete pLineGraph1;
    delete pText1;
    delete pText2;
    delete pText3;
    delete pLineEdit1;
    delete pLineEdit2;
    delete m_ButtonGroup;
    delete pButton1;
    delete pButton2;
    delete pButton3;

    delete pGridLayout;
    delete pVBoxLayout1;
    delete pHBoxLayout1;
    delete pVBoxLayoutMain;
}

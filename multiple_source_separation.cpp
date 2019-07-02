#include "multiple_source_separation.h"

ColorSignWidget::ColorSignWidget(QWidget *parent) : QWidget(parent)
{
    setStyleSheet("background-color: #CCCCCC;");

    m_Color_Label0 = new QLabel(this);
    m_Color_Label1 = new QLabel(this);
    m_Color_Label2 = new QLabel(this);
    m_Color_Label3 = new QLabel(this);
    m_Color_Label4 = new QLabel(this);
    m_Color_Label5 = new QLabel(this);

    m_Color_Label0 -> setStyleSheet("background-color: #00e500;");
    m_Color_Label0 -> resize(25, 15);
    m_Color_Label0 -> move(10, 10);
    m_Color_Label1 -> setStyleSheet("background-color: #ff0000;");
    m_Color_Label1 -> resize(25, 15);
    m_Color_Label1 -> move(10, 35);
    m_Color_Label2 -> setStyleSheet("background-color: #ff9900;");
    m_Color_Label2 -> resize(25, 15);
    m_Color_Label2 -> move(10, 60);
    m_Color_Label3 -> setStyleSheet("background-color: #ffff00;");
    m_Color_Label3 -> resize(25, 15);
    m_Color_Label3 -> move(10, 85);
    m_Color_Label4 -> setStyleSheet("background-color: #8A2BE2;");
    m_Color_Label4 -> resize(25, 15);
    m_Color_Label4 -> move(10, 110);
    m_Color_Label5 -> setStyleSheet("background-color: #0000ff;");
    m_Color_Label5 -> resize(25, 15);
    m_Color_Label5 -> move(10, 135);

    m_Text_PRPD0 = new QLabel(this);
    m_Text_PRPD1 = new QLabel(this);
    m_Text_PRPD2 = new QLabel(this);
    m_Text_PRPD3 = new QLabel(this);
    m_Text_PRPD4 = new QLabel(this);
    m_Text_PRPD5 = new QLabel(this);

    m_Text_PRPD0 -> setText("<span style=\"color:#000000;font-size:15px;text-align:center;\">PRPD-0</span>");
    m_Text_PRPD1 -> setText("<span style=\"color:#000000;font-size:15px;text-align:center;\">PRPD-1</span>");
    m_Text_PRPD2 -> setText("<span style=\"color:#000000;font-size:15px;text-align:center;\">PRPD-2</span>");
    m_Text_PRPD3 -> setText("<span style=\"color:#000000;font-size:15px;text-align:center;\">PRPD-3</span>");
    m_Text_PRPD4 -> setText("<span style=\"color:#000000;font-size:15px;text-align:center;\">PRPD-4</span>");
    m_Text_PRPD5 -> setText("<span style=\"color:#000000;font-size:15px;text-align:center;\">PRPD-5</span>");

    m_Text_PRPD0 -> move(40, 10);
    m_Text_PRPD1 -> move(40, 35);
    m_Text_PRPD2 -> move(40, 60);
    m_Text_PRPD3 -> move(40, 85);
    m_Text_PRPD4 -> move(40, 110);
    m_Text_PRPD5 -> move(40, 135);
}

ColorSignWidget::~ColorSignWidget()
{
    delete m_Color_Label0;
    delete m_Color_Label1;
    delete m_Color_Label2;
    delete m_Color_Label3;
    delete m_Color_Label4;
    delete m_Color_Label5;

    delete m_Text_PRPD0;
    delete m_Text_PRPD1;
    delete m_Text_PRPD2;
    delete m_Text_PRPD3;
    delete m_Text_PRPD4;
    delete m_Text_PRPD5;
}

void ColorSignWidget::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style() -> drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);
}


MSSeparationDialog::MSSeparationDialog(QWidget *parent) : QDialog(parent)
{
    Qt::WindowFlags flags = Qt::Dialog;

    flags &= ~Qt::WindowContextHelpButtonHint;
    flags |= Qt::WindowMinMaxButtonsHint;
    flags |= Qt::WindowCloseButtonHint;

    setWindowFlags(flags);
    setWindowTitle("多源分离");
    setStyleSheet("background-color: #999999;");

    // 获取桌面屏幕大小
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect rect = screen -> availableGeometry();
    m_screen_width = rect.width();
    m_screen_height = rect.height();

    resize(m_screen_width / 2, m_screen_height / 2);

    pCaption = new QLabel(this);
    pCaption -> setText("<p style=\"color:#6699CC;font-size:20px;text-align:center;\">多 源 分 离</p>");


    pColorSignWidget = new ColorSignWidget(this);

    pHBoxLayout_1 = new QHBoxLayout();
    pHBoxLayout_1 -> addWidget(pColorSignWidget);

    pVBoxLayoutMain = new QVBoxLayout(this);
    pVBoxLayoutMain -> addWidget(pCaption);
    pVBoxLayoutMain -> addLayout(pHBoxLayout_1);

    setLayout(pVBoxLayoutMain);
}

MSSeparationDialog::~MSSeparationDialog()
{
    delete pCaption;

    delete pColorSignWidget;
    delete pHBoxLayout_1;
    delete pVBoxLayoutMain;
}

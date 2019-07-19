#include "query_dialog.h"

CBarGraph1::CBarGraph1(QWidget *parent): QChartView(new QChart(), parent)
{
    QDateTime startTime(QDate(2000, 1, 1), QTime(0, 0, 0));
    QDateTime endTime(QDate(2000, 1, 1), QTime(0, 20, 0));

    m_AxisX = new QValueAxis;
    m_AxisX -> setTitleText("<span style=\"color:#FFFFFF;\">相位(°)</span>");
    m_AxisX -> setLabelsBrush(QBrush(QColor(255, 255, 255)));
    m_AxisX -> setTickCount(10);
    m_AxisX -> setRange(0, 360);

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

CBarGraph1::~CBarGraph1()
{
    delete m_AxisX;
    delete m_AxisY;
}


CBarGraph2::CBarGraph2(QWidget *parent): QChartView(new QChart(), parent)
{
    QDateTime startTime(QDate(2000, 1, 1), QTime(0, 0, 0));
    QDateTime endTime(QDate(2000, 1, 1), QTime(0, 20, 0));

    m_AxisX = new QValueAxis;
    m_AxisX -> setTitleText("<span style=\"color:#FFFFFF;\">相位(°)</span>");
    m_AxisX -> setLabelsBrush(QBrush(QColor(255, 255, 255)));
    m_AxisX -> setTickCount(10);
    m_AxisX -> setRange(0, 360);

    m_AxisY = new QValueAxis;
    m_AxisY -> setTitleText("<span style=\"color:#FFFFFF;\">个数</span>");
    m_AxisY -> setLabelsBrush(QBrush(QColor(255, 255, 255)));
    m_AxisY -> setTickCount(7);
    m_AxisY -> setRange(0, 1000);

    chart() -> legend() -> setVisible(false);
    chart() -> setBackgroundBrush(QBrush(QColor(0, 0, 0)));
    chart() -> addAxis(m_AxisX, Qt::AlignBottom);
    chart() -> addAxis(m_AxisY, Qt::AlignLeft);
}

CBarGraph2::~CBarGraph2()
{
    delete m_AxisX;
    delete m_AxisY;
}


CBarLine::CBarLine(QWidget *parent) : QWidget(parent)
{
    setStyleSheet("background-color:#00ff00;");

    setCursor(QCursor(Qt::OpenHandCursor));
}

CBarLine::~CBarLine()
{

}

void CBarLine::mousePressEvent(QMouseEvent *event)
{
    setCursor(QCursor(Qt::ClosedHandCursor));

    if(event -> button() == Qt::LeftButton)
    {
        m_bar_moved = true;
        // 获得鼠标的初始位置
        mouseStartPoint = event -> globalPos();
        // 获得窗口的初始位置
        windowTopLeftPoint = this -> frameGeometry().topLeft();
    }
}

void CBarLine::mouseMoveEvent(QMouseEvent *event)
{
    if(m_bar_moved == true)
    {
        // 获得鼠标移动的距离
        QPoint distance = event -> globalPos() - mouseStartPoint;

        QPoint barpos = windowTopLeftPoint + distance;
        this -> move(barpos.x(), static_cast<int>(m_PlotArea.y()));
        m_posX = barpos.x();
        m_posY = static_cast<int>(m_PlotArea.y());
    }
}

void CBarLine::mouseReleaseEvent(QMouseEvent *event)
{
    setCursor(QCursor(Qt::OpenHandCursor));

    if(event -> button() == Qt::LeftButton)
    {
        m_bar_moved = false;
    }

    if(m_PlotArea.x() > this -> frameGeometry().topLeft().x())  // 如果超出左边位置，则停留在最左的开始位置
    {
        this -> move(static_cast<int>(m_PlotArea.x()), static_cast<int>(m_PlotArea.y()));
    }

    if(static_cast<int>(m_PlotArea.width() + m_PlotArea.x()) < this -> frameGeometry().bottomRight().x())  // 如果超出右边位置，则停留在最右的开始位置
    {
        this -> move(static_cast<int>(m_PlotArea.width() + m_PlotArea.x()), static_cast<int>(m_PlotArea.y()));
    }
}

CBarGraph5::CBarGraph5(QWidget *parent): QChartView(new QChart(), parent)
{
    QDateTime startTime(QDate(2000, 1, 1), QTime(0, 0, 0));
    QDateTime endTime(QDate(2000, 1, 1), QTime(0, 20, 0));

    m_AxisX_Time = new QDateTimeAxis(this);
    m_AxisX_Time -> setTitleText("<span style=\"color:#FFFFFF;\">时 间</span>");
    m_AxisX_Time -> setLabelsBrush(QBrush(QColor(255, 255, 255)));
    m_AxisX_Time -> setTickCount(10);
    m_AxisX_Time -> setRange(startTime, endTime);
    m_AxisX_Time -> setFormat("hh:mm:ss");

    m_AxisY_Data = new QValueAxis();
    m_AxisY_Data -> setTitleText("<span style=\"color:#FFFFFF;\">幅值V</span>");
    m_AxisY_Data -> setLabelsBrush(QBrush(QColor(255, 255, 255)));
    m_AxisY_Data -> setTickCount(7);
    m_AxisY_Data -> setRange(-1, 1);
    m_AxisY_Data -> setLabelFormat("%.1f");

    chart() -> legend() -> setVisible(false);
    chart() -> setBackgroundBrush(QBrush(QColor(0, 0, 0)));
    chart() -> addAxis(m_AxisX_Time, Qt::AlignBottom);
    chart() -> addAxis(m_AxisY_Data, Qt::AlignLeft);

    pBarLine = new CBarLine(this -> viewport());

}

CBarGraph5::~CBarGraph5()
{
    delete m_AxisX_Time;
    delete m_AxisY_Data;

    delete pBarLine;
}

void CBarGraph5::showEvent(QShowEvent *event)
{
    QChartView::showEvent(event);

    pBarLine -> resize(3, static_cast<int>(chart() -> plotArea().height()));
    pBarLine -> move(static_cast<int>(this -> viewport() -> width()) / 2, static_cast<int>(chart() -> plotArea().y()));
    pBarLine -> setPlotArea(chart() -> plotArea());
}

void CBarGraph5::resizeEvent(QResizeEvent *re)
{
    QChartView::resizeEvent(re);

    pBarLine -> resize(3, static_cast<int>(chart() -> plotArea().height()));
    pBarLine -> move(static_cast<int>(this -> viewport() -> width()) / 2, static_cast<int>(chart() -> plotArea().y()));
    pBarLine -> setPlotArea(chart() -> plotArea());
}


CQueryDialog::CQueryDialog(QWidget *parent) : QDialog(parent)
{
    Qt::WindowFlags flags = Qt::Dialog;

    flags &= ~Qt::WindowContextHelpButtonHint;
    flags |= Qt::WindowMinMaxButtonsHint;
    flags |= Qt::WindowCloseButtonHint;

    setWindowFlags(flags);
    setWindowTitle("查 询");
    setStyleSheet("background-color: #999999;");

    // 获取桌面屏幕大小
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect rect = screen -> availableGeometry();
    m_screen_width = rect.width();
    m_screen_height = rect.height();

    resize(m_screen_width / 2, m_screen_height / 2);

    pTextTitle = new QLabel(this);
    pTextTitle -> setText("<p style=\"color:#00FF00;font-size:15px;text-align:center;\">查询方式</p>");

    pTabWidget = new QTabWidget();
    pTabW1 = new QWidget(pTabWidget);
    pTabW2 = new QWidget(pTabWidget);
    pTabWidget -> addTab(pTabW1, "按项目名称查询");
    pTabWidget -> addTab(pTabW2, "按时间查询");

    pTabW1_Layout = new QVBoxLayout(pTabW1);
    pTabW2_Layout = new QVBoxLayout(pTabW2);

    pLabelText1 = new QLabel;
    pLabelText1 -> setText("<p style=\"color:#00FF00;font-size:12px;text-align:center;\">项目名称</p>");

    pLineEdit1 = new QLineEdit;
    pLineEdit1 -> setStyleSheet("background-color: #ffffff;");

    pTabW1_Layout1 = new QFormLayout;
    pTabW1_Layout1 -> addRow(pLabelText1, pLineEdit1);

    pSearchButton1 = new QPushButton;
    pSearchButton1 -> setStyleSheet("background-color: #1bd1a5;");
    pSearchButton1 -> setIcon(QIcon(QPixmap(":/resource/images/search_32px_1182191_easyicon.net.ico")));
    pSearchButton1 -> setText("查 询");

    pTabW1_Layout -> addSpacerItem(new QSpacerItem(10, 10));
    pTabW1_Layout -> addLayout(pTabW1_Layout1, 1);
    pTabW1_Layout -> addWidget(pSearchButton1, 1);

    pLabelText2 = new QLabel;
    pLabelText2 -> setText("<p style=\"color:#00FF00;font-size:12px;text-align:center;\">起始时间</p>");
    pDateEdit1 = new QDateEdit;
    pDateEdit1 -> setStyleSheet("background-color: #ffffff;");
    pDateEdit1 -> setCalendarPopup(true);
    pLabelText3 = new QLabel;
    pLabelText3 -> setText("<p style=\"color:#00FF00;font-size:12px;text-align:center;\">终止时间</p>");
    pDateEdit2 = new QDateEdit;
    pDateEdit2 -> setStyleSheet("background-color: #ffffff;");
    pDateEdit2 -> setCalendarPopup(true);
    pSearchButton2 = new QPushButton;
    pSearchButton2 -> setStyleSheet("background-color: #1bd1a5;");
    pSearchButton2 -> setIcon(QIcon(QPixmap(":/resource/images/search_32px_1182191_easyicon.net.ico")));
    pSearchButton2 -> setText("查 询");

    pCalendar1 = new QCalendarWidget(this);
    pCalendar1 -> setStyleSheet("background-color: #99CC99;");
    pCalendar1 -> show();
    pDateEdit1 -> setCalendarWidget(pCalendar1);
    pDateEdit1 -> setDate(pCalendar1 -> selectedDate());
    QDate date(QDateTime::currentDateTime().date());
    date.setDate(date.year(), date.month(), date.day());
    pCalendar1 -> setSelectedDate(date);

    pCalendar2 = new QCalendarWidget(this);
    pCalendar2 -> setStyleSheet("background-color: #99CC99;");
    pCalendar2 -> show();
    pDateEdit2 -> setCalendarWidget(pCalendar2);
    pDateEdit2 -> setDate(pCalendar2 -> selectedDate());
    pCalendar2 -> setSelectedDate(date);


    pTabW2_HLayout1 = new QHBoxLayout;
    pTabW2_HLayout1 -> addWidget(pLabelText2, 1);
    pTabW2_HLayout1 -> addWidget(pDateEdit1, 2);

    pTabW2_HLayout2 = new QHBoxLayout;
    pTabW2_HLayout2 -> addWidget(pLabelText3, 1);
    pTabW2_HLayout2 -> addWidget(pDateEdit2, 2);

    pTabW2_HLayout3 = new QHBoxLayout;
    pTabW2_HLayout3 -> addWidget(pSearchButton2);

    pTabW2_Layout -> addLayout(pTabW2_HLayout1);
    pTabW2_Layout -> addLayout(pTabW2_HLayout2);
    pTabW2_Layout -> addLayout(pTabW2_HLayout3);

    pTabW1 -> setLayout(pTabW1_Layout);
    pTabW2 -> setLayout(pTabW2_Layout);

    pVBoxLayout1 = new QVBoxLayout();
    pVBoxLayout1 -> addWidget(pTextTitle, 1);
    pVBoxLayout1 -> addWidget(pTabWidget, 5);
    pVBoxLayout1 -> addStretch(10);

    pBarGraph1 = new CBarGraph1;
    pBarGraph2 = new CBarGraph1;
    pBarGraph3 = new CBarGraph2;
    pBarGraph4 = new CBarGraph2;
    pBarGraph5 = new CBarGraph5;

    pGridLayout = new QGridLayout;
    pGridLayout -> addWidget(pBarGraph1, 0, 0, 1, 1);
    pGridLayout -> addWidget(pBarGraph2, 0, 1, 1, 1);
    pGridLayout -> addWidget(pBarGraph3, 1, 0, 1, 1);
    pGridLayout -> addWidget(pBarGraph4, 1, 1, 1, 1);
    pGridLayout -> addWidget(pBarGraph5, 2, 0, 1, 2);


    pHBoxLayoutMain = new QHBoxLayout(this);
    pHBoxLayoutMain -> addLayout(pVBoxLayout1, 1);
    pHBoxLayoutMain -> addLayout(pGridLayout, 5);

    setLayout(pHBoxLayoutMain);
}

CQueryDialog::~CQueryDialog()
{
    delete pBarGraph1;
    delete pBarGraph2;
    delete pBarGraph3;
    delete pBarGraph4;
    delete pBarGraph5;
    delete pTextTitle;
    delete pCalendar1;
    delete pCalendar2;
    delete pLabelText1;
    delete pLineEdit1;
    delete pSearchButton1;
    delete pLabelText2;
    delete pDateEdit1;
    delete pLabelText3;
    delete pDateEdit2;
    delete pSearchButton2;

    delete pTabW1_Layout1;
    delete pTabW2_HLayout1;
    delete pTabW2_HLayout2;
    delete pTabW2_HLayout3;
    delete pTabW1_Layout;
    delete pTabW2_Layout;
    delete pTabW1;
    delete pTabW2;
    delete pGridLayout;
    delete pTabWidget;
    delete pVBoxLayout1;
    delete pHBoxLayoutMain;
}

#include "trend_channel_widget.h"

QCPLine1::QCPLine1(QWidget *parent) : QWidget(parent)
{

    m_Plot = new QCustomPlot(this);
    m_Plot -> setBackground(QBrush(Qt::black));
    m_Plot -> setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes);

    QSharedPointer<QCPAxisTickerTime> timeTickerX(new QCPAxisTickerTime);
    timeTickerX -> setTimeFormat("%m:%s");
    timeTickerX -> setTickCount(10);
    m_Plot -> xAxis -> setTicker(timeTickerX);
    m_Plot -> xAxis -> setTickPen(QPen(QColor(255, 255, 255)));
    m_Plot -> xAxis -> setSubTickPen(QPen(QColor(255, 255, 255)));
    m_Plot -> xAxis -> setBasePen(QPen(QColor(255, 255, 255)));
    m_Plot -> xAxis -> setTickLabelColor(QColor(255, 255, 255));

    QSharedPointer<QCPAxisTicker> axisTickerY(new QCPAxisTicker);
    axisTickerY -> setTickCount(9);
    m_Plot -> yAxis -> setRange(-1, 1);
    m_Plot -> yAxis -> setTicker(axisTickerY);
    m_Plot -> yAxis -> setTickPen(QPen(QColor(255, 255, 255)));
    m_Plot -> yAxis -> setSubTickPen(QPen(QColor(255, 255, 255)));
    m_Plot -> yAxis -> setBasePen(QPen(QColor(255, 255, 255)));
    m_Plot -> yAxis -> setTickLabelColor(QColor(255, 255, 255));


    m_Graph1 = m_Plot -> addGraph(m_Plot -> xAxis, m_Plot -> yAxis);
    m_Graph2 = m_Plot -> addGraph(m_Plot -> xAxis, m_Plot -> yAxis);
    m_Graph1 -> rescaleValueAxis(false, false);
    m_Graph1 -> setPen(QPen(QColor(250, 120, 0)));
    m_Graph2 -> setPen(QPen(QColor(0, 180, 60)));

    connect(m_Plot, SIGNAL(mouseMove(QMouseEvent *)), this, SLOT(QCPMoveEvent(QMouseEvent *)));

    m_startTime = QDateTime::currentDateTime().time().minute() * 60 + QDateTime::currentDateTime().time().second();

    m_HBoxLayout = new QHBoxLayout(this);
    m_HBoxLayout -> addWidget(m_Plot);

    setLayout(m_HBoxLayout);

    startTimer(1000);
}

QCPLine1::~QCPLine1()
{
    delete m_Plot;
    delete m_HBoxLayout;
}

void QCPLine1::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style() -> drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);
}

void QCPLine1::timerEvent(QTimerEvent *)
{
    qsrand(static_cast<unsigned int>(QTime(0,0,0).secsTo(QTime::currentTime())));

    int x = qrand() % 360;
    qreal y = 0;

    int tmp = qrand() % 10;
    if(tmp != 0){
        if(x % 2 == 0)
        {
            y = static_cast<qreal>(tmp) / 10;
            y = -y;
        } else {
            y = static_cast<qreal>(tmp) / 10;
        }
    }

    // 一小时内的经过秒数
    int passPointX = QDateTime::currentDateTime().time().minute() * 60 + QDateTime::currentDateTime().time().second();

    if((passPointX >= 0) && (passPointX <= 1))
    {
        m_startTime = QDateTime::currentDateTime().time().minute() * 60 + QDateTime::currentDateTime().time().second();
    }

    m_Graph1 -> addData(passPointX, y);
    m_Plot -> xAxis -> setRange(m_startTime, passPointX);
    m_Plot -> replot();
}

void QCPLine1::QCPMoveEvent(QMouseEvent *event)
{
    //获取鼠标坐标，相对父窗体坐标
    int posX = event -> pos().x();
    int posY = event -> pos().y();

    //鼠标坐标转化为CustomPlot内部坐标
    int val_time_X = static_cast<int>(m_Plot -> xAxis -> pixelToCoord(posX));
    double val_Y = m_Plot -> yAxis -> pixelToCoord(posY);

    //获得x轴坐标位置对应的曲线上y的值
    double lineY_Val = m_Plot -> graph(0) -> data() -> at(static_cast<int>(val_time_X)) -> value;

    //曲线的上点坐标位置，用来显示QToolTip提示框
    int out_X = static_cast<int>(m_Plot -> xAxis -> coordToPixel(val_time_X));
    int out_Y = static_cast<int>(m_Plot -> yAxis -> coordToPixel(lineY_Val));

    int minute = val_time_X / 60;
    int second = val_time_X % 60;

    QString strToolTip, tmp;
    strToolTip += "X : ";
    strToolTip += tmp.sprintf("%02d", minute) + ':' + QString::number(second, 10);
    strToolTip += "\n";

    strToolTip += "Y : ";
    strToolTip += QString::number(val_Y, 10, 1);
    strToolTip += "\n";

    QToolTip::showText(mapToGlobal(QPoint(out_X, out_Y)), strToolTip, m_Plot);
}

QCPLine2::QCPLine2(QWidget *parent) : QWidget(parent)
{
    m_Plot = new QCustomPlot(this);
    m_Plot -> setBackground(QBrush(Qt::black));
    m_Plot -> setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes);

    QSharedPointer<QCPAxisTickerTime> timeTickerX(new QCPAxisTickerTime);
    timeTickerX -> setTimeFormat("%m:%s");
    timeTickerX -> setTickCount(10);
    m_Plot -> xAxis -> setTicker(timeTickerX);
    m_Plot -> xAxis -> setTickPen(QPen(QColor(255, 255, 255)));
    m_Plot -> xAxis -> setSubTickPen(QPen(QColor(255, 255, 255)));
    m_Plot -> xAxis -> setBasePen(QPen(QColor(255, 255, 255)));
    m_Plot -> xAxis -> setTickLabelColor(QColor(255, 255, 255));

    QSharedPointer<QCPAxisTicker> axisTickerY(new QCPAxisTicker);
    axisTickerY -> setTickCount(10);
    m_Plot -> yAxis -> setRange(0, m_MaxValueY);
    m_Plot -> yAxis -> setTicker(axisTickerY);
    m_Plot -> yAxis -> setTickPen(QPen(QColor(255, 255, 255)));
    m_Plot -> yAxis -> setSubTickPen(QPen(QColor(255, 255, 255)));
    m_Plot -> yAxis -> setBasePen(QPen(QColor(255, 255, 255)));
    m_Plot -> yAxis -> setTickLabelColor(QColor(255, 255, 255));


    m_Graph1 = m_Plot -> addGraph(m_Plot -> xAxis, m_Plot -> yAxis);
    m_Graph2 = m_Plot -> addGraph(m_Plot -> xAxis, m_Plot -> yAxis);
    m_Graph1 -> rescaleValueAxis(false, true);
    m_Graph1 -> setPen(QPen(QColor(250, 120, 0)));
    m_Graph2 -> setPen(QPen(QColor(0, 180, 60)));

    connect(m_Plot, SIGNAL(mouseMove(QMouseEvent *)), this, SLOT(QCPMoveEvent(QMouseEvent *)));

    m_startTime = QDateTime::currentDateTime().time().minute() * 60 + QDateTime::currentDateTime().time().second();

    m_HBoxLayout = new QHBoxLayout(this);
    m_HBoxLayout -> addWidget(m_Plot);

    setLayout(m_HBoxLayout);

    startTimer(1000);
}

QCPLine2::~QCPLine2()
{
    delete m_Plot;

    delete m_HBoxLayout;
}

void QCPLine2::timerEvent(QTimerEvent *)
{
    qsrand(static_cast<unsigned int>(QTime(0,0,0).secsTo(QTime::currentTime())));

    int y = qrand() % 2000;

    // 一小时内的经过秒数
    int passPointX = QDateTime::currentDateTime().time().minute() * 60 + QDateTime::currentDateTime().time().second();

    if((passPointX >= 0) && (passPointX <= 1))
    {
        m_startTime = QDateTime::currentDateTime().time().minute() * 60 + QDateTime::currentDateTime().time().second();
    }

    m_Graph1 -> addData(passPointX, y);
    m_Plot -> xAxis -> setRange(m_startTime, passPointX);

    if(y > m_MaxValueY)
    {
        m_MaxValueY = y;
        m_Plot -> yAxis -> setRange(0, m_MaxValueY);
    }

    m_Plot -> replot();
}

void QCPLine2::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style() -> drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);
}

void QCPLine2::QCPMoveEvent(QMouseEvent *event)
{
    //获取鼠标坐标，相对父窗体坐标
    int posX = event -> pos().x();
    int posY = event -> pos().y();

    //鼠标坐标转化为CustomPlot内部坐标
    int val_time_X = static_cast<int>(m_Plot -> xAxis -> pixelToCoord(posX));
    double val_Y = m_Plot -> yAxis -> pixelToCoord(posY);

    //获得x轴坐标位置对应的曲线上y的值
    double lineY_Val = m_Plot -> graph(0) -> data() -> at(static_cast<int>(val_time_X)) -> value;

    //曲线的上点坐标位置，用来显示QToolTip提示框
    int out_X = static_cast<int>(m_Plot -> xAxis -> coordToPixel(val_time_X));
    int out_Y = static_cast<int>(m_Plot -> yAxis -> coordToPixel(lineY_Val));

    int minute = val_time_X / 60;
    int second = val_time_X % 60;

    QString strToolTip, tmp;
    strToolTip += "X : ";
    strToolTip += tmp.sprintf("%02d", minute) + ':' + QString::number(second, 10);
    strToolTip += "\n";

    strToolTip += "Y : ";
    strToolTip += QString::number(val_Y, 10, 0);
    strToolTip += "\n";

    QToolTip::showText(mapToGlobal(QPoint(out_X, out_Y)), strToolTip, m_Plot);
}

TrendChannelWidget::TrendChannelWidget(QWidget *parent) : QWidget(parent)
{
    QLabel *text4 = new QLabel(this);
    text4 -> setText("<p style=\"height:15px;color:green;font-size:13px;text-align:center;\">趋势通道选择</p>");

    QRadioButton *radioButton1 = new QRadioButton(this);
    radioButton1 -> setLayoutDirection(Qt::RightToLeft);
    radioButton1 -> setText("CH1");
    QRadioButton *radioButton2 = new QRadioButton(this);
    radioButton2 -> setLayoutDirection(Qt::RightToLeft);
    radioButton2 -> setText("CH2");
    QRadioButton *radioButton3 = new QRadioButton(this);
    radioButton3 -> setLayoutDirection(Qt::RightToLeft);
    radioButton3 -> setText("CH3");
    QRadioButton *radioButton4 = new QRadioButton(this);
    radioButton4 -> setLayoutDirection(Qt::RightToLeft);
    radioButton4 -> setText("CH4");

    m_ButtonGroup = new QButtonGroup(this);
    m_ButtonGroup -> addButton(radioButton1, 0);
    m_ButtonGroup -> addButton(radioButton2, 1);
    m_ButtonGroup -> addButton(radioButton3, 2);
    m_ButtonGroup -> addButton(radioButton4, 3);

    pQCPLine1 = new QCPLine1(this);
    pQCPLine2 = new QCPLine2(this);

    m_CH_Layout = new QVBoxLayout();
    m_CH_Layout -> setMargin(15);
    m_CH_Layout -> addWidget(text4, 1);
    m_CH_Layout -> addWidget(radioButton1, 2, Qt::AlignCenter);
    m_CH_Layout -> addWidget(radioButton2, 2, Qt::AlignCenter);
    m_CH_Layout -> addWidget(radioButton3, 2, Qt::AlignCenter);
    m_CH_Layout -> addWidget(radioButton4, 2, Qt::AlignCenter);

    m_HBoxLayout = new QHBoxLayout(this);
    m_HBoxLayout -> addLayout(m_CH_Layout, 1);
    m_HBoxLayout -> addWidget(pQCPLine1, 8);
    m_HBoxLayout -> addWidget(pQCPLine2, 8);

    this -> setLayout(m_HBoxLayout);
}

TrendChannelWidget::~TrendChannelWidget()
{
    delete m_CH_Layout;
    delete m_ButtonGroup;
    delete pQCPLine1;
    delete pQCPLine2;
    delete m_HBoxLayout;
}

void TrendChannelWidget::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style() -> drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);
}

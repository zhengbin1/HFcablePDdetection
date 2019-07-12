#include "query_dialog.h"

CBarLine::CBarLine(QWidget *parent) : QWidget(parent)
{
    setStyleSheet("background-color:#00ff00;");

    setCursor(QCursor(Qt::OpenHandCursor));
}

CBarLine::~CBarLine()
{

}

void CBarLine::paintEvent(QPaintEvent *)
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
    qDebug() << "mouseStartPoint " << mouseStartPoint;
    qDebug() << this -> frameGeometry().topLeft();
    qDebug() << event -> globalPos() - mouseStartPoint;

    qDebug() << windowTopLeftPoint + (event -> globalPos() - mouseStartPoint);

    if(m_bar_moved == true)
    {
        // 获得鼠标移动的距离
        QPoint distance = event -> globalPos() - mouseStartPoint;

        QPoint barpos = windowTopLeftPoint + distance;
        this -> move(barpos.x(), static_cast<int>(m_PlotArea.y()));
    }
}

void CBarLine::mouseReleaseEvent(QMouseEvent *event)
{
    setCursor(QCursor(Qt::OpenHandCursor));

    if(event -> button() == Qt::LeftButton)
    {
        m_bar_moved = false;
    }

    if(m_PlotArea.x() > this -> frameGeometry().topLeft().x())
    {
        this -> move(static_cast<int>(m_PlotArea.x()), static_cast<int>(m_PlotArea.y()));
    }

    if(static_cast<int>(m_PlotArea.width() + m_PlotArea.x()) < this -> frameGeometry().bottomRight().x()){
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

    pBarGraph = new CBarGraph5();

    pHBoxLayoutMain = new QHBoxLayout(this);
    pHBoxLayoutMain -> addWidget(pBarGraph);

    setLayout(pHBoxLayoutMain);
}

CQueryDialog::~CQueryDialog()
{
    delete pBarGraph;
    delete pHBoxLayoutMain;
}

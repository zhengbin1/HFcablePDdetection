#include "multiple_source_separation.h"


MScatterPlot::MScatterPlot(QWidget *parent): QChartView(new QChart(), parent)
{
    setRenderHint(QPainter::Antialiasing);

    m_Scatter_Red = new QScatterSeries();
    m_Scatter_Red -> setColor(QColor(255, 0, 0));
    m_Scatter_Red -> setBrush(QBrush(QColor(255, 0, 0)));
    m_Scatter_Red -> setPen(QPen(QColor(255, 0, 0)));
    m_Scatter_Red -> setMarkerSize(2);
    m_Scatter_Red -> setMarkerShape(QScatterSeries::MarkerShapeCircle);

    m_Scatter_Green = new QScatterSeries();
    m_Scatter_Green -> setColor(QColor(0, 255, 0));
    m_Scatter_Green -> setBrush(QBrush(QColor(0, 255, 0)));
    m_Scatter_Green -> setPen(QPen(QColor(0, 255, 0)));
    m_Scatter_Green -> setMarkerSize(2);
    m_Scatter_Green -> setMarkerShape(QScatterSeries::MarkerShapeCircle);

    m_Scatter_Yellow = new QScatterSeries();
    m_Scatter_Yellow -> setColor(QColor(255, 255, 0));
    m_Scatter_Yellow -> setBrush(QBrush(QColor(255, 255, 0)));
    m_Scatter_Yellow -> setPen(QPen(QColor(255, 255, 0)));
    m_Scatter_Yellow -> setMarkerSize(2);
    m_Scatter_Yellow -> setMarkerShape(QScatterSeries::MarkerShapeCircle);

    m_axisX = new QValueAxis(this);
    m_axisX -> setTitleText("<span style=\"color:#ffffff;\">等效时长/us</span>");
    m_axisX -> setLabelsBrush(QBrush(QColor(255, 255, 255)));
    m_axisX -> setRange(0, 50);
    m_axisX -> setTickCount(20);
    m_axisX -> setLabelFormat("%d");

    m_axisY = new QValueAxis(this);
    m_axisY -> setTitleText("<span style=\"color:#ffffff;\">等效频宽/MHz</span>");
    m_axisY -> setLabelsBrush(QBrush(QColor(255, 255, 255)));
    m_axisY -> setRange(0, 50);
    m_axisY -> setTickCount(10);
    m_axisY -> setLabelFormat("%d");

    chart() -> legend() -> setVisible(false);
    chart() -> setBackgroundBrush(QBrush(QColor(0, 0, 0)));
    chart() -> addSeries(m_Scatter_Red);
    chart() -> addSeries(m_Scatter_Green);
    chart() -> addSeries(m_Scatter_Yellow);
    chart() -> addAxis(m_axisX, Qt::AlignBottom);
    chart() -> addAxis(m_axisY, Qt::AlignLeft);

    // startTimer(1000);
}

MScatterPlot::~MScatterPlot()
{
    delete m_Scatter_Red;
    delete m_Scatter_Green;
    delete m_Scatter_Yellow;

    delete m_axisX;
    delete m_axisY;
}

void MScatterPlot::paintEvent(QPaintEvent *e)
{
    QChartView::paintEvent(e);


    if(m_PRPD1to5_Draw[0] == true)
    {
        QPainter painter(this -> viewport());
        QPen pen;
        pen.setColor(QColor(255, 0, 0));
        QBrush brush(QColor(255, 0, 0, 100));
        painter.setPen(pen);
        painter.setBrush(brush);
        painter.drawRect(m_pos_start_X[0], m_pos_start_Y[0], m_pos_end_X[0] - m_pos_start_X[0], m_pos_end_Y[0] - m_pos_start_Y[0]);
    }
    if(m_PRPD1to5_Draw[1] == true)
    {
        QPainter painter(this -> viewport());
        QPen pen;
        pen.setColor(QColor(255, 165, 0));
        QBrush brush(QColor(255, 165, 0, 100));
        painter.setPen(pen);
        painter.setBrush(brush);
        painter.drawRect(m_pos_start_X[1], m_pos_start_Y[1], m_pos_end_X[1] - m_pos_start_X[1], m_pos_end_Y[1] - m_pos_start_Y[1]);
    }
    if(m_PRPD1to5_Draw[2] == true)
    {
        QPainter painter(this -> viewport());
        QPen pen;
        pen.setColor(QColor(255, 255, 0));
        QBrush brush(QColor(255, 255, 0, 100));
        painter.setPen(pen);
        painter.setBrush(brush);
        painter.drawRect(m_pos_start_X[2], m_pos_start_Y[2], m_pos_end_X[2] - m_pos_start_X[2], m_pos_end_Y[2] - m_pos_start_Y[2]);
    }
    if(m_PRPD1to5_Draw[3] == true)
    {
        QPainter painter(this -> viewport());
        QPen pen;
        pen.setColor(QColor(128, 0, 128));
        QBrush brush(QColor(128, 0, 128, 100));
        painter.setPen(pen);
        painter.setBrush(brush);
        painter.drawRect(m_pos_start_X[3], m_pos_start_Y[3], m_pos_end_X[3] - m_pos_start_X[3], m_pos_end_Y[3] - m_pos_start_Y[3]);
    }
    if(m_PRPD1to5_Draw[4] == true)
    {
        QPainter painter(this -> viewport());
        QPen pen;
        pen.setColor(QColor(0, 0, 255));
        QBrush brush(QColor(0, 0, 255, 100));
        painter.setPen(pen);
        painter.setBrush(brush);
        painter.drawRect(m_pos_start_X[4], m_pos_start_Y[4], m_pos_end_X[4] - m_pos_start_X[4], m_pos_end_Y[4] - m_pos_start_Y[4]);
    }

}

void MScatterPlot::mousePressEvent(QMouseEvent *e)
{
    if(m_rect_num <= 5)
    {
        switch (m_rect_num)
        {
        case 1:
            m_PRPD1to5_Draw[0] = true;
            m_pos_start_X[0] = e -> pos().x();
            m_pos_start_Y[0] = e -> pos().y();
            break;
        case 2:
            m_PRPD1to5_Draw[1] = true;
            m_pos_start_X[1] = e -> pos().x();
            m_pos_start_Y[1] = e -> pos().y();
            break;
        case 3:
            m_PRPD1to5_Draw[2] = true;
            m_pos_start_X[2] = e -> pos().x();
            m_pos_start_Y[2] = e -> pos().y();
            break;
        case 4:
            m_PRPD1to5_Draw[3] = true;
            m_pos_start_X[3] = e -> pos().x();
            m_pos_start_Y[3] = e -> pos().y();
            break;
        case 5:
            m_PRPD1to5_Draw[4] = true;
            m_pos_start_X[4] = e -> pos().x();
            m_pos_start_Y[4] = e -> pos().y();
            break;
        }

        m_clicked = true;
    } else {
        m_clicked = false;
    }
}

void MScatterPlot::mouseMoveEvent(QMouseEvent *e)
{
    if(m_clicked == true)
    {
        switch (m_rect_num)
        {
        case 1:
            m_PRPD1to5_Draw[0] = true;
            m_pos_end_X[0] = e -> pos().x();
            m_pos_end_Y[0] = e -> pos().y();
            break;
        case 2:
            m_PRPD1to5_Draw[1] = true;
            m_pos_end_X[1] = e -> pos().x();
            m_pos_end_Y[1] = e -> pos().y();
            break;
        case 3:
            m_PRPD1to5_Draw[2] = true;
            m_pos_end_X[2] = e -> pos().x();
            m_pos_end_Y[2] = e -> pos().y();
            break;
        case 4:
            m_PRPD1to5_Draw[3] = true;
            m_pos_end_X[3] = e -> pos().x();
            m_pos_end_Y[3] = e -> pos().y();
            break;
        case 5:
            m_PRPD1to5_Draw[4] = true;
            m_pos_end_X[4] = e -> pos().x();
            m_pos_end_Y[4] = e -> pos().y();
            break;
        }
    }

    update();
}

void MScatterPlot::mouseReleaseEvent(QMouseEvent *e)
{
    switch (m_rect_num)
    {
    case 1:
        m_pos_end_X[0] = e -> pos().x();
        m_pos_end_Y[0] = e -> pos().y();
        break;
    case 2:
        m_pos_end_X[1] = e -> pos().x();
        m_pos_end_Y[1] = e -> pos().y();
        break;
    case 3:
        m_pos_end_X[2] = e -> pos().x();
        m_pos_end_Y[2] = e -> pos().y();
        break;
    case 4:
        m_pos_end_X[3] = e -> pos().x();
        m_pos_end_Y[3] = e -> pos().y();
        break;
    case 5:
        m_pos_end_X[4] = e -> pos().x();
        m_pos_end_Y[4] = e -> pos().y();
        break;
    }

    m_clicked = false;

    if(m_rect_num <= 5)
    {
        m_rect_num ++;
    }

    update();
}


ColorSignWidget::ColorSignWidget(QWidget *parent) : QWidget(parent)
{
    setStyleSheet("background-color: #000000;");

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

    m_Text_PRPD0 -> setText("<span style=\"color:#ffffff;font-size:15px;text-align:center;\">PRPD-0</span>");
    m_Text_PRPD1 -> setText("<span style=\"color:#ffffff;font-size:15px;text-align:center;\">PRPD-1</span>");
    m_Text_PRPD2 -> setText("<span style=\"color:#ffffff;font-size:15px;text-align:center;\">PRPD-2</span>");
    m_Text_PRPD3 -> setText("<span style=\"color:#ffffff;font-size:15px;text-align:center;\">PRPD-3</span>");
    m_Text_PRPD4 -> setText("<span style=\"color:#ffffff;font-size:15px;text-align:center;\">PRPD-4</span>");
    m_Text_PRPD5 -> setText("<span style=\"color:#ffffff;font-size:15px;text-align:center;\">PRPD-5</span>");

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

    pCaption = new QLabel();
    pCaption -> setText("<p style=\"color:#00BFFF;font-size:20px;text-align:center;\">多 源 分 离</p>");

    pMScatterPlotMain = new MScatterPlot();
    pColorSignWidget = new ColorSignWidget();

    pHBoxLayout_1 = new QHBoxLayout();
    pHBoxLayout_1 -> addWidget(pColorSignWidget, 1);
    pHBoxLayout_1 -> addWidget(pMScatterPlotMain, 5);

    pVBoxLayoutMain = new QVBoxLayout();
    pVBoxLayoutMain -> addWidget(pCaption, 1);
    pVBoxLayoutMain -> addLayout(pHBoxLayout_1, 5);

    setLayout(pVBoxLayoutMain);
}

MSSeparationDialog::~MSSeparationDialog()
{
    delete pCaption;

    delete pMScatterPlotMain;
    delete pColorSignWidget;

    delete pHBoxLayout_1;
    delete pVBoxLayoutMain;
}

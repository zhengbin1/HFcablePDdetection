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

    m_Scatter_Red -> attachAxis(m_axisX);
    m_Scatter_Red -> attachAxis(m_axisY);
    m_Scatter_Green -> attachAxis(m_axisX);
    m_Scatter_Green -> attachAxis(m_axisY);
    m_Scatter_Yellow -> attachAxis(m_axisX);
    m_Scatter_Yellow -> attachAxis(m_axisY);


    startTimer(1000);
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
        painter.drawRect(pointXY[0].pos_start_X, pointXY[0].pos_start_Y, pointXY[0].pos_end_X - pointXY[0].pos_start_X, pointXY[0].pos_end_Y - pointXY[0].pos_start_Y);
    }
    if(m_PRPD1to5_Draw[1] == true)
    {
        QPainter painter(this -> viewport());
        QPen pen;
        pen.setColor(QColor(255, 165, 0));
        QBrush brush(QColor(255, 165, 0, 100));
        painter.setPen(pen);
        painter.setBrush(brush);
        painter.drawRect(pointXY[1].pos_start_X, pointXY[1].pos_start_Y, pointXY[1].pos_end_X - pointXY[1].pos_start_X, pointXY[1].pos_end_Y - pointXY[1].pos_start_Y);
    }
    if(m_PRPD1to5_Draw[2] == true)
    {
        QPainter painter(this -> viewport());
        QPen pen;
        pen.setColor(QColor(255, 255, 0));
        QBrush brush(QColor(255, 255, 0, 100));
        painter.setPen(pen);
        painter.setBrush(brush);
        painter.drawRect(pointXY[2].pos_start_X, pointXY[2].pos_start_Y, pointXY[2].pos_end_X - pointXY[2].pos_start_X, pointXY[2].pos_end_Y - pointXY[2].pos_start_Y);
    }
    if(m_PRPD1to5_Draw[3] == true)
    {
        QPainter painter(this -> viewport());
        QPen pen;
        pen.setColor(QColor(128, 0, 128));
        QBrush brush(QColor(128, 0, 128, 100));
        painter.setPen(pen);
        painter.setBrush(brush);
        painter.drawRect(pointXY[3].pos_start_X, pointXY[3].pos_start_Y, pointXY[3].pos_end_X - pointXY[3].pos_start_X, pointXY[3].pos_end_Y - pointXY[3].pos_start_Y);
    }
    if(m_PRPD1to5_Draw[4] == true)
    {
        QPainter painter(this -> viewport());
        QPen pen;
        pen.setColor(QColor(0, 0, 255));
        QBrush brush(QColor(0, 0, 255, 100));
        painter.setPen(pen);
        painter.setBrush(brush);
        painter.drawRect(pointXY[4].pos_start_X, pointXY[4].pos_start_Y, pointXY[4].pos_end_X - pointXY[4].pos_start_X, pointXY[4].pos_end_Y - pointXY[4].pos_start_Y);
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
            pointXY[0].pos_start_X = e -> pos().x();
            pointXY[0].pos_start_Y = e -> pos().y();
            break;
        case 2:
            m_PRPD1to5_Draw[1] = true;
            pointXY[1].pos_start_X = e -> pos().x();
            pointXY[1].pos_start_Y = e -> pos().y();
            break;
        case 3:
            m_PRPD1to5_Draw[2] = true;
            pointXY[2].pos_start_X = e -> pos().x();
            pointXY[2].pos_start_Y = e -> pos().y();
            break;
        case 4:
            m_PRPD1to5_Draw[3] = true;
            pointXY[3].pos_start_X = e -> pos().x();
            pointXY[3].pos_start_Y = e -> pos().y();
            break;
        case 5:
            m_PRPD1to5_Draw[4] = true;
            pointXY[4].pos_start_X = e -> pos().x();
            pointXY[4].pos_start_Y = e -> pos().y();
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
            pointXY[0].pos_end_X = e -> pos().x();
            pointXY[0].pos_end_Y = e -> pos().y();
            break;
        case 2:
            m_PRPD1to5_Draw[1] = true;
            pointXY[1].pos_end_X = e -> pos().x();
            pointXY[1].pos_end_Y = e -> pos().y();
            break;
        case 3:
            m_PRPD1to5_Draw[2] = true;
            pointXY[2].pos_end_X = e -> pos().x();
            pointXY[2].pos_end_Y = e -> pos().y();
            break;
        case 4:
            m_PRPD1to5_Draw[3] = true;
            pointXY[3].pos_end_X = e -> pos().x();
            pointXY[3].pos_end_Y = e -> pos().y();
            break;
        case 5:
            m_PRPD1to5_Draw[4] = true;
            pointXY[4].pos_end_X = e -> pos().x();
            pointXY[4].pos_end_Y = e -> pos().y();
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
        pointXY[0].pos_end_X = e -> pos().x();
        pointXY[0].pos_end_Y = e -> pos().y();
        pointXY[0].series_start_X = chart() -> mapToValue(QPointF(pointXY[0].pos_start_X, pointXY[0].pos_start_Y)).x();
        pointXY[0].series_start_Y = chart() -> mapToValue(QPointF(pointXY[0].pos_start_X, pointXY[0].pos_start_Y)).y();
        pointXY[0].series_end_X = chart() -> mapToValue(QPointF(pointXY[0].pos_end_X, pointXY[0].pos_end_Y)).x();
        pointXY[0].series_end_Y = chart() -> mapToValue(QPointF(pointXY[0].pos_end_X, pointXY[0].pos_end_Y)).y();
        break;
    case 2:
        pointXY[1].pos_end_X = e -> pos().x();
        pointXY[1].pos_end_Y = e -> pos().y();
        pointXY[1].series_start_X = chart() -> mapToValue(QPointF(pointXY[1].pos_start_X, 0)).x();
        pointXY[1].series_start_Y = chart() -> mapToValue(QPointF(0, pointXY[1].pos_start_Y)).y();
        pointXY[1].series_end_X = chart() -> mapToValue(QPointF(pointXY[1].pos_end_X, 0)).x();
        pointXY[1].series_end_Y = chart() -> mapToValue(QPointF(0, pointXY[1].pos_end_Y)).y();
        break;
    case 3:
        pointXY[2].pos_end_X = e -> pos().x();
        pointXY[2].pos_end_Y = e -> pos().y();
        pointXY[2].series_start_X = chart() -> mapToValue(QPointF(pointXY[2].pos_start_X, pointXY[2].pos_start_Y)).x();
        pointXY[2].series_start_Y = chart() -> mapToValue(QPointF(pointXY[2].pos_start_X, pointXY[2].pos_start_Y)).y();
        pointXY[2].series_end_X = chart() -> mapToValue(QPointF(pointXY[2].pos_end_X, pointXY[2].pos_end_Y)).x();
        pointXY[2].series_end_Y = chart() -> mapToValue(QPointF(pointXY[2].pos_end_X, pointXY[2].pos_end_Y)).y();
        break;
    case 4:
        pointXY[3].pos_end_X = e -> pos().x();
        pointXY[3].pos_end_Y = e -> pos().y();
        pointXY[3].series_start_X = chart() -> mapToValue(QPointF(pointXY[3].pos_start_X, pointXY[3].pos_start_Y)).x();
        pointXY[3].series_start_Y = chart() -> mapToValue(QPointF(pointXY[3].pos_start_X, pointXY[3].pos_start_Y)).y();
        pointXY[3].series_end_X = chart() -> mapToValue(QPointF(pointXY[3].pos_end_X, pointXY[3].pos_end_Y)).x();
        pointXY[3].series_end_Y = chart() -> mapToValue(QPointF(pointXY[3].pos_end_X, pointXY[3].pos_end_Y)).y();
        break;
    case 5:
        pointXY[4].pos_end_X = e -> pos().x();
        pointXY[4].pos_end_Y = e -> pos().y();
        pointXY[4].series_start_X = chart() -> mapToValue(QPointF(pointXY[4].pos_start_X, pointXY[4].pos_start_Y)).x();
        pointXY[4].series_start_Y = chart() -> mapToValue(QPointF(pointXY[4].pos_start_X, pointXY[4].pos_start_Y)).y();
        pointXY[4].series_end_X = chart() -> mapToValue(QPointF(pointXY[4].pos_end_X, pointXY[4].pos_end_Y)).x();
        pointXY[4].series_end_Y = chart() -> mapToValue(QPointF(pointXY[4].pos_end_X, pointXY[4].pos_end_Y)).y();
        break;
    }

    m_clicked = false;

    if(m_rect_num <= 5)
    {
        m_rect_num ++;
    }

    qDebug() << pointXY[1].pos_start_X;
    qDebug() << pointXY[1].pos_start_Y;
    qDebug() << pointXY[1].pos_end_X;
    qDebug() << pointXY[1].pos_end_Y;
    qDebug() << pointXY[1].series_start_X;
    qDebug() << pointXY[1].series_start_Y;
    qDebug() << pointXY[1].series_end_X;
    qDebug() << pointXY[1].series_end_Y;


    update();
}


void MScatterPlot::timerEvent(QTimerEvent *)
{
    m_Scatter_Red -> clear();
    m_Scatter_Green -> clear();
    m_Scatter_Yellow -> clear();

    qsrand(static_cast<unsigned int>(QTime(0,0,0).secsTo(QTime::currentTime())));

    for (int i = 0;i < 1000; i++) {
        int x = qrand() % 50;
        int y = qrand() % 50;

        if(x < 20){
            *m_Scatter_Yellow << QPointF(x, y);
        } else if ((x > 20) && (x < 40)) {
            *m_Scatter_Green << QPointF(x, y);
        } else if (x > 40) {
            *m_Scatter_Red << QPointF(x, y);
        }
    }
}

void MScatterPlot::setPRPD1to5Draw(bool ifDraw)
{
    for (int i = 0; i < 5; i ++)
    {
        m_PRPD1to5_Draw[i] = ifDraw;
    }

    m_rect_num = 1;
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

ClusterChoice::ClusterChoice(QWidget *parent) : QWidget(parent)
{
    setStyleSheet("background-color: #000000;");

    pCaption = new QPushButton;
    pCaption -> setStyleSheet("color: #FFFFFF;");
    pCaption -> setText("聚类选择");

    m_Combo_Channel = new QComboBox;
    m_Combo_Channel -> setStyleSheet("background-color:#FFFFFF;");
    m_Combo_Channel -> insertItem(0, "通道1");
    m_Combo_Channel -> insertItem(1, "通道2");
    m_Combo_Channel -> insertItem(2, "通道3");
    m_Combo_Channel -> insertItem(3, "通道4");

    m_Start_Button = new QPushButton;
    m_refresh_Button = new QPushButton;
    m_MSSeparation_Button = new QPushButton;
    m_Save_Button = new QPushButton;
    m_Cancel_Button = new QPushButton;

    m_Start_Button -> setText("开 始");
    m_Start_Button -> setStyleSheet("background-color: #CCCCCC;");
    m_refresh_Button -> setText("刷 新");
    m_refresh_Button -> setStyleSheet("background-color: #CCCCCC;");
    m_MSSeparation_Button -> setText("多源分离");
    m_MSSeparation_Button -> setStyleSheet("background-color: #CCCCCC;");
    m_Save_Button -> setText("保 存");
    m_Save_Button -> setStyleSheet("background-color: #CCCCCC;");
    m_Cancel_Button -> setText("取 消");
    m_Cancel_Button -> setStyleSheet("background-color: #CCCCCC;");

    pVBoxLayout = new QVBoxLayout;
    pVBoxLayout -> addWidget(pCaption, 1);
    pVBoxLayout -> addWidget(m_Combo_Channel, 1);
    pVBoxLayout -> addWidget(m_Start_Button, 1);
    pVBoxLayout -> addWidget(m_refresh_Button, 1);
    pVBoxLayout -> addWidget(m_MSSeparation_Button, 1);
    pVBoxLayout -> addWidget(m_Save_Button, 1);
    pVBoxLayout -> addWidget(m_Cancel_Button, 1);

    setLayout(pVBoxLayout);

    connect(m_refresh_Button, SIGNAL(pressed()), this, SIGNAL(refresh()));
}

ClusterChoice::~ClusterChoice()
{
    delete pCaption;
    delete m_Combo_Channel;
    delete m_Start_Button;
    delete m_refresh_Button;
    delete m_MSSeparation_Button;
    delete m_Save_Button;
    delete m_Cancel_Button;
}

void ClusterChoice::paintEvent(QPaintEvent *e)
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
    pCaption -> setText("<p style=\"color:#00BFFF;font-size:25px;text-align:center;\">多 源 分 离</p>");

    pMScatterPlotMain = new MScatterPlot();
    pColorSignWidget = new ColorSignWidget();
    pClusterChoice = new ClusterChoice();

    pHBoxLayout_1 = new QHBoxLayout();
    pHBoxLayout_1 -> addWidget(pColorSignWidget, 1);
    pHBoxLayout_1 -> addWidget(pMScatterPlotMain, 7);
    pHBoxLayout_1 -> addWidget(pClusterChoice, 1);

    pVBoxLayoutMain = new QVBoxLayout();
    pVBoxLayoutMain -> addWidget(pCaption, 1);
    pVBoxLayoutMain -> addLayout(pHBoxLayout_1, 5);

    setLayout(pVBoxLayoutMain);

    connect(pClusterChoice, SIGNAL(refresh()), this, SLOT(refreshClick()));
}

MSSeparationDialog::~MSSeparationDialog()
{
    delete pCaption;

    delete pMScatterPlotMain;
    delete pColorSignWidget;
    delete pClusterChoice;

    delete pHBoxLayout_1;
    delete pVBoxLayoutMain;
}

void MSSeparationDialog::refreshClick()
{
    pMScatterPlotMain -> setPRPD1to5Draw(false);
}

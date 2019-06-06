#include "scatter_plot.h"

ScatterPlot::ScatterPlot(QWidget *parent): QChartView(new QChart(), parent)
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

    chart() -> legend() -> setVisible(false);
    chart() -> setBackgroundBrush(QBrush(QColor(0, 0, 0)));
    chart() -> addSeries(m_Scatter_Red);
    chart() -> addSeries(m_Scatter_Green);
    chart() -> addSeries(m_Scatter_Yellow);
    chart() -> createDefaultAxes();
    chart() -> axes(Qt::Horizontal).first() -> setLabelsBrush(QBrush(QColor(255, 255, 255)));
    chart() -> axes(Qt::Vertical).first() -> setLabelsBrush(QBrush(QColor(255, 255, 255)));
    chart() -> axes(Qt::Horizontal).first() -> setLinePen(QPen(QColor(255, 255, 255)));
    chart() -> axes(Qt::Vertical).first() -> setLinePen(QPen(QColor(255, 255, 255)));
    chart() -> axes(Qt::Horizontal).first() -> setRange(0, 360);
    chart() -> axes(Qt::Vertical).first() -> setRange(-1, 1);

    startTimer(1000);
}

ScatterPlot::~ScatterPlot()
{
    delete m_Scatter_Red;
    delete m_Scatter_Green;
    delete m_Scatter_Yellow;
}


void ScatterPlot::timerEvent(QTimerEvent *)
{
    m_Scatter_Red -> clear();
    m_Scatter_Green -> clear();
    m_Scatter_Yellow -> clear();

    qsrand(static_cast<unsigned int>(QTime(0,0,0).secsTo(QTime::currentTime())));
    for(int i = 0;i < 1000; i ++)
    {
        int x = qrand() % 360;
        qreal y = 0;

        int tmp = qrand() % 10;
        if(tmp != 0){
            if(i % 2 == 0)
            {
                y = static_cast<qreal>(tmp) / 10;
                y = -y;
            } else {
                y = static_cast<qreal>(tmp) / 10;
            }
        }

        if(x < 50){
            *m_Scatter_Yellow << QPointF(x, y);
        } else if ((x > 50) && (x < 100)) {
            *m_Scatter_Green << QPointF(x, y);
        } else if (x > 100) {
            *m_Scatter_Red << QPointF(x, y);
        }
    }
}

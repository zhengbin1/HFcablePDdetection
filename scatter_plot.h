#ifndef SCATTER_PLOT_H
#define SCATTER_PLOT_H

#include <QtCharts/QChartGlobal>
#include <QtCharts/QChartView>
#include <QtCharts/QScatterSeries>
#include <QTime>

QT_CHARTS_USE_NAMESPACE

class ScatterPlot : public QChartView
{
public:
    ScatterPlot(QWidget *parent = nullptr);
    ~ScatterPlot();
    void timerEvent(QTimerEvent *);

private:
    QScatterSeries *m_Scatter_Red;
    QScatterSeries *m_Scatter_Green;
    QScatterSeries *m_Scatter_Yellow;
};

#endif // SCATTER_PLOT_H

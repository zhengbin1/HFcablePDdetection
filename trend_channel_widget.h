#ifndef TREND_CHANNEL_WIDGET_H
#define TREND_CHANNEL_WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QStyleOption>
#include <QButtonGroup>
#include <QRadioButton>
#include <QLabel>
#include <QGridLayout>
#include <QTimer>

#include "library/qcustomplot/qcustomplot.h"

class QCPLine1 : public QWidget
{
    Q_OBJECT

public:
    explicit QCPLine1(QWidget *parent = nullptr);
    ~QCPLine1();
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);

private:
    QCustomPlot *m_Plot;
    QPointer<QCPGraph> m_Graph1;
    QPointer<QCPGraph> m_Graph2;

    int m_startTime = 0;

private slots:
    void QCPMoveEvent(QMouseEvent *);
};


// 趋势通道
class TrendChannelWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TrendChannelWidget(QWidget *parent = nullptr);
    ~TrendChannelWidget();
    void paintEvent(QPaintEvent *);

private:
    QGridLayout *m_CH_Layout;
    QButtonGroup *buttonGroup;
    QCPLine1 *pQCPLine1;

signals:

public slots:
};

#endif // TREND_CHANNEL_WIDGET_H

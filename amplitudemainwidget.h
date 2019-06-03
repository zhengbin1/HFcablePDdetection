#ifndef AMPLITUDEMAINWIDGET_H
#define AMPLITUDEMAINWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QStyleOption>
#include "./library/axis-tags/axistag.h"

class AmplitudeMainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AmplitudeMainWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void setSize(int width, int height);

private:
    QCustomPlot *mPlot;
    QPointer<QCPGraph> mGraph1;
    AxisTag *mTag1;
    QTimer mDataTimer;

signals:

public slots:
    void timerSlot();
};

#endif // AMPLITUDEMAINWIDGET_H

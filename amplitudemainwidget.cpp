#include "amplitudemainwidget.h"

AmplitudeMainWidget::AmplitudeMainWidget(QWidget *parent) : QWidget(parent)
{
    mPlot = new QCustomPlot(this);

    // configure plot to have two right axes:
    mPlot->yAxis->setTickLabels(false);
    mPlot->axisRect()->addAxis(QCPAxis::atRight);
    mPlot->axisRect()->axis(QCPAxis::atRight, 0)->setPadding(30); // add some padding to have space for tags

    // create graphs:
    mGraph1 = mPlot->addGraph(mPlot->xAxis, mPlot->axisRect()->axis(QCPAxis::atRight, 0));
    mGraph1->setPen(QPen(QColor(250, 120, 0)));


    // create tags with newly introduced AxisTag class (see axistag.h/.cpp):
    mTag1 = new AxisTag(mGraph1->valueAxis());
    mTag1 -> setPen(mGraph1->pen());

    connect(&mDataTimer, SIGNAL(timeout()), this, SLOT(timerSlot()));
    mDataTimer.start(40);
}

void AmplitudeMainWidget::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style() -> drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);
}

void AmplitudeMainWidget::timerSlot()
{
  // calculate and add a new data point to each graph:
  mGraph1->addData(mGraph1->dataCount(), qSin(mGraph1->dataCount()/50.0)+qSin(mGraph1->dataCount()/50.0/0.3843)*0.25);

  // make key axis range scroll with the data:
  mPlot->xAxis->rescale();
  mGraph1->rescaleValueAxis(false, true);
  mPlot->xAxis->setRange(mPlot->xAxis->range().upper, 100, Qt::AlignRight);

  // update the vertical axis tag positions and texts to match the rightmost data point of the graphs:
  double graph1Value = mGraph1->dataMainValue(mGraph1->dataCount()-1);
  mTag1->updatePosition(graph1Value);
  mTag1->setText(QString::number(graph1Value, 'f', 2));

  mPlot->replot();
}

void AmplitudeMainWidget::setSize(int width, int height)
{
    this -> resize(width, height);
    mPlot -> resize(width, height);
}

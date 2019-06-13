#ifndef TREND_CHANNEL_WIDGET_H
#define TREND_CHANNEL_WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QStyleOption>
#include <QButtonGroup>
#include <QRadioButton>
#include <QLabel>
#include <QGridLayout>

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

signals:

public slots:
};

#endif // TREND_CHANNEL_WIDGET_H

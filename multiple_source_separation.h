#ifndef MULTIPLE_SOURCE_SEPARATION_H
#define MULTIPLE_SOURCE_SEPARATION_H

#include <QDialog>
#include <QPainter>
#include <QStyleOption>
#include <QGuiApplication>
#include <QScreen>
#include <QBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QtCharts>
#include <QTime>

QT_CHARTS_USE_NAMESPACE

class MScatterPlot : public QChartView
{
public:
    MScatterPlot(QWidget *parent = nullptr);
    ~MScatterPlot();
    // void timerEvent(QTimerEvent *);
    void paintEvent(QPaintEvent *);

    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

private:

    int m_rect_num = 1;  // 第几个矩形

    int m_pos_start_X[5] = {0};  // 鼠标开始的X位置
    int m_pos_start_Y[5] = {0};  // 鼠标开始的Y位置

    int m_pos_end_X[5] = {0};  // 鼠标结束的X位置
    int m_pos_end_Y[5] = {0};  // 鼠标结束的Y位置

    bool m_clicked = false;  // 判断鼠标是否在移动
    bool m_PRPD1to5_Draw[5] = {false};  // 判断是否绘制矩形圈选框

    QValueAxis *m_axisX;
    QValueAxis *m_axisY;

    QScatterSeries *m_Scatter_Red;
    QScatterSeries *m_Scatter_Green;
    QScatterSeries *m_Scatter_Yellow;
};

class ColorSignWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ColorSignWidget(QWidget *parent = nullptr);
    ~ColorSignWidget();

    void paintEvent(QPaintEvent *);

private:
    QLabel *m_Color_Label0;
    QLabel *m_Color_Label1;
    QLabel *m_Color_Label2;
    QLabel *m_Color_Label3;
    QLabel *m_Color_Label4;
    QLabel *m_Color_Label5;

    QLabel *m_Text_PRPD0;
    QLabel *m_Text_PRPD1;
    QLabel *m_Text_PRPD2;
    QLabel *m_Text_PRPD3;
    QLabel *m_Text_PRPD4;
    QLabel *m_Text_PRPD5;
};

class MSSeparationDialog : public QDialog
{
    Q_OBJECT

public:
    MSSeparationDialog(QWidget *parent = nullptr);
    ~MSSeparationDialog();

private:
    int m_screen_width;
    int m_screen_height;

    QLabel *pCaption;

    MScatterPlot *pMScatterPlotMain;
    ColorSignWidget *pColorSignWidget;

    QVBoxLayout *pVBoxLayoutMain;
    QHBoxLayout *pHBoxLayout_1;
};

#endif // MULTIPLE_SOURCE_SEPARATION_H

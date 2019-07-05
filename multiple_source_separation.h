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

typedef struct
{
    int pos_start_X = 0;  // 鼠标开始的X位置
    int pos_start_Y = 0;  // 鼠标开始的Y位置

    int pos_end_X = 0;  // 鼠标结束的X位置
    int pos_end_Y = 0;  // 鼠标结束的Y位置

    qreal series_start_X = 0;  // 鼠标开始的X位置
    qreal series_start_Y = 0;  // 鼠标开始的Y位置

    qreal series_end_X = 0;  // 鼠标结束的X位置
    qreal series_end_Y = 0;  // 鼠标结束的Y位置

} MPointXY;

class MScatterPlot : public QChartView
{
public:
    MScatterPlot(QWidget *parent = nullptr);
    ~MScatterPlot();
    void timerEvent(QTimerEvent *);
    void paintEvent(QPaintEvent *);

    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

    void setPRPD1to5Draw(bool);  // 设置是否绘制矩形圈选框

private:

    int m_rect_num = 1;  // 第几个矩形

//    int m_pos_start_X[5] = {0};  // 鼠标开始的X位置
//    int m_pos_start_Y[5] = {0};  // 鼠标开始的Y位置

//    int m_pos_end_X[5] = {0};  // 鼠标结束的X位置
//    int m_pos_end_Y[5] = {0};  // 鼠标结束的Y位置

    MPointXY pointXY[5];

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

class ClusterChoice : public QWidget
{
    Q_OBJECT

public:
    explicit ClusterChoice(QWidget *parent = nullptr);
    ~ClusterChoice();

    void paintEvent(QPaintEvent *);

private:
    QPushButton *pCaption;
    QComboBox *m_Combo_Channel;
    QPushButton *m_Start_Button;
    QPushButton *m_refresh_Button;
    QPushButton *m_MSSeparation_Button;
    QPushButton *m_Save_Button;
    QPushButton *m_Cancel_Button;

    QVBoxLayout *pVBoxLayout;

signals:
    void refresh();
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
    ClusterChoice *pClusterChoice;

    QVBoxLayout *pVBoxLayoutMain;
    QHBoxLayout *pHBoxLayout_1;

private slots:
    void refreshClick();
};

#endif // MULTIPLE_SOURCE_SEPARATION_H

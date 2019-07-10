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

class ScatterPlotPRPD1to5 : public QChartView
{
public:
    ScatterPlotPRPD1to5(QWidget *parent = nullptr);
    ~ScatterPlotPRPD1to5();
    // void timerEvent(QTimerEvent *);
    // void paintEvent(QPaintEvent *);
    void setTextColor(QString textColor)
    {
        m_textColor = textColor;
        m_axisX -> setTitleText("<span style=\"color:" + textColor + ";\">相位</span>");
        m_axisY -> setTitleText("<span style=\"color:" + textColor + ";\">幅值V</span>");
    }
    void setTitleName(QString titleName)
    {
        chart() -> setTitle("<span style=\"color:" + m_textColor + ";\">" + titleName + "</span>");
    }

private:
    QValueAxis *m_axisX;
    QValueAxis *m_axisY;

    QScatterSeries *m_Scatter_Red;
    QScatterSeries *m_Scatter_Green;
    QScatterSeries *m_Scatter_Yellow;

    QString m_textColor;
};

class PRPD1to5Widget : public QWidget
{
    Q_OBJECT

public:
    explicit PRPD1to5Widget(QWidget *parent = nullptr);
    ~PRPD1to5Widget();

    void paintEvent(QPaintEvent *);

private:
    QWidget *m_parent;

    ScatterPlotPRPD1to5 *pScatterPlotPRPD1;
    ScatterPlotPRPD1to5 *pScatterPlotPRPD2;
    ScatterPlotPRPD1to5 *pScatterPlotPRPD3;
    ScatterPlotPRPD1to5 *pScatterPlotPRPD4;
    ScatterPlotPRPD1to5 *pScatterPlotPRPD5;

    QHBoxLayout *pHBoxLayout;
};

class ScatterPlotPRPD0 : public QChartView
{
public:
    ScatterPlotPRPD0(QWidget *parent = nullptr);
    ~ScatterPlotPRPD0();
    // void timerEvent(QTimerEvent *);
    void paintEvent(QPaintEvent *);

private:
    QValueAxis *m_axisX;
    QValueAxis *m_axisY;

    QScatterSeries *m_Scatter_Red;
    QScatterSeries *m_Scatter_Green;
    QScatterSeries *m_Scatter_Yellow;
};

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
    void setStartOrEnd(bool state)  // 设置是开始运行还是结束
    {
        m_start_or_end = state;
    }

private:

    int m_rect_num = 1;  // 第几个矩形

    bool m_start_or_end = false;

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
    bool startButtonState = false;

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
    void startState(bool);
};

class MSSeparationDialog : public QDialog
{
    Q_OBJECT

public:
    MSSeparationDialog(QWidget *parent = nullptr);
    ~MSSeparationDialog();

    void changeEvent(QEvent * event);

private:
    int m_screen_width;
    int m_screen_height;

    MScatterPlot *pMScatterPlotMain;
    ColorSignWidget *pColorSignWidget;
    ClusterChoice *pClusterChoice;
    ScatterPlotPRPD0 *pScatterPlotPRPD0;
    PRPD1to5Widget *pPRPD1to5Widget;

    QScrollArea *m_ScrollArea;

    QVBoxLayout *pVBoxLayoutMain;
    QHBoxLayout *pHBoxLayout_1;
    QHBoxLayout *pHBoxLayout_2;

private slots:
    void refreshClick();
};

#endif // MULTIPLE_SOURCE_SEPARATION_H

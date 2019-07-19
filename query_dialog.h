#ifndef QUERY_DIALOG_H
#define QUERY_DIALOG_H

#include <QDialog>
#include <QBoxLayout>
#include <QPainter>
#include <QStyleOption>
#include <QGuiApplication>
#include <QScreen>
#include <QtCharts>
#include <QTabWidget>


class CBarGraph1 : public QChartView
{
public:
    CBarGraph1(QWidget *parent = nullptr);
    ~CBarGraph1();

private:
    QValueAxis *m_AxisX;
    QValueAxis *m_AxisY;
};

class CBarGraph2 : public QChartView
{
public:
    CBarGraph2(QWidget *parent = nullptr);
    ~CBarGraph2();

private:
    QValueAxis *m_AxisX;
    QValueAxis *m_AxisY;
};

class CBarLine : public QWidget
{
public:
    CBarLine(QWidget *parent = nullptr);
    ~CBarLine();

    void setPlotArea(QRectF plotArea)
    {
        m_PlotArea = plotArea;
    }

    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

private:
    QRectF m_PlotArea;
    bool m_bar_moved = false;
    QPoint mouseStartPoint;
    QPoint windowTopLeftPoint;
    int m_posX = 0;
    int m_posY = 0;
};


class CBarGraph5 : public QChartView
{
public:
    CBarGraph5(QWidget *parent = nullptr);
    ~CBarGraph5();
    // void timerEvent(QTimerEvent *);
    // void paintEvent(QPaintEvent *);
    void showEvent(QShowEvent *);
    void resizeEvent(QResizeEvent *);

private:
    QDateTimeAxis *m_AxisX_Time;
    QValueAxis *m_AxisY_Data;
    CBarLine *pBarLine;
};


class CQueryDialog : public QDialog
{
    Q_OBJECT

public:
    CQueryDialog(QWidget *parent = nullptr);
    ~CQueryDialog();

private:
    QLabel *pTextTitle;

    QHBoxLayout *pHBoxLayoutMain;
    QVBoxLayout *pVBoxLayout1;

    int m_screen_width;
    int m_screen_height;

    CBarGraph1 *pBarGraph1;
    CBarGraph1 *pBarGraph2;
    CBarGraph2 *pBarGraph3;
    CBarGraph2 *pBarGraph4;

    CBarGraph5 *pBarGraph5;

    QTabWidget *pTabWidget;
    QLabel *pLabelText1;
    QLineEdit *pLineEdit1;
    QPushButton *pSearchButton1;
    QLabel *pLabelText2;
    QDateEdit *pDateEdit1;
    QCalendarWidget *pCalendar1;
    QLabel *pLabelText3;
    QDateEdit *pDateEdit2;
    QCalendarWidget *pCalendar2;
    QPushButton *pSearchButton2;
    QWidget *pTabW1;
    QWidget *pTabW2;
    QVBoxLayout *pTabW1_Layout;
    QFormLayout *pTabW1_Layout1;
    QVBoxLayout *pTabW2_Layout;
    QHBoxLayout *pTabW2_HLayout1;
    QHBoxLayout *pTabW2_HLayout2;
    QHBoxLayout *pTabW2_HLayout3;
    QGridLayout *pGridLayout;
};

#endif // QUERY_DIALOG_H

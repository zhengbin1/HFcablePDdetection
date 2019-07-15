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

class CBarLine : public QWidget
{
public:
    CBarLine(QWidget *parent = nullptr);
    ~CBarLine();
    void paintEvent(QPaintEvent *);
    // void timerEvent(QTimerEvent *);

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

    CBarGraph5 *pBarGraph;

    QTabWidget *pTabWidget;
    QLabel *pLabelText1;
    QLineEdit *pLineEdit1;
    QWidget *pTabW1;
    QWidget *pTabW2;
    QVBoxLayout *pTabW1_Layout;
    QFormLayout *pTabW1_Layout1;
    QVBoxLayout *pTabW2_Layout;
};

#endif // QUERY_DIALOG_H

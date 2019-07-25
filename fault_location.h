#ifndef CFAULTLOCATION_H
#define CFAULTLOCATION_H

#include <QDialog>
#include <QLabel>
#include <QBoxLayout>
#include <QPainter>
#include <QStyleOption>
#include <QGuiApplication>
#include <QScreen>
#include <QtCharts>

class CCourseLine : public QWidget
{
public:
    CCourseLine(QWidget *parent = nullptr);
    ~CCourseLine();
    void paintEvent(QPaintEvent *);

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

class CLineGraph1 : public QChartView
{
public:
    CLineGraph1(QWidget *parent = nullptr);
    ~CLineGraph1();

    void setRangeX(float);

    void paintEvent(QPaintEvent *);
    void showEvent(QShowEvent *);
    void resizeEvent(QResizeEvent *);

private:
    QValueAxis *m_AxisX;
    QValueAxis *m_AxisY;
    CCourseLine *pCourseLine1;
    QLabel *m_lineText1;
    CCourseLine *pCourseLine2;
    QLabel *m_lineText2;
};


class CFaultLocation : public QDialog
{
public:
    CFaultLocation(QWidget *parent = nullptr);
    ~CFaultLocation();

private:
    QLabel *pTextTitle;
    CLineGraph1 *pLineGraph1;
    QLabel *pText1;
    QLabel *pText2;
    QLabel *pText3;

    QLineEdit *pLineEdit1;
    QLineEdit *pLineEdit2;

    QButtonGroup *m_ButtonGroup;

    QPushButton *pButton1;
    QPushButton *pButton2;
    QPushButton *pButton3;

    QGridLayout *pGridLayout;
    QVBoxLayout *pVBoxLayoutMain;
    QHBoxLayout *pHBoxLayout1;
    QVBoxLayout *pVBoxLayout1;

    int m_screen_width;
    int m_screen_height;
};

#endif // CFAULTLOCATION_H

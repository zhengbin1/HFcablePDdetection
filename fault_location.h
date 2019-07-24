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


class CLineGraph1 : public QChartView
{
public:
    CLineGraph1(QWidget *parent = nullptr);
    ~CLineGraph1();

private:
    QValueAxis *m_AxisX;
    QValueAxis *m_AxisY;
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

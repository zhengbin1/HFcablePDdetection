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

    ColorSignWidget *pColorSignWidget;
    QVBoxLayout *pVBoxLayoutMain;
    QHBoxLayout *pHBoxLayout_1;
};

#endif // MULTIPLE_SOURCE_SEPARATION_H

#ifndef MAINWINDOW_QMENU4_H
#define MAINWINDOW_QMENU4_H

#include <QMenu>
#include <QMouseEvent>

class QMenu4 : public QMenu
{
public:
    QMenu4(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *);
};

#endif // MAINWINDOW_QMENU4_H

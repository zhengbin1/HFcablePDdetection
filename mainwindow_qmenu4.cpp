#include "mainwindow_qmenu4.h"
#include <QDebug>

QMenu4::QMenu4(QWidget *parent) : QMenu(parent)
{

}

void QMenu4::mousePressEvent(QMouseEvent *)
{
    emit clicked();
}

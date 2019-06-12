#include "type_diagnosis_double_slider.h"
#include <QDebug>

TypeDiagnosisDoubleSlider::TypeDiagnosisDoubleSlider(QWidget *parent) : QSlider(parent)
{
    setOrientation(Qt::Horizontal);
    setMinimum(-100);
    setMaximum(100);
    setSingleStep(1);

    setStyleSheet("QSlider::groove:horizontal {height: 5px;background: #C0C0C0;border: 1px solid #4A708B;border-radius: 1px; padding-left:-1px; padding-right:-1px;}"
                  "QSlider::sub-page:horizontal {height: 10px; background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #B1B1B1, stop:1 #c4c4c4); background: qlineargradient(x1:0, y1:0.2, x2:1, y2:1, stop:0 #5DCCFF, stop:1 #1874CD); border: 1px solid #4A708B; border-radius: 2px;}"
                  "QSlider::add-page:horizontal {height: 10px; background: #575757; border: 0px solid #777; border-radius: 2px;}"
                  "QSlider::handle:horizontal { width: 11px; background: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.6 #45ADED, stop:0.778409 rgba(255, 255, 255, 255)); margin-top: -3px; margin-bottom: -3px; border-radius: 5px;}"
                  "QSlider::handle:horizontal:hover {width: 11px; background: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.6 #2A8BDA, stop:0.778409 rgba(255, 255, 255, 255));margin-top: -3px;margin-bottom: -3px;border-radius: 5px;}"
                  "QSlider::sub-page:horizontal:disabled {background: #00009C; border-color: #999;}"
                  "QSlider::add-page:horizontal:disabled {background: #eee; border-color: #999;}"
                  "QSlider::handle:horizontal:disabled { background: #eee; border: 1px solid #aaa; border-radius: 4px;}");
}

void TypeDiagnosisDoubleSlider::setDoubleValue(double givenValue)
{
    givenValue = givenValue * 100;

    setValue(static_cast<int>(givenValue));
}


void TypeDiagnosisDoubleSlider::mousePressEvent(QMouseEvent *e)
{
    QSlider::mousePressEvent(e);

    double pos = static_cast<double>(value()) / 100.0;

    emit valueDoubleChanged(pos);
}

void TypeDiagnosisDoubleSlider::mouseMoveEvent(QMouseEvent *e)
{
    QSlider::mouseMoveEvent(e);

    double pos = static_cast<double>(value()) / 100.0;

    emit valueDoubleChanged(pos);
}

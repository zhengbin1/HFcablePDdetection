#ifndef TYPE_DIAGNOSIS_DOUBLE_SLIDER_H
#define TYPE_DIAGNOSIS_DOUBLE_SLIDER_H

#include <QSlider>
#include <QMouseEvent>

class TypeDiagnosisDoubleSlider : public QSlider
{
    Q_OBJECT
public:
    explicit TypeDiagnosisDoubleSlider(QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);

signals:
    void valueDoubleChanged(double);

public slots:
    void setDoubleValue(double givenValue);
};

#endif // TYPE_DIAGNOSIS_DOUBLE_SLIDER_H

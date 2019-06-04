#ifndef TYPE_DIAGNOSIS_WIDGET_H
#define TYPE_DIAGNOSIS_WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QStyleOption>
#include <QLabel>
#include <QGridLayout>
#include <QProgressBar>


// 类型诊断窗口
class TypeDiagnosisWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TypeDiagnosisWidget(QWidget *parent = nullptr);
    ~TypeDiagnosisWidget();
    void paintEvent(QPaintEvent *);

    void setTitleName(QString name);
    void setSize(int width, int height);

private:
    QLabel *titleName;
    int m_width;
    int m_height;

    QGridLayout *pGridLayout;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;

    QProgressBar *progressBar1;
    QProgressBar *progressBar2;
    QProgressBar *progressBar3;

signals:

public slots:
};

#endif // TYPE_DIAGNOSIS_WIDGET_H

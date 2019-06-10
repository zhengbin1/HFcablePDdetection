#ifndef TYPE_DIAGNOSIS_WIDGET_H
#define TYPE_DIAGNOSIS_WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QStyleOption>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QProgressBar>
#include <QPushButton>
#include <QSpinBox>


// 开始和暂停按钮
class PlayAndPauseButton : public QPushButton
{
    Q_OBJECT
public:
    PlayAndPauseButton(QWidget *parent = nullptr);
    virtual ~PlayAndPauseButton();

private:
    void paintEvent(QPaintEvent *);
};


// 类型诊断窗口
class TypeDiagnosisWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TypeDiagnosisWidget(QWidget *parent = nullptr);
    virtual ~TypeDiagnosisWidget();
    void paintEvent(QPaintEvent *);

    void setTitleName(QString name);
    void setSize(int width, int height);

    void setTypeName(QString name);
private:
    QLabel *titleName;
    int m_width;
    int m_height;

    QGridLayout *pGridLayout;

    QLineEdit *pLineEdit1;
    QLineEdit *pLineEdit2;
    QLineEdit *pLineEdit3;

    QProgressBar *progressBar1;
    QProgressBar *progressBar2;
    QProgressBar *progressBar3;

    void timerEvent(QTimerEvent *);

    int m_progressValue;

    QString m_TypeName;
signals:

public slots:
};

#endif // TYPE_DIAGNOSIS_WIDGET_H

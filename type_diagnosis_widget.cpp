#include "type_diagnosis_widget.h"

TypeDiagnosisWidget::TypeDiagnosisWidget(QWidget *parent) : QWidget(parent)
{
    titleName = new QLabel(this);
    setStyleSheet("background-color:#00CED1;");

    pLineEdit1 = new QLineEdit(this);
    pLineEdit2 = new QLineEdit(this);
    pLineEdit3 = new QLineEdit(this);

    pLineEdit1 -> setStyleSheet("background-color: #fff;");
    pLineEdit2 -> setStyleSheet("background-color: #fff;");
    pLineEdit3 -> setStyleSheet("background-color: #fff;");

    pLineEdit1 -> resize(100, 50);

    progressBar1 = new QProgressBar(this);
    progressBar2 = new QProgressBar(this);
    progressBar3 = new QProgressBar(this);

    progressBar1 -> setStyleSheet("border: 1px solid #000;color:rhb(0,255,127); text-align: center;");
    progressBar1 -> setRange(0,100);
    progressBar1 -> setMinimum(0);
    progressBar1 -> setMaximum(100);

    progressBar2 -> setStyleSheet("border: 1px solid #000;color:rhb(0,255,127); text-align: center;");
    progressBar2 -> setRange(0,100);
    progressBar2 -> setMinimum(0);
    progressBar2 -> setMaximum(100);

    progressBar3 -> setStyleSheet("border: 1px solid #000;color:rhb(0,255,127); text-align: center;");
    progressBar3 -> setRange(0,100);
    progressBar3 -> setMinimum(0);
    progressBar3 -> setMaximum(100);

    pGridLayout = new QGridLayout(this);

    pGridLayout -> addWidget(pLineEdit1, 0, 0, 1, 2);
    pGridLayout -> addWidget(pLineEdit2, 1, 0, 1, 2);
    pGridLayout -> addWidget(pLineEdit3, 2, 0, 1, 2);

    pGridLayout -> addWidget(progressBar1, 0, 2, 1, 2);
    pGridLayout -> addWidget(progressBar2, 1, 2, 1, 2);
    pGridLayout -> addWidget(progressBar3, 2, 2, 1, 2);

    m_progressValue = 0;

    startTimer(1000);
}

TypeDiagnosisWidget::~TypeDiagnosisWidget()
{
    delete titleName;
    delete pGridLayout;

    delete pLineEdit1;
    delete pLineEdit2;
    delete pLineEdit3;

    delete progressBar1;
    delete progressBar2;
    delete progressBar3;
}

void TypeDiagnosisWidget::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style() -> drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);

    m_width = this -> geometry().width();  // 窗口宽度
    m_height = this -> geometry().height();  // 窗口高度

    pGridLayout -> setGeometry(QRect(0, 30, m_width, m_height - 30));

    titleName -> resize(m_width, 30);
    titleName -> move(0, 0);
}

void TypeDiagnosisWidget::setTitleName(QString name)
{
    titleName -> setText("<p style=\"line-height:30px;height:20px;color:#FFF68F;font-size:12px;text-align:center;\">" + name + "<p>");
}

void TypeDiagnosisWidget::setSize(int width, int height)
{
    this -> resize(width, height);
}

void TypeDiagnosisWidget::timerEvent(QTimerEvent *)
{
    m_progressValue ++;

    if(m_progressValue >= 100)
    {
        m_progressValue = 0;
    } else {
        progressBar1 -> setValue(m_progressValue);
        progressBar2 -> setValue(m_progressValue);
        progressBar3 -> setValue(m_progressValue);
    }
}

#include "type_diagnosis_widget.h"

TypeDiagnosisWidget::TypeDiagnosisWidget(QWidget *parent) : QWidget(parent)
{
    titleName = new QLabel(this);
    setStyleSheet("background-color:#00CED1;");

    pGridLayout = new QGridLayout(this);

    label1 = new QLabel(this);
    label2 = new QLabel(this);
    label3 = new QLabel(this);

    label1 -> setStyleSheet("background-color: #fff;");
    label2 -> setStyleSheet("background-color: #fff;");
    label3 -> setStyleSheet("background-color: #fff;");


    progressBar1 = new QProgressBar(this);
    progressBar2 = new QProgressBar(this);
    progressBar3 = new QProgressBar(this);

    pGridLayout -> addWidget(label1, 0, 0, 1, 2);
    pGridLayout -> addWidget(label2, 1, 0, 1, 2);
    pGridLayout -> addWidget(label3, 2, 0, 1, 2);

    pGridLayout -> addWidget(progressBar1, 0, 1, 1, 2);
    pGridLayout -> addWidget(progressBar2, 1, 1, 1, 2);
    pGridLayout -> addWidget(progressBar3, 2, 1, 1, 2);
}

TypeDiagnosisWidget::~TypeDiagnosisWidget()
{
    delete titleName;
    delete pGridLayout;

    delete label1;
    delete label2;
    delete label3;

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

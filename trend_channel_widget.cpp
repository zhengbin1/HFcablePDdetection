#include "trend_channel_widget.h"

TrendChannelWidget::TrendChannelWidget(QWidget *parent) : QWidget(parent)
{
    QLabel *text4 = new QLabel(this);
    text4 -> setText("<p style=\"color:green;font-size:13px;text-align:center;\">趋势通道选择<p>");

    QRadioButton *radioButton1 = new QRadioButton(this);
    radioButton1 -> setLayoutDirection(Qt::RightToLeft);
    radioButton1 -> setText("CH1");
    QRadioButton *radioButton2 = new QRadioButton(this);
    radioButton2 -> setLayoutDirection(Qt::RightToLeft);
    radioButton2 -> setText("CH2");
    QRadioButton *radioButton3 = new QRadioButton(this);
    radioButton3 -> setLayoutDirection(Qt::RightToLeft);
    radioButton3 -> setText("CH3");
    QRadioButton *radioButton4 = new QRadioButton(this);
    radioButton4 -> setLayoutDirection(Qt::RightToLeft);
    radioButton4 -> setText("CH4");

    buttonGroup = new QButtonGroup(this);
    buttonGroup -> addButton(radioButton1, 0);
    buttonGroup -> addButton(radioButton2, 1);
    buttonGroup -> addButton(radioButton3, 2);
    buttonGroup -> addButton(radioButton4, 3);

    m_CH_Layout = new QGridLayout();
    m_CH_Layout -> addWidget(text4, 0, 0, 1, 2);
    m_CH_Layout -> addWidget(radioButton1, 1, 0, 5, 1);
    m_CH_Layout -> addWidget(radioButton2, 1, 1, 5, 1);
    m_CH_Layout -> addWidget(radioButton3, 2, 0, 5, 1);
    m_CH_Layout -> addWidget(radioButton4, 2, 1, 5, 1);

    m_CH_Layout -> setRowStretch(0, 1);
    m_CH_Layout -> setRowStretch(1, 5);
    m_CH_Layout -> setRowStretch(2, 5);

    this -> setLayout(m_CH_Layout);
}

TrendChannelWidget::~TrendChannelWidget()
{
    delete m_CH_Layout;
    delete buttonGroup;
}

void TrendChannelWidget::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style() -> drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);
}

#include "type_diagnosis_widget.h"
#include <QDebug>


RadioButton::RadioButton(QWidget *parent) : QPushButton (parent)
{
    m_flag = 1;
}

RadioButton::~RadioButton() {}

void RadioButton::mousePressEvent(QMouseEvent *)
{
    if(m_flag == 1)
    {
        m_flag = 2;
    } else if (m_flag == 2) {
        m_flag = 1;
    }
}

void RadioButton::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style() -> drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);

    this -> resize(16, 16);

    if(m_flag == 1){
        p.setPen(QPen(Qt::lightGray, 1, Qt::SolidLine));
        p.setBrush(QBrush(Qt::white, Qt::SolidPattern));
        p.drawEllipse(0, 0, 16, 16);
        p.setPen(QPen(Qt::white, 1, Qt::SolidLine));
        p.setBrush(QBrush(Qt::green, Qt::SolidPattern));
        p.drawEllipse(2, 2, 13, 13);
        p.end();
    } else if (m_flag == 2) {
        p.setPen(QPen(Qt::lightGray, 1, Qt::SolidLine));
        p.setBrush(QBrush(Qt::white, Qt::SolidPattern));
        p.drawEllipse(0, 0, 16, 16);
        p.setPen(QPen(Qt::white, 1, Qt::SolidLine));
        p.setBrush(QBrush(Qt::red, Qt::SolidPattern));
        p.drawEllipse(2, 2, 13, 13);
        p.end();
    }
}


PlayAndPauseButton::PlayAndPauseButton(QWidget *parent) : QPushButton (parent)
{
    m_flag = 1;
}

PlayAndPauseButton::~PlayAndPauseButton() {}

void PlayAndPauseButton::mousePressEvent(QMouseEvent *)
{
    if(m_flag == 1)
    {
        m_flag = 2;
    } else if (m_flag == 2) {
        m_flag = 1;
    }
}

void PlayAndPauseButton::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style() -> drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);

    if(m_flag == 1){
        QImage backImage;
        backImage.load(":/resource/images/pause_32px_1134007_easyicon.net.png");

        this -> resize(backImage.width(), backImage.height());

        QPixmap pixmap = QPixmap(":/resource/images/pause_32px_1134007_easyicon.net.png").scaled(this -> size());
        p.drawPixmap(this -> rect(), pixmap);
    } else if (m_flag == 2) {
        QImage backImage;
        backImage.load(":/resource/images/play_32px_1134011_easyicon.net.png");

        this -> resize(backImage.width(), backImage.height());

        QPixmap pixmap = QPixmap(":/resource/images/play_32px_1134011_easyicon.net.png").scaled(this -> size());
        p.drawPixmap(this -> rect(), pixmap);
    }
}

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

    PlayAndPauseButton *pPlayAndPauseButton = new PlayAndPauseButton();

    QLabel *text1 = new QLabel();
    QLabel *text2 = new QLabel();
    text1 -> setText("相位");
    text2 -> setText("阈值");

    QSlider *pSlider1 = new QSlider(Qt::Horizontal);  // 相位
    pSlider1 -> setStyleSheet("QSlider::groove:horizontal {height: 5px;background: #C0C0C0;border: 1px solid #4A708B;border-radius: 1px; padding-left:-1px; padding-right:-1px;}"
                              "QSlider::sub-page:horizontal {height: 10px; background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #B1B1B1, stop:1 #c4c4c4); background: qlineargradient(x1:0, y1:0.2, x2:1, y2:1, stop:0 #5DCCFF, stop:1 #1874CD); border: 1px solid #4A708B; border-radius: 2px;}"
                              "QSlider::add-page:horizontal {height: 10px; background: #575757; border: 0px solid #777; border-radius: 2px;}"
                              "QSlider::handle:horizontal { width: 11px; background: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.6 #45ADED, stop:0.778409 rgba(255, 255, 255, 255)); margin-top: -3px; margin-bottom: -3px; border-radius: 5px;}"
                              "QSlider::handle:horizontal:hover {width: 11px; background: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.6 #2A8BDA, stop:0.778409 rgba(255, 255, 255, 255));margin-top: -3px;margin-bottom: -3px;border-radius: 5px;}"
                              "QSlider::sub-page:horizontal:disabled {background: #00009C; border-color: #999;}"
                              "QSlider::add-page:horizontal:disabled {background: #eee; border-color: #999;}"
                              "QSlider::handle:horizontal:disabled { background: #eee; border: 1px solid #aaa; border-radius: 4px;}");

    pSlider1 -> setMinimum(-180);
    pSlider1 -> setMaximum(180);
    pSlider1 -> setSingleStep(1);

    TypeDiagnosisDoubleSlider *pSlider2 = new TypeDiagnosisDoubleSlider(this);  // 阈值

    QSpinBox *pSpinBox1 = new QSpinBox(this);
    pSpinBox1 -> setMinimum(-180);
    pSpinBox1 -> setMaximum(180);
    pSpinBox1 -> setSingleStep(1);

    QDoubleSpinBox *pSpinBox2 = new QDoubleSpinBox(this);
    pSpinBox2 -> setMinimum(-1);
    pSpinBox2 -> setMaximum(1);
    pSpinBox2 -> setSingleStep(0.01);

    connect(pSpinBox1, SIGNAL(valueChanged(int)), pSlider1, SLOT(setValue(int)));  // 相位
    connect(pSlider1, SIGNAL(valueChanged(int)), pSpinBox1, SLOT(setValue(int)));

    connect(pSpinBox2, SIGNAL(valueChanged(double)), pSlider2, SLOT(setDoubleValue(double)));  // 阈值
    connect(pSlider2, SIGNAL(valueDoubleChanged(double)), pSpinBox2, SLOT(setValue(double)));

    RadioButton *radioButton1 = new RadioButton(this);

    QLabel *text3 = new QLabel();
    text3 -> setText("累积");

    radioButton2 = new QRadioButton(this);
    radioButton2 -> setLayoutDirection(Qt::RightToLeft);

    pLineEdit4 = new QLineEdit(this);
    pLineEdit4 -> setStyleSheet("background-color: #fff;");

    QGridLayout *pGridLayout2 = new QGridLayout();
    pGridLayout2 -> addWidget(pPlayAndPauseButton, 0, 0, 2, 1, Qt::AlignVCenter);
    pGridLayout2 -> addWidget(text1, 0, 1, 1, 1);
    pGridLayout2 -> addWidget(text2, 1, 1, 1, 1);
    pGridLayout2 -> addWidget(pSlider1, 0, 2, 1, 1);
    pGridLayout2 -> addWidget(pSlider2, 1, 2, 1, 1);
    pGridLayout2 -> addWidget(pSpinBox1, 0, 3, 1, 1);
    pGridLayout2 -> addWidget(pSpinBox2, 1, 3, 1, 1);
    pGridLayout2 -> addWidget(text3, 0, 4, 1, 1);
    pGridLayout2 -> addWidget(radioButton1, 0, 5, 1, 1);
    pGridLayout2 -> addWidget(pLineEdit4, 0, 6, 1, 1);
    pGridLayout2 -> addWidget(radioButton2, 1, 4, 1, 3, Qt::AlignHCenter);

    pGridLayout2 -> setColumnStretch(0, 1);
    pGridLayout2 -> setColumnStretch(1, 1);
    pGridLayout2 -> setColumnStretch(2, 5);
    pGridLayout2 -> setColumnStretch(3, 1);
    pGridLayout2 -> setColumnStretch(4, 1);
    pGridLayout2 -> setColumnStretch(5, 1);
    pGridLayout2 -> setColumnStretch(6, 1);


    pGridLayout -> addLayout(pGridLayout2, 3, 0, 1, 4);

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
    delete pLineEdit4;

    delete progressBar1;
    delete progressBar2;
    delete progressBar3;

    delete radioButton2;
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

    radioButton2 -> setText(getTypeName() + "降噪");
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

void TypeDiagnosisWidget::setTypeName(QString name)
{
    m_TypeName = name;
}

QString TypeDiagnosisWidget::getTypeName()
{
    return m_TypeName;
}

#include "project_manage_dialog.h"
#include <QDebug>

ProjectManageDialog::ProjectManageDialog(QWidget *parent) : QDialog (parent)
{
    Qt::WindowFlags flags = Qt::Dialog;

    flags &= ~Qt::WindowContextHelpButtonHint;
    flags |= Qt::WindowMinMaxButtonsHint;
    flags |= Qt::WindowCloseButtonHint;

    setWindowFlags(flags);
    setWindowTitle("项目管理");
    setStyleSheet("background-color:#333333;");

    // 获取桌面屏幕大小
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect rect = screen -> availableGeometry();
    m_screen_width = rect.width();
    m_screen_height = rect.height();

    resize(m_screen_width / 2, m_screen_height / 2);

    pText1 = new QLabel(this);
    pText1 -> setText("<p style=\"color:#FFFFFF;font-size:20px;text-align:center;\">项目信息管理</p>");
    pText2 = new QLabel(this);
    pText2 -> setText("<span style=\"color:#33CC33;font-size:12px;\">变电站名称</span>");
    pText3 = new QLabel(this);
    pText3 -> setText("<span style=\"color:#33CC33;font-size:12px;\">检测位置</span>");
    pText4 = new QLabel(this);
    pText4 -> setText("<span style=\"color:#33CC33;font-size:12px;\">设备类型</span>");
    pText5 = new QLabel(this);
    pText5 -> setText("<span style=\"color:#33CC33;font-size:12px;\">检测向别</span>");
    pText6 = new QLabel(this);
    pText6 -> setText("<span style=\"color:#33CC33;font-size:12px;\">电压等级</span>");

    m_LineEdit1 = new QLineEdit(this);
    m_LineEdit2 = new QLineEdit(this);

    m_LineEdit1 -> setStyleSheet("background-color:#FFFFFF;");
    m_LineEdit2 -> setStyleSheet("background-color:#FFFFFF;");

    m_ComboBox1 = new QComboBox(this);
    m_ComboBox2 = new QComboBox(this);
    m_ComboBox3 = new QComboBox(this);

    m_ComboBox1 -> setStyleSheet("background-color:#FFFFFF;");
    m_ComboBox2 -> setStyleSheet("background-color:#FFFFFF;");
    m_ComboBox3 -> setStyleSheet("background-color:#FFFFFF;");

    m_ComboBox1 -> insertItem(0, "GIS");
    m_ComboBox1 -> insertItem(1, "变压器");
    m_ComboBox1 -> insertItem(2, "开关柜");
    m_ComboBox1 -> insertItem(3, "高压电缆");

    m_ComboBox2 -> insertItem(0, "A组");
    m_ComboBox2 -> insertItem(1, "B组");
    m_ComboBox2 -> insertItem(2, "C组");
    m_ComboBox2 -> insertItem(3, "三项共体");

    m_ComboBox3 -> insertItem(0, "10kV");
    m_ComboBox3 -> insertItem(1, "35kV");
    m_ComboBox3 -> insertItem(2, "110kV");
    m_ComboBox3 -> insertItem(3, "220kV");
    m_ComboBox3 -> insertItem(4, "330kV");
    m_ComboBox3 -> insertItem(5, "500kV");
    m_ComboBox3 -> insertItem(6, "750kV");
    m_ComboBox3 -> insertItem(7, "1000kV");

    m_Open_Button = new QPushButton(this);
    m_Open_Button -> setStyleSheet("background-color:#1bd1a5;");
    m_Open_Button -> setText("打 开");

    m_Delete_Button = new QPushButton(this);
    m_Delete_Button -> setStyleSheet("background-color:#1bd1a5;");
    m_Delete_Button -> setText("删 除");

    m_Modify_Button = new QPushButton(this);
    m_Modify_Button -> setStyleSheet("background-color:#1bd1a5;");
    m_Modify_Button -> setText("修改位置");

    m_TableView = new QTableView(this);
    m_TableView -> verticalHeader() -> setHidden(true);
    m_TableView -> horizontalHeader() -> setSectionResizeMode(QHeaderView::Stretch);
    m_TableView -> horizontalHeader() -> setStyleSheet("QHeaderView::section{background-color:#000000;color:#FFFFFF;} QHeaderView::section:hover{background-color:#41555d;}");
    m_TableView -> setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_TableView -> setStyleSheet("color:#ffffff");

    m_model = new QStandardItemModel(this);

    m_TableView -> setModel(m_model);

    m_HBoxLayout = new QHBoxLayout();
    m_HBoxLayout -> addWidget(pText2);
    m_HBoxLayout -> addWidget(m_LineEdit1);
    m_HBoxLayout -> addWidget(pText3);
    m_HBoxLayout -> addWidget(m_LineEdit2);
    m_HBoxLayout -> addWidget(pText4);
    m_HBoxLayout -> addWidget(m_ComboBox1);
    m_HBoxLayout -> addWidget(pText5);
    m_HBoxLayout -> addWidget(m_ComboBox2);
    m_HBoxLayout -> addWidget(pText6);
    m_HBoxLayout -> addWidget(m_ComboBox3);
    m_HBoxLayout -> addWidget(m_Open_Button);
    m_HBoxLayout -> addWidget(m_Delete_Button);
    m_HBoxLayout -> addWidget(m_Modify_Button);

    m_VBoxLayout = new QVBoxLayout(this);
    m_VBoxLayout -> addWidget(pText1);
    m_VBoxLayout -> addLayout(m_HBoxLayout);
    m_VBoxLayout -> addWidget(m_TableView);
    setLayout(m_VBoxLayout);

    connect(m_TableView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(TableView_Clicked(const QModelIndex &)));
}

ProjectManageDialog::~ProjectManageDialog()
{
    delete pText1;
    delete pText2;
    delete pText3;
    delete pText4;
    delete pText5;
    delete pText6;

    delete  m_LineEdit1;
    delete  m_LineEdit2;

    delete m_ComboBox1;
    delete m_ComboBox2;
    delete m_ComboBox3;

    delete m_Open_Button;
    delete m_Delete_Button;
    delete m_Modify_Button;

    delete m_TableView;
    delete m_model;

    delete m_HBoxLayout;
    delete m_VBoxLayout;
}

void ProjectManageDialog::showEvent(QShowEvent *)
{
    m_model -> clear();

    QStringList headherlist;
    headherlist << "变电站名称" << "设备类型" << "电压等级" << "检测相别" << "检测位置";

    m_model -> setHorizontalHeaderLabels(headherlist);
    m_model -> setColumnCount(headherlist.count());

    QSqlQuery query = OperationSqlite::selectShowAll();

    while (query.next())
    {
        int rowcount = m_model -> rowCount();

        m_model -> setItem(rowcount, 0, new QStandardItem(query.value(0).toString()));
        m_model -> setItem(rowcount, 1, new QStandardItem(query.value(1).toString()));
        m_model -> setItem(rowcount, 2, new QStandardItem(query.value(2).toString()));
        m_model -> setItem(rowcount, 3, new QStandardItem(query.value(3).toString()));
        m_model -> setItem(rowcount, 4, new QStandardItem(query.value(4).toString()));
    }
}

void ProjectManageDialog::TableView_Clicked(const QModelIndex &)
{
    int row = m_TableView -> currentIndex().row();

    for(int i = 0; i < 5; i++)
    {
        QModelIndex index = m_model -> index(row, i);
        QString value = m_model -> data(index).toString();

        switch (i)
        {
        case 0:
            m_LineEdit1 -> setText(value);  // 变电站名称
            break;
        case 1:
            m_ComboBox1 -> setCurrentText(value);  // 设备类型
            break;
        case 2:
            m_ComboBox3 -> setCurrentText(value);  // 检测相别
            break;
        case 3:
            m_ComboBox2 -> setCurrentText(value);  // 电压等级
            break;
        case 4:
            m_LineEdit2 -> setText(value);  // 检测位置
            break;
        }
    }
}

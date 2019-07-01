#ifndef PROJECT_MANAGE_DIALOG_H
#define PROJECT_MANAGE_DIALOG_H

#include <QDialog>
#include <QPainter>
#include <QStyleOption>
#include <QGuiApplication>
#include <QScreen>
#include <QBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QTableView>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QMessageBox>

#include "operation_sqlite.h"


class ProjectManageDialog : public QDialog
{
    Q_OBJECT

public:
    ProjectManageDialog(QWidget *parent = nullptr);
    ~ProjectManageDialog();
    void showEvent(QShowEvent *);

private:
    QLabel *pText1;
    QLabel *pText2;
    QLabel *pText3;
    QLabel *pText4;
    QLabel *pText5;
    QLabel *pText6;

    QLineEdit *m_LineEdit1;
    QLineEdit *m_LineEdit2;

    QComboBox *m_ComboBox1;
    QComboBox *m_ComboBox2;
    QComboBox *m_ComboBox3;

    QTableView *m_TableView;
    QStandardItemModel *m_model;

    QPushButton *m_Open_Button;
    QPushButton *m_Delete_Button;
    QPushButton *m_Modify_Button;

    int m_screen_width;
    int m_screen_height;

    QHBoxLayout *m_HBoxLayout;
    QVBoxLayout *m_VBoxLayout;

private slots:
    void TableView_Clicked(const QModelIndex &);
};

#endif // PROJECT_MANAGE_DIALOG_H

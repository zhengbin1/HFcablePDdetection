#ifndef NEW_PRODUCT_DIALOG_H
#define NEW_PRODUCT_DIALOG_H

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


class NewProjectDialog : public QDialog
{
    Q_OBJECT

public:
    NewProjectDialog(QWidget *parent = nullptr);
    ~NewProjectDialog();
    void showEvent(QShowEvent *);

private:
    int m_screen_width;
    int m_screen_height;

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

    QPushButton *m_Decide_Button;

    QTableView *m_TableView;
    QStandardItemModel *m_model;

    QHBoxLayout *m_HBoxLayout;
    QVBoxLayout *m_VBoxLayout;

private slots:
    void click_Decide_Button();
};

#endif // NEW_PRODUCT_DIALOG_H

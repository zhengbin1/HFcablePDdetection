#ifndef MULTIPLE_SOURCE_SEPARATION_H
#define MULTIPLE_SOURCE_SEPARATION_H

#include <QDialog>
#include <QPainter>
#include <QStyleOption>
#include <QGuiApplication>
#include <QScreen>
#include <QBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>


class MSSeparationDialog : public QDialog
{
    Q_OBJECT

public:
    MSSeparationDialog(QWidget *parent = nullptr);
    ~MSSeparationDialog();

private:
    int m_screen_width;
    int m_screen_height;
};

#endif // MULTIPLE_SOURCE_SEPARATION_H

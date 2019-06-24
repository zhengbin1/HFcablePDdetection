#ifndef NEW_PRODUCT_DIALOG_H
#define NEW_PRODUCT_DIALOG_H

#include <QDialog>
#include <QPainter>
#include <QStyleOption>

class NewProductDialog : public QDialog
{
    Q_OBJECT
public:
    NewProductDialog(QWidget *parent = nullptr);
    ~NewProductDialog();
    void paintEvent(QPaintEvent *);
};

#endif // NEW_PRODUCT_DIALOG_H

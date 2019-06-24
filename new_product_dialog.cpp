#include "new_product_dialog.h"

NewProductDialog::NewProductDialog(QWidget *parent):QDialog (parent)
{
    Qt::WindowFlags flags = Qt::Dialog;

    flags &= ~Qt::WindowContextHelpButtonHint;
    flags |= Qt::WindowMinMaxButtonsHint;
    flags |= Qt::WindowCloseButtonHint;

    setWindowFlags(flags);
}

NewProductDialog::~NewProductDialog()
{

}

void NewProductDialog::paintEvent(QPaintEvent *)
{

}

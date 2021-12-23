#ifndef BUTTON_H
#define BUTTON_H
#include <QPushButton>

class AddToCartBtn:public QPushButton
{
    Q_OBJECT
public:
    AddToCartBtn(QPushButton* parent);
    AddToCartBtn(){};
};

#endif // BUTTON_H


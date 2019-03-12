#include <QtWidgets>
#include <cmath>
#include "button.h"
#include "lw.h"

Button *LW::createButton(const QString &text, const char *member)
{
    Button *button = new Button(text);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}

LW::LW(QWidget *parent)
    : QWidget(parent)
{
    /*display = new QLineEdit("0");
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMaxLength(15);
    QFont font = display->font();
    font.setPointSize(font.pointSize() + 8);
    display->setFont(font);*/

    //Button *pointButton = createButton(tr("."), SLOT(pointClicked()));

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    //mainLayout->addWidget(display, 0, 0, 1, 6);
    //some widjets

    setLayout(mainLayout);
    setWindowTitle(tr("Calculator"));
}

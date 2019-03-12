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
    stdts = new QComboBox();
    inp = new QLineEdit("Новый студент...");
    //Button *pointButton = createButton(tr("."), SLOT(pointClicked()));
    add = createButton("Добавить", SLOT(addStdt()));
    del = createButton("Удалить", SLOT(delStdt()));
    QLabel *eNameField = new QLabel("Контроль студентов");
    QLabel *eMarksField = new QLabel("Ввод оценок");
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    mainLayout->addWidget(eNameField, 0, 0, 1, 6);
    mainLayout->addWidget(inp, 1, 0, 1, 6);
    mainLayout->addWidget(add, 2, 0, 1, 3);
    mainLayout->addWidget(del, 2, 3, 1, 3);
    mainLayout->addWidget(stdts, 3, 0, 1, 6);
    mainLayout->addWidget(eMarksField, 4, 0, 1, 6);

    setLayout(mainLayout);
    setWindowTitle("Marks");
}

void LW::addStdt(){
    if (inp->displayText() != "")
        stdts->addItem(inp->displayText());
}

void LW::delStdt(){
    if (stdts->count() != 0)
        stdts->removeItem(stdts->count() - 1);
}


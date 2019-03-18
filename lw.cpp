#include <QtWidgets>
#include "button.h"
#include "lw.h"

Button *LW::createButton(const QString &text, const char *member)
{
    Button *button = new Button(text);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}

LW::LW(QWidget *parent) : QWidget(parent){
    root = new Marks; root->next = NULL;
    QLabel *eNameField = new QLabel("Контроль студентов");
    inp = new QLineEdit();
    add = createButton("Добавить", SLOT(addStdt()));
    del = createButton("Удалить", SLOT(delStdt())); del->setEnabled(0);
    QLabel *eMarksField = new QLabel("Ввод оценок");
    stdts = new QComboBox();
    connect(stdts, SIGNAL(currentIndexChanged(int)), this, SLOT(refreshOutput()));
    inpMarks = new QSpinBox*[N];
    for (int i = 0; i < N; i++){
        inpMarks[i] = new QSpinBox();
        inpMarks[i]->setRange(1, 10);
    }
    submit = createButton("Сохранить", SLOT(submitMarks())); submit->setEnabled(0);
    connect(submit, SIGNAL(clicked()), this, SLOT(refreshOutput()));
    reset = createButton("Сбросить", SLOT(resetInpMarks()));
    QLabel *oMarksField = new QLabel("Оценки в базе");
    out = new QLineEdit("Добавьте студентов!"); out->setReadOnly(1);
    clr = createButton("Очистить", SLOT(clrData())); clr->setEnabled(0);
    connect(clr, SIGNAL(clicked()), this, SLOT(refreshOutput()));
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    mainLayout->addWidget(eNameField, 0, 0, 1, 4*N);
    mainLayout->addWidget(inp, 1, 0, 1, 4*N);
    mainLayout->addWidget(add, 2, 0, 1, 2*N);
    mainLayout->addWidget(del, 2, 2*N, 1, 2*N);
    mainLayout->addWidget(eMarksField, 3, 0, 1, 4*N);
    mainLayout->addWidget(stdts, 4, 0, 1, 4*N);
    for (int i = 0; i < N; i++){
        mainLayout->addWidget(inpMarks[i], 5, 4*i, 1, 4);
    }
    mainLayout->addWidget(submit, 6, 0, 1, 2*N);
    mainLayout->addWidget(reset, 6, 2*N, 1, 2*N);
    mainLayout->addWidget(oMarksField, 7, 0, 1, 4*N);
    mainLayout->addWidget(out, 8, 0, 1, 4*N);
    mainLayout->addWidget(clr, 9, 0, 1, 2*N);
    setLayout(mainLayout);
    setWindowTitle("Marks");
}

void LW::addStdt(){
    if (inp->displayText() != ""){
        Marks *t = root, *newElem = new Marks;
        for (int i = 0; i < N; i++){
            newElem->m[i] = -1;
        }
        newElem->next = NULL;
        while (t->next){
            t = t->next;
        }
        t->next = newElem;
        stdts->addItem(inp->displayText());
        del->setEnabled(1);
    }
}
void LW::delStdt(){
    if (stdts->count() != 0){
        Marks *t = root->next, *before_t = t, *after_t = t->next;
        for (int i = 0; i < stdts->currentIndex(); i++){
            before_t = t;
            t = t->next;
            after_t = t->next;
        }
        for (int i = 0; i < N; i++){
            t->m[i] = -1;
        }
        before_t->next = after_t;
        delete(t);
        stdts->removeItem(stdts->currentIndex());
        if (stdts->count() == 0) del->setEnabled(0);
    }
}
void LW::submitMarks(){
    if (stdts->count() == 0) return;
    Marks *t = root->next;
    for (int i = 0; i < stdts->currentIndex(); i++){
        t = t->next;
    }
    for (int i = 0; i < N; i++){
        t->m[i] = inpMarks[i]->value();
    }
}
void LW::refreshOutput(){
    out->clear();
    if (!stdts->count()) {
        out->setText("Добавьте студентов!");
        for (int i = 0; i < N; i++){
            inpMarks[i]->setValue(1);
        }
        clr->setEnabled(0);
        submit->setEnabled(0);
        return;
    }
    bool haveMarks = 0;
    QString current = "";
    Marks *t = root->next;
    for (int i = 0; i < stdts->currentIndex(); i++){
        t = t->next;
    }
    bool firstInOutput = 0;
    for (int i = 0; i < N; i++){
        if (t->m[i] != -1){
            haveMarks = 1;
            if (!firstInOutput){ //После последнего числа не будет запятой
                firstInOutput = 1;
                current += QVariant(t->m[i]).toString();
            }
            else current += ", " + QVariant(t->m[i]).toString();
        }
    }
    for (int i = 0; i < N; i++){
        if (t->m[i] != -1)
            inpMarks[i]->setValue(t->m[i]);
        else
            inpMarks[i]->setValue(1);
    }
    if (!haveMarks) {
        out->setText("Оценок в базе нет!");
        clr->setEnabled(0);
        submit->setEnabled(1);
    }
    else {
        out->setText(current);
        clr->setEnabled(1);
        submit->setEnabled(1);
    }
}
void LW::clrData(){
    if (stdts->count() == 0) return;
    for (int i = 0; i < N; i++){
        inpMarks[i]->setValue(1);
    }
    Marks *t = root->next;
    for (int i = 0; i < stdts->currentIndex(); i++){
        t = t->next;
    }
    for (int i = 0; i < N; i++){
        t->m[i] = -1;
    }
}
void LW::resetInpMarks(){
    for(int i = 0; i < N; i++){
        inpMarks[i]->setValue(1);
    }
}

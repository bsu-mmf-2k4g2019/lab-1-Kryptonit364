#ifndef LW_H
#define LW_H

#include <QWidget>

class QLineEdit;
class Button;
class QComboBox;
class QSpinBox;

//! [0]
class LW : public QWidget
{
    Q_OBJECT
public:
    const static int N = 3; //Количество оценок, 3-5 оптимально
    struct Marks{
        int *m = new int[N];
        Marks *next;
    };
    LW(QWidget *parent = 0);
    ~LW() = default;
private slots:
    void clrFIO();
    void addStdt();
    void delFStdt();
    void delCStdt();
    void submitMarks();
    void refreshOutput();
    void clrData();
    void resetInpMarks();
    void countSB();
private:
    Marks *root;
    Button *createButton(const QString &text, const char *member);
    QLineEdit *inp;
    Button *clrInp;
    QComboBox *stdts;
    QSpinBox **inpMarks;
    Button *add;
    Button *delF;
    Button *delC;
    Button *submit;
    Button *reset;
    QLineEdit *out;
    Button *findSB;
    Button *clr;
    Button *outSB;
};
#endif // LW_H

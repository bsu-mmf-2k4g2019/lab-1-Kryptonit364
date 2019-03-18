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
    void addStdt();
    void delStdt();
    void submitMarks();
    void refreshOutput();
    void clrData();
    void resetInpMarks();
private:
    Marks *root;
    Button *createButton(const QString &text, const char *member);
    QComboBox *stdts;
    QLineEdit *inp;
    QSpinBox **inpMarks;
    Button *add;
    Button *del;
    Button *submit;
    Button *reset;
    QLineEdit *out;
    Button *clr;
};
#endif // LW_H

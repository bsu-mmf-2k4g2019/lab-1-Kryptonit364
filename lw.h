#ifndef LW_H
#define LW_H

#include <QWidget>

class QLineEdit;
class Button;
class QComboBox;

//! [0]
class LW : public QWidget
{
    Q_OBJECT
public:
    LW(QWidget *parent = 0);
    ~LW() = default;
private slots:
    void addStdt();
    void delStdt();
private:
    Button *createButton(const QString &text, const char *member);
    QComboBox *stdts;
    QLineEdit *inp;
    Button *add;
    Button *del;
};
#endif // LW_H

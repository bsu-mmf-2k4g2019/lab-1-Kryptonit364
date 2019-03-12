#ifndef LW_H
#define LW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLineEdit;
QT_END_NAMESPACE
class Button;

//! [0]
class LW : public QWidget
{
    Q_OBJECT
public:
    LW(QWidget *parent = 0);
private slots:
    //void digitClicked();
private:
    Button *createButton(const QString &text, const char *member);
    QLineEdit *inpFIO;

    //..
}
#endif // LW_H

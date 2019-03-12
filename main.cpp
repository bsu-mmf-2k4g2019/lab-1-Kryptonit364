#include <QApplication>
#include "lw.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    LW first;
    first.show();
    return app.exec();
}

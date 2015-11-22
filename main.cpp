#include "qwol.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWoL w;
    w.show();

    return a.exec();
}

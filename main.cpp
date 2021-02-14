#include "manager.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Manager m;
    if (argc > 1)
        m.open_document(argv[1]);
    m.show();
    return a.exec(); // NOLINT(readability-static-accessed-through-instance)
}

#include <iostream>

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    std::cout<< "Hello World! Press any Ctrl+C to exit" << std::endl;
    return a.exec();
}

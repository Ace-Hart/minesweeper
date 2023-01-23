#include "mainwindow.h"

#include "Minefield.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      mMinefield{std::make_unique<Minefield>(9, 9, 10)} {}



#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "IMinefield.h"

#include <QMainWindow>

class MainWindow final : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() = default;

signals:

private:
    std::unique_ptr<IMinefield> mMinefield;
};

#endif // MAINWINDOW_H

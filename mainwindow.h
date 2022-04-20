#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "jsonreader.h"
#include "abstractreader.h"
#include <QMainWindow>
#include <cars.h>
#include "QString"
#include "cars.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    std::vector<Cars> cars;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void findCars();
    void addCars();
    void read_file(AbstractReader &rd);
    void openCars();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

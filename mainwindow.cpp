#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cars.h"
#include "csvreader.h"
#include "QString"
#include <QDebug>
#include "writer.h"
#include "mybrowser.h"
#include <iostream>
#include <string>
#include <QFileDialog>
#include <QMessageBox>
#include "jsonreader.h"
#include "abstractreader.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    }


MainWindow::~MainWindow()
{
    writer csv("cars_add.csv");
    csv.WriteAll(cars);
    delete ui;
}
void MainWindow::read_file(AbstractReader &rd)
{
    if (rd.is_open()){}

}

void MainWindow::findCars()
{
    ui->textBrowser->clear();
    int f=0;
    for (const auto &c: cars)
        if(ui->editSearch->text().isEmpty()){
            ui->textBrowser->append(QString::number(c.n)+ ", "+c.model+ ", "+QString::number(c.color)+", "+ QString::number(c.year));
            f=1;}
            else if(c.model==ui->editSearch->text()){
        ui->textBrowser->GreenText(QString::number(c.n)+ ", "+c.model+", "+QString::number(c.color)+", "+ QString::number(c.year));
        f=1;}

  if(f==0) ui->textBrowser->RedText("ERORR");
}

void MainWindow::addCars()
{
    Cars m;
    m.n = (ui->editID->text()).toInt();
    m.model = ui->editModel->text();
    m.year = (ui->editYear->text()).toInt();
    m.color = static_cast<Color>(ui->comboColor->currentIndex());

    cars.push_back(m);
}

// здесь будем считывать файл сразу после нажатия кнопки
void MainWindow::openCars()
{
    QString file_name = QFileDialog::getOpenFileName(this,"Open a file");
    QMessageBox::information(this,"..",file_name);
    if (ui->typeSelect->currentText() == "CSV")
    {
        // открытие файла csv
        CSVReader csv(file_name);
        read_file(csv);
              if (csv.is_open())
      {

            cars = csv.readAll();
        }
    }
    if (ui->typeSelect->currentText() == "JSON")
    {
        // открытие файла JSON
        JSONReader json(file_name);
        read_file(json);
             if (json.is_open())
       {
           cars = json.readAll();
       }
    }

}


#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myProcess = new QProcess(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startBtn_clicked()
{
     qDebug()<<myProcess->state();
    if (myProcess->state() == QProcess::Running)
    {
        qDebug()<<"Process already Running, killing";
        myProcess->kill();
        myProcess->waitForFinished(10000);
        qDebug()<<"Process Killed";
    }
    qDebug()<<myProcess->state();

    QStringList arguments;

    myProcess->setArguments(arguments);
    myProcess->setProgram(ui->programEdit->text());

    myProcess->start();
    qDebug()<<"Process starting";
    myProcess->waitForStarted(10000);
    qDebug()<<"Process started";
    qDebug()<<myProcess->state();
}

void MainWindow::on_stopBtn_clicked()
{
    if (myProcess->state() == QProcess::Running)
    {
        qDebug()<<"Process Running, killing";
        myProcess->kill();
        myProcess->waitForFinished(10000);
        qDebug()<<"Process Killed";
    }
}

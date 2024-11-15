#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->loadFile, &QPushButton::clicked, this, &MainWindow::loadFile);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadFile()
{

    QString filePath = QFileDialog::getOpenFileName(this,
                                                    tr("Open File"),
                                                    "",
                                                    tr("All Files (*.*);;Text Files (*.txt);;CSV Files (*.csv)"));
    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            QString fileContent = in.readAll();
            file.close();

            ui->sourceTextBox->setPlainText(fileContent);
        } else {
            QMessageBox::critical(this, tr("Error"), tr("Unable to open file: %1").arg(file.errorString()));
        }
    } else {
        QMessageBox::warning(this, tr("No File Selected"), tr("Please select a file to proceed."));
    }
}

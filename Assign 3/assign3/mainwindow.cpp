#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->input->setPlaceholderText("Enter keyword here...");

    connect(ui->loadFile, &QPushButton::clicked, this, &MainWindow::loadFile);
    connect(ui->findButton, &QPushButton::clicked, this, &MainWindow::countWordFrequency);
    connect(ui->saveFile, &QPushButton::clicked, this, &MainWindow::saveOutput);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadFile()
{
    //get file path
    QString filePath = QFileDialog::getOpenFileName(this,
                                                    tr("Open File"),
                                                    "",
                                                    tr("All Files (*.*);;Text Files (*.txt);;CSV Files (*.csv)"));
    //if file path isnt empty
    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            QString fileContent = in.readAll();
            file.close();

            ui->sourceTextBox->setPlainText(fileContent); //fill th source text box
            this->filePath = filePath; //store file path
        } else {
            //cant read file
            QMessageBox::critical(this, tr("Error"), tr("Unable to open file: %1").arg(file.errorString()));
        }
    } else {
        //not file was selected
        QMessageBox::warning(this, tr("No File Selected"), tr("Please select a file to proceed."));
    }
}

void MainWindow::countWordFrequency()
{
    //get the source text
    QString text = ui->sourceTextBox->toPlainText();

    //check if its empty
    if (text.isEmpty()) {
        QMessageBox::warning(this, tr("No Text Available"), tr("The source text box is empty. Please load or enter text."));
        return;
    }

    //get the keyword
    QString wordToFind = ui->input->text();
    if (wordToFind.isEmpty()) {
        QMessageBox::warning(this, tr("No Word Specified"), tr("Please enter a word to search for."));
        return;
    }

    //make keyword lowercase
    std::string word = wordToFind.toStdString();
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);

    //make source text lowercase
    std::string sourceText = text.toStdString();
    std::transform(sourceText.begin(), sourceText.end(), sourceText.begin(), ::tolower);

    std::istringstream textStream(sourceText);
    std::string currentWord;
    int totalWords = 0;
    int wordCount = 0;

    //loop through words and count occurances
    while (textStream >> currentWord) {
        currentWord.erase(std::remove_if(currentWord.begin(), currentWord.end(), ::ispunct), currentWord.end());

        totalWords++;
        if (currentWord == word || currentWord.find(word + "-") != std::string::npos) {
            wordCount++;
        }
    }

    //build result string
    QString result = QString("%1 words searched\nWord '%2' found %3 time(s)")
                         .arg(totalWords)
                         .arg(wordToFind)
                         .arg(wordCount);
    //send result to info box
    ui->infoBox->setPlainText(result);
}

void MainWindow::saveOutput()
{
    //get the output text
    QString outputText = ui->infoBox->toPlainText();
    //check if output text was empty
    if (outputText.isEmpty()) {
        QMessageBox::warning(this, tr("No Output to Save"), tr("The output box is empty. Please generate results before saving."));
        return;
    }

    //get the file path of where to save
    QString filePath = QFileDialog::getSaveFileName(this,
                                                    tr("Save Output File"),
                                                    "",
                                                    tr("Text Files (*.txt);;All Files (*.*)"));

    //if file path isnt empty
    if (!filePath.isEmpty()) {
        QFile file(filePath);
        //write text to the file
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << outputText;
            file.close();

            QMessageBox::information(this, tr("File Saved"), tr("The output has been saved successfully."));
        } else {
            //if file couldnt be saved
            QMessageBox::critical(this, tr("Error"), tr("Unable to save file: %1").arg(file.errorString()));
        }
    } else {
        //if not file was selected
        QMessageBox::warning(this, tr("No File Selected"), tr("Please specify a valid file to save the output."));
    }
}

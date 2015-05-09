#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DisplayWarning(string text)
{
    QMessageBox warning;
    warning.setText(QString::fromStdString(text));
    warning.setIcon(QMessageBox::Information);

    warning.exec();
    return;
}

void MainWindow::on_pB_UsunSiec_pressed()
{
    this->network.DeleteNetwork();
    network.ClearAllNeuronsNumber();
    network.SetLayersNumber(0);
    ui->gB_TworzenieSieci->setEnabled(true);
    ui->pB_BudujSiec->setEnabled(true);
    ui->pB_UsunSiec->setEnabled(false);
}



void MainWindow::on_pB_BudujSiec_clicked()
{
    if(ui->rB_StworzSiecRecznie->isChecked())
    {
        Create_Network networkDataDialog(&(this->network), this);
        networkDataDialog.exec();

    }
    else
    {   
        QFileDialog loadDialog;
        QStringList fileNames;
        loadDialog.setParent(this);
        //  The ability to choose both existing and non-existing files
        loadDialog.setFileMode(QFileDialog::AnyFile);
        //  The AcceptButton is Save button
        loadDialog.setAcceptMode(QFileDialog::AcceptOpen);
        //  Show only .txt files
        loadDialog.setNameFilter("Network(*.txt)");
        //  Show detailed description of files
        loadDialog.setViewMode(QFileDialog::Detail);
        //  Set directory to C:/Users/Konrad/Desktop/
        loadDialog.setDirectory("C:/Users/Konrad/Desktop/");

        //  Show the save window and get the filename
        if (loadDialog.exec())
            fileNames = loadDialog.selectedFiles();
        if(!fileNames.isEmpty())
        {
            this->network.LoadNetwork(fileNames[0].toStdString().c_str());
            if(this->network.GetLayersNumber() != 0)
            {
                ui->pB_UsunSiec->setEnabled(true);
                ui->pB_BudujSiec->setEnabled(false);
                ui->gB_TworzenieSieci->setEnabled(false);
            }
        }
        else
            DisplayWarning(NETWORK_NOT_LOADED);
    }


}

void MainWindow::on_pB_SaveNetwork_clicked()
{
    QFileDialog saveDialog;
    QStringList fileNames;
    saveDialog.setParent(this);
    //  The ability to choose both existing and non-existing files
    saveDialog.setFileMode(QFileDialog::AnyFile);
    //  The AcceptButton is Save button
    saveDialog.setAcceptMode(QFileDialog::AcceptSave);
    //  Show only .txt files
    saveDialog.setNameFilter("Network(*.txt)");
    //  Show detailed description of files
    saveDialog.setViewMode(QFileDialog::Detail);
    //  Set directory to C:/Users/Konrad/Desktop/
    saveDialog.setDirectory("C:/Users/Konrad/Desktop/");

    //  Show the save window and get the filename
    if (saveDialog.exec())
        fileNames = saveDialog.selectedFiles();

    if(!fileNames.isEmpty())
    {
        //  Save the network
        this->network.SaveNetwork(fileNames[0].toStdString());
    }
    else
        DisplayWarning(NETWORK_NOT_SAVED);
}

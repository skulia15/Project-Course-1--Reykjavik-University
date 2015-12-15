#include "addcomputerdialog.h"
#include "ui_addcomputerdialog.h"
#include "services/scientistservice.h"
#include "services/computerservice.h"
#include "utilities/utils.h"
#include "mainwindow.h"

AddComputerDialog::AddComputerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddComputerDialog)
{
    ui->setupUi(this);
}

AddComputerDialog::~AddComputerDialog()
{
    delete ui;
}

void AddComputerDialog::on_button_add_computer_box_clicked()
{
    ComputerService computerService;

    bool thereWasAnError = false;

    ui->label_error_computer_name->setText("");
    ui->label_error_computer_type->setText("");

    QString name = ui->Input_computer_name->text();
    QString yearBuilt = ui->input_year_built->text();
    QString computerType = ui->input_computer_type->text();

    if (name.isEmpty()){
        ui->label_error_computer_name->setText("The computer must have a name!");

        thereWasAnError = true;
    }

    if (computerType.isEmpty()){
        ui->label_error_computer_type->setText("The computer must have a type!");

        thereWasAnError = true;
    }

    if (thereWasAnError)
    {
        return;
    }

    bool success = computerService.addComputer(Computer(name.toStdString(), utils::intToComputerType(computerType.toInt()), yearBuilt.toInt()));


    if (success){
        ui->Input_computer_name->setText("");
        ui->input_computer_type->setText("");
        ui->input_year_built->setText("");
        this->done(0);
    }
    else{
        this->done(-1);
        // there was some error, tell the user
       qDebug() << QDate::currentDate();
    }
}

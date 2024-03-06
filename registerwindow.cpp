#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "welcomewindow.h"
#include "Users.h"
#include <QDate>

RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
        int currentYear = QDate::currentDate().year();

    for (int year = 1907; year <= currentYear; ++year) {
        ui->comboBoxYear->addItem(QString::number(year));
    }
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}
void RegisterWindow::handleRegisterButtonClicked() {
{
    ui->errorUsernameExists->setVisible(false);
    ui->errorPasswordMismatch->setVisible(false);
    ui->errorAgeTooYoung->setVisible(false);
    ui->errorMissingField->setVisible(false);

    QString enteredUsername = ui->lineEdit->text();
    QString enteredPassword = ui->lineEditPassword->text();
    QString retypePassword = ui->lineEditRetypePassword->text();
    QString selectedYear = ui->comboBoxYear->currentText();

    if (isUsernameExists(enteredUsername)) {
        ui->errorUsernameExists->setVisible(true);
    } else if (enteredPassword != retypePassword) {
        ui->errorPasswordMismatch->setVisible(true);
    } else {

        int currentYear = QDate::currentDate().year();
        int enteredYear = selectedYear.toInt();
        int age = currentYear - enteredYear;

        if (age < 12) {
            ui->errorAgeTooYoung->setVisible(true);
        } else {
            addUser(enteredUsername, enteredPassword, age);
            WelcomeWindow* welcomeWindow = new WelcomeWindow(this, enteredUsername, age);
            welcomeWindow->show();
        }
    }
}

}

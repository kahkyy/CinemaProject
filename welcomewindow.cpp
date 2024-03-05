#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include "loginwindow.h"

WelcomeWindow::WelcomeWindow(QWidget *parent, QString username, int age)
    : QDialog(parent)
    , ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);

    QString ageString = QString::number(age);
    QString helloText = "Hello " + username + " " + ageString;
    ui->hello_label->setText(helloText);
    QPixmap pix ("/Users/yahiaelbanhawy/Downloads/visiting-the-cinema-in-vietnam-2.jpg");
    int w = ui->image_label->width();
    int h = ui->image_label->height();
    ui->image_label->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

void WelcomeWindow::on_logout_label_clicked()
{
    hide();
    LoginWindow* loginWindow = new LoginWindow(this); // create the new window
    loginWindow->show(); //show the new window
}


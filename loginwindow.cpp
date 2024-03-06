#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "welcomewindow.h"
#include "Users.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->error_label->setVisible(false);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_login_push_button_clicked()
{
    QString enteredUsername = ui->username_line_edit->text();
    QString enteredPassword = ui->password_line_edit->text();

    bool x = false;
    bool y = false;

    for(int i = 0; i<=3; i++){
        if (enteredUsername != usernames[i]){
            continue;
        }
        else{
            x = true;
            break;
        }
    }

    for(int i = 0; i<=3; i++){
        if (enteredPassword != passwords[i]){
            continue;
        }
        else{
            y = true;
            break;
        }
    }

    if (x==true && y == true){
        hide(); // hide the current window
        WelcomeWindow* welcomewindow = new WelcomeWindow(this); // create the new window
        welcomewindow->show(); // show the new window
    }
    else{
        ui->error_label->setVisible(true);
    }
}


void LoginWindow::on_register_push_button_clicked()
{
    RegisterWindow *registerWindow = new RegisterWindow(this);
    registerWindow->show();
}


#include "LoginWindow.h"
#include <iostream>

LoginWindow::LoginWindow(Netflix* & netflix){

  this->netflix = netflix;

  mainLayout = new QVBoxLayout();
  buttonLayout = new QHBoxLayout();
  quitButton = new QPushButton("&Quit");
  loginButton = new QPushButton("&Login");
  newUserButton = new QPushButton("&New User");

  buttonLayout->addWidget(loginButton);
  buttonLayout->addWidget(quitButton);
  buttonLayout->addWidget(newUserButton);

  welcomeLabel = new QLabel("Welcome to 104Flix");
  mainLayout->addWidget(welcomeLabel);

  login = new QLineEdit();
  loginRow = new QFormLayout();
  loginRow->addRow("Login:", login);

  mainLayout->addLayout(loginRow);
  mainLayout->addLayout(buttonLayout);

  setLayout(mainLayout);

  QObject::connect(loginButton, SIGNAL(clicked()), this, SLOT(loginButtonClicked()));
  QObject::connect(quitButton, SIGNAL(clicked()), this, SLOT(quitButtonClicked()));
}

void LoginWindow::loginButtonClicked(){
  
  bool success = netflix->loginUser(login->text().toStdString());
  if(success){
    //user successfully logged in. Emit signal to open MainWindow
    emit userLoggedIn(netflix);
  } else {
    QMessageBox badUsernameMessage;
    badUsernameMessage.setText("That username does not exist. Please try again.");
    badUsernameMessage.exec();
  }

}

void LoginWindow::quitButtonClicked(){

  emit quit();

}

#include "LoginWindow.h"

LoginWindow::LoginWindow(){

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
}

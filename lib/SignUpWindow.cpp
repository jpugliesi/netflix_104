#include "SignUpWindow.h"

SignUpWindow::SignUpWindow(){

  netflix = NULL;
  mainLayout = new QVBoxLayout();
  
  welcomeSignIn = new QLabel("Please sign up for 104Flix");
  
  mainLayout->addWidget(welcomeSignIn);
  signUpForm = new QFormLayout();

  username = new QLineEdit();
  name = new QLineEdit();

  signUpForm->addRow("Login:", username);
  signUpForm->addRow("Name:", name);
  
  buttonLayout = new QHBoxLayout();
  confirmButton = new QPushButton("&Confirm");
  cancelButton = new QPushButton("Cancel");
  buttonLayout->addWidget(confirmButton);
  buttonLayout->addWidget(cancelButton);

  mainLayout->addLayout(signUpForm);
  mainLayout->addLayout(buttonLayout);

  setLayout(mainLayout);

  QObject::connect(confirmButton, SIGNAL(clicked()), this, SLOT(createUser()));
  QObject::connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));
  QObject::connect(cancelButton, SIGNAL(clicked()), this SLOT(cancel()));

}

void SignUpWindow::openSignUpWindow(Netflix* &netflix){

  this->netflix = netflix;
  this->show();

}

void SignUpWindow::createUser(){

  std::cout << "Creating a user" << std::endl;

}

void SignUpWindow::cancel(){

  this->close();
  emit cancelSignUp();

}

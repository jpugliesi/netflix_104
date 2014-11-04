#include "SignUpWindow.h"

SignUpWindow::SignUpWindow(){

  mainLayout = new QVBoxLayout();
  
  welcomeSignIn = new QLabel("Please sign up for 104Flix");
  
  mainLayout->add(welcomeSignIn);
  signUpForm = new QFormLayout();

  username = new QLineEdit();
  name = new QLineEdit();

  signUpForm->addRow("Login:", username);
  signUpForm->addRow("Name:", name);
  
  buttonLayout = new QHBoxLayout();
  confirm = new QPushButton("&Confirm");
  cancel = new QPushButton("Cancel");
  buttonLayout->addWidget(confirm);
  buttonLayout->addWidget(cancel);

  mainLayout->addLayout(signUpForm);
  mainLayout->addLayout(buttonLayout);

}

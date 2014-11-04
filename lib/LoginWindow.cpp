#include "LoginWindow.h"

LoginWindow::LoginWindow(){

  setGeometry(0, 0, 600, 600);

  mainLayout = new QVBoxLayout();
  buttonLayout = new QHBoxLayout();
  quitButton = new QPushButton("&Quit");
  loginButton = new QPushButton("&Login");
  newUserButton = new QPushButton("&New User");

}

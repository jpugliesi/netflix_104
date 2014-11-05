#include <QApplication>
#include <QObject>
#include "LoginWindow.h"
#include "SignUpWindow.h"
#include "MainWindow.h"
#include "Netflix.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

/*** Global file variable names ***/

int main(int argc, char ** argv){

  Netflix* netflix = new Netflix();
  //Check if user provides us with the main data file
  if (argc < 2){
    std::cout << "USAGE: " << argv[0] << " <MAIN_DATA_FILE>" << std::endl;
    return 1;
  }

  std::string input_file = argv[1];

  netflix->initializeData(input_file);

  QApplication app(argc, argv);

  LoginWindow loginWindow(netflix);
  SignUpWindow sw(netflix);
  MainWindow mw(netflix);

  //Upon successful login open the MainWindow
  QObject::connect(&loginWindow, SIGNAL(userLoggedIn()), &mw, SLOT(openMainWindow()));

  //Quit if quit button clicked
  QObject::connect(&loginWindow, SIGNAL(quit()), &app, SLOT(quit()));
  QObject::connect(&loginWindow, SIGNAL(createNewUser()), &sw, SLOT(openSignUpWindow()));
  QObject::connect(&sw, SIGNAL(cancelSignUp()), &loginWindow, SLOT(openLoginWindow()));
  QObject::connect(&sw, SIGNAL(userCreated(QString)), &loginWindow, SLOT(openLoginWindow(QString)));

  loginWindow.show();

  return app.exec();

}



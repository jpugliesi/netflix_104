#include <QApplication>
#include "LoginWindow.h"
#include "SignUpWindow.h"
#include "Netflix.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

/*** Global file variable names ***/

int main(int argc, char ** argv){

  Netflix netflix;
  //Check if user provides us with the main data file
  if (argc < 2){
    std::cout << "USAGE: " << argv[0] << " <MAIN_DATA_FILE>" << std::endl;
    return 1;
  }

  std::string input_file = argv[1];

  QApplication app(argc, argv);

  LoginWindow loginWindow;
  SignUpWindow sw;
  sw.show();
  loginWindow.show();

  return app.exec();

}



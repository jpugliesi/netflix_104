#ifndef LOGIN_WINDOW_H
#define LOGIN_WINDOW_H

#include <QtGui>
class LoginWindow : public QWidget{

  Q_OBJECT

  private:
    std::string username;
    QVBoxLayout * mainLayout;
    QHBoxLayout * buttonLayout;
    QPushButton * quitButton;
    QPushButton * loginButton;
    QPushButton * newUserButton;

    QLabel * welcomeLabel;
    QLineEdit * login;
    QFormLayout * loginRow;

  public:
    LoginWindow();

};

#endif

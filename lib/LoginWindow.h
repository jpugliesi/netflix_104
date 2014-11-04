#ifndef LOGIN_WINDOW_H
#define LOGIN_WINDOW_H

#include <QtGui>
#include <QObject>
#include "Netflix.h"
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

    Netflix* netflix;

  public:
    LoginWindow(Netflix* & netflix);

  private slots:
    void loginButtonClicked();

  signals:
    void userLoggedIn(Netflix* & netflix);
    
};

#endif

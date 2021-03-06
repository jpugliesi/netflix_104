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
    ~LoginWindow();


  private slots:
    void openLoginWindow();
    void openLoginWindow(QString);
    void loginButtonClicked();
    void quitButtonClicked();
    void newUserButtonClicked();

  public slots:
    void keyPressEvent(QKeyEvent *event);

  signals:
    void userLoggedIn();
    void quit();
    void createNewUser();
    
};

#endif

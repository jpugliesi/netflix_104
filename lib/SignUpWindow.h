#ifndef SIGN_UP_WINDOW_H
#define SIGN_UP_WINDOW_H

#include <QtGui>
class SignUpWindow : public QWidget{

  Q_OBJECT

  public:
    SignUpWindow();

  private:

    QLabel *welcomeSignIn;

    QLineEdit *username;
    QLineEdit *name;
    QFormLayout *signUpForm;
    
    QVBoxLayout *mainLayout;
    QHBoxLayout *buttonLayout;

    QPushButton *confirm;
    QPushButton *cancel;

};

#endif

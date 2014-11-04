#ifndef SIGN_UP_WINDOW_H
#define SIGN_UP_WINDOW_H

class SignUpWindow : public QWidget{

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

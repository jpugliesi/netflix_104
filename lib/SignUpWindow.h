#ifndef SIGN_UP_WINDOW_H
#define SIGN_UP_WINDOW_H

#include <QtGui>
#include <QObject>
#include "Netflix.h"
class SignUpWindow : public QWidget{

  Q_OBJECT

  public:
    SignUpWindow(Netflix* & netflix);

  private:

    QLabel *welcomeSignIn;

    QLineEdit *username;
    QLineEdit *name;
    QFormLayout *signUpForm;
    
    QVBoxLayout *mainLayout;
    QHBoxLayout *buttonLayout;

    QPushButton *confirmButton;
    QPushButton *cancelButton;

    Netflix* netflix;

  public slots:
    void openSignUpWindow();
    void keyPressEvent(QKeyEvent *event);

  private slots:
    void createUser();
    void cancel();

  signals:
    void cancelSignUp();
    void userCreated(QString);
};

#endif

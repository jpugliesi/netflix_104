#ifndef RATING_WINDOW_H
#define RATING_WINDOW_H

#include <QtGui>
#include "User.h"

class RatingWindow : public QWidget{

  Q_OBJECT
  
  public:
    RatingWindow(User* & user);
  private:

    User* user;
    
    QVBoxLayout* mainLayout;
    QVBoxLayout* radioLayout;
    QGroupBox* ratingGroup;

    QHBoxLayout* buttonLayout;
    QPushButton* submit;
    QPushButton* skip;

    QRadioButton* radio1;
    QRadioButton* radio2;
    QRadioButton* radio3;
    QRadioButton* radio4;
    QRadioButton* radio5;

    int getRating();
  private slots:
    void submitButtonClicked();
    void skipButtonClicked();

  signals:
    void closeWindow();

};

#endif

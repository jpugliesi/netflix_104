#ifndef BACON_GAME_WINDOW_H
#define BACON_GAME_WINDOW_H

#include <QtGui>
#include "Movie.h"
#include "Netflix.h"

class BaconGameWindow : public QWidget{

  Q_OBJECT
  public:
    BaconGameWindow(Netflix* netflix);

  private:
    QVBoxLayout* mainLayout;
    QLabel* distanceLabel;
    QPushButton* search;
    QPushButton* backToMain;

    QFormLayout* searchForm;
    QLineEdit* actor1Text;
    QLineEdit* actor2Text;

    Netflix* netflix;

  private slots:
    void searchClicked();
    void backToMainButtonClicked();

};

#endif

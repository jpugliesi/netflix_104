#ifndef RECOMMENDATON_WINDOW_H
#define RECOMMENDATON_WINDOW_H

#include <QtGui>
#include "Movie.h"
#include "Netflix.h"

class RecommendationWindow : public QWidget{

  Q_OBJECT
  public:
    RecommendationWindow(Netflix*, Movie*);

  private:
    QLabel* recommendation;
    QVBoxLayout* mainLayout;
    QHBoxLayout* buttonLayout;
    QPushButton* addToQueue;
    QPushButton* skip;

    Netflix* netflix;
    Movie* recommended_movie;

  private slots:
    void addToQueueClicked();
    void closeWindow();

  signals:
    void closedWindow();

};

#endif

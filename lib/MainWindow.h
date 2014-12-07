#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QObject>
#include "Netflix.h"
#include "RatingWindow.h"
#include "SearchResultsWindow.h"
#include "RecommendationWindow.h"

class MainWindow : public QWidget{

  Q_OBJECT

  public:
    MainWindow(Netflix* & netflix);

  private:

    Netflix* netflix;
    
    QVBoxLayout *mainLayout;
    QLabel *welcomeLabel;

    QVBoxLayout *movieVBox;
    QGroupBox *currentMovieGroup;
    QLabel *currentMovieLabel;

    QVBoxLayout *queueVBox;
    QGroupBox *movieQueueGroup;
    QLabel *topOfQueue;

    QVBoxLayout *searchVBox;
    QGroupBox *searchMovieGroup;
    QFormLayout *searchForm;
    QLineEdit *searchText;
    
    QPushButton *returnMovieButton;
    QPushButton *rentMovieButton;
    QPushButton *removeFromQueueButton;
    QPushButton *moveToBackOfQueueButton;
    QPushButton *searchByTitleButton;
    QPushButton *searchByKeywordButton;
    QPushButton *logoutButton;

    SearchResultsWindow* searchWindow;
    RatingWindow* ratingWindow;
    RecommendationWindow* recommendationWindow;

  public slots:
    void openMainWindow();
    void keyPressEvent(QKeyEvent *event);

  private slots:

    void returnMovieButtonClicked();

    void rentMovieButtonClicked();
    void removeFromQueueButtonClicked();
    void moveToBackOfQueueButtonClicked();
    void updateTopOfQueue();
    void updateCurrentMovie();

    void searchByTitleButtonClicked();
    void searchByKeywordButtonClicked();
    void logoutButtonClicked();

    void closeSearchWindow();
    void closeRatingWindow();
    void closeRecommendationWindow();
  signals:
    void logout();
};

#endif

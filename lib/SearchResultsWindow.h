#ifndef SEARCH_RESULTS_WINDOW_H
#define SEARCH_RESULTS_WINDOW_H

#include <QtGui>
#include <vector>
#include <string>
#include "Netflix.h"
#include "Set.h"
#include "Movie.h"
class SearchResultsWindow : public QWidget{

  Q_OBJECT

  public:
    SearchResultsWindow(Netflix* & netflix, std::string search_string, bool title);

  private:
    QVBoxLayout *mainLayout;

    QLabel* movieTitle;
    QGroupBox *keywordsGroup;

    QVBoxLayout* keywordsVBox;
    QHBoxLayout* buttonLayout; 
    QPushButton* nextMovieButton;
    QPushButton* addToQueueButton;
    QPushButton* returnToMainButton;

    Netflix* netflix;
    Set<Movie*>* searchSet;

    std::vector<QLabel*> labelSet;
    Set<Movie*>::Iterator movieIt;
    Set<std::string>::Iterator keywordsIt;

  private slots:
    void returnToMainButtonClicked();
    void nextMovieButtonClicked();
    void addToQueueButtonClicked();

  signals:
    void closeWindow();
    
};

#endif

#ifndef SEARCH_RESULTS_WINDOW_H
#define SEARCH_RESULTS_WINDOW_H

#include <QtGui>
#include <vector>
#include <string>
#include <set>
#include "Netflix.h"
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
    std::set<Movie*> searchSet;

    std::vector<QLabel*> labelSet;
    std::set<Movie*>::iterator movieIt;
    std::set<std::string>::iterator keywordsIt;

  private slots:
    void returnToMainButtonClicked();
    void nextMovieButtonClicked();
    void addToQueueButtonClicked();

  signals:
    void closeWindow();
    
};

#endif

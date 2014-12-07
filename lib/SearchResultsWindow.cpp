#include "SearchResultsWindow.h"
#include <QObject>
#include <iostream>

SearchResultsWindow::SearchResultsWindow(Netflix* & netflix, std::set<Movie*> & s_set){

  this->netflix = netflix;

  
  mainLayout = new QVBoxLayout();
  movieTitle = new QLabel("No results");
  
  keywordsGroup = new QGroupBox("Movie Info");
  keywordsVBox = new QVBoxLayout();

  buttonLayout = new QHBoxLayout();
  nextMovieButton = new QPushButton("&Next Movie");
  addToQueueButton = new QPushButton("&Add to my Queue");
  returnToMainButton = new QPushButton("&Return to Main");

  //Add keywords here
  searchSet = s_set;

  if(searchSet.size() != 0){
    //set movie title add keywords to the screen
    movieIt = searchSet.begin();
    if(movieIt != searchSet.end()){
      Movie* firstMovie = *movieIt;
      //set title
      movieTitle->setText(QString::fromStdString(firstMovie->getTitle()));
      std::set<std::string> keywords = firstMovie->getAllKeywords();
      for(keywordsIt = keywords.begin(); keywordsIt != keywords.end(); ++keywordsIt){
        labelSet.push_back(new QLabel(QString::fromStdString((*keywordsIt))));
      }
      std::set<Movie*>::iterator nextMovieIt = movieIt;
      ++nextMovieIt;
      if(nextMovieIt == searchSet.end()){
        //disable buttons if no more movies to iterate through
	nextMovieButton->setEnabled(false);
      }
    }
    //need to check if there is another item to iterate, and disable buttons appropriately
  } else {
    labelSet.push_back(new QLabel("0 results found"));
    nextMovieButton->setEnabled(false);
    addToQueueButton->setEnabled(false);
  }
  //for loop to add keywords as QLabel s
  for(int i = 0; i < labelSet.size(); i++){
    keywordsVBox->addWidget(labelSet.at(i));
  }
  keywordsGroup->setLayout(keywordsVBox);

  

  QObject::connect(returnToMainButton, SIGNAL(clicked()), this, SLOT(returnToMainButtonClicked()));
  QObject::connect(addToQueueButton, SIGNAL(clicked()), this, SLOT(addToQueueButtonClicked()));
  QObject::connect(nextMovieButton, SIGNAL(clicked()), this, SLOT(nextMovieButtonClicked()));

  

  buttonLayout->addWidget(nextMovieButton);
  buttonLayout->addWidget(addToQueueButton);
  buttonLayout->addWidget(returnToMainButton);

  mainLayout->addWidget(movieTitle);
  mainLayout->addWidget(keywordsGroup);
  mainLayout->addLayout(buttonLayout);

  setLayout(mainLayout);
  this->show();

}

void SearchResultsWindow::returnToMainButtonClicked(){

  this->close();
  emit closeWindow();

}

void SearchResultsWindow::nextMovieButtonClicked(){

  for(int i = 0; i < labelSet.size(); i++){
    keywordsVBox->removeWidget(labelSet.at(i));
    delete labelSet.at(i);
  }
  labelSet.clear();

  if(movieIt != searchSet.end()){
    ++movieIt;
    Movie* firstMovie = *movieIt;
    //set title
    movieTitle->setText(QString::fromStdString(firstMovie->getTitle()));
    std::set<std::string> keywords = firstMovie->getAllKeywords();
    for(keywordsIt = keywords.begin(); keywordsIt != keywords.end(); ++keywordsIt){
      labelSet.push_back(new QLabel(QString::fromStdString((*keywordsIt))));
    }
    std::set<Movie*>::iterator nextMovieIt = movieIt;
    ++nextMovieIt;
    if(nextMovieIt == searchSet.end()){
      //disable buttons if no more movies to iterate through
      nextMovieButton->setEnabled(false);
    }
  }
  //for loop to add keywords as QLabel s
  for(int i = 0; i < labelSet.size(); i++){
    keywordsVBox->addWidget(labelSet.at(i));
  }
  keywordsGroup->setLayout(keywordsVBox);
}

void SearchResultsWindow::addToQueueButtonClicked(){

  std::queue<Movie*>* users_queue = netflix->getCurrentUser()->movieQueue();
  users_queue->push((*movieIt));

}

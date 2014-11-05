#include "SearchResultsWindow.h"
#include <QObject>

SearchResultsWindow::SearchResultsWindow(Set<Movie*>* & searchMovies){

  searchSet = searchMovies;

  mainLayout = new QVBoxLayout();
  movieTitle = new QLabel("The Princess Bride");
  
  keywordsGroup = new QGroupBox("Movie Info");
  keywordsVBox = new QVBoxLayout();
  //Add keywords here
  keywordsGroup->setLayout(keywordsVBox);

  //for loop to add keywords as QLabel s
  
  buttonLayout = new QHBoxLayout();
  nextMovieButton = new QPushButton("&Next Movie");
  addToQueueButton = new QPushButton("&Add to my Queue");
  returnToMainButton = new QPushButton("&Return to Main");

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

  

}

void SearchResultsWindow::addToQueueButtonClicked(){

}

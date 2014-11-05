#include "SearchResultsWindow.h"
#include <QObject>

SearchResultsWindow::SearchResultsWindow(Set<Movie*>* & searchMovies){

  searchSet = searchMovies;

  //add keywords to the screen
  movieIt = searchSet->begin();
  if(movieIt != searchSet->end()){
    Movie* firstMovie = *(movieIt);
    Set<std::string> keywords = firstMovie->getAllKeywords();
    Set<std::string>::Iterator keywordsIt;
    for(keywordsIt = keywords.begin(); keywordsIt != keywords.end(); ++keywordsIt){
      labelSet.push_back(new QLabel(QString::fromStdString((*keywordsIt))));
    }
  }
  
  mainLayout = new QVBoxLayout();
  movieTitle = new QLabel("The Princess Bride");
  
  keywordsGroup = new QGroupBox("Movie Info");
  keywordsVBox = new QVBoxLayout();
  //Add keywords here
  for(int i = 0; i < labelSet.size(); i++){
    keywordsVBox->addWidget(labelSet.at(i));
  }
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

#include "SearchResultsWindow.h"
#include <QObject>

SearchResultsWindow::SearchResultsWindow(Netflix* & netflix, std::string search_string, bool title){

  this->netflix = netflix;

  if(title){
    searchSet = netflix->searchMoviesByTitle(search_string);
  } else {
    searchSet = netflix->searchMoviesByKeyword(search_string);
  }

  if(searchSet != NULL && searchSet->size() != 0){
    //add keywords to the screen
    movieIt = searchSet->begin();
    if(movieIt != searchSet->end()){
      Movie* firstMovie = *movieIt;
      std::cout << firstMovie->getTitle() << std::endl;
      Set<std::string> keywords = firstMovie->getAllKeywords();
      for(keywordsIt = keywords.begin(); keywordsIt != keywords.end(); ++keywordsIt){
        labelSet.push_back(new QLabel(QString::fromStdString((*keywordsIt))));
      }
    }
  } else {
    labelSet.push_back(new QLabel("0 results found"));
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

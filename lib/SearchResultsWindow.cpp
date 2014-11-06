#include "SearchResultsWindow.h"
#include <QObject>

SearchResultsWindow::SearchResultsWindow(Netflix* & netflix, std::string search_string, bool title){

  this->netflix = netflix;

  
  mainLayout = new QVBoxLayout();
  movieTitle = new QLabel("The Princess Bride");
  
  keywordsGroup = new QGroupBox("Movie Info");
  keywordsVBox = new QVBoxLayout();

  buttonLayout = new QHBoxLayout();
  nextMovieButton = new QPushButton("&Next Movie");
  addToQueueButton = new QPushButton("&Add to my Queue");
  returnToMainButton = new QPushButton("&Return to Main");

  //Add keywords here
  if(title){
    searchSet = netflix->searchMoviesByTitle(search_string);
    std::cerr << "Search Set size in Window: " << searchSet.size() << std::endl;
  } else {
    searchSet = netflix->searchMoviesByKeyword(search_string);
    std::cerr << "Search Set size in Window: " << searchSet.size() << std::endl;
  }

  if(searchSet.size() != 0){
    //set movie title add keywords to the screen
    movieIt = searchSet.begin();
    if(movieIt != searchSet.end()){
      Movie* firstMovie = *movieIt;
      //set title
      movieTitle->setText(QString::fromStdString(firstMovie->getTitle()));
      Set<std::string> keywords = firstMovie->getAllKeywords();
      for(keywordsIt = keywords.begin(); keywordsIt != keywords.end(); ++keywordsIt){
        labelSet.push_back(new QLabel(QString::fromStdString((*keywordsIt))));
      }
      Set<Movie*>::Iterator nextMovieIt = movieIt;
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
    Set<std::string> keywords = firstMovie->getAllKeywords();
    for(keywordsIt = keywords.begin(); keywordsIt != keywords.end(); ++keywordsIt){
      labelSet.push_back(new QLabel(QString::fromStdString((*keywordsIt))));
    }
    Set<Movie*>::Iterator nextMovieIt = movieIt;
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

}

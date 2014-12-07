#include "MainWindow.h"
#include "SearchResultsWindow.h"
#include "User.h"
#include <iostream>

MainWindow::MainWindow(Netflix* & netflix){

  this->netflix = netflix;

  mainLayout = new QVBoxLayout();
  movieVBox = new QVBoxLayout();
  queueVBox = new QVBoxLayout();
  searchVBox = new QVBoxLayout();

  searchWindow = NULL;
  ratingWindow = NULL;

  QString name;
  User* currentUser = netflix->getCurrentUser();
  if(currentUser != NULL){
    name = QString::fromStdString(netflix->getCurrentUser()->getName());
  } else {
    name = "Nobody";
  }
  welcomeLabel = new QLabel("Welcome to CS104-Flix, " + name);

  currentMovieGroup = new QGroupBox("Your Current Movie");
  currentMovieLabel = new QLabel("Citizen Kane");
  returnMovieButton = new QPushButton("&Return Movie");
  movieVBox->addWidget(currentMovieLabel);
  movieVBox->addWidget(returnMovieButton);
  currentMovieGroup->setLayout(movieVBox);

  QObject::connect(returnMovieButton, SIGNAL(clicked()), this, SLOT(returnMovieButtonClicked()));

  movieQueueGroup = new QGroupBox("Your Movie Queue");
  topOfQueue = new QLabel("Front of Queue: Modern Times");
  rentMovieButton = new QPushButton("R&ent Movie");
  removeFromQueueButton = new QPushButton("&Delete from Queue");
  moveToBackOfQueueButton = new QPushButton("Move to Back of Queue");
  queueVBox->addWidget(topOfQueue);
  queueVBox->addWidget(rentMovieButton);
  queueVBox->addWidget(removeFromQueueButton);
  queueVBox->addWidget(moveToBackOfQueueButton);
  movieQueueGroup->setLayout(queueVBox);

  QObject::connect(rentMovieButton, SIGNAL(clicked()), this, SLOT(rentMovieButtonClicked()));
  QObject::connect(removeFromQueueButton, SIGNAL(clicked()), this, SLOT(removeFromQueueButtonClicked()));
  QObject::connect(moveToBackOfQueueButton, SIGNAL(clicked()), this, SLOT(moveToBackOfQueueButtonClicked()));

  searchMovieGroup = new QGroupBox("Search for Movies");
  searchForm = new QFormLayout();
  searchText = new QLineEdit();
  searchForm->addRow("&Search:", searchText);
  searchByTitleButton = new QPushButton("Search by Title");
  searchByKeywordButton = new QPushButton("Search by Keyword");
  searchByActorButton = new QPushButton("Search by Actor");
  searchVBox->addLayout(searchForm);
  searchVBox->addWidget(searchByTitleButton);
  searchVBox->addWidget(searchByKeywordButton);
  searchVBox->addWidget(searchByActorButton);
  searchMovieGroup->setLayout(searchVBox);

  QObject::connect(searchByTitleButton, SIGNAL(clicked()), this, SLOT(searchByTitleButtonClicked()));
  QObject::connect(searchByKeywordButton, SIGNAL(clicked()), this, SLOT(searchByKeywordButtonClicked()));
  QObject::connect(searchByActorButton, SIGNAL(clicked()), this, SLOT(searchByActorButtonClicked()));

  baconGameButton = new QPushButton("Play the Bacon Game");
  QObject::connect(baconGameButton, SIGNAL(clicked()), this, SLOT(baconGameButtonClicked()));

  logoutButton = new QPushButton("Logout");
  QObject::connect(logoutButton, SIGNAL(clicked()), this, SLOT(logoutButtonClicked()));

  mainLayout->addWidget(welcomeLabel);
  mainLayout->addWidget(currentMovieGroup);
  mainLayout->addWidget(movieQueueGroup);
  mainLayout->addWidget(searchMovieGroup);
  mainLayout->addWidget(baconGameButton);
  mainLayout->addWidget(logoutButton);

  setLayout(mainLayout);
}

void MainWindow::openMainWindow(){
  QString name;
  User* currentUser = netflix->getCurrentUser();
  if(currentUser != NULL){
    name = QString::fromStdString(netflix->getCurrentUser()->getName());
  } else {
    name = "Nobody";
  }
  welcomeLabel->setText("Welcome to CS104-Flix, " + name);

  this->show();

  recommendationWindow = new RecommendationWindow(netflix, netflix->getMostInterestingMovie());
  QObject::connect(recommendationWindow, SIGNAL(closedWindow()), this, SLOT(closeRecommendationWindow()));

  updateTopOfQueue();
  updateCurrentMovie();

}

void MainWindow::baconGameButtonClicked(){

 baconGameWindow = new BaconGameWindow(netflix); 

}
void MainWindow::returnMovieButtonClicked(){

  User* currentUser = netflix->getCurrentUser();
  //Ratings
  if(currentUser->currentMovie() != NULL){
    this->hide();
    //std::map<Movie*, int>* users_ratings = currentUser->movieRatings();

    ratingWindow = new RatingWindow(currentUser, currentUser->currentMovie());
    QObject::connect(ratingWindow, SIGNAL(closeWindow()), this, SLOT(closeRatingWindow()));
  }

  currentUser->returnMovie();
  updateCurrentMovie();

}
void MainWindow::updateTopOfQueue(){
  Movie* topMovie = netflix->getTopOfQueue();
  if(topMovie != NULL){
    std::string topOfQueueTitle = topMovie->getTitle();
    QString title = QString::fromStdString(topOfQueueTitle);
    topOfQueue->setText(title);
  } else {
    topOfQueue->setText("Empty");
  }
  
}

void MainWindow::updateCurrentMovie(){

  Movie* c_movie = netflix->getCurrentMovie();
  if(c_movie != NULL){
    std::cerr << netflix->getCurrentUser()->getName() << " has a movie " << netflix->getCurrentMovie() << std::endl;
    std::string c_movie_title = c_movie->getTitle();
    QString title = QString::fromStdString(c_movie_title);
    currentMovieLabel->setText(title);
  } else {
    std::cerr << netflix->getCurrentUser()->getName() << " does not have a movie" << std::endl;
    currentMovieLabel->setText("None");
  }
  
}
void MainWindow::rentMovieButtonClicked(){

  int result = netflix->orderTopOfQueue();
  if(result == 1){
      updateCurrentMovie();
      updateTopOfQueue();
  } else if(result == 0){
    QMessageBox noMovies;
    noMovies.setText("You have no movies in your queue to rent.");
    noMovies.exec();
  } else {
    QMessageBox noMovies;
    noMovies.setText("You cannot order a new movie until you return the current one.");
    noMovies.exec();
  }

}

void MainWindow::removeFromQueueButtonClicked(){

  int result = netflix->removeTopOfQueue();
  if(result == 0){
    QMessageBox noMovies;
    noMovies.setText("You have no movies to remove.");
    noMovies.exec();
  }
  updateTopOfQueue();

}

void MainWindow::moveToBackOfQueueButtonClicked(){

  int result = netflix->moveToBackOfQueue();
  if(result == 0){
    QMessageBox noMovies;
    noMovies.setText("You have no movies to move.");
    noMovies.exec();
  }
  updateTopOfQueue();

}   

void MainWindow::searchByTitleButtonClicked(){

  std::string search_string = searchText->text().toStdString();
  std::set<Movie*> searchSet = netflix->searchMoviesByTitle(search_string);
  searchWindow = new SearchResultsWindow(netflix, searchSet);
  QObject::connect(searchWindow, SIGNAL(closeWindow()), this, SLOT(closeSearchWindow()));
  this->hide();

}
void MainWindow::searchByKeywordButtonClicked(){

  std::string search_string = searchText->text().toStdString();
  std::set<Movie*> searchSet = netflix->searchMoviesByKeyword(search_string);
  searchWindow = new SearchResultsWindow(netflix, searchSet);
  QObject::connect(searchWindow, SIGNAL(closeWindow()), this, SLOT(closeSearchWindow()));
  this->hide();
}

void MainWindow::searchByActorButtonClicked(){

  std::string search_string = searchText->text().toStdString();
  std::set<Movie*> searchSet = netflix->searchMoviesByActor(search_string);
  searchWindow = new SearchResultsWindow(netflix, searchSet);
  QObject::connect(searchWindow, SIGNAL(closeWindow()), this, SLOT(closeSearchWindow()));
  this->hide();

}

void MainWindow::logoutButtonClicked(){
  netflix->logoutCurrentUser();
  emit logout();
  this->close();

}

void MainWindow::closeSearchWindow(){

  delete searchWindow;
  searchWindow = NULL;
  updateCurrentMovie();
  updateTopOfQueue();
  this->show();

}

void MainWindow::closeRatingWindow(){

  delete ratingWindow;
  ratingWindow = NULL;
  this->show();
}

void MainWindow::closeRecommendationWindow(){
  delete recommendationWindow;
  recommendationWindow = NULL;
  updateCurrentMovie();
  updateTopOfQueue();
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_Return){
        searchByTitleButtonClicked();
    }
}

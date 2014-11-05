#include "MainWindow.h"

MainWindow::MainWindow(Netflix* & netflix){

  this->netflix = netflix;

  mainLayout = new QVBoxLayout();
  movieVBox = new QVBoxLayout();
  queueVBox = new QVBoxLayout();
  searchVBox = new QVBoxLayout();

  welcomeLabel = new QLabel("Welcome to CS104-Flix, John");

  currentMovieGroup = new QGroupBox("Your Current Movie");
  currentMovie = new QLabel("Citizen Kane");
  returnMovieButton = new QPushButton("&Return Movie");
  movieVBox->addWidget(currentMovie);
  movieVBox->addWidget(returnMovieButton);
  currentMovieGroup->setLayout(movieVBox);

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

  searchMovieGroup = new QGroupBox("Search for Movies");
  searchForm = new QFormLayout();
  searchText = new QLineEdit();
  searchForm->addRow("&Search:", searchText);
  searchByTitleButton = new QPushButton("Search by Title");
  searchByKeywordButton = new QPushButton("Search by Keyword");
  searchVBox->addLayout(searchForm);
  searchVBox->addWidget(searchByTitleButton);
  searchVBox->addWidget(searchByKeywordButton);
  searchMovieGroup->setLayout(searchVBox);

  logoutButton = new QPushButton("Logout");

  mainLayout->addWidget(welcomeLabel);
  mainLayout->addWidget(currentMovieGroup);
  mainLayout->addWidget(movieQueueGroup);
  mainLayout->addWidget(searchMovieGroup);
  mainLayout->addWidget(logoutButton);

  setLayout(mainLayout);
}

void MainWindow::openMainWindow(){
  this->show();
}

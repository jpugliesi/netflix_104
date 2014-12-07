#include "RecommendationWindow.h"

RecommendationWindow::RecommendationWindow(Netflix* netflix, Movie* movie){

  this->netflix = netflix;
  this->recommended_movie = movie;


  mainLayout = new QVBoxLayout();
  buttonLayout = new QHBoxLayout();

  addToQueue = new QPushButton("Cool, Add it to My Queue");
   
  if(recommended_movie != NULL){
    recommendation = new QLabel(QString::fromStdString("We think you might like" + recommended_movie->getTitle() + "."));
    skip = new QPushButton("No thanks");
  } else {
    recommendation = new QLabel("No more movies to recommended...");
    addToQueue->setEnabled(false);
    skip = new QPushButton("Exit");
  }
  buttonLayout->addWidget(addToQueue);
  buttonLayout->addWidget(skip);

  QObject::connect(addToQueue, SIGNAL(clicked()), this, SLOT(addToQueueClicked()));
  QObject::connect(skip, SIGNAL(clicked()), this, SLOT(closeWindow()));

  mainLayout->addWidget(recommendation);
  mainLayout->addLayout(buttonLayout);

  setLayout(mainLayout);

  this->show();
}

void RecommendationWindow::addToQueueClicked(){
  std::queue<Movie*>* users_queue = netflix->getCurrentUser()->movieQueue();
  users_queue->push(recommended_movie);
  closeWindow();
}

void RecommendationWindow::closeWindow(){
  this->close();
  emit closedWindow();
}

#include "RatingWindow.h"
#include "Movie.h"
#include <QObject>
#include <iostream>
#include <sstream>

RatingWindow::RatingWindow(User* & user, Movie* current_movie){

  this->user = user;
  this->current_movie = current_movie;
  QString title = QString::fromStdString(current_movie->getTitle());
  
  mainLayout = new QVBoxLayout();
  radioLayout = new QVBoxLayout();
  buttonLayout = new QHBoxLayout();
  
  ratingGroup = new QGroupBox(title);

  radio1 = new QRadioButton("1 - Very Bad");
  radio2 = new QRadioButton("2 - Pretty Bad");
  radio3 = new QRadioButton("3 - Average");
  radio4 = new QRadioButton("4 - Good");
  radio5 = new QRadioButton("5 - Very Good");

  radioLayout->addWidget(radio1);
  radioLayout->addWidget(radio2);
  radioLayout->addWidget(radio3);
  radioLayout->addWidget(radio4);
  radioLayout->addWidget(radio5);

  ratingGroup->setLayout(radioLayout);

  submit = new QPushButton("Submit");
  skip = new QPushButton("Skip");

  QObject::connect(submit, SIGNAL(clicked()), this, SLOT(submitButtonClicked()));
  QObject::connect(skip, SIGNAL(clicked()), this, SLOT(skipButtonClicked()));

  buttonLayout->addWidget(submit);
  buttonLayout->addWidget(skip);

  mainLayout->addWidget(ratingGroup);
  mainLayout->addLayout(buttonLayout);

  this->setLayout(mainLayout);

  //select radio button if rating exists
  std::map<Movie*, int>* movie_ratings = user->movieRatings();
  std::map<Movie*, int>::iterator ratings_it = movie_ratings->find(current_movie);

  if(ratings_it != movie_ratings->end()){
    //found a rating for this movie
    if(ratings_it->second == 1){
      radio1->setChecked(true);
    } else if(ratings_it->second == 2){
      radio2->setChecked(true);
    } else if(ratings_it->second == 3){
      radio3->setChecked(true);
    } else if(ratings_it->second == 4){
      radio4->setChecked(true);
    } else if(ratings_it->second == 5){
      radio5->setChecked(true);
    }
  } else {
    //movie hasn't been rated
  }

  this->show();
  
}

int RatingWindow::getRating(){
  if(radio1->isChecked()){
    return 1;
  } else if(radio2->isChecked()){
    return 2;
  } else if(radio3->isChecked()){
    return 3;
  } else if(radio4->isChecked()){
    return 4;
  } else if(radio5->isChecked()){
    return 5;
  } else {
    return 0;
  }
}

void RatingWindow::submitButtonClicked(){
  int rating_val = getRating();
  std::cerr << "RATING VAL IS: " << rating_val << std::endl;
  if(rating_val != 0){
    //user supplied rating
    if(current_movie != NULL){
      //update the rating value
      std::map<Movie*, int>* movie_ratings = user->movieRatings();
      std::map<Movie*, int>::iterator ratings_it = movie_ratings->find(current_movie);
      std::cerr << "Rating exists for Current movie: " << current_movie << " (" << current_movie->getTitle() << std::endl;
      if(ratings_it != movie_ratings->end()){
        movie_ratings->at(current_movie) = rating_val;
      } else {
        std::pair<Movie*, int> new_rating;
        new_rating.first = current_movie;
        new_rating.second = rating_val;
	std::stringstream ss;
	std::string r;
	ss << rating_val;
	ss >> r;
	std::cerr << "Adding rating for " << current_movie << " (" << current_movie->getTitle() << ") of " << r << std::endl; 
        movie_ratings->insert(new_rating);
      }
    }
    this->close();
    emit closeWindow();

  } else {
    QMessageBox msgBox;
    msgBox.setText("You did not supply a rating.");
    msgBox.exec();
  }
}

void RatingWindow::skipButtonClicked(){

  this->close();
  emit closeWindow();
}

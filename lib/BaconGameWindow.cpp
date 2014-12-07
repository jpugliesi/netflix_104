#include "BaconGameWindow.h"

BaconGameWindow::BaconGameWindow(Netflix* netflix){

  this->netflix = netflix;

  mainLayout = new QVBoxLayout();

  searchForm = new QFormLayout();
  actor1Text = new QLineEdit();
  actor2Text = new QLineEdit();

  searchForm->addRow("Main Actor", actor1Text);
  searchForm->addRow("Second Actor", actor2Text);

  search = new QPushButton("Get Bacon Distance");
  backToMain = new QPushButton("Exit");

  distanceLabel = new QLabel("");

  QObject::connect(search, SIGNAL(clicked()), this, SLOT(searchClicked()));
  QObject::connect(backToMain, SIGNAL(clicked()), this, SLOT(backToMainButtonClicked()));

  mainLayout->addLayout(searchForm);
  mainLayout->addWidget(distanceLabel);
  mainLayout->addWidget(search);
  mainLayout->addWidget(backToMain);

  setLayout(mainLayout);
  this->show();

}

void BaconGameWindow::backToMainButtonClicked(){

  this->close();

}

void BaconGameWindow::searchClicked(){

  std::string a1 = actor1Text->text().toStdString();
  std::string a2 = actor2Text->text().toStdString();

  for(int i = 0; a1[i]; i++) a1[i] = tolower(a1[i]);
  for(int i = 0; a2[i]; i++) a2[i] = tolower(a2[i]);

  Actor* main_actor = netflix->searchActors(a1);  
  Actor* second_actor = netflix->searchActors(a2);

  if(main_actor == NULL || second_actor == NULL){
    distanceLabel->setText("One of the actors doesn't exist in the database..."); 
  } else {

    int bacon_distance = netflix->calculateBaconDistance(main_actor, second_actor);
    if(bacon_distance == 0){

      distanceLabel->setText("These actors don't have a Bacon Distance...");

    } else {
      QString d = QString::number(bacon_distance);
      QString s = QString::fromStdString(main_actor->getName() + " and " + second_actor->getName() + " have a Bacon Distance of ");
      QString c = s + d;
      distanceLabel->setText(c);

    }

  }

}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QObject>
#include "Netflix.h"
class MainWindow : public QWidget{

  Q_OBJECT

  public:
    MainWindow(Netflix* & netflix);

  private:

    Netflix* netflix;
    
    QVBoxLayout *mainLayout;
    QLabel *welcomeLabel;

    QVBoxLayout *movieVBox;
    QGroupBox *currentMovieGroup;
    QLabel *currentMovie;

    QVBoxLayout *queueVBox;
    QGroupBox *movieQueueGroup;
    QLabel *topOfQueue;

    QVBoxLayout *searchVBox;
    QGroupBox *searchMovieGroup;
    QFormLayout *searchForm;
    QLineEdit *searchText;
    
    QPushButton *returnMovieButton;
    QPushButton *rentMovieButton;
    QPushButton *removeFromQueueButton;
    QPushButton *moveToBackOfQueueButton;
    QPushButton *searchByTitleButton;
    QPushButton *searchByKeywordButton;
    QPushButton *logoutButton;

  public slots:
    void openMainWindow();
};

#endif

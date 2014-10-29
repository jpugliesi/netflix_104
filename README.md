# CS 104 Project Repository

- **Name**: John Pugliesi
- **USC ID**: 2623486095
- **Email**: pugliesi@usc.edu

# Project Structure

* **Makefile** - The makefile with rules for compiling the source code.
* **data/** - A directory containing sample data files for the movie application. Add the three data files to this directory and specify the master data file upon running the application.
* **lib/** - Contains all of the source include headers and implementation files for the Map, Set, User, Movie classes.
* **obj/ (Created upon make)** - Contains all of the generated object (.o) files upon compilation.
* **bin/ (Created upon make)** - Contains the application's executable, called `project`.
* **log.md** - A very simple log file for me to keep track of how a project performs in terms of memory leaks.
* **main.cpp** - The main cpp file for running the movie application.

# Compiling the Project

To compile the project, change into the project's main directory and run:
```
make
```

# Running the Application

The executable for the compiled application is located in the bin folder. To run the project, use something like:
```
bin/project data/data.dat
```
where data/data.dat is the main data file parameter upon which to run the movie application

# Running the Tests

The GTests can be run with the command:
```
make tests
```

#############################################################################
# Makefile for building: project_pugliesi
# Generated by qmake (2.01a) (Qt 4.8.1) on: Fri Dec 5 14:24:09 2014
# Project:  project_pugliesi.pro
# Template: app
# Command: /usr/bin/qmake -o Makefile project_pugliesi.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -Ilib -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		lib/LoginWindow.cpp \
		lib/MainWindow.cpp \
		lib/Movie.cpp \
		lib/Netflix.cpp \
		lib/RatingWindow.cpp \
		lib/SearchResultsWindow.cpp \
		lib/SignUpWindow.cpp \
		lib/User.cpp moc_LoginWindow.cpp \
		moc_MainWindow.cpp \
		moc_RatingWindow.cpp \
		moc_SearchResultsWindow.cpp \
		moc_SignUpWindow.cpp
OBJECTS       = main.o \
		LoginWindow.o \
		MainWindow.o \
		Movie.o \
		Netflix.o \
		RatingWindow.o \
		SearchResultsWindow.o \
		SignUpWindow.o \
		User.o \
		moc_LoginWindow.o \
		moc_MainWindow.o \
		moc_RatingWindow.o \
		moc_SearchResultsWindow.o \
		moc_SignUpWindow.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		project_pugliesi.pro
QMAKE_TARGET  = project_pugliesi
DESTDIR       = 
TARGET        = project_pugliesi

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: project_pugliesi.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -o Makefile project_pugliesi.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile project_pugliesi.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/project_pugliesi1.0.0 || $(MKDIR) .tmp/project_pugliesi1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/project_pugliesi1.0.0/ && $(COPY_FILE) --parents lib/EmptyQueueException.h lib/LoginWindow.h lib/MainWindow.h lib/Map.h lib/MapImpl.h lib/MergeSort.h lib/MergeSortImpl.h lib/Movie.h lib/Netflix.h lib/Node.h lib/NodeImp.h lib/NoSuchElementException.h lib/Pair.h lib/Queue.h lib/QueueImpl.h lib/RatingWindow.h lib/SearchResultsWindow.h lib/Set.h lib/SetImpl.h lib/SignUpWindow.h lib/User.h .tmp/project_pugliesi1.0.0/ && $(COPY_FILE) --parents main.cpp lib/LoginWindow.cpp lib/MainWindow.cpp lib/Movie.cpp lib/Netflix.cpp lib/RatingWindow.cpp lib/SearchResultsWindow.cpp lib/SignUpWindow.cpp lib/User.cpp .tmp/project_pugliesi1.0.0/ && (cd `dirname .tmp/project_pugliesi1.0.0` && $(TAR) project_pugliesi1.0.0.tar project_pugliesi1.0.0 && $(COMPRESS) project_pugliesi1.0.0.tar) && $(MOVE) `dirname .tmp/project_pugliesi1.0.0`/project_pugliesi1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/project_pugliesi1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_LoginWindow.cpp moc_MainWindow.cpp moc_RatingWindow.cpp moc_SearchResultsWindow.cpp moc_SignUpWindow.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_LoginWindow.cpp moc_MainWindow.cpp moc_RatingWindow.cpp moc_SearchResultsWindow.cpp moc_SignUpWindow.cpp
moc_LoginWindow.cpp: lib/Netflix.h \
		lib/Map.h \
		lib/Pair.h \
		lib/MapImpl.h \
		lib/NoSuchElementException.h \
		lib/Movie.h \
		lib/Set.h \
		lib/SetImpl.h \
		lib/MergeSort.h \
		lib/MergeSortImpl.h \
		lib/User.h \
		lib/Queue.h \
		lib/Node.h \
		lib/NodeImp.h \
		lib/QueueImpl.h \
		lib/EmptyQueueException.h \
		lib/LoginWindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) lib/LoginWindow.h -o moc_LoginWindow.cpp

moc_MainWindow.cpp: lib/Netflix.h \
		lib/Map.h \
		lib/Pair.h \
		lib/MapImpl.h \
		lib/NoSuchElementException.h \
		lib/Movie.h \
		lib/Set.h \
		lib/SetImpl.h \
		lib/MergeSort.h \
		lib/MergeSortImpl.h \
		lib/User.h \
		lib/Queue.h \
		lib/Node.h \
		lib/NodeImp.h \
		lib/QueueImpl.h \
		lib/EmptyQueueException.h \
		lib/RatingWindow.h \
		lib/SearchResultsWindow.h \
		lib/MainWindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) lib/MainWindow.h -o moc_MainWindow.cpp

moc_RatingWindow.cpp: lib/User.h \
		lib/Queue.h \
		lib/Node.h \
		lib/NodeImp.h \
		lib/QueueImpl.h \
		lib/EmptyQueueException.h \
		lib/Movie.h \
		lib/Set.h \
		lib/Map.h \
		lib/Pair.h \
		lib/MapImpl.h \
		lib/NoSuchElementException.h \
		lib/SetImpl.h \
		lib/MergeSort.h \
		lib/MergeSortImpl.h \
		lib/RatingWindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) lib/RatingWindow.h -o moc_RatingWindow.cpp

moc_SearchResultsWindow.cpp: lib/Netflix.h \
		lib/Map.h \
		lib/Pair.h \
		lib/MapImpl.h \
		lib/NoSuchElementException.h \
		lib/Movie.h \
		lib/Set.h \
		lib/SetImpl.h \
		lib/MergeSort.h \
		lib/MergeSortImpl.h \
		lib/User.h \
		lib/Queue.h \
		lib/Node.h \
		lib/NodeImp.h \
		lib/QueueImpl.h \
		lib/EmptyQueueException.h \
		lib/SearchResultsWindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) lib/SearchResultsWindow.h -o moc_SearchResultsWindow.cpp

moc_SignUpWindow.cpp: lib/Netflix.h \
		lib/Map.h \
		lib/Pair.h \
		lib/MapImpl.h \
		lib/NoSuchElementException.h \
		lib/Movie.h \
		lib/Set.h \
		lib/SetImpl.h \
		lib/MergeSort.h \
		lib/MergeSortImpl.h \
		lib/User.h \
		lib/Queue.h \
		lib/Node.h \
		lib/NodeImp.h \
		lib/QueueImpl.h \
		lib/EmptyQueueException.h \
		lib/SignUpWindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) lib/SignUpWindow.h -o moc_SignUpWindow.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

main.o: main.cpp lib/LoginWindow.h \
		lib/Netflix.h \
		lib/Map.h \
		lib/Pair.h \
		lib/MapImpl.h \
		lib/NoSuchElementException.h \
		lib/Movie.h \
		lib/Set.h \
		lib/SetImpl.h \
		lib/MergeSort.h \
		lib/MergeSortImpl.h \
		lib/User.h \
		lib/Queue.h \
		lib/Node.h \
		lib/NodeImp.h \
		lib/QueueImpl.h \
		lib/EmptyQueueException.h \
		lib/SignUpWindow.h \
		lib/MainWindow.h \
		lib/RatingWindow.h \
		lib/SearchResultsWindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

LoginWindow.o: lib/LoginWindow.cpp lib/LoginWindow.h \
		lib/Netflix.h \
		lib/Map.h \
		lib/Pair.h \
		lib/MapImpl.h \
		lib/NoSuchElementException.h \
		lib/Movie.h \
		lib/Set.h \
		lib/SetImpl.h \
		lib/MergeSort.h \
		lib/MergeSortImpl.h \
		lib/User.h \
		lib/Queue.h \
		lib/Node.h \
		lib/NodeImp.h \
		lib/QueueImpl.h \
		lib/EmptyQueueException.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o LoginWindow.o lib/LoginWindow.cpp

MainWindow.o: lib/MainWindow.cpp lib/MainWindow.h \
		lib/Netflix.h \
		lib/Map.h \
		lib/Pair.h \
		lib/MapImpl.h \
		lib/NoSuchElementException.h \
		lib/Movie.h \
		lib/Set.h \
		lib/SetImpl.h \
		lib/MergeSort.h \
		lib/MergeSortImpl.h \
		lib/User.h \
		lib/Queue.h \
		lib/Node.h \
		lib/NodeImp.h \
		lib/QueueImpl.h \
		lib/EmptyQueueException.h \
		lib/RatingWindow.h \
		lib/SearchResultsWindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o MainWindow.o lib/MainWindow.cpp

Movie.o: lib/Movie.cpp lib/Movie.h \
		lib/Set.h \
		lib/Map.h \
		lib/Pair.h \
		lib/MapImpl.h \
		lib/NoSuchElementException.h \
		lib/SetImpl.h \
		lib/MergeSort.h \
		lib/MergeSortImpl.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Movie.o lib/Movie.cpp

Netflix.o: lib/Netflix.cpp lib/Netflix.h \
		lib/Map.h \
		lib/Pair.h \
		lib/MapImpl.h \
		lib/NoSuchElementException.h \
		lib/Movie.h \
		lib/Set.h \
		lib/SetImpl.h \
		lib/MergeSort.h \
		lib/MergeSortImpl.h \
		lib/User.h \
		lib/Queue.h \
		lib/Node.h \
		lib/NodeImp.h \
		lib/QueueImpl.h \
		lib/EmptyQueueException.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Netflix.o lib/Netflix.cpp

RatingWindow.o: lib/RatingWindow.cpp lib/RatingWindow.h \
		lib/User.h \
		lib/Queue.h \
		lib/Node.h \
		lib/NodeImp.h \
		lib/QueueImpl.h \
		lib/EmptyQueueException.h \
		lib/Movie.h \
		lib/Set.h \
		lib/Map.h \
		lib/Pair.h \
		lib/MapImpl.h \
		lib/NoSuchElementException.h \
		lib/SetImpl.h \
		lib/MergeSort.h \
		lib/MergeSortImpl.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o RatingWindow.o lib/RatingWindow.cpp

SearchResultsWindow.o: lib/SearchResultsWindow.cpp lib/SearchResultsWindow.h \
		lib/Netflix.h \
		lib/Map.h \
		lib/Pair.h \
		lib/MapImpl.h \
		lib/NoSuchElementException.h \
		lib/Movie.h \
		lib/Set.h \
		lib/SetImpl.h \
		lib/MergeSort.h \
		lib/MergeSortImpl.h \
		lib/User.h \
		lib/Queue.h \
		lib/Node.h \
		lib/NodeImp.h \
		lib/QueueImpl.h \
		lib/EmptyQueueException.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o SearchResultsWindow.o lib/SearchResultsWindow.cpp

SignUpWindow.o: lib/SignUpWindow.cpp lib/SignUpWindow.h \
		lib/Netflix.h \
		lib/Map.h \
		lib/Pair.h \
		lib/MapImpl.h \
		lib/NoSuchElementException.h \
		lib/Movie.h \
		lib/Set.h \
		lib/SetImpl.h \
		lib/MergeSort.h \
		lib/MergeSortImpl.h \
		lib/User.h \
		lib/Queue.h \
		lib/Node.h \
		lib/NodeImp.h \
		lib/QueueImpl.h \
		lib/EmptyQueueException.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o SignUpWindow.o lib/SignUpWindow.cpp

User.o: lib/User.cpp lib/User.h \
		lib/Queue.h \
		lib/Node.h \
		lib/NodeImp.h \
		lib/QueueImpl.h \
		lib/EmptyQueueException.h \
		lib/Movie.h \
		lib/Set.h \
		lib/Map.h \
		lib/Pair.h \
		lib/MapImpl.h \
		lib/NoSuchElementException.h \
		lib/SetImpl.h \
		lib/MergeSort.h \
		lib/MergeSortImpl.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o User.o lib/User.cpp

moc_LoginWindow.o: moc_LoginWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_LoginWindow.o moc_LoginWindow.cpp

moc_MainWindow.o: moc_MainWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_MainWindow.o moc_MainWindow.cpp

moc_RatingWindow.o: moc_RatingWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_RatingWindow.o moc_RatingWindow.cpp

moc_SearchResultsWindow.o: moc_SearchResultsWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_SearchResultsWindow.o moc_SearchResultsWindow.cpp

moc_SignUpWindow.o: moc_SignUpWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_SignUpWindow.o moc_SignUpWindow.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:


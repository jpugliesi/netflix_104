#############################################################################
# Makefile for building: project_pugliesi.app/Contents/MacOS/project_pugliesi
# Generated by qmake (2.01a) (Qt 4.8.6) on: Tue Nov 4 19:50:00 2014
# Project:  project_pugliesi.pro
# Template: app
# Command: /usr/local/bin/qmake -o Makefile project_pugliesi.pro
#############################################################################

####### Compiler, tools and options

CC            = clang
CXX           = clang++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -mmacosx-version-min=10.7 -O2 -arch x86_64 -Wall -W $(DEFINES)
CXXFLAGS      = -pipe -stdlib=libc++ -mmacosx-version-min=10.7 -O2 -arch x86_64 -Wall -W $(DEFINES)
INCPATH       = -I/usr/local/Cellar/qt/4.8.5/mkspecs/unsupported/macx-clang-libc++ -I. -I/usr/local/Cellar/qt/4.8.5/lib/QtCore.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.5/lib/QtCore.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.5/lib/QtGui.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.5/lib/QtGui.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.5/include -I. -Ilib -I. -F/usr/local/Cellar/qt/4.8.5/lib
LINK          = clang++
LFLAGS        = -headerpad_max_install_names -stdlib=libc++ -mmacosx-version-min=10.7 -arch x86_64
LIBS          = $(SUBLIBS) -F/usr/local/Cellar/qt/4.8.5/lib -L/usr/local/Cellar/qt/4.8.5/lib -framework QtGui -L/opt/X11/lib -L/usr/local/Cellar/qt/4.8.5/lib -F/usr/local/Cellar/qt/4.8.5/lib -framework QtCore 
AR            = ar cq
RANLIB        = ranlib -s
QMAKE         = /usr/local/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
STRIP         = 
INSTALL_FILE  = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = $(COPY_FILE)
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
export MACOSX_DEPLOYMENT_TARGET = 10.7

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		lib/LoginWindow.cpp \
		lib/MainWindow.cpp \
		lib/Movie.cpp \
		lib/Netflix.cpp \
		lib/SignUpWindow.cpp \
		lib/User.cpp moc_LoginWindow.cpp \
		moc_MainWindow.cpp \
		moc_SignUpWindow.cpp
OBJECTS       = main.o \
		LoginWindow.o \
		MainWindow.o \
		Movie.o \
		Netflix.o \
		SignUpWindow.o \
		User.o \
		moc_LoginWindow.o \
		moc_MainWindow.o \
		moc_SignUpWindow.o
DIST          = /usr/local/Cellar/qt/4.8.5/mkspecs/common/unix.conf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/common/mac.conf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/common/gcc-base.conf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/common/gcc-base-macx.conf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/common/clang.conf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/qconfig.pri \
		/usr/local/Cellar/qt/4.8.5/mkspecs/modules/qt_webkit_version.pri \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/qt_functions.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/qt_config.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/exclusive_builds.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/default_pre.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/default_pre.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/release.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/default_post.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/default_post.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/x86_64.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/objective_c.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/shared.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/warn_on.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/qt.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/unix/thread.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/moc.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/rez.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/sdk.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/resources.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/uic.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/yacc.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/lex.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/include_source_dir.prf \
		project_pugliesi.pro
QMAKE_TARGET  = project_pugliesi
DESTDIR       = 
TARGET        = project_pugliesi.app/Contents/MacOS/project_pugliesi

####### Custom Compiler Variables
QMAKE_COMP_QMAKE_OBJECTIVE_CFLAGS = -pipe \
		-O2 \
		-arch \
		x86_64 \
		-Wall \
		-W


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

all: Makefile project_pugliesi.app/Contents/PkgInfo project_pugliesi.app/Contents/Resources/empty.lproj project_pugliesi.app/Contents/Info.plist $(TARGET)

$(TARGET):  $(OBJECTS)  
	@$(CHK_DIR_EXISTS) project_pugliesi.app/Contents/MacOS/ || $(MKDIR) project_pugliesi.app/Contents/MacOS/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: project_pugliesi.pro  /usr/local/Cellar/qt/4.8.5/mkspecs/unsupported/macx-clang-libc++/qmake.conf /usr/local/Cellar/qt/4.8.5/mkspecs/common/unix.conf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/common/mac.conf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/common/gcc-base.conf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/common/gcc-base-macx.conf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/common/clang.conf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/qconfig.pri \
		/usr/local/Cellar/qt/4.8.5/mkspecs/modules/qt_webkit_version.pri \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/qt_functions.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/qt_config.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/exclusive_builds.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/default_pre.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/default_pre.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/release.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/default_post.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/default_post.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/x86_64.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/objective_c.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/shared.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/warn_on.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/qt.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/unix/thread.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/moc.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/rez.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/sdk.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/resources.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/uic.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/yacc.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/lex.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/include_source_dir.prf \
		/usr/local/Cellar/qt/4.8.5/lib/QtGui.framework/QtGui.prl \
		/usr/local/Cellar/qt/4.8.5/lib/QtCore.framework/QtCore.prl
	$(QMAKE) -o Makefile project_pugliesi.pro
/usr/local/Cellar/qt/4.8.5/mkspecs/common/unix.conf:
/usr/local/Cellar/qt/4.8.5/mkspecs/common/mac.conf:
/usr/local/Cellar/qt/4.8.5/mkspecs/common/gcc-base.conf:
/usr/local/Cellar/qt/4.8.5/mkspecs/common/gcc-base-macx.conf:
/usr/local/Cellar/qt/4.8.5/mkspecs/common/clang.conf:
/usr/local/Cellar/qt/4.8.5/mkspecs/qconfig.pri:
/usr/local/Cellar/qt/4.8.5/mkspecs/modules/qt_webkit_version.pri:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/qt_functions.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/qt_config.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/exclusive_builds.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/default_pre.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/default_pre.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/release.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/default_post.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/default_post.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/x86_64.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/objective_c.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/shared.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/warn_on.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/qt.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/unix/thread.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/moc.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/rez.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/sdk.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/resources.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/uic.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/yacc.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/lex.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/include_source_dir.prf:
/usr/local/Cellar/qt/4.8.5/lib/QtGui.framework/QtGui.prl:
/usr/local/Cellar/qt/4.8.5/lib/QtCore.framework/QtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile project_pugliesi.pro

project_pugliesi.app/Contents/PkgInfo: 
	@$(CHK_DIR_EXISTS) project_pugliesi.app/Contents || $(MKDIR) project_pugliesi.app/Contents 
	@$(DEL_FILE) project_pugliesi.app/Contents/PkgInfo
	@echo "APPL????" >project_pugliesi.app/Contents/PkgInfo
project_pugliesi.app/Contents/Resources/empty.lproj: 
	@$(CHK_DIR_EXISTS) project_pugliesi.app/Contents/Resources || $(MKDIR) project_pugliesi.app/Contents/Resources 
	@touch project_pugliesi.app/Contents/Resources/empty.lproj
	
project_pugliesi.app/Contents/Info.plist: 
	@$(CHK_DIR_EXISTS) project_pugliesi.app/Contents || $(MKDIR) project_pugliesi.app/Contents 
	@$(DEL_FILE) project_pugliesi.app/Contents/Info.plist
	@sed -e "s,@SHORT_VERSION@,1.0,g" -e "s,@TYPEINFO@,????,g" -e "s,@ICON@,,g" -e "s,@EXECUTABLE@,project_pugliesi,g" -e "s,@TYPEINFO@,????,g" /usr/local/Cellar/qt/4.8.5/mkspecs/unsupported/macx-clang-libc++/Info.plist.app >project_pugliesi.app/Contents/Info.plist
dist: 
	@$(CHK_DIR_EXISTS) .tmp/project_pugliesi1.0.0 || $(MKDIR) .tmp/project_pugliesi1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/project_pugliesi1.0.0/ && $(COPY_FILE) --parents lib/EmptyQueueException.h lib/LoginWindow.h lib/MainWindow.h lib/Map.h lib/MapImpl.h lib/MergeSort.h lib/MergeSortImpl.h lib/Movie.h lib/Netflix.h lib/Node.h lib/NodeImp.h lib/NoSuchElementException.h lib/Pair.h lib/Queue.h lib/QueueImpl.h lib/Set.h lib/SetImpl.h lib/SignUpWindow.h lib/User.h .tmp/project_pugliesi1.0.0/ && $(COPY_FILE) --parents main.cpp lib/LoginWindow.cpp lib/MainWindow.cpp lib/Movie.cpp lib/Netflix.cpp lib/SignUpWindow.cpp lib/User.cpp .tmp/project_pugliesi1.0.0/ && (cd `dirname .tmp/project_pugliesi1.0.0` && $(TAR) project_pugliesi1.0.0.tar project_pugliesi1.0.0 && $(COMPRESS) project_pugliesi1.0.0.tar) && $(MOVE) `dirname .tmp/project_pugliesi1.0.0`/project_pugliesi1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/project_pugliesi1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) -r project_pugliesi.app
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_objective_c_make_all:
compiler_objective_c_clean:
compiler_moc_header_make_all: moc_LoginWindow.cpp moc_MainWindow.cpp moc_SignUpWindow.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_LoginWindow.cpp moc_MainWindow.cpp moc_SignUpWindow.cpp
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
	/usr/local/Cellar/qt/4.8.5/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ lib/LoginWindow.h -o moc_LoginWindow.cpp

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
		lib/MainWindow.h
	/usr/local/Cellar/qt/4.8.5/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ lib/MainWindow.h -o moc_MainWindow.cpp

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
	/usr/local/Cellar/qt/4.8.5/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ lib/SignUpWindow.h -o moc_SignUpWindow.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_rez_source_make_all:
compiler_rez_source_clean:
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
		lib/MainWindow.h
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
		lib/EmptyQueueException.h
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

moc_SignUpWindow.o: moc_SignUpWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_SignUpWindow.o moc_SignUpWindow.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:


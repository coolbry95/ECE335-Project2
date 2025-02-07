#-------------------------------------------------
#
# Project created by QtCreator 2018-04-14T10:45:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    shoppingcart.cpp

HEADERS += \
        mainwindow.h \
    csvreader.h \
    builder.h \
    databasebuilder.h \
    BinarySearch.h \
    Bird.h \
    BubbleSort.h \
    BubbleSortDecreasing.h \
    BubbleSortIncreasing.h \
    PetDatabaseSortableByWeight.h \
    Pet.h \
    PetDatabase.h \
    PetDatabaseSearchableByName.h \
    PetDatabaseSearchableByPrice.h \
    PetDatabaseSearchableByType.h \
    PetDatabaseSearchableByWeight.h \
    PetDatabaseSortableByName.h \
    PetDatabaseSortableByPrice.h \
    PetDatabaseSortableByType.h \
    SearchableVector.h \
    SortableVector.h \
    Cat.h \
    Dog.h \
    Fish.h \
    sortableitemvector.h \
    itemvector.h \
    bundle.h \
    item.h \
    visitor.h \
    pettablevisitor.h \
    bundletablevisitor.h \
    carttablevisitor.h \
    shoppingcart.h \
    shoppingcart.h \
    subject.h \
    observer.h \
    shoppingcartvisitor.h

FORMS += \
        mainwindow.ui \
    shoppingcart.ui \
    shoppingcart.ui

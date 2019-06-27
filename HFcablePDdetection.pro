#-------------------------------------------------
#
# Project created by QtCreator 2019-05-30T16:00:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport charts

TARGET = HFcablePDdetection
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

CONFIG += c++11

SOURCES += \
        library/qcustomplot/qcustomplot.cpp \
        logindialog.cpp \
        main.cpp \
        mainwindow.cpp \
        new_product_dialog.cpp \
        operation_file.cpp \
        scatter_plot.cpp \
        trend_channel_widget.cpp \
        type_diagnosis_double_slider.cpp \
        type_diagnosis_widget.cpp

HEADERS += \
        library/qcustomplot/qcustomplot.h \
        logindialog.h \
        mainwindow.h \
        new_product_dialog.h \
        operation_file.h \
        scatter_plot.h \
        trend_channel_widget.h \
        type_diagnosis_double_slider.h \
        type_diagnosis_widget.h

FORMS += \
        logindialog.ui \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc

DISTFILES +=

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QHBoxLayout>
#include <QTimer>
#include <QDateTime>
#include <QPainter>
#include <QSize>
#include <QGridLayout>

#include "amplitude_main_widget.h"
#include "type_diagnosis_widget.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *);

private:
    Ui::MainWindow *ui;
    QGridLayout *pGridLayout;
    QLabel *text3;

    AmplitudeMainWidget *amplitudeMainWidget1;
    AmplitudeMainWidget *amplitudeMainWidget2;
    AmplitudeMainWidget *amplitudeMainWidget3;
    AmplitudeMainWidget *amplitudeMainWidget4;

    TypeDiagnosisWidget *typeDiagnosisCH1;
    TypeDiagnosisWidget *typeDiagnosisCH2;
    TypeDiagnosisWidget *typeDiagnosisCH3;
    TypeDiagnosisWidget *typeDiagnosisCH4;


private slots:
    void timerUpdate();
};

#endif // MAINWINDOW_H

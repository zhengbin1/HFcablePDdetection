#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include <QDateTime>
#include <QPainter>
#include <QSize>
#include <QGridLayout>
#include <QMouseEvent>

#include "scatter_plot.h"
#include "type_diagnosis_widget.h"
#include "trend_channel_widget.h"
#include "operation_file.h"
#include "project_manage_dialog.h"
#include "new_project_dialog.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QGridLayout *pGridLayout;
    QLabel *text3;

    ScatterPlot *pScatterPlot1;
    ScatterPlot *pScatterPlot2;
    ScatterPlot *pScatterPlot3;
    ScatterPlot *pScatterPlot4;

    TypeDiagnosisWidget *typeDiagnosisCH1;
    TypeDiagnosisWidget *typeDiagnosisCH2;
    TypeDiagnosisWidget *typeDiagnosisCH3;
    TypeDiagnosisWidget *typeDiagnosisCH4;

    TrendChannelWidget *trendChannelWidget;

    QWidget *pCentralWidget;

    NewProjectDialog *pNewProjectDialog;
    ProjectManageDialog *pProjectManageDialog;


private slots:
    void timerUpdate();
    void triggerMenu1(QAction *);
};

#endif // MAINWINDOW_H

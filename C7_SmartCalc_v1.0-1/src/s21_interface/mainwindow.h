#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QWidget>
#include "graph_window.h"
#include "credit_calc.h"
#include "contribution_calc.h"

extern "C" {
#include "../backend/s21_calc.h"
}

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void get_operator_number_from_button();
    void get_function_from_button();
    void on_pushButton_graph_clicked();
    void on_pushButton_equal_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_credit_clicked();

    void on_pushButton_contribution_clicked();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int x_flag = 0;
    int symbol_flag = 0;
};
#endif // MAINWINDOW_H

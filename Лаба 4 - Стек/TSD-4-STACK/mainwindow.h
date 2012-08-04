#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "arraystack.h"
#include "liststack.h"
#include "stack.h"

enum StackType {
    List,
    Array
};

const int MAX_STACK_SIZE = 1024;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_4_clicked();

    void on_pushButton_8_clicked();

    void on_radioButton_3_toggled(bool checked);

    void on_tabWidget_currentChanged(int index);

    void on_tabWidget_selected(const QString &arg1);

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
    Stack<QString> *stack;
    inline bool isRightBrackets(QString &st, StackType type);
    inline void Log(QString *st);
    inline void RefreshInfo();
};

#endif // MAINWINDOW_H

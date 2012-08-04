#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stack.h"
#include "arraystack.h"
#include "liststack.h"
#include <QPalette>
#include <QColor>
#include <time.h>
#include <windows.h>
#include "error.h"
#include <QTextCodec>
#include <QMessageBox>
#include <fstream>
#include "dialogaddr.h"

#define LOG if (isLogEnabled) Log(stack->getLog());
#define SET_CODEC QTextCodec::setCodecForCStrings(QTextCodec::codecForName("CP1251"));
const bool isLogEnabled = true;

using namespace std;

inline bool isOpeningBracket(QChar b);
inline bool matchingBrackets(QChar a, QChar b);

ArrayStack<QString> stackArray = ArrayStack<QString>(MAX_STACK_SIZE);
ListStack<QString> stackList;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    stack = &stackArray;
    ui->setupUi(this);
    if (ui->tabWidget->currentIndex() == 1) {
        if (ui->radioButton_3->isChecked()) {
            ui->groupBox_3->setEnabled(false);
            ui->pushButton_6->setEnabled(false);
            ui->pushButton_7->setEnabled(false);
        }
        else {
            ui->groupBox_3->setEnabled(true);
            ui->pushButton_6->setEnabled(true);
            ui->pushButton_7->setEnabled(true);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Проверка скобок
void MainWindow::on_pushButton_clicked()
{
    SET_CODEC;
    StackType type;
    if (ui->radioButton_3->isChecked())
        type = Array;
    else
        type = List;

    QString text = ui->lineEdit->text().trimmed();
    if (text.length() == 0) {
        Error error((QString) "Пустой ввод!");
        error.Show();
        return;
    }
    if (!(text.contains('(') || text.contains(')') || text.contains('[') || text.contains(']')
          || text.contains('{') || text.contains('}'))) {
        Error error((QString) "Введенное выражение не содержит скобок!");
        error.Show();
        return;
    }
    ui->textEdit->clear();

    // Проверка на правильность скобок
    bool result;
    try {
        result = isRightBrackets(text, type);

        // Вывод результата проверки
        QColor color;
        QPalette::ColorRole cr;
        QPalette palette;
        if (result) {
            ui->label_2->setText("Скобки расставлены верно!");
            color.setNamedColor("green");

        } else {
            ui->label_2->setText("Скобки расставлены неверно!");
            color.setNamedColor("red");
        }
        cr = QPalette::WindowText;
        palette.setColor(cr, color);
        ui->label_2->setPalette(palette);
    } catch(Error err) {
        this->Log((QString *) &(err.getErrorDescription()));
        err.Show();
    }
}

bool MainWindow::isRightBrackets(QString &st, StackType type) {
    ArrayStack<QChar> aStack(MAX_STACK_SIZE);
    ListStack<QChar> lStack;

    Stack<QChar> *stack;
    if (type == Array)
        stack = &aStack;
    else
        stack = &lStack;

    LOG;
    for (int i = 0; i < st.length(); i++) {
        if ((st[i] == '{') || (st[i] == '}') || (st[i] == '[') || (st[i] == ']') ||
                (st[i] == '(') || (st[i] == ')'))
        {
            if (isOpeningBracket(st[i])) {
                stack->Push(st[i]);
                LOG;
            }
            else {
                if (stack->isEmpty())
                    return false;
                if ((matchingBrackets(stack->Top(), st[i]))) {
                    LOG;
                    stack->Pop();
                    LOG;
                } else {
                    stack->Free();
                    return false;
                }
            }
        }
    }

    bool Result = true;
    if (!(stack->isEmpty())) {
        Result = false;
        stack->Free();
        LOG;
    }
    return Result;
}

inline bool isOpeningBracket(QChar b) {
    return ((b == '{') || (b == '[') || (b == '('));
}

inline bool matchingBrackets(QChar a, QChar b) {
    if (a == '{')
        return (b == '}');

    if (a == '[')
        return (b == ']');

    if (a == '(')
        return (b == ')');

    return false;
}

inline void MainWindow::Log(QString *st) {
    ui->textEdit->setText(ui->textEdit->toPlainText() + *st + "\n");
}

// Сравнение методов
void MainWindow::on_pushButton_2_clicked()
{
    const int IterationsCount = 100000;
    const int TEST_MAX_SIZE = 100000;
    const char *TEST_FILE_NAME = "Test.txt";
    char *tmp = new char[TEST_MAX_SIZE];

    ifstream *File = new ifstream(TEST_FILE_NAME);
    if (File != 0)
        File->getline(tmp, TEST_MAX_SIZE);
    QString TestString;
    TestString = TestString.fromAscii(tmp);

    StackType type;
    DWORD cListTime;
    DWORD cArrayTime;
    double ListTime;
    double ArrayTime;

    int OnePercentTime = IterationsCount / 50;
    ui->progressBar->setEnabled(true);
    ui->progressBar->setValue(0);

    try {
        // Измеряем время при организации стека как списка
        type = List;
        cListTime = GetTickCount();
        for (int i = 0; i < IterationsCount; i++) {
            isRightBrackets(TestString, type);
            if (i % OnePercentTime == 0)
                ui->progressBar->setValue(ui->progressBar->value() + 1);
        }
        ListTime = (double) ((GetTickCount() - cListTime) / 1000.0);

        // Измеряем время при организации стека как массива
        type = Array;
        cArrayTime = GetTickCount();
        for (int i = 0; i < IterationsCount; i++) {
            isRightBrackets(TestString, type);
            if (i % OnePercentTime == 0)
                ui->progressBar->setValue(ui->progressBar->value() + 1);
        }
        ArrayTime = (double) ((GetTickCount() - cArrayTime) / 1000.0);
    } catch(Error error) {
        error.Show();
    }

    SET_CODEC;
    QString MsgText = "Время при организации стека списком: " + QString::number((double) ListTime, 'g', 6) +
            "с\nВремя при организации стека массивом: " + QString::number((double) ArrayTime, 'g', 6) + "с";
    QMessageBox msg;
    msg.setWindowTitle("Сравнение времени");
    msg.setText(MsgText);
    msg.exec();

    ui->progressBar->setValue(0);
    ui->progressBar->setEnabled(false);
}

// Кнопка очистки для первого таба
void MainWindow::on_pushButton_3_clicked()
{
    ui->lineEdit->clear();
    ui->textEdit->clear();
    ui->label_2->clear();
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    ui->textEdit->clear();
    ui->label_2->clear();
}


inline void MainWindow::RefreshInfo() {
    SET_CODEC;
    if (stack->isEmpty()) {
        ui->lineEdit_5->setText("Стек пуст!");
        ui->label_3->setText("0");
    } else {
        ui->lineEdit_5->setText(stack->Top());
        ui->label_3->setText(QString::number(stack->Length(), 10));
    }
}

// Кнопка очистки для второго таба
void MainWindow::on_pushButton_8_clicked()
{
    ui->lineEdit_2->clear();
}

void MainWindow::on_radioButton_3_toggled(bool checked)
{
    if (ui->tabWidget->currentIndex() == 1) {
        if (ui->radioButton_3->isChecked()) {
            ui->groupBox_3->setEnabled(false);
            ui->pushButton_6->setEnabled(false);
            ui->pushButton_7->setEnabled(false);
        }
        else {
            ui->groupBox_3->setEnabled(true);
            ui->pushButton_6->setEnabled(true);
            ui->pushButton_7->setEnabled(true);
        }

    }
    ui->textEdit->clear();

    if (stack->isEmpty() == false)
        stack->Clear();

    if (ui->radioButton_3->isChecked())
        stack = &stackArray;
    else
        stack = &stackList;
    RefreshInfo();
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    on_pushButton_8_clicked();
    //on_radioButton_3_toggled(true);
    on_pushButton_3_clicked();
}

void MainWindow::on_tabWidget_selected(const QString &arg1)
{

}

// Кнопка "Добавить"
void MainWindow::on_pushButton_4_clicked()
{
    SET_CODEC;
    if (ui->lineEdit_2->text().trimmed().length() == 0) {
        Error error((QString) "Пустой ввод!");
        error.Show();
        return;
    }

    int MaxLength = ui->lineEdit_3->text().toInt(0, 10);
    int MaxAddress = ui->lineEdit_4->text().toInt(0, 16);
    if (stack->canPush(ui->lineEdit_2->text(), MaxLength, MaxAddress) == false) {
        if (stack->Length() >= MaxLength) {
            Error error((QString) "Стек максимально полон, добавление невозможно!");
            error.Show();
        } else {
            Error error((QString) "Превышена верхняя граница адресов для элементов стека, добавление невозможно!");
            error.Show();
        }
        return;
    }

    LOG;
    RefreshInfo();
    ui->lineEdit_2->clear();
}

// Кнопка "Вытолкнуть"
void MainWindow::on_pushButton_5_clicked()
{
    SET_CODEC;
    if (stack->isEmpty()) {
        Error error("Стек пуст!");
        error.Show();
    } else {
        stack->Pop();
        LOG;
        RefreshInfo();
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    DialogAddr *dlg = new DialogAddr(0);
    dlg->setWindowTitle("Список занятых адресов:");
    QString addr = stack->getBusyAddresses();
    if (addr.length() == 0)
        addr = "Занятых адресов пока нет!";
    dlg->setText(addr);
    dlg->show();
    //  delete dlg;
}

void MainWindow::on_pushButton_7_clicked()
{
    DialogAddr *dlg = new DialogAddr(0);
    dlg->setWindowTitle("Список освобожденных адресов:");
    QString addr = stack->getFreeAddresses();
    if (addr.length() == 0)
        addr = "Освобожденных адресов пока нет!";
    dlg->setText(addr);
    dlg->show();
    //  delete dlg;
}

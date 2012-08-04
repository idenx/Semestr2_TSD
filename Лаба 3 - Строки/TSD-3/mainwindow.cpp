#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "tsdString.h"
#include "ListString.h"
#include "ArrayString.h"
#include <time.h>
#include <QMessageBox>
#include <QTextCodec>
#include <windows.h>
#include <fstream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::isRightLetter(QChar c) {
    for (char ch = 'a'; ch <= 'z'; ch++) {
        if (c == ch)
            return true;
    }
    return false;
}

QString MainWindow::ClearString(QString &st) {
    while (st.contains("  "))
        st.replace("  ", " ");
    st.remove('.');
    st.trimmed();
    if (st[0] == ' ')
        st.remove(0, 1);
    QString Result = "";
    QString Word;
    int i = 0, j;
    while (i < st.length())  {
        bool right = true;
        j = i;
        Word = "";
        while (st[j] != ' ' && j < st.length()) {
            if (!isRightLetter(st[j])) {
                right = false;
                break;
            } else
                Word.append(st[j++]);
        }
        if (right) {
            Result.append(Word);
            Result.append(" ");
        } else {
            while (st[j] != ' ' && j < st.length() - 1)
                j++;
        }
        i = j + 1;
    }
    return Result.trimmed();
}

void MainWindow::on_pushButton_clicked()
{
    #define SHOW_ERROR(error_text) {msg.setText(error_text); msg.exec(); return; }

    QString text = ui->textEdit->toPlainText();
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("CP1251"));
    QMessageBox msg;
    msg.setWindowTitle("Ошибка!");

    if (text.length() == 0)
        SHOW_ERROR("Пустой ввод!");

    text = ClearString(text);

    if (text.trimmed().length() == 0)
        SHOW_ERROR("Во введенной строке нет слов из малых латинских букв!");

    tsdString *tSt;
    ArrayString aSt;
    ListString lSt;

    if (ui->radioButton->isChecked())
        tSt = &lSt;
    else
        tSt = &aSt;

    tSt->Create(&text);
    QString result = tSt->getRenderedString().trimmed();
    tSt->Free();
    if (result.length() == 0)
        SHOW_ERROR("Во введенной строке нет слов с неповторяющимися буквами, отличных от последнего слова!");
    result.append('.');
    ui->textEdit_2->setText((const QString &) result);
}



void MainWindow::on_pushButton_2_clicked()
{
    const int IterationsCount = 5000;
    const int TEST_MAX_SIZE = 1024;
    char *tmp = new char[TEST_MAX_SIZE];

    ifstream *File = new ifstream("Test.txt");
    if (File != 0)
        File->getline(tmp, TEST_MAX_SIZE);
    QString TestString;
    TestString = TestString.fromAscii(tmp);

    QString result;
    ListString lSt;
    ArrayString aSt;

    clock_t cListTime;
    clock_t cArrayTime;
    double ListTime;
    double ArrayTime;

    int OnePercentTime = IterationsCount / 50;
    ui->progressBar->setEnabled(true);
    ui->progressBar->setValue(0);

    // Измеряем время при организации строки как списка
    cListTime = clock();
    for (int i = 0; i < IterationsCount; i++) {
        lSt.Create(&TestString);
        result = lSt.getRenderedString();
        lSt.Free();
        if (i % OnePercentTime == 0)
            ui->progressBar->setValue(ui->progressBar->value() + 1);
    }
    ListTime = (double) ((clock() - cListTime) / 1000.0);

    // Измеряем время при организации строки как массива
    cArrayTime = clock();
    for (int i = 0; i < IterationsCount; i++) {
        aSt.Create(&TestString);
        result = aSt.getRenderedString();
        aSt.Free();
        if (i % OnePercentTime == 0)
            ui->progressBar->setValue(ui->progressBar->value() + 1);
    }
    ArrayTime = (double) ((clock() - cArrayTime) / 1000.0);

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("CP1251"));
    QString MsgText = "Время обработки при организации строки списком: " + QString::number((double) ListTime, 'g', 6) + "с\nВремя обработки при организации строки массивом: " +
            QString::number((double) ArrayTime, 'g', 6) + "c\nПамять на символ в строке:\nорганизация строки списком - 8 байт,\nорганизация строки массивом - 2 байта";
    QMessageBox msg;
    msg.setWindowTitle("Сравнение методов организации строк");
    msg.setText(MsgText);
    msg.exec();

    ui->progressBar->setValue(0);
    ui->progressBar->setEnabled(false);

}

void MainWindow::on_textEdit_textChanged()
{
    ui->textEdit_2->clear();
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->textEdit->clear();
    ui->textEdit_2->clear();
}

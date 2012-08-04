#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "request.h"
#include "queue.h"
#include "queuearray.h"
#include "queuelist.h"
#include "error.h"
#include <QString>
#include <time.h>
#include <windows.h>
#include <QTextCodec>
#include <math.h>
#include <algorithm>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    srand(time(NULL));
    ui->setupUi(this);
    ui->radioButton->setChecked(true);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("CP1251"));

    ui->label->setEnabled(false);
    ui->textEdit_2->setEnabled(false);
    ui->tableWidget->setEnabled(false);
    ui->textEdit->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Process() {
    const int ProcessedRequestsLimit = 1000;
    const int QueueMaxSize = 8192;
    const int MaxProcessingsCount = 5;

    Request *AddRequest = 0, *ProcessRequest = 0;
    QueueArray<Request*> queueArray = QueueArray<Request*>(QueueMaxSize);
    QueueList<Request*> queueList = QueueList<Request*>();

    Queue<Request*> *queue = 0;
    if (ui->radioButton->isChecked())
        queue = &queueArray;
    else
        queue = &queueList;

    double Time = 0;
    double OverallProcessingTime = 0;
    double ProcessingTime = 0, AddTime = 0;
    double AvQueueLength = 0;

    int CountOfProcessedRequests = 0;
    int AddCount = 0, ProcessingsCount = 0;
    int LengthCount = 0, MaxLength = 0;
    QTableWidgetItem* cells = 0;

    while (CountOfProcessedRequests != ProcessedRequestsLimit) {

        // Создаем заявку для добавления, если ее нет
        if (AddRequest == 0) {
            AddRequest = new Request();
            AddTime = AddRequest->AddTime();
        }

        // Берем заявку для обработки из очереди, если ее нет
        if (!queue->isEmpty() && ProcessRequest == 0) {

            AvQueueLength += queue->Length();
            LengthCount++;
            if (queue->Length() > MaxLength)
                MaxLength = queue->Length();

            ProcessRequest = queue->Pop();

            ProcessingTime = ProcessRequest->ProcessingTime();
        }

        if (ProcessingTime > AddTime || ProcessRequest == 0) {
            ProcessingTime -= AddTime;  // Тут при выполнении второго условия будет отрицательное число
            Time += AddTime;

            AddCount++;

            AvQueueLength += queue->Length();
            LengthCount++;
            if (queue->Length() > MaxLength)
                MaxLength = queue->Length();

            queue->Push(AddRequest);

            AddRequest = 0; // delete AddRequest;
            continue;
        }

        if (ProcessingTime <= AddTime) {
            // Обрабатываем заявку, если это быстрее чем добавление новой заявки
            AddTime -= ProcessingTime;
            Time += ProcessingTime;

            // Статистические замеры
            OverallProcessingTime += ProcessRequest->ProcessingTime();
            ProcessingsCount++;

            if (ProcessingsCount % 100 == 0) {
                cells = new QTableWidgetItem[3];
                cells[0].setText(QString::number(ProcessingsCount, 10));
                cells[1].setText(QString::number(queue->Length(), 10));
                cells[2].setText(QString::number((double) AvQueueLength / LengthCount, 'g', 1));
                int CurRow = ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(CurRow);
                ui->tableWidget->setItem(CurRow, 0, cells);
                ui->tableWidget->setItem(CurRow, 1, cells + 1);
                ui->tableWidget->setItem(CurRow, 2, cells + 2);
            }

            if (ProcessRequest->incProcessingsCount() == MaxProcessingsCount) {
                CountOfProcessedRequests++;
                delete ProcessRequest;
            } else {
                AvQueueLength += queue->Length();
                LengthCount++;
                if (queue->Length() > MaxLength)
                    MaxLength = queue->Length();

                queue->Push(ProcessRequest);


            }
            ProcessRequest = 0;
            continue;
        }

    }

    double DownTime = Time - OverallProcessingTime;

    double ThAvAddTime = (double) (Request::MaxAddTime - Request::MinAddTime) / 2;
    double ThAvProcessTime = (double) (Request::MaxProcessingTime - Request::MinProcessingTime) / 2;

    double ThAddCount = (double) Time / ThAvAddTime;
    double EnterImprecision = (double) fabs(ThAddCount - AddCount) / ThAddCount;

    double ThTime = ProcessingsCount * ThAvProcessTime + DownTime;
    double ExitImprecision = (double) fabs(ThTime - Time) / ThTime;

    double ThModelTime = max<double>(ThAvAddTime, ThAvProcessTime * MaxProcessingsCount) * ProcessedRequestsLimit;
    double TimePrecision = (double) fabs(ThModelTime - Time) / ThModelTime;

    if (ui->radioButton->isChecked())
        MaxLength = sizeof(Request*) * QueueMaxSize;
    QString Result = "Вошло заявок: " + QString::number(AddCount, 10) +
            "\nВышло заявок: " + QString::number(CountOfProcessedRequests, 10) +
            "\nАвтомат сработал " + QString::number(ProcessingsCount, 10) + " раз" +
            "\nВремя моделирования: " + QString::number(Time, 'g', 4) + " е.в." +
            "\nВремя простоя: " + QString::number(DownTime, 'g', 4) + " е.в." +
            "\nПогрешность (по входу): " + QString::number(EnterImprecision * 100, 'g', 2) + "%" +
            "\nПогрешность (по выходу): " + QString::number(ExitImprecision * 100, 'g', 2) + "%" +
            "\nПогрешность (по времени): " + QString::number(TimePrecision * 100, 'g', 2) + "%" +
            "\nЗатрачено памяти: " + QString::number(MaxLength * (sizeof(TList<Request*>)), 10) + " байт";

    ui->textEdit->setText(Result);

    // Освобождение памяти
    queueList.Free();
    queueArray.Free();

    ui->textEdit_2->clear();
    if (ui->radioButton_2->isChecked())
        ui->textEdit_2->setText(queueList.getLog());
}

void MainWindow::on_pushButton_clicked()
{
    try {
        if (ui->radioButton_2->isChecked()) {
            ui->label->setEnabled(true);
            ui->textEdit_2->setEnabled(true);
        }

        ui->tableWidget->setEnabled(true);
        ui->textEdit->setEnabled(true);
        ui->tableWidget->clear();
        ui->tableWidget->setRowCount(0);
        this->Process();
    } catch(Error error) {
        error.Show();
    }
}

void MainWindow::on_radioButton_toggled(bool checked)
{
    ui->textEdit_2->clear();
    ui->textEdit->clear();
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);

    ui->label->setEnabled(false);
    ui->textEdit_2->setEnabled(false);
    ui->tableWidget->setEnabled(false);
    ui->textEdit->setEnabled(false);
}

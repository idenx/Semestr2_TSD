#ifndef QUEUELIST_H
#define QUEUELIST_H

#include <QString>
#include "error.h"
#include <QTextCodec>
#include "queue.h"

#define CHECK_IS_QUEUE_EMPTY if (this->isEmpty()) {\
    Error error((QString) "Очередь пуста!"); \
    throw error; \
    };

template<class T>
struct TList {
    T data;
    TList* next;
};

template<class T>
class QueueList : public Queue<T>
{
public:
    QueueList();
    T Pop();
    void Push(const T &data);
    bool isEmpty();
    void Free();
    int Length();
    void Clear();
    QString &getLog();
private:
    TList<T> *getLoc;
    TList<T> *last;
    QString Log;
};


template<class T>
inline QueueList<T>::QueueList()
{
    getLoc = 0;
    last = 0;
    Log = "";
}

template<class T>
void QueueList<T>::Free() {
    TList<T> *temp = getLoc;

    while (getLoc != 0) {
        temp = getLoc;
        getLoc = getLoc->next;
        Log += "Освобождение памяти " + QString::number((int) temp, 16) + "\n";
        delete temp;
    }
}

template<class T>
bool QueueList<T>::isEmpty() {
    return (getLoc == 0);
}

template<class T>
void QueueList<T>::Clear()
{
    this->Free();
}

template<class T>
int QueueList<T>::Length() {
    TList<T> *Counter = this->getLoc;
    int Length = 0;
    while (Counter != 0) {
        Length++;
        Counter = Counter->next;
    }
    return Length;
}

template<class T>
T QueueList<T>::Pop() {
    CHECK_IS_QUEUE_EMPTY;

    if (getLoc == last)
        last = 0;
    T toReturn = getLoc->data;
    TList<T> *toDelete = getLoc;
    getLoc = getLoc->next;
    Log += "Освобождение памяти " + QString::number((int) toDelete, 16) + "\n";
    delete toDelete;
    return toReturn;
}

template<class T>
void QueueList<T>::Push(const T &data) {
    TList<T> *toAdd = new TList<T>;
    Log += "Выделение памяти " + QString::number((int) toAdd, 16) + "\n";
    toAdd->data = data;
    toAdd->next = 0;

    if (last == 0) {
        last = toAdd;
        getLoc = toAdd;
    } else {
        last->next = toAdd;
        last = toAdd;
    }
}

template<class T>
QString &QueueList<T>::getLog() {
    return this->Log;
}

#endif // QUEUELIST_H

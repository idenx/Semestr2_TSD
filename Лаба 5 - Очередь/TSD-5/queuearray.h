#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H
#include "queue.h"
#include <QString>
#include "error.h"
#include <QTextCodec>

#define CHECK_IS_QUEUE_EMPTY if (this->isEmpty()) {\
    Error error((QString) "Очередь пуста!"); \
    throw error; \
    };

template<class T>
class QueueArray : public Queue<T>
{
public:
    QueueArray(int size);
    T Pop();
    void Push(const T &data);
    bool isEmpty();
    void Free();
    int Length();
    void Clear();
private:
    T *begin;    // Начало массива
    int MaxSize; // Сколько памяти выделено под массив

    T *putLoc;
    T *getLoc;
};


template<class T>
QueueArray<T>::QueueArray(int size)
{
    this->MaxSize = size;
    begin = new T[MaxSize];
    putLoc = begin;
    getLoc = 0;
}

template<class T>
int QueueArray<T>::Length()
{
    if (getLoc == 0)
        return 0;
    return (putLoc - getLoc);
}

template<class T>
void QueueArray<T>::Clear()
{
    putLoc = begin;
    getLoc = 0;
}


template<class T>
void QueueArray<T>::Free() {
    delete [] begin;
}


template<class T>
bool QueueArray<T>::isEmpty() {
    return (getLoc == 0);
}

template<class T>
T QueueArray<T>::Pop() {
    CHECK_IS_QUEUE_EMPTY;

    T Result = *getLoc;
    getLoc++;
    if (putLoc == getLoc) {
        putLoc = begin;
        getLoc = 0;
    }
    return Result;
}

template<class T>
void QueueArray<T>::Push(const T &data) {
    if (putLoc > begin + MaxSize) {
        Error error((QString) "Переполнение очереди!");
        throw error;
    }
    *putLoc = data;
    if (getLoc == 0)
        getLoc = putLoc;
    putLoc++;
}

#endif // QUEUEARRAY_H

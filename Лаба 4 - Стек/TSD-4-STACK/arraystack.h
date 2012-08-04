#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#include "stack.h"
#include <QString>
#include "error.h"
#include <QTextCodec>

template<class T>
class ArrayStack : public Stack<T>
{
public:
    ArrayStack(int size);
    T Pop();
    T Top();
    void Push(const T &data);
    bool isEmpty();
    inline QString *getLog();
    void Free();
    int Length();
    void Clear();
    QString getFreeAddresses();
    QString getBusyAddresses();
    bool canPush(const T &data, int MaxElements, int MaxAddress);
private:
    T *Begin;
    T *Head;
    int MaxSize;
    QString Log;
};


template<class T>
ArrayStack<T>::ArrayStack(int size)
{
    this->MaxSize = size;
    Begin = new T[MaxSize];
    Head = 0;
    this->Log = (QString) "������� ����� � ���� ������� ������ " + QString::number(MaxSize, 10) +
            " � ��������� ������� " + QString::number((int) Begin, 16) + " - " + QString::number((int)(Begin + MaxSize), 16);
}

template<class T>
int ArrayStack<T>::Length()
{
    if (Head == 0)
        return 0;
    return (Head - Begin + 1);
}

template<class T>
QString ArrayStack<T>::getFreeAddresses()
{
    return (QString) "";
}

template<class T>
QString ArrayStack<T>::getBusyAddresses()
{
    return (QString) "";
}

template<class T>
void ArrayStack<T>::Clear()
{
    Head = 0;
}


template<class T>
void ArrayStack<T>::Free() {
    this->Log = (QString) "������������ ������ � ��������� ������� " + QString::number((int) Begin, 16) + " - " + QString::number((int)(Begin + MaxSize), 16);
    delete [] Begin;
}


template<class T>
bool ArrayStack<T>::isEmpty() {
    bool Result = (Head == 0);
    return Result;
}

template<class T>
bool ArrayStack<T>::canPush(const T &data, int MaxElements, int MaxAddress) {
    this->Push(data);
    return true;
}

template<class T>
T ArrayStack<T>::Pop() {
    if (isEmpty()) {
        Error error((QString) "���� ����!");
        throw error;
    }
    else {
        if (Head == Begin) {
            Head = 0;
            Log = "�������� �������� '" + (QString) *Begin +
                    "' �� ������� ����� �� ������ " + QString::number((int) Begin, 16);
            return *Begin;
        } else {
            Head = Head - 1;
            Log = "�������� �������� '" + (QString) (*(Head + 1)) +
                    "' �� ������� ����� �� ������ " + QString::number((int) (Head + 1), 16);
            return *(Head + 1);
        }
    }
}

template<class T>
T ArrayStack<T>::Top() {
    if (isEmpty()) {
        Error error((QString) "���� ����!");
        throw error;
    }
    else {
        Log = "������ � �������� '" + (QString) (*Head) +
                "' �� ������� ����� (��� ��������) �� ������ " + QString::number((int) Head, 16);
        return *Head;
    }
}

template<class T>
void ArrayStack<T>::Push(const T &data) {
    if (isEmpty()) {
        *Begin = data;
        Head = Begin;
        Log = "���������� �������� '" + (QString) (data) +
                "' �� ������ " + QString::number((int) Head, 16);
    } else {
        if (Head == Begin + MaxSize - 1) {
            Error error((QString) "������������ �����!", (QString) ("������� ���������� �������� '"
                                                                    + (QString) (data) + "' � ����, �� ���� ��� �����!"));
            throw error;
        } else {
            Head = Head + 1;
            Log = "���������� �������� '" + (QString) (data) +
                    "' �� ������ " + QString::number((int) Head, 16);
            *Head = data;
        }
    }
}

template<class T>
inline QString *ArrayStack<T>::getLog() {
    return &(this->Log);
}


#endif // ARRAYSTACK_H

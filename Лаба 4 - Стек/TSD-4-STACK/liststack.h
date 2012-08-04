#ifndef LISTSTACK_H
#define LISTSTACK_H
#include "stack.h"
#include "error.h"

template<class T>
struct TList {
    T data;
    TList* next;
};

template<class T>
class ListStack : public Stack<T>
{
public:
    inline ListStack();
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
    TList<T> *Begin;
    TList<T> *Head;
    QString Log;
    QString FreeAddresses;
};


template<class T>
inline ListStack<T>::ListStack()
{
    Begin = 0;
    Head = 0;
    Log = "Создание стека в виде списка";
    FreeAddresses = "";
}

template<class T>
void ListStack<T>::Free() {
    QString Addresses = "";
    TList<T> *temp = Head;
    while (temp != 0) {
        Addresses.append(QString::number((int) temp, 16));
        this->FreeAddresses.append(QString::number((int) temp, 16));
        temp = temp->next;
        if (temp != 0) {
            Addresses.append(", ");
            this->FreeAddresses.append("\n");
        }
    }

    while (Head != 0) {
        temp = Head;
        Head = Head->next;
        delete temp;
    }
    this->Log = (QString) "Освобождение памяти по адресам: " + Addresses;
}

template<class T>
bool ListStack<T>::isEmpty() {
    bool Result = (Head == 0);
    return Result;
}

template<class T>
void ListStack<T>::Clear()
{
    this->Free();
}

template<class T>
int ListStack<T>::Length() {
    TList<T> *Counter = this->Head;
    int Length = 0;
    while (Counter != 0) {
        Length++;
        Counter = Counter->next;
    }
    return Length;
}

template<class T>
QString ListStack<T>::getFreeAddresses()
{
    return (this->FreeAddresses);
}

template<class T>
bool ListStack<T>::canPush(const T &data, int MaxElements, int MaxAddress)
{
    if (this->Length() >= MaxElements)
        return false;
    this->Push(data);
    int HeadAddress = (int)(this->Head);
    if (HeadAddress > MaxAddress) {
        this->Pop();
        return false;
    }
    return true;
}

template<class T>
QString ListStack<T>::getBusyAddresses()
{
    QString BusyAddresses = "";
    TList<T> *temp = Head;
    while (temp != 0) {
        BusyAddresses.append(QString::number((int) temp, 16));
        temp = temp->next;
        if (temp != 0)
            BusyAddresses.append("\n");
    }
    return BusyAddresses;
}

template<class T>
T ListStack<T>::Pop() {
    if (isEmpty()) {
        Error error((QString) "Стек пуст!");
        throw error;
    } else {
        T toReturn = Head->data;
        TList<T> *toDelete = Head;
        this->FreeAddresses += QString::number((int) Head, 16) + "\n";
        Log = "Удаление элемента '" + (QString) (Head->data) +
                "' из вершины стека по адресу " + QString::number((int) Head, 16) + " с освобождением памяти";

        Head = Head->next;
        if (Head == 0)
            Begin = 0;

        delete toDelete;
        return toReturn;
    }
}

template<class T>
T ListStack<T>::Top() {
    if (isEmpty()) {
        Error error((QString) "Стек пуст!");
        throw error;
    } else {
        Log = "Доступ к элементу '" + (QString) (Head->data) +
                "' на вершине стека (без удаления) по адресу " + QString::number((int) Head, 16);
        return Head->data;
    }
}

template<class T>
void ListStack<T>::Push(const T &data) {
    TList<T> *toAdd = new TList<T>;
    toAdd->data = data;
    toAdd->next = Head;

    if (Head == 0)
        Begin = toAdd;

    Head = toAdd;

    Log = "Добавление элемента '" + (QString) (data) +
            "' по адресу " + QString::number((int) Head, 16) + " с выделением памяти";
}

template<class T>
inline QString *ListStack<T>::getLog() {
    return &(this->Log);
}


#endif // LISTSTACK_H

#ifndef QUEUE_H
#define QUEUE_H

#include <QString>

template<class T>
class Queue
{
public:
    virtual T Pop() = 0;
    virtual void Push(const T &data) = 0;
    virtual bool isEmpty() = 0;
    virtual void Free() = 0;
    virtual int Length() = 0;
    virtual void Clear() = 0;
};

#endif // QUEUE_H

#ifndef STACK_H
#define STACK_H
#include <QString>

template<class T>
class Stack
{
public:
    virtual T Pop() = 0;
    virtual void Push(const T &data) = 0;
    virtual bool isEmpty() = 0;
    virtual T Top() = 0;
    virtual QString *getLog() = 0;
    virtual void Free() = 0;
    virtual int Length() = 0;
    virtual void Clear() = 0;
    virtual QString getFreeAddresses() = 0;
    virtual QString getBusyAddresses() = 0;
    virtual bool canPush(const T &data, int MaxElements, int MaxAddress) = 0;
};

#endif // STACK_H

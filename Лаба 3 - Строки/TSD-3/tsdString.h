#ifndef TSDSTRING_H
#define TSDSTRING_H
#include <QString>


class tsdString {
protected:
    int size;
public:
    virtual void Create(QString* qSt) = 0;
    virtual QString getRenderedString() = 0;
    virtual void Free() = 0;
protected:
    int length() const;
    void setLength(int length);
};
#endif // TSDSTRING_H

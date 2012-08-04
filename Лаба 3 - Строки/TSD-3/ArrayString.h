#ifndef ARRAYSTRING_H
#define ARRAYSTRING_H

#include "tsdString.h"
#include <QString>

class ArrayString : public tsdString {
    QChar* arr;
public:
    void Create(QString* qSt);
    void Create(int size);
    QString getRenderedString();
    void Free();
private:
    ArrayString *Render();
    QString toString();
    ArrayString *getLastWord();
    bool isEquals(ArrayString *st);
    bool isRepeatedLetters();
    ArrayString *getNextWord(int &Position);
    void Append(ArrayString *st);

};
#endif // ARRAYSTRING_H

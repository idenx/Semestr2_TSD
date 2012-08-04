#ifndef LISTSTRING_H
#define LISTSTRING_H

#include "tsdString.h"
#include <QString>

struct tListStruct {
    QChar ch;
    tListStruct* ptr;
};

typedef struct tListStruct ListStruct;

class ListString : public tsdString {
    ListStruct* StringHead;
public:
    void Create(QString* qSt);
    void Create(int size);
    QString getRenderedString();
    void Free();
private:
    ListString *Render();
    QString toString();
    void Append(ListString *st);
    void Append(QChar ch);
    ListString *getNextWord(ListStruct* &Position);
    ListString* getLastWord();
    bool isEquals(ListString* st);
    bool isRepeatedLetters();
    ListStruct *getPtrToEnd();
};
#endif // LISTSTRING_H

#include "ListString.h"
#include <QString>

#define CHECK_NULL_PTR(ptr) if (ptr == 0) break;

void ListString::Create(QString* qSt) {
    this->size = qSt->length();
    ListStruct *head = 0, *temp = 0, *last = 0;
    for (int i = 0; i < qSt->length(); i++) {
        temp = new ListStruct;
        temp->ch = (*qSt)[i];
        temp->ptr = 0;

        if (i == 0)
            head = temp;
        else
            last->ptr = temp;

        last = temp;
    }
    this->StringHead = head;
}

void ListString::Free() {
    ListStruct *Saver = this->StringHead;
    ListStruct *toDelete;
    while (Saver != 0) {
        toDelete = Saver;
        Saver = Saver->ptr;
        delete toDelete;
    }
}

void ListString::Create(int size) {
    ListStruct *head = 0, *temp = 0, *last = 0;
    for (int i = 0; i < size; i++) {
        temp = new ListStruct;
        temp->ch = '\0';
        temp->ptr = 0;

        if (i == 0)
            head = temp;
        else
            last->ptr = temp;

        last = temp;
    }
    this->StringHead = head;
    this->size = size;
}


QString ListString::toString() {
    QString result;
    ListStruct* tmp = this->StringHead;
    int i = 0;
    for (int j = 0; j < this->length(); j++) {
        result[i++] = tmp->ch;
        tmp = tmp->ptr;
    }
    return result;
}

ListStruct *ListString::getPtrToEnd() {
    if (this->StringHead == 0)
        return 0;
    ListStruct *temp = this->StringHead;
    while (temp->ptr != 0)
        temp = temp->ptr;
    return temp;
}

void ListString::Append(ListString *st) {
    ListStruct *tmp = this->getPtrToEnd();
    if (this->StringHead != 0)
        tmp->ptr = st->StringHead;
    else
        this->StringHead = st->StringHead;
    this->setLength(this->length() + st->length());
}

void ListString::Append(QChar ch) {
    ListStruct *Last = new ListStruct;
    Last->ch = ch;
    Last->ptr = 0;

    ListStruct *tmp = this->getPtrToEnd();
    if (this->StringHead != 0)
        tmp->ptr = Last;
    else
        this->StringHead = Last;
    this->setLength(this->length() + 1);
}

bool ListString::isEquals(ListString* st) {
    if (this->length() != st->length()) {
        return false;
    }

    ListStruct *temp1 = this->StringHead, *temp2 = st->StringHead;
    while (temp1 != 0) {
        if (temp1->ch != temp2->ch) {
            return false;
        }
        temp1 = temp1->ptr;
        temp2 = temp2->ptr;
    }
    return true;
}

bool ListString::isRepeatedLetters() {
    ListStruct* temp1 = this->StringHead;
    ListStruct* temp2;

    while (temp1 != 0) {
        temp2 = temp1->ptr;
        while (temp2 != 0) {
            if (temp2->ch == temp1->ch) {
                return true;
            }
            temp2 = temp2->ptr;
        }
        temp1 = temp1->ptr;
    }
    return false;
}

ListString *ListString::getNextWord(ListStruct* &Position) {
    ListString *Word = new ListString;
    Word->Create(0);

    while (Position->ch == ' ') {
        Position = Position->ptr;
        CHECK_NULL_PTR(Position);
    }

    int WordLength = 0;
    while (Position->ch != ' ') {
        Word->Append(Position->ch);
        Position = Position->ptr;
        WordLength++;
        CHECK_NULL_PTR(Position);
    }

    Word->setLength(WordLength);
    return Word;
}

ListString* ListString::getLastWord() {
    ListString *Word = new ListString;

    // Найдем последнее слово в строке
    ListStruct *temp = this->StringHead;
    while (temp != 0) {
        Word->Create(0);
        while (temp->ch != ' '){
            Word->Append(temp->ch);
            temp = temp->ptr;
            CHECK_NULL_PTR(temp);
        }
        CHECK_NULL_PTR(temp);

        while (temp->ch == ' ') {
            temp = temp->ptr;
            CHECK_NULL_PTR(temp);
        }
    }

    return Word;
}

ListString *ListString::Render() {
    if (this->size == 0)
        return 0;

    ListString *Word,
            *LastWord = this->getLastWord();

    ListString *Result = new ListString;
    Result->Create(0);

    ListStruct *Position = this->StringHead;

    // Обработка строки
    QChar Space = ' ';
    while (Position != 0) {
        Word = getNextWord(Position);
        if (!(Word->isRepeatedLetters()) && !(Word->isEquals(LastWord))) {
            Result->Append(Word);
            Result->Append(Space);
        }
    }

    return Result;
}

QString ListString::getRenderedString() {
    return this->Render()->toString();
}

#include "ArrayString.h"
#include <QString>


void ArrayString::Create(QString* qSt) {
    this->size = qSt->length();
    this->arr = new QChar[this->size + 1];

    for (int i = 0; i < this->size; i++) {
        this->arr[i] = (*qSt)[i];
    }
}

void ArrayString::Free() {
    delete [] this->arr;
}

void ArrayString::Create(int size) {
    this->arr = new QChar[size + 1];
    this->size = size;
}

QString ArrayString::toString() {
    QString result;

    for (int i = 0; i < this->size; i++) {
        result[i] = this->arr[i];
    }
    return result;
}

ArrayString *ArrayString::getLastWord() {
    int f = 0;
    ArrayString *Word = new ArrayString;
    Word->Create(this->size + 1);

    ArrayString *LastWord = new ArrayString;
    LastWord->Create(this->size + 1);
    while (f < this->length()) {
        int k = 0;

        while (this->arr[f] != ' ' && (f < this->length())) {
            Word->arr[k++] = this->arr[f++];
        }

        Word->setLength(k);

        while ((this->arr[f] == ' ') && (f < this->length())) {
            f++;
        }
    }

    for (int i = 0; i < Word->length(); i++) {
        LastWord->arr[i] = Word->arr[i];
    }
    LastWord->setLength(Word->length());

    return LastWord;
}

bool ArrayString::isEquals(ArrayString *st) {
    if (st->length() != this->length())
        return false;
    for (int i = 0; i < this->length(); i++) {
        if (this->arr[i] != st->arr[i]) {
            return false;
        }
    }
    return true;
}

bool ArrayString::isRepeatedLetters() {
    for (int i = 0; i < this->length(); i++) {
        for (int j = i + 1; j < this->length(); j++) {
            if (this->arr[i] == this->arr[j]) {
                return true;
                break;
            }
        }
    }
    return false;
}

ArrayString *ArrayString::getNextWord(int &Position) {
    int WordPosition = 0;
    ArrayString *Word = new ArrayString;
    Word->Create(this->size + 1);

    while ((this->arr[Position] == ' ') && (Position < this->length())) {
        Position++;
    }

    while ((this->arr[Position] != ' ') && (Position < this->length())) {
        Word->arr[WordPosition++] = this->arr[Position++];
    }
    Word->setLength(WordPosition);
    return Word;
}

void ArrayString::Append(ArrayString *st) {
    if (st->length() != 0) {
        int r = this->length();
        for (int j = 0; j < st->length(); j++) {
            this->arr[r++] = st->arr[j];
        }
        this->setLength(r);
    }
}

ArrayString *ArrayString::Render() {
    // Находим последнее слово в строке
    if (this->size == 0)
        return 0;
    int pos = 0;

    ArrayString *Word;
    ArrayString *Space = new ArrayString;
    Space->Create(1);
    Space->arr[0] = ' ';

    // Найдем последнее слово в строке
    ArrayString *LastWord = this->getLastWord();

    // Обработка строки
    ArrayString *Result = new ArrayString;
    Result->Create(this->size + 1);
    Result->setLength(0);

    while (pos < this->length()) {
        Word = getNextWord(pos);
        if (!(Word->isRepeatedLetters()) && !(Word->isEquals(LastWord))) {
            Result->Append(Word);
            Result->Append(Space);
        }
    }
    return Result;
}

QString ArrayString::getRenderedString() {
    return this->Render()->toString();
}

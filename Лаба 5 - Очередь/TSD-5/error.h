#ifndef ERROR_H
#define ERROR_H
#include <QString>

class Error
{
    QString ErrorText;
    QString ErrorDescription;
public:
    Error(QString ErrorText, QString ErrorDescription);
    Error(QString ErrorText);
    void Show();
    QString getErrorDescription();
};

#endif // ERROR_H

#include "error.h"
#include <QTextCodec>
#include <QMessageBox>

Error::Error(QString ErrorText, QString ErrorDescription)
{
    this->ErrorText = ErrorText;
    this->ErrorDescription = ErrorDescription;
}

Error::Error(QString ErrorText) {
    this->ErrorText = ErrorText;
    this->ErrorDescription = "";

}

void Error::Show() {
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("CP1251"));
    QMessageBox msg;
    msg.setWindowTitle("Îøèáêà!");
    msg.setText(this->ErrorText);
    msg.exec();
}

QString Error::getErrorDescription() {
    return this->ErrorDescription;
}

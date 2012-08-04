#ifndef DIALOGADDR_H
#define DIALOGADDR_H

#include <QWidget>
#include <QString>

namespace Ui {
class DialogAddr;
}

class DialogAddr : public QWidget
{
    Q_OBJECT

public:
    explicit DialogAddr(QWidget *parent = 0);
    void setText(QString text);
    ~DialogAddr();
private:
    Ui::DialogAddr *ui;
};

#endif // DIALOGADDR_H

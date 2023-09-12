#ifndef DIALOGDOOR_H
#define DIALOGDOOR_H

#include <QDialog>
#include <QTimer>

#include "GlobalHeader.h"


namespace Ui {
class DialogDoor;
}

class DialogDoor : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDoor(QWidget *parent = nullptr);
    ~DialogDoor();

    int IsPlatformClosed();


public slots:
    void onTimer();

private:
    Ui::DialogDoor *ui;
    QTimer timer;
};

#endif // DIALOGDOOR_H

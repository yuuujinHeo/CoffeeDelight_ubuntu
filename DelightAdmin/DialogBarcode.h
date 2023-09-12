#ifndef DIALOGBARCODE_H
#define DIALOGBARCODE_H

#include <QDialog>
#include <QTimer>

#include "GlobalHeader.h"


namespace Ui {
class DialogBarcode;
}

class DialogBarcode : public QDialog
{
    Q_OBJECT

public:
    explicit DialogBarcode(QWidget *parent = nullptr);
    ~DialogBarcode();

    int NewInputNotification;
    QString NewBarcodePin;

public slots:
    void onTimer();

private:
    Ui::DialogBarcode *ui;
    QTimer timer;
};

#endif // DIALOGBARCODE_H

#ifndef DIALOGICECREAM_H
#define DIALOGICECREAM_H

#include <QDialog>
#include <QTimer>

#include "GlobalHeader.h"


namespace Ui {
class DialogIcecream;
}

class DialogIcecream : public QDialog
{
    Q_OBJECT

public:
    explicit DialogIcecream(QWidget *parent = nullptr);
    ~DialogIcecream();

    void DispenseIcecreamByWeight(int weight_g);
    void Tare();
    void SetCalibParam(int scale, int loadcell_id);

    int LoadcellValue();

    QString icecream_error;

public slots:
    void onTimer();

private slots:
    void on_BTN_SET_SCALE_2_clicked();

    void on_BTN_SET_SCALE_clicked();

    void on_BTN_TARE_clicked();

    void on_BTN_DISPENSE_ICECREAM_BY_WEIGHT_clicked();

    void on_BTN_ICECREAM_CLEANING_START_clicked();

    void on_BTN_ICECREAM_CLEANING_STOP_clicked();

private:
    Ui::DialogIcecream *ui;
    QTimer timer;
};

#endif // DIALOGICECREAM_H

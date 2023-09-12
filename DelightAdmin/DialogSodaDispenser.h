#ifndef DIALOGSODADISPENSER_H
#define DIALOGSODADISPENSER_H

#include <QDialog>
#include <QTimer>

#include "DialogStock.h"
#include "GlobalHeader.h"


namespace Ui {
class DialogSodaDispenser;
}

class DialogSodaDispenser : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSodaDispenser(QWidget *parent = nullptr, DialogStock *_stock = nullptr);
    ~DialogSodaDispenser();


    void DispenseSodaByTime(int time_ms);
    void DispenseSodaByWeight(int weight_g);
    void Tare();
    void SetCalibParam(int scale);

    int LoadcellValue();

    QString soda_error;

public slots:
    void onTimer();

private slots:
    void on_BTN_DISPENSE_SODA_BY_TIME_clicked();
    void on_BTN_DISPENSE_SODA_BY_WEIGHT_clicked();
    void on_BTN_TARE_clicked();
    void on_BTN_SET_SCALE_clicked();

private:
    Ui::DialogSodaDispenser *ui;
    QTimer timer;

    DialogStock *stock;
};

#endif // DIALOGSODADISPENSER_H

#ifndef DIALOGHOTDISPENSER_H
#define DIALOGHOTDISPENSER_H

#include <QDialog>
#include <QTimer>

#include "GlobalHeader.h"


namespace Ui {
class DialogHotDispenser;
}

class DialogHotDispenser : public QDialog
{
    Q_OBJECT

public:
    explicit DialogHotDispenser(QWidget *parent = nullptr);
    ~DialogHotDispenser();


    void DispenseHotByTime(int time_ms);
    void DispenseHotByWeight(int weight_g);
    void Tare();
    void SetCalibParam(int scale, int loadcell_id);

    int LoadcellValue();

    QString hot_error;

public slots:
    void onTimer();

private slots:
    void on_BTN_DISPENSE_HOT_BY_TIME_clicked();
    void on_BTN_DISPENSE_HOT_BY_WEIGHT_clicked();
    void on_BTN_TARE_clicked();
    void on_BTN_SET_SCALE_clicked();

    void on_BTN_SET_SCALE_2_clicked();

private:
    Ui::DialogHotDispenser *ui;
    QTimer timer;
};

#endif // DIALOGHOTDISPENSER_H

#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

class Logger : QObject
{
    Q_OBJECT

    static Logger instance;

public:
    Logger();

    void write(const QString &str, bool print=true);
    static void write_space();

    static void start_measure_takttime(const QString &menu);
    static void add_takttime(const QString &str, int time);
    static void stop_measure_takttime(const QString &menu, int time);
private:
    QFile *file;
    QFile *takttime_file;

    QString filename;
    QString filename_takttime;

    QString getFileName();
    QString gettakttimeFileName();
};

#endif // LOGGER_H

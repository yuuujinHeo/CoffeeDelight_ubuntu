#include "Logger.h"
#include "GlobalHeader.h"

#include <iostream>
#include <QDebug>



Logger Logger::instance;


Logger::Logger()
{
    filename = getFileName();
    file = new QFile;
    file->setFileName(filename);
    file->open(QIODevice::Append | QIODevice::Text);


    filename_takttime = getFileName();
    takttime_file = new QFile;
    takttime_file->setFileName(filename_takttime);
    takttime_file->open(QIODevice::Append | QIODevice::Text);
}

void Logger::write(const QString &str, bool print){
    QString text = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") + " " + str + "\n";


    QString tempname = instance.getFileName();
    if(tempname != instance.filename){
        // date changed
        if(instance.file->isOpen()){
            instance.file->close();
            delete instance.file;
        }
        instance.filename = tempname;
        instance.file = new QFile;
        instance.file->setFileName(instance.filename);
        instance.file->open(QIODevice::Append | QIODevice::Text);
    }

    if(print == true)
        qDebug() << str;

    QTextStream out(instance.file);
    out.setCodec("UTF-8");

    if(instance.file != nullptr){
        out << text;
    }
}

void Logger::write_space(){
    QString tempname = instance.getFileName();
    if(tempname != instance.filename){
        // date changed
        if(instance.file->isOpen()){
            instance.file->close();
            delete instance.file;
        }
        instance.filename = tempname;
        instance.file = new QFile;
        instance.file->setFileName(instance.filename);
        instance.file->open(QIODevice::Append | QIODevice::Text);
    }

    QTextStream out(instance.file);
    out.setCodec("UTF-8");

    if(instance.file != nullptr){
        out << "\n\n\n";
    }
}

void Logger::start_measure_takttime(const QString &menu){
    QString tempname = instance.gettakttimeFileName();
    if(tempname != instance.filename_takttime){
        // date changed
        if(instance.takttime_file->isOpen()){
            instance.takttime_file->close();
            delete instance.takttime_file;
        }
        instance.filename_takttime = tempname;
        instance.takttime_file = new QFile;
        instance.takttime_file->setFileName(instance.filename_takttime);
        instance.takttime_file->open(QIODevice::Append | QIODevice::Text);
    }

    QTextStream out(instance.takttime_file);
    out.setCodec("UTF-8");

    if(instance.takttime_file != nullptr){
        out << QDateTime::currentDateTime().toString("[hh:mm:ss]") + "===============================================================\n";
        out << QDateTime::currentDateTime().toString("[hh:mm:ss]") + "     START MEASURE :: " + menu + "\n";
        out << QDateTime::currentDateTime().toString("[hh:mm:ss]") + "---------------------------------------------------------------\n";
    }
}

void Logger::add_takttime(const QString &str, int time){
    QString msg = QDateTime::currentDateTime().toString("[hh:mm:ss]  ") + str + "    : " + QString().sprintf("%.2f sec",time/1000.) + "\n";
    QTextStream out(instance.takttime_file);
    out.setCodec("UTF-8");

    if(instance.takttime_file != nullptr){
        out << msg;
    }
}

void Logger::stop_measure_takttime(const QString &menu,int time){
    QTextStream out(instance.takttime_file);
    out.setCodec("UTF-8");

    if(instance.takttime_file != nullptr){
        out << QDateTime::currentDateTime().toString("[hh:mm:ss]") + "     STOP MEASURE :: " + menu + "\n";
        out << QDateTime::currentDateTime().toString("[hh:mm:ss]") + "     TAKT TIME :: " + QString().sprintf("%.2f sec",time/1000.)  + "\n";
        out << QDateTime::currentDateTime().toString("[hh:mm:ss]") + "===============================================================\n\n\n\n";
    }
}

QString Logger::getFileName(){
    QString tempname = QDateTime::currentDateTime().toString("LOG/yyyy_MM_dd") + "_log.txt";
    return tempname;
}

QString Logger::gettakttimeFileName(){
    QString tempname = "LOG/TAKT/" + QDateTime::currentDateTime().toString("yyyy_MM_dd") + "_takttime.txt";
    return tempname;
}

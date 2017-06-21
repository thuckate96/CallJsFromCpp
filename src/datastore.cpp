#include "datastore.h"
#include <QDebug>

DataStore::DataStore(QObject *parent) : QObject(parent), count(0), msg("0 hits"){

}

void DataStore::setMessage(QString str){
    msg = str;
    emit messageChanged();
}

int DataStore::qInvokeExample(QString str){
    qDebug(str.toLatin1());
    return count;
}

void DataStore::callMeFromQml(){
    qDebug("Inside from QML ");
    count++;
    setMessage(QString("%1 hits").arg(count));
}

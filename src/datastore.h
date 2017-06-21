#ifndef DATASTORE_H
#define DATASTORE_H
#include <QObject>

class DataStore : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)
public:
    explicit DataStore(QObject *parent = 0);
    QString message(){return msg;}
    void setMessage(QString str);
    Q_INVOKABLE int qInvokeExample(QString str);
signals:
    void messageChanged();
public slots:
    void callMeFromQml();
private:
    int count;
    QString msg;
};
#endif // DATASTORE_H

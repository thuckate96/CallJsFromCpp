#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QQmlContext>
#include "src/datastore.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QQmlContext* context = engine.rootContext();
    DataStore dt;
    context->setContextProperty("dataStore", &dt);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QObject* rof = engine.rootObjects().first();
    QVariant firstArg("arg++");
    QVariant retValue;
    QMetaObject::invokeMethod(rof, "functionInJavaScript",
                              Q_RETURN_ARG(QVariant, retValue),
                              Q_ARG(QVariant, firstArg));
    qDebug() << "Return value from javascript: " << retValue.toString() ;
    return app.exec();
}

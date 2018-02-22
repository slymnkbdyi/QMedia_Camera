#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuick/QQuickItem>
#include<QQmlContext>
#include<follow_gps.h>
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
   QQmlContext * ctx =engine.rootContext();
   follow_gps flwgps;
   ctx->setContextProperty("follow",&flwgps);
     engine.addImportPath(QStringLiteral(":/imports"));
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    QObject::connect(&engine, SIGNAL(quit()), qApp, SLOT(quit()));
    if (engine.rootObjects().isEmpty())
        return -1;
    return app.exec();
}

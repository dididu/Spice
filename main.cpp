#include <QtGui/QApplication>
#include <qdeclarative.h>
#include <QDeclarativeView>

#include "qmlapplicationviewer.h"
#include "todoitem.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<ToDoItem>("Spice", 1, 0, "ToDoItem");

    QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/Spice/main.qml"));
    viewer.showExpanded();

    return app.exec();
}

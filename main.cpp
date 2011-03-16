#include <QtGui/QApplication>
#include <qdeclarative.h>
#include <QDeclarativeView>
#include <QDeclarativeContext>


#include "qmlapplicationviewer.h"
#include "todoitem.h"
#include "todolistmodel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //qmlRegisterType<ToDoItem>("Spice", 1, 0, "ToDoItem");

    ToDoListModel model;
    model.addItem(ToDoItem("Wolf"));
    model.addItem(ToDoItem("Polar bear"));
    model.addItem(ToDoItem("Quoll"));

    QmlApplicationViewer viewer;

    QDeclarativeContext *ctxt = viewer.rootContext();
    ctxt->setContextProperty("ToDoModel", &model);

    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/Spice/main.qml"));
    viewer.showExpanded();

    return app.exec();
}

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
    model.addItem(ToDoItem(QDate(2011, 03, 17), "Wolf"));
    model.addItem(ToDoItem(QDate(2011, 03, 18), "Polar bear"));
    model.addItem(ToDoItem(QDate(2011, 03, 19), "Quoll"));

    model.writeXML("spice.xml");
    QmlApplicationViewer viewer;

    QDeclarativeContext *ctxt = viewer.rootContext();
    ctxt->setContextProperty("ToDoModel", &model);

    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/Spice/main.qml"));
    viewer.showExpanded();

    return app.exec();

}

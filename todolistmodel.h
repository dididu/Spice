#ifndef TODOLISTMODEL_H
#define TODOLISTMODEL_H

#include <QAbstractListModel>
#include "todoitem.h"

class ToDoListModel : public QAbstractListModel
{
    Q_OBJECT

public:

    enum ItemRoles {
             ItemTextRole = Qt::UserRole + 1,
             ItemDueDateRole
         };

    ToDoListModel(QObject *parent = 0);

    void addItem(const ToDoItem &item);
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role) const;


    void writeXML(QString fileName);
    void readXML(QString fileName);

private:

    ToDoItem& parseItem(QXmlStreamReader& );

    QList<ToDoItem> m_items;

signals:

public slots:

};

#endif // TODOLISTMODEL_H

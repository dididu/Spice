#include <QFile>
#include <QXmlStreamWriter>
#include "todolistmodel.h"

ToDoListModel::ToDoListModel(QObject *parent) :
    QAbstractListModel(parent)
{
    QHash<int, QByteArray> roles;
    roles[ItemTextRole] = "itemtext";
    roles[ItemDueDateRole] = "itemduedate";
    setRoleNames(roles);
}

void ToDoListModel::addItem(const ToDoItem &item)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_items << item;
    endInsertRows();
}

int ToDoListModel::rowCount(const QModelIndex & parent) const {
    return m_items.count();
}

QVariant ToDoListModel::data(const QModelIndex & index, int role) const {
    if (index.row() < 0 || index.row() > m_items.count())
        return QVariant();

    const ToDoItem &item = m_items[index.row()];
    if (role == ItemTextRole)
        return item.text();
    else if (role == ItemDueDateRole)
        return item.dueDate().toString();

    return QVariant();
}

void ToDoListModel::writeXML(QString fileName) {

    QFile file(fileName);
    file.open(QIODevice::WriteOnly);

    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("Spice");

    ToDoItem item;
    foreach(item, m_items) {
        item.writeXML(xmlWriter);
    }

    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();

    file.close();
}

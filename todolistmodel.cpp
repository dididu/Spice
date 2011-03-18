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

void ToDoListModel::readXML(QString fileName) {

    QFile file(fileName);
    file.open(QFile::ReadOnly | QFile::Text);

    QXmlStreamReader xml(&file);

    while(!xml.atEnd() && !xml.hasError()) {
            /* Read next element.*/
            QXmlStreamReader::TokenType token = xml.readNext();

            /* If token is just StartDocument, we'll go to next.*/
            if(token == QXmlStreamReader::StartDocument) continue;

            /* If token is StartElement, we'll see if we can read it.*/
            if(token == QXmlStreamReader::StartElement) {
                    /* If it's named persons, we'll go to the next.*/
                    if(xml.name() == "Spice") continue;

                    /* If it's named person, we'll dig the information from there.*/
                    if(xml.name() == "Item") this->addItem(this->parseItem(xml));
            }
    }

    file.close();
}


ToDoItem& ToDoListModel::parseItem(QXmlStreamReader& xml) {

    ToDoItem* item = new ToDoItem();

    /* Next element... */
    xml.readNext();
    /*
     * We're going to loop over the things because the order might change.
     * We'll continue the loop until we hit an EndElement named person.
     */
    while(!(xml.tokenType() == QXmlStreamReader::EndElement &&
                    xml.name() == "Item")) {

            xml.readNext();

            if(xml.name() == "Text"  && xml.tokenType() == QXmlStreamReader::StartElement) {
                xml.readNext();

                QString txt = xml.text().toString();
                item->setText(txt);
            }

            if(xml.name() == "DueDate" && xml.tokenType() == QXmlStreamReader::StartElement) {
                xml.readNext();

                QDate dueDate = QDate::fromString(xml.text().toString());
                item->setDueDate(dueDate);
            }
    }

    return (*item);
}


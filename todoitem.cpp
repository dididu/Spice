#include "todoitem.h"

ToDoItem::ToDoItem() {
}

ToDoItem::ToDoItem(QDate dueDate, QString text) {

    setText(text);
    setDueDate(dueDate);
}

QString ToDoItem::text() const {

    return m_text;
}

void ToDoItem::setText(QString newText) {

    m_text = newText;
}

QDate ToDoItem::dueDate() const {

    return m_duedate;
}

void ToDoItem::setDueDate(QDate newDueDate) {

    m_duedate = newDueDate;
}

void ToDoItem::writeXML(QXmlStreamWriter& xmlWriter) {

    xmlWriter.writeStartElement("Item");
    xmlWriter.writeTextElement("Text", this->text());
    xmlWriter.writeTextElement("DueDate", this->dueDate().toString());
    xmlWriter.writeEndElement();
}


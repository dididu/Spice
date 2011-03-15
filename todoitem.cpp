#include "todoitem.h"

ToDoItem::ToDoItem(QDeclarativeItem *parent) :
    QDeclarativeItem(parent)
{
}


QString ToDoItem::text() const {

    return m_text;
}

void ToDoItem::setText(QString newText) {

    m_text = newText;
}

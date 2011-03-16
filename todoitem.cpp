#include "todoitem.h"

ToDoItem::ToDoItem() {
}

ToDoItem::ToDoItem(QString text) {
    setText(text);
}

QString ToDoItem::text() const {

    return m_text;
}

void ToDoItem::setText(QString newText) {

    m_text = newText;
}

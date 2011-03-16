#ifndef TODOITEM_H
#define TODOITEM_H

#include <QDeclarativeItem>

class ToDoItem
{
public:
    ToDoItem();
    ToDoItem(QString text);

    QString text() const;
    void setText(QString newText);

private:
     QString m_text;
};

#endif // TODOITEM_H

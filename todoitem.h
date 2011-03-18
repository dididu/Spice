#ifndef TODOITEM_H
#define TODOITEM_H

#include <QDeclarativeItem>
#include <QDate>
#include <QXmlStreamWriter>

class ToDoItem
{
public:
    ToDoItem();
    ToDoItem(QDate duedate, QString text);

    QString text() const;
    void setText(QString newText);

    QDate dueDate() const;
    void setDueDate(QDate newDueDate);

    void writeXML(QXmlStreamWriter& );

private:
     QString m_text;
     QDate m_duedate;
};

#endif // TODOITEM_H

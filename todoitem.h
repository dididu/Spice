#ifndef TODOITEM_H
#define TODOITEM_H

#include <QDeclarativeItem>

class ToDoItem : public QDeclarativeItem
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText)

public:
    ToDoItem(QDeclarativeItem *parent = 0);

    QString text() const;
    void setText(QString newText);

private:
     QString m_text;

signals:

public slots:

};

#endif // TODOITEM_H

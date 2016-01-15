#ifndef BLUEGIGA_H
#define BLUEGIGA_H

#include <QObject>

class bluegiga : public QObject
{
    Q_OBJECT
public:
    explicit bluegiga(QObject *parent = 0);

signals:

public slots:
};

#endif // BLUEGIGA_H
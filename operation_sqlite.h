#ifndef OPERATION_SQLITE_H
#define OPERATION_SQLITE_H

#include <QString>
#include <QtSql>
#include <QDebug>

class OperationSqlite
{
public:
    static bool ConnectDB(QString);
    static bool CreateTable(QString);

private:
    OperationSqlite();

    static QSqlDatabase m_db;
};

#endif // OPERATION_SQLITE_H

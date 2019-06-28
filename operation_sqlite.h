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
    static bool insertRow(QString, QString, QString, QString, QString);
    static QSqlQuery selectShowAll();

private:
    OperationSqlite();

    static QSqlDatabase m_db;
    static QString m_tablename;
};

#endif // OPERATION_SQLITE_H

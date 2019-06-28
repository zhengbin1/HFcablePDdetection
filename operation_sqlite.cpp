#include "operation_sqlite.h"

QSqlDatabase OperationSqlite::m_db = QSqlDatabase::addDatabase( "QSQLITE" );

bool OperationSqlite::ConnectDB(QString dbnameall)
{
    m_db.setDatabaseName(dbnameall);

    if(m_db.open())
    {
        return true;
    } else {
        qDebug() << m_db.lastError();
        qDebug() << "Failed to connect.";
        return false;
    }
}

bool OperationSqlite::CreateTable(QString tablename)
{
    QSqlQuery query(m_db);
    QString strSql;
    strSql = QString("CREATE TABLE IF NOT EXISTS %1 (substation VARCHAR(100), devicetype VARCHAR(100), voltagegrade VARCHAR(100), detection VARCHAR(100), position VARCHAR(100))").arg(tablename);
    query.prepare(strSql);
    if(query.exec())
    {
        return true;
    }
    else
    {
        qDebug() << query.lastError();
        return false;
    }
}

OperationSqlite::OperationSqlite() {}

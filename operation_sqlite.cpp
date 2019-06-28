#include "operation_sqlite.h"

QSqlDatabase OperationSqlite::m_db = QSqlDatabase::addDatabase( "QSQLITE" );
QString OperationSqlite::m_tablename = QString();

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
    m_tablename = tablename;
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

// strSubstation 变电站名称 strDeviceType 设备类型 strVoltageGrade 电压等级 strDetection 检测相别 strPosition 检测位置
bool OperationSqlite::insertRow(QString strSubstation, QString strDeviceType, QString strVoltageGrade, QString strDetection, QString strPosition)
{
    QSqlQuery query(m_db);
    QString strSql;
    strSql = QString("INSERT INTO %1 (substation, devicetype, voltagegrade, detection, position) VALUES (?, ?, ?, ?, ?)").arg(m_tablename);
    query.prepare(strSql);
    query.bindValue(0, strSubstation);
    query.bindValue(1, strDeviceType);
    query.bindValue(2, strVoltageGrade);
    query.bindValue(3, strDetection);
    query.bindValue(4, strPosition);

    if(query.exec())
    {
        return true;
    } else {
        qDebug() << query.lastError();
        return false;
    }

}

QSqlQuery OperationSqlite::selectShowAll()
{
    QSqlQuery query(m_db);
    QString strSql;
    strSql = QString("SELECT * FROM %1;").arg(m_tablename);

    query.exec(strSql);

    return query;
}

OperationSqlite::OperationSqlite() {}

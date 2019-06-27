#ifndef OPERATION_FILE_H
#define OPERATION_FILE_H

#include <QObject>
#include <QString>
#include <QDir>


class OperationFile
{
public:

    static bool isDirExist(QString);

    static QString strRootPath;  // 存放的根目录

private:

};

#endif // OPERATION_FILE_H

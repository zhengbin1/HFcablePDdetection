#include "operation_file.h"

bool OperationFile::isDirExist(QString fullPath)
{
    QDir dir(fullPath);

    if(dir.exists())
    {
        return true;
    }

    dir.mkpath(fullPath);
    return false;
}

QString OperationFile::strRootPath = QString("C:\\局放测试数据\\测试\\");

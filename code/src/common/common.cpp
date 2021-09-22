#include <QDesktopWidget>
#include <QFile>
#include <QDebug>

#include "common.h"

Common::Common()
{
}

Common::~Common()
{
}

void Common::readQssFile(QString strQssFile, QWidget *pWidget)
{
    QFile file(strQssFile);
    file.open(QFile::ReadOnly);
    if (file.isOpen()) {
        pWidget->setStyleSheet(file.readAll());
        file.close();
    } else
        qDebug() << "open file is faild = " << strQssFile;
    return;
}
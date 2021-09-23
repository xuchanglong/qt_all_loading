#include <QDesktopWidget>
#include <QFile>
#include <QDebug>
#include <QApplication>

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

void Common::moveWin2ScreenCenter(QWidget *win)
{
    if (win == nullptr)
        return;
    QDesktopWidget *desktopWidget = QApplication::desktop();
    int nWidth = desktopWidget->availableGeometry().width();
    int nHeight = desktopWidget->availableGeometry().height();
    int x = nWidth / 2 - win->width() / 2;
    int y = nHeight / 2 - win->height() / 2;
    win->move(x, y);
    return;
}
#ifndef COMMON_H
#define COMMON_H

class Common {
public:
    explicit Common();
    ~Common();

public:
    static void readQssFile(QString strQssFile, QWidget *pWidget);
    static void moveWin2ScreenCenter(QWidget *);
};

#endif

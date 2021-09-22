#ifndef COMMON_H
#define COMMON_H

class Common {
public:
    explicit Common();
    ~Common();

public:
    static void readQssFile(QString strQssFile, QWidget *pWidget);
};

#endif

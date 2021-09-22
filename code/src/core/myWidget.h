#ifndef MYWIDGET_H_
#define MYWIDGET_H_

#include "baseGui/solidCircleLoadingWin.h"

class MyWidget : public QWidget {
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

private:
    void InitSolidCircleLoadingWin();

private:
    SolidCircleLoadingWin *m_pSolidCircleLoadingWin;
};

#endif
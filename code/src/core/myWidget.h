#ifndef MYWIDGET_H_
#define MYWIDGET_H_

#include "baseGui/solidCircleLoadingWin.h"
#include "baseGui/dotCircleLoadingWin.h"

class MyWidget : public QWidget {
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

private:
    void InitSolidCircleLoadingWin();
    void InitDotCircleLoadingWin();

private:
    SolidCircleLoadingWin *m_pSolidCircleLoadingWin;
    DotCircleLoadingWin *m_pDotCircleLoadingWin;
};

#endif
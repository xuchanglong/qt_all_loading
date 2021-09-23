#ifndef MYWIDGET_H_
#define MYWIDGET_H_

#include "baseGui/solidCircleLoadingWin.h"
#include "baseGui/dotCircleLoadingWin.h"
#include "baseGui/customProgressIndicator.h"

class MyWidget : public QWidget {
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

private:
    void InitSolidCircleLoadingWin();
    void InitDotCircleLoadingWin();
    void InitCustomProgressIndicator();

private:
    SolidCircleLoadingWin *m_pSolidCircleLoadingWin;
    DotCircleLoadingWin *m_pDotCircleLoadingWin;
    CustomProgressIndicator *m_pCustomProgressIndicator;
};

#endif
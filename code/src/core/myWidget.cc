#include "myWidget.h"
#include "common/common.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(500, 400);
    InitSolidCircleLoadingWin();
    InitDotCircleLoadingWin();
}

MyWidget::~MyWidget()
{
}

void MyWidget::InitSolidCircleLoadingWin()
{
    m_pSolidCircleLoadingWin = new SolidCircleLoadingWin(this);
    m_pSolidCircleLoadingWin->setObjectName("m_pSolidCircleLoadingWin");
    m_pSolidCircleLoadingWin->setGeometry(50, 50, 50, 50);
    SolidCircleLoadingWin::sInfo info;
    info.m_darkest_color = QColor("#00B64B");
    info.m_lightest_color = QColor(255, 255, 255, 0);
    info.m_str_background_color = "rgba(0, 0, 0, 0)";
    info.m_msec_by_one_degree = 2;
    m_pSolidCircleLoadingWin->setParas(info);
    m_pSolidCircleLoadingWin->start();
    return;
}

void MyWidget::InitDotCircleLoadingWin()
{
    m_pDotCircleLoadingWin = new DotCircleLoadingWin(this);
    m_pDotCircleLoadingWin->setObjectName("m_pDotCircleLoadingWin");
    m_pDotCircleLoadingWin->setGeometry(150, 50, 50, 50);
    m_pDotCircleLoadingWin->setDotCount(10);
    m_pDotCircleLoadingWin->setDotColor(QColor("#00B64B"));
    m_pDotCircleLoadingWin->setMaxDiameter(10);
    m_pDotCircleLoadingWin->setMinDiameter(2);
    m_pDotCircleLoadingWin->start();
    return;
}
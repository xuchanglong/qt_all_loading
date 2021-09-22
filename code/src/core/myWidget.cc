#include "myWidget.h"
#include "common/common.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(500, 400);
    InitSolidCircleLoadingWin();
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
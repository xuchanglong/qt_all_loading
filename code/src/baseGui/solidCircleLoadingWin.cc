#include "solidCircleLoadingWin.h"
#include <QPainter>

SolidCircleLoadingWin::SolidCircleLoadingWin(QWidget *parent)
    : QFrame(parent)
{
    m_timer_id = 0;
    m_rotation_degree = 0;
    setWindowFlag(Qt::FramelessWindowHint);
    //setWindowOpacity(0);
    setStyleSheet("SolidCircleLoadingWin{background:red;}");
}

SolidCircleLoadingWin::~SolidCircleLoadingWin()
{
    end();
}

void SolidCircleLoadingWin::start()
{
    m_timer_id = startTimer(m_info.m_msec_by_one_degree);
    return;
}

void SolidCircleLoadingWin::end()
{
    if (m_timer_id == 0)
        return;
    killTimer(m_timer_id);
    return;
}

void SolidCircleLoadingWin::paintEvent(QPaintEvent *e)
{
    int width = this->width();
    int height = this->height();
    int side = qMin(width, height);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter.translate(width / 2, height / 2);
    painter.scale(0.5, 0.5);

    QConicalGradient gra(QPoint(0, 0), 0);
    gra.setColorAt(0, m_info.m_darkest_color);
    gra.setColorAt(1, m_info.m_lightest_color);
    QBrush brush(gra);

    int radis = side;
    int sider = side * 0.2;
    QRect rect(-radis, -radis, radis * 2, radis * 2);
    QPainterPath path;
    path.arcTo(rect, 0, 360);

    QPainterPath subPath;
    subPath.addEllipse(rect.adjusted(sider, sider, -sider, -sider));

    path = path - subPath;
    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);
    painter.rotate(m_rotation_degree);
    painter.drawPath(path);
    return QFrame::paintEvent(e);
}

void SolidCircleLoadingWin::timerEvent(QTimerEvent *e)
{
    m_rotation_degree++;
    if (m_rotation_degree == 360) {
        m_rotation_degree = 0;
    }
    update();
    return QFrame::timerEvent(e);
}
#include "dotCircleLoadingWin.h"
#include "qmath.h"
#include <QDebug>

DotCircleLoadingWin::DotCircleLoadingWin(QWidget *parent)
    : QFrame(parent)
    , _i(0)
    , _interval(50)
    , _index(0)
{
    this->setWindowFlags(Qt::FramelessWindowHint);

    setDotColor(QColor(49, 177, 190));
    setDotCount(20);
    connect(&timer, &QTimer::timeout, this, &DotCircleLoadingWin::slot_refresh);
    setMaxDiameter(30);
    setMinDiameter(5);
}

void DotCircleLoadingWin::setDotCount(int count)
{
    _dotCount = count;
}

void DotCircleLoadingWin::setDotColor(const QColor &color)
{
    _dotColor = color;
}

void DotCircleLoadingWin::start()
{
    timer.setInterval(_interval);
    timer.start();
    return;
}

void DotCircleLoadingWin::setMaxDiameter(float max)
{
    _maxDiameter = max;
}

void DotCircleLoadingWin::setMinDiameter(float min)
{
    _minDiameter = min;
}

void DotCircleLoadingWin::slot_refresh()
{
    repaint();
    return;
}

void DotCircleLoadingWin::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)
    caculate();
    return;
}

void DotCircleLoadingWin::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setPen(_dotColor);
    painter.setBrush(_dotColor);

    paintDot(painter);
    return;
}

void DotCircleLoadingWin::caculate()
{
    int center_x = 0, center_y = 0;
    _squareWidth = qMin(this->width(), this->height());
    if (this->width() > this->height()) {
        center_x = this->width() / 4;
    } else if (this->width() < this->height()) {
        center_y = this->height() / 4;
    }
    float half = _squareWidth / 2;
    _centerDistance = half - _maxDiameter / 2 - 1;

    float gap = (_maxDiameter - _minDiameter) / (_dotCount - 1) / 2;
    float angleGap = (float)360 / _dotCount;

    locationList.clear();
    radiiList.clear();

    for (int i = 0; i < _dotCount; i++) {
        radiiList << _maxDiameter / 2 - i * gap;
        float radian = qDegreesToRadians(-angleGap * i);
        locationList.append(sLocation(half + _centerDistance * qCos(radian) + center_x, half - _centerDistance * qSin(radian) + center_y));
    }
    return;
}

void DotCircleLoadingWin::paintDot(QPainter &painter)
{
    for (int i = 0; i < _dotCount; i++) {
        painter.setPen(_dotColor);
        //半径
        float radii = radiiList.at((_index + _dotCount - i) % _dotCount);

        //绘制圆点
        painter.drawEllipse(QPointF(locationList.at(i).x, locationList.at(i).y), radii, radii);
        //绘制正方形
        //painter.drawRect(locationList.at(i).x,locationList.at(i).y,radii,radii);
        //绘制文字
        //QFont font("Microsoft YaHei",radii*1.2,75);
        //painter.setFont(font);
        //painter.drawText(QPointF(locationList.at(i).x,locationList.at(i).y),u8"霞");
    }
    _index++;
    return;
}

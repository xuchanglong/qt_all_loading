#include "customProgressIndicator.h"
#include <QPainter>

CustomProgressIndicator::CustomProgressIndicator(QWidget *parent)
    : QFrame(parent)
    , angle_(0)
    , timerId_(-1)
    , delay_(20)
    , displayedWhenStopped_(false)
    , color_(Qt::green)
{
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setFocusPolicy(Qt::NoFocus);
}

bool CustomProgressIndicator::isAnimated() const
{
    return (timerId_ != -1);
}

void CustomProgressIndicator::setDisplayedWhenStopped(bool state)
{
    displayedWhenStopped_ = state;
    update();
    return;
}

bool CustomProgressIndicator::isDisplayedWhenStopped() const
{
    return displayedWhenStopped_;
}

void CustomProgressIndicator::startAnimation()
{
    angle_ = 0;

    if (timerId_ == -1) {
        timerId_ = startTimer(delay_);
    }
    return;
}

void CustomProgressIndicator::stopAnimation()
{
    if (timerId_ != -1) {
        killTimer(timerId_);
    }
    timerId_ = -1;
    update();
    return;
}

void CustomProgressIndicator::setAnimationDelay(int delay)
{
    if (timerId_ != -1) {
        killTimer(timerId_);
    }
    delay_ = delay;
    if (timerId_ != -1) {
        timerId_ = startTimer(delay_);
    }
    return;
}

void CustomProgressIndicator::setColor(const QColor &color)
{
    color_ = color;
    update();
    return;
}

QSize CustomProgressIndicator::sizeHint() const
{
    return QSize(25, 25);
}

void CustomProgressIndicator::timerEvent(QTimerEvent * /*event*/)
{
    angle_ = (angle_ + 30) % 360;
    update();
    return;
}

void CustomProgressIndicator::paintEvent(QPaintEvent * /*event*/)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);
    if (!displayedWhenStopped_ && !isAnimated()) {
        p.drawPixmap(rect(), currentPix_);
        return;
    }

    int width = qMin(this->width(), this->height());

    int outerRadius = (width - 1) >> 1;
    int innerRadius = ((width - 1) >> 1) * 0.38;

    int capsuleHeight = outerRadius - innerRadius;
    int capsuleWidth = (width > 32) ? capsuleHeight * .23 : capsuleHeight * .35;
    int capsuleRadius = capsuleWidth >> 1;

    /* 撰写进度 */
    if (progress_ > 0 && progress_ < 100) {
        p.setPen(color_);
        p.drawText(rect(), Qt::AlignCenter, QString("%1%").arg(progress_));
    } else if (progress_ == 100) {
        stopAnimation();
    }

    for (int i = 0; i < 12; ++i) {
        QColor color = color_;
        color.setAlphaF(1.0f - (i / 12.0f));
        p.setPen(Qt::NoPen);
        p.setBrush(color);
        p.save();
        p.translate(rect().center());
        p.rotate(angle_ - i * 30.0f);
        p.drawRoundedRect(((-capsuleWidth) >> 1), -(innerRadius + capsuleHeight), capsuleWidth, capsuleHeight, capsuleRadius, capsuleRadius);
        p.restore();
    }
    return;
}
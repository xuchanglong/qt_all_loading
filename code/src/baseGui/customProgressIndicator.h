#ifndef CUSTOMPROGRESSINDICATOR_H
#define CUSTOMPROGRESSINDICATOR_H

#include <QFrame>
#include <QColor>

class CustomProgressIndicator : public QFrame {
    Q_OBJECT
    Q_PROPERTY(int delay READ animationDelay WRITE setAnimationDelay)
    Q_PROPERTY(bool displayedWhenStopped READ isDisplayedWhenStopped WRITE setDisplayedWhenStopped)
    Q_PROPERTY(QColor color READ color WRITE setColor)

public:
    explicit CustomProgressIndicator(QWidget *parent = 0);

public:
    int animationDelay() const { return delay_; }
    bool isAnimated() const;

    /*  动画完毕后，是否隐藏菊花转  */
    bool isDisplayedWhenStopped() const;

    /*  当前菊花转的颜色  */
    const QColor &color() const { return color_; }

    /*  虚函数：当前大小  */
    virtual QSize sizeHint() const;

    void setBackground(const QString &_icon)
    {
        currentPix_ = QPixmap(_icon);
    }

signals:
    void Finished(void);

public slots:
    void startAnimation();
    void stopAnimation();

    /*  设置菊花转的转速  */
    void setAnimationDelay(int delay);

    /*  动画完毕后，是否隐藏菊花转  */
    void setDisplayedWhenStopped(bool state);

    /*  设置菊花转颜色  */
    void setColor(const QColor &color);

    /*
     * 进度
     * 参数 _progress：当前进度 0 < _progress < 100
    */
    void onProgress(short _progress) { progress_ = _progress; }

protected:
    virtual void timerEvent(QTimerEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;

private:
    unsigned int angle_;
    int timerId_;
    /*  转速  */
    int delay_;
    /*  是否隐藏  */
    bool displayedWhenStopped_;
    QColor color_;
    /*  进度  */
    short progress_;
    /*  背景图  */
    QPixmap currentPix_;
};

#endif // CUSTOMPROGRESSINDICATOR_H
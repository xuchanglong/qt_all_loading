#ifndef DOTCIRCLELOADINGWIN_H_
#define DOTCIRCLELOADINGWIN_H_

#include <QFrame>
#include <QPainter>
#include <QTimer>
#include <QMap>

struct sLocation {
    explicit sLocation(float _x, float _y)
    {
        x = _x;
        y = _y;
    }
    float x;
    float y;
};

class DotCircleLoadingWin : public QFrame {
    Q_OBJECT

public:
    explicit DotCircleLoadingWin(QWidget *parent = nullptr);

public:
    void setDotCount(int);
    void setDotColor(const QColor &);
    void start();
    void setMaxDiameter(float);
    void setMinDiameter(float);

protected:
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void resizeEvent(QResizeEvent *event) override;

private slots:
    void slot_refresh();

    private:
        void paintDot(QPainter &);
    void caculate();


private:
    //刷新计数
    int _index;
    QColor _dotColor;
    int _dotCount;
    float _minDiameter;
    float _maxDiameter;
    //计数
    int _i;
    //时间间隔 单位：毫秒(ms)
    int _interval;
    //定时器
    QTimer timer;
    //绘制区域边长
    float _squareWidth;
    //圆的直径
    float _centerDistance;
    //直径列表
    QList<float> radiiList;
    //圆点坐标列表
    QList<sLocation> locationList;
};

#endif

#ifndef SOLIDCIRCLELOADING_H_
#define SOLIDCIRCLELOADING_H_

#include <QFrame>

class SolidCircleLoadingWin : public QFrame {
    Q_OBJECT

public:
    struct sInfo {
        sInfo()
        {
            m_msec_by_one_degree = 0;
        }
        QColor m_lightest_color;
        QColor m_darkest_color;
        unsigned char m_msec_by_one_degree;
    };

public:
    explicit SolidCircleLoadingWin(QWidget *parent = NULL);
    ~SolidCircleLoadingWin();

public:
    inline void setParas(sInfo info) { m_info = info; };
    void start();
    void end();

protected:
    virtual void paintEvent(QPaintEvent *);
    virtual void timerEvent(QTimerEvent *);

private:
    int m_timer_id;
    int m_rotation_degree;
    sInfo m_info;
};

#endif
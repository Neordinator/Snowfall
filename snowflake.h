#ifndef SNOWFLAKE_H
#define SNOWFLAKE_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QPointF>
#include <QApplication>
#include <QPixmap>
#include <QTimer>
#include <QTime>
#include <QDebug>
#include <QRandomGenerator64>

class Snowflake : public QObject, public QGraphicsItem
{
    Q_OBJECT
    //Q_INTERFACES
public:
    int DistanceLevel;

    Snowflake(int, int, int);
    //explicit Snowflake(QObject *parent = 0);
    Snowflake();
    ~Snowflake();
    QRectF boundingRect() const override;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;

    int randomBetween(int, int);
    void setImage(QString);
    void moving();
    void rotate();

signals:
    void btnMouseReleaseEvent(Qt::MouseButton);

private:
    QPixmap mPixMap;
    int mWidth{32}, mHeight{32};
    int mWindowWidth, mWindowHeight;
    int mAngle;

    QPointF mStartMovePos{100, 0};
    QPointF mEndMovePos{100, 800};

    QRandomGenerator64 qsrand;
    QTimer mTimer;
    int mTime;
    int mTextureNumber;

    void construction(int/*distance*/, int/*window Width*/, int/*window Height*/);

private slots:
    void timerSlot();
};

#endif // SNOWFLAKE_H

#include "snowflake.h"

Snowflake::Snowflake(int Distance, int WindowW, int WindowH)
//Snowflake::Snowflake(QObject *parent) : QObject(parent), QGraphicsItem()
{
    this->construction(Distance, WindowW, WindowH);
}
Snowflake::Snowflake()
{
    this->construction(Snowflake::randomBetween(1, 9), 800, 800);
}
Snowflake::~Snowflake()
{
}

QRectF Snowflake::boundingRect() const
{
    return QRectF(0, 0, mWidth, mHeight);
}

void Snowflake::paint(QPainter *painter, const QStyleOptionGraphicsItem* /*option*/, QWidget* /*widget*/)
{
    painter->drawPixmap(0, 0, mWidth, mHeight, mPixMap);
}

void Snowflake::setImage(QString aPath)
{
    mPixMap.load(aPath);
    mWidth = mPixMap.width();
    mHeight = mPixMap.height();
}

void Snowflake::moving()
{
    if(this->pos().y() < mEndMovePos.y() - mHeight)
    {
        this->moveBy(0, 1);
    }
    else
    {
        this->deleteLater();
    }
}

void Snowflake::rotate()
{
    ++mAngle;
    this->setRotation(mAngle);
}

void Snowflake::construction(int Distance, int WindowW, int WindowH)
{
    mTextureNumber = Snowflake::randomBetween(3, 5);
    switch (mTextureNumber)
    {
    case 3:
        Snowflake::setImage(":/images/textures/Snowflake1_32.png");
        break;
    case 4:
        Snowflake::setImage(":/images/textures/Snowflake2_32.png");
        break;
    case 5:
        Snowflake::setImage(":/images/textures/Snowflake3_32.png");
        break;
    }
    DistanceLevel = Distance;
    mWindowWidth = WindowW, mWindowHeight = WindowH;
    mAngle = 0;

    mStartMovePos.setX(Snowflake::randomBetween(0, mWindowWidth));
    mStartMovePos.setY(0);
    mEndMovePos.setX(mStartMovePos.x());
    if(DistanceLevel == 1)
    {
        mEndMovePos.setY(mWindowHeight);
    }
    else
    {
        mEndMovePos.setY(mWindowHeight - (mWindowHeight * (0.10f * DistanceLevel)));
    }
    Snowflake::setPos(mStartMovePos);
    Snowflake::setScale(1.00f / (float)DistanceLevel);

    connect(&mTimer, SIGNAL(timeout()), this, SLOT(timerSlot()));
    mTimer.start(25);
}

void Snowflake::timerSlot()
{
    ++mTime;
    Snowflake::rotate();
    Snowflake::moving();
    this->update();
}

int Snowflake::randomBetween(int low, int high)
{
    qsrand.seed(QDateTime::currentMSecsSinceEpoch());
    return (qsrand.generate64() % ((high + 1) - low) + low);
}

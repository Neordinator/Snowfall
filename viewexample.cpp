#include "viewexample.h"

ViewExample::ViewExample(int WindowW, int WindowH)
{
    this->construction(WindowW, WindowH);
}

ViewExample::ViewExample()
{
    this->construction(800, 800);
}

ViewExample::~ViewExample()
{
    this->garbageCollection();
}

void ViewExample::construction(int WindowW, int WindowH)
{
    mBackGround.load(":/images/textures/BigMoon_852x480.png");

    setRenderHint(QPainter::Antialiasing);
    setCacheMode(QGraphicsView::CacheNone);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setWindowTitle("View Example");
    setFrameStyle(0);

    setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
    if(mBackGround.width() == mScene.width() && mBackGround.height() == mScene.height())
    {
        setSceneRect(0, 0, WindowW, WindowH);
        setFixedSize(WindowW, WindowH);
    }
    else
    {
        setSceneRect(0, 0, mBackGround.width(), mBackGround.height());
        setFixedSize(mBackGround.width(), mBackGround.height());
    }

    mScene.setItemIndexMethod(QGraphicsScene::NoIndex);
    mScene.setBackgroundBrush(mBackGround);
    setScene(&mScene);

    qsrand = new QRandomGenerator64();
    mSceneTimer = new QTimer();
    connect(mSceneTimer, SIGNAL(timeout()), this, SLOT(toSnowfall()));
    mSceneTimer->start(200);
}

int ViewExample::randomBetween(int low, int high)
{
    qsrand->seed(QDateTime::currentMSecsSinceEpoch());
    return (qsrand->generate64() % ((high + 1) - low) + low);
}

void ViewExample::garbageCollection()
{
    for(auto i : Snowfall_1)
    {
        delete i;
    }
    for(auto i : Snowfall_2)
    {
        delete i;
    }
    for(auto i : Snowfall_3)
    {
        delete i;
    }
    for(auto i : Snowfall_4)
    {
        delete i;
    }
    for(auto i : Snowfall_5)
    {
        delete i;
    }
    for(auto i : Snowfall_6)
    {
        delete i;
    }
    for(auto i : Snowfall_7)
    {
        delete i;
    }
    for(auto i : Snowfall_8)
    {
        delete i;
    }
    for(auto i : Snowfall_9)
    {
        delete i;
    }
    delete mSceneTimer;
    delete qsrand;
}
//
//-----------------------------------------------S.L.O.T.S
//
void ViewExample::toSnowfall()
{
    int Distance = ViewExample::randomBetween(1, 9);
    Snowflake* snowflake = new Snowflake(Distance, window()->width(), window()->height());
    switch (Distance)
    {
    case 1:
        this->Snowfall_1.push_back(snowflake);
        mScene.addItem(Snowfall_1.back());
        break;
    case 2:
        this->Snowfall_2.push_back(snowflake);
        mScene.addItem(Snowfall_2.back());
        break;
    case 3:
        this->Snowfall_3.push_back(snowflake);
        mScene.addItem(Snowfall_3.back());
        break;
    case 4:
        this->Snowfall_4.push_back(snowflake);
        mScene.addItem(Snowfall_4.back());
        break;
    case 5:
        this->Snowfall_5.push_back(snowflake);
        mScene.addItem(Snowfall_5.back());
        break;
    case 6:
        this->Snowfall_6.push_back(snowflake);
        mScene.addItem(Snowfall_6.back());
        break;
    case 7:
        this->Snowfall_7.push_back(snowflake);
        mScene.addItem(Snowfall_7.back());
        break;
    case 8:
        this->Snowfall_8.push_back(snowflake);
        mScene.addItem(Snowfall_8.back());
        break;
    case 9:
        this->Snowfall_9.push_back(snowflake);
        mScene.addItem(Snowfall_9.back());
        break;
    }
}

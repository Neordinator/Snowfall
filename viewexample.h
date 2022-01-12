#ifndef VIEWEXAMPLE_H
#define VIEWEXAMPLE_H

#include <QVector>
#include <QGraphicsView>
#include <QGraphicsScene>

#include "snowflake.h"

class ViewExample : public QGraphicsView
{
    Q_OBJECT

public:
    ViewExample(int, int);
    ViewExample();
    ~ViewExample();


private:
    QGraphicsScene mScene;
    QPixmap mBackGround;

    QTimer* mSceneTimer;
    QRandomGenerator64* qsrand;

    std::list<Snowflake*> Snowfall_1;
    std::list<Snowflake*> Snowfall_2;
    std::list<Snowflake*> Snowfall_3;
    std::list<Snowflake*> Snowfall_4;
    std::list<Snowflake*> Snowfall_5;
    std::list<Snowflake*> Snowfall_6;
    std::list<Snowflake*> Snowfall_7;
    std::list<Snowflake*> Snowfall_8;
    std::list<Snowflake*> Snowfall_9;

    void construction(int, int);
    int randomBetween(int, int);
    void garbageCollection();

private slots:
    void toSnowfall();
};
#endif // VIEWEXAMPLE_H

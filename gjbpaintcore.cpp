#include "gjbpaintcore.h"
#include <QWidget>
#include <QPainter>

#include <QDebug>

GJBPaintCore::GJBPaintCore()
{
    GJBWidget = NULL;
    GJBPainter = NULL;
}

//初始化绘制引擎
void GJBPaintCore::GJB_Init_GJBWidget(QWidget *widget)
{
    GJBWidget = widget;
}

//设置画笔样式
void GJBPaintCore::GJB_Init_Painter(int painterColor)
{
    switch(painterColor)
    {
    case 0:
        break;
    case 1:
        break;
    }

    GJBPainter = new QPainter(GJBWidget);
}

//返回可以绘制的军标类型
void GJBPaintCore::GJB_Get_GJBList(QList<QString> *list)
{
    list->clear();
}

//判断画布、画笔是否已经设置
int GJBPaintCore::GJB_Check_WidgetPainter()
{
    if(GJBWidget == NULL)
    {
        return 0;
    }
    else
    {
        if(GJBPainter == NULL)
        {
            return 0;
        }
        else
        {
           return 1;
        }
    }

}

//-----------------------分割线-----------------------------//

//绘制小船一号类型
void GJBPaintCore::GJB_Paint_BoatOne()
{
    if(GJB_Check_WidgetPainter()==0)
    {
        qDebug()<<"false";
        return ;
    }

    GJBPainter->save();
    GJBPainter->setPen(QPen(Qt::red,5));
    GJBPainter->drawLine(0,0,100,100);
    GJBPainter->restore();
}


GJBPaintCore::~GJBPaintCore()
{
    if(GJBWidget!=NULL)
    {
        delete GJBWidget;
        GJBWidget=NULL;
    }

    if(GJBPainter!=NULL)
    {
        delete GJBPainter;
        GJBPainter=NULL;
    }
}




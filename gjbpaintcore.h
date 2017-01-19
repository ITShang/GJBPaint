#ifndef GJBPAINTCORE_H
#define GJBPAINTCORE_H
#include <QString>

enum PainterType
{
    GJB_Black,
    GJB_Yellow
};

class QWidget;
class QPainter;

class GJBPaintCore
{
public:
    GJBPaintCore();
    ~GJBPaintCore();
    void GJB_Init_GJBWidget(QWidget* widget);
    void GJB_Init_Painter(int painterColor);
    void GJB_Get_GJBList(QList<QString> *list);
    void GJB_Paint_BoatOne();

private:
    int GJB_Check_WidgetPainter();

    QWidget* GJBWidget;
    QPainter* GJBPainter;
};

#endif // GJBPAINTCORE_H

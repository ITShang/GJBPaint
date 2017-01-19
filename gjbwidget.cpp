#include "gjbwidget.h"
#include "ui_gjbwidget.h"
#include "gjbpaintcore.h"

#include <QDebug>

GJBWidget::GJBWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GJBWidget)
{
    ui->setupUi(this);
    initGJB();
    initGJBList();
    initConnect();
    ui->GJBwidget->installEventFilter(this);
}

bool GJBWidget::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == ui->GJBwidget)
    {
        if(event->type() == QEvent::Paint)
        {
            painteGJB();
            return true;
        }
    }
    return QWidget::eventFilter(obj,event);
}

void GJBWidget::initConnect()
{
    connect(ui->GJBlist,SIGNAL(itemPressed(QListWidgetItem*)),
            this,SLOT(showGJB(QListWidgetItem*)));
}

//初始化GJB绘制引擎
void GJBWidget::initGJB()
{
    GJB = new GJBPaintCore();
    GJB->GJB_Init_GJBWidget(ui->GJBwidget);
    GJB->GJB_Init_Painter(0);
}

void GJBWidget::initGJBList()
{
    ui->GJBlist->clear();
    ui->GJBlist->insertItem(0,tr("Boat"));
}

void GJBWidget::showGJB(QListWidgetItem *item)
{
    painteGJB();
}

void GJBWidget::painteGJB()
{
    GJB->GJB_Paint_BoatOne();
    ui->GJBwidget->update();
}

GJBWidget::~GJBWidget()
{
    delete ui;
}

#ifndef GJBWIDGET_H
#define GJBWIDGET_H

#include <QWidget>
class GJBPaintCore;
class QListWidgetItem;

namespace Ui {
class GJBWidget;
}

class GJBWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit GJBWidget(QWidget *parent = 0);
    ~GJBWidget();

protected:
    bool eventFilter(QObject *, QEvent *);

private slots:
    void showGJB(QListWidgetItem*);
    
private:
    void initGJBList();
    void initGJB();
    void painteGJB();

    void initConnect();

    Ui::GJBWidget *ui;
    GJBPaintCore *GJB;
};

#endif // GJBWIDGET_H

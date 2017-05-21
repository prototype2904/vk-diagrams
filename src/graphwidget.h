#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QGraphicsView>
#include <entity/User.h>
#include "er_diagram.h"


class User;
template<typename T> class Entity;
template<typename T> class ER;
class Node;
class GraphWidget : public QGraphicsView
{
    Q_OBJECT

public:
    GraphWidget(QWidget *parent, ER<User*>* er);
    void itemMoved();
    Node* getNode();
    Node* getSelectedNode(){return selectedNode;}
    void setSelectedNode(Node *node){ this->selectedNode = node;}
    void drawRelation(Relation* r, bool focus);
    void drawEntity(Entity<User*>* e,QPainter *painter, bool focus, bool isAbstract);
public slots:
    void shuffle();
    void zoomIn();
    void zoomOut();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void timerEvent(QTimerEvent *event) override;
#ifndef QT_NO_WHEELEVENT
    void wheelEvent(QWheelEvent *event) override;
#endif
    void drawBackground(QPainter *painter, const QRectF &rect) override;
 //   void paintEvent(QPaintEvent *);

    void scaleView(qreal scaleFactor);

private:
    int timerId;
    ER<User*>* er;
    Node* node;
    Node* selectedNode;
};

#endif // GRAPHWIDGET_H

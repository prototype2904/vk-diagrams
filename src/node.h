
#ifndef NODE_H
#define NODE_H

#include <QGraphicsItem>
#include <QList>
#include <entity/User.h>

class Edge;
class GraphWidget;
class User;
QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
QT_END_NAMESPACE

class Node : public QGraphicsItem
{
public:
    Node(User* user);
    Node(GraphWidget *graphWidget);
    User* getUser();
    void setGraphWidget(GraphWidget *graphWidget);
    void addEdge(Edge *edge);
    QList<Edge *> edges() const;

    enum { Type = UserType + 1 };
    int type() const override { return Type; }

    void calculateForces();
    bool advance();

    Node* getCenterNode();
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    User* user;
    QList<Edge *> edgeList;
    QPointF newPos;
    GraphWidget *graph;
};

#endif // NODE_H


#ifndef NODE_H
#define NODE_H

#include <QGraphicsItem>
#include <QList>
#include <entity/User.h>
#include <entity.h>


class Edge;
class GraphWidget;
class User;


QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
QT_END_NAMESPACE

class Node : public QGraphicsItem, public Entity<User*>
{
public:
    static const int WIDTH = 180 ;
    static const int HEIGHT = 90;
    Node();
    Node(Entity<User*> *entity);
    Node(Entity<User*> *entity,GraphWidget *graphWidget);
    ~Node();
    User* getUser();
    Entity<User*>* getEntity();
    void setGraphWidget(GraphWidget *graphWidget);
    void addEdge(Edge *edge);
    QList<Edge *> edges() const;
    void drawEntity(QPainter *painter, bool focus, bool isAbstract);
    void drawRelation(Relation* r,QPainter *painter, bool focus);
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
    Entity<User*>* entity;
    QPointF newPos;
    GraphWidget *graph;
};

#endif // NODE_H

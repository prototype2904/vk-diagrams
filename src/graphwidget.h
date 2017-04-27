#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QGraphicsView>

class Node;
class GraphWidget : public QGraphicsView
{
    Q_OBJECT

public:
    GraphWidget(Node *center, QList<Node*>* friends, QWidget *parent);
    Node* getSelectNode(){return selectNode;}
    void setSelectNode(Node* node){selectNode = node;}
    void itemMoved();
    Node* getCenterNode();
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

    void scaleView(qreal scaleFactor);

private:
    int timerId;
    Node* centerNode;
    Node* selectNode = NULL;
};

#endif // GRAPHWIDGET_H

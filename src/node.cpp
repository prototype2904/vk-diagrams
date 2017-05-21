
#include "edge.h"
#include "node.h"
#include "graphwidget.h"
#include "servise/userservicefacade.h"
#include "dialog.h"
#include "entity.h"

#include "util/DialogSingleton.h"
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOption>

Node::Node(Entity<User*>* entity):
    Entity(entity->getValue())
{
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    setZValue(-1);
    this->entity = entity;
}

Node::Node(Entity<User*>* entity, GraphWidget *graphWidget)
    : graph(graphWidget)
{
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    setZValue(-1);
    this->entity = entity;
}

Node::Node(){
     setFlag(ItemIsMovable);
     setFlag(ItemSendsGeometryChanges);
     setCacheMode(DeviceCoordinateCache);
     setZValue(-1);
     this->entity = NULL;
}
Node::~Node(){
}

Entity<User*>* Node::getEntity(){
    return this->entity;
}

void Node::setGraphWidget(GraphWidget *graphWidget){
    this->graph = graphWidget;
}

void Node::calculateForces()
{
//    if (!scene() || scene()->mouseGrabberItem() == this) {
//        newPos = pos();
//        return;
//    }
//    // Sum up all forces pushing this item away
//    qreal xvel = 0;
//    qreal yvel = 0;
//    foreach (QGraphicsItem *item, scene()->items()) {
//        Node *node = qgraphicsitem_cast<Node *>(item);
//        if (!node)
//            continue;

//        QPointF vec = mapToItem(node, 0, 0);
//        qreal dx = vec.x();
//        qreal dy = vec.y();
//        double l = 2.0 * (dx * dx + dy * dy);
//        if (l > 0) {
//            xvel += (dx * 150.0) / l;
//            yvel += (dy * 150.0) / l;
//        }
//    }
//    // Now subtract all forces pulling items together
//    double weight = (edgeList.size() + 1) * 10;
//    foreach (Edge *edge, edgeList) {
//        QPointF vec;
//        if (edge->sourceNode() == this)
//            vec = mapToItem(edge->destNode(), 0, 0);
//        else
//            vec = mapToItem(edge->sourceNode(), 0, 0);
//        xvel -= vec.x() / weight;
//        yvel -= vec.y() / weight;
//    }
//    if (qAbs(xvel) < 0.1 && qAbs(yvel) < 0.1)
//        xvel = yvel = 0;
//    QRectF sceneRect = scene()->sceneRect();
//    newPos = pos() + QPointF(xvel, yvel);
//    newPos.setX(qMin(qMax(newPos.x(), sceneRect.left() + 10), sceneRect.right() - 10));
//    newPos.setY(qMin(qMax(newPos.y(), sceneRect.top() + 10), sceneRect.bottom() - 10));
}

bool Node::advance()
{
    if (newPos == pos())
        return false;

    setPos(newPos);
    return true;
}

QRectF Node::boundingRect() const
{
    qreal adjust = 2;
    return QRectF( -1000 - adjust, -1000 - adjust, 2300 + adjust, 2300 + adjust);
}

QPainterPath Node::shape() const
{
    QPainterPath path;
    path.addRect(0,0, 120,80);
    return path;
}

void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
   drawEntity(painter, true, true);
}

QVariant Node::itemChange(GraphicsItemChange change, const QVariant &value)
{
//    switch (change) {
//    case ItemPositionHasChanged:
//        foreach (Edge *edge, edgeList)
//            edge->adjust();
//        graph->itemMoved();
//        break;
//    default:
//        break;
//    };

    return QGraphicsItem::itemChange(change, value);
}

void Node::drawEntity(QPainter *painter, bool focus, bool isAbstract){
//    this->calculateEntitie(e);
    int x = 0;
    int y = 0;
    int w = WIDTH;
    int h = HEIGHT;
    int t = 1;
    bool mov = true;
//    for(int i=0; i<this->core->getEntitieCount(); i++){
//       Entitie* e0 = this->core->getEntitieAt(i);
//       int xe = ((IntField*)e0->fieldByID("X"))->getValue();
//       int ye = ((IntField*)e0->fieldByID("Y"))->getValue();
//       int we = ((IntField*)e0->fieldByID("W"))->getValue();
//       int he = ((IntField*)e0->fieldByID("H"))->getValue();
//       if((xe-w-15<x)&&(ye-h-15<y)&&(we+xe+15>x)&&(he+ye+15>y)&&(e0!=e)){
//           mov = false;
//       }
//    }
    int alpha =  (((isAbstract)||(!mov)) ? 20 : 250);
    int alpha0 = (((isAbstract)||(!mov)) ? 0 : 25);
    int alpha1 = (((isAbstract)||(!mov)) ? 0 : 100);
//    if(isAbstract){
//        ((IntField*)e->fieldByID("X"))->setValue(this->curX);
//        ((IntField*)e->fieldByID("Y"))->setValue(this->curY);
//    }

    QColor color(255,200,125,alpha);
    QColor color1(255,170,100,alpha);
    QColor color2(215,215,255,alpha);
    QColor colorRed(252,139,130,alpha);
    QColor colorGreen(125,220,125,alpha);
    QColor colorBlue(125,125,220,alpha);
    QColor colorGreenAlpha(55,155,55,alpha0);
    QColor colorBlackAlpha(0,0,0,alpha1);
    QPen pen1 = QPen(Qt::black, 1, Qt::SolidLine);
    QPen pen2 = QPen(colorBlackAlpha, 1, Qt::SolidLine);
    painter->setPen(pen1);
    if(graph->getNode() == this){
     painter->setBrush(QBrush(colorGreen));
    }
    else if(graph->getSelectedNode() == this){
        painter->setBrush(QBrush(colorRed));
    }else{
        painter->setBrush(QBrush(colorBlue));
    }

//    if(this->core->getState()==10 && this->core->getWeightOfSolution()!=-1){
//        bool green = false;
//        for(int i=0; i<this->core->getBestWay()->size(); i++){
//            if(e->getID()==this->core->getBestWay()->at(i)){
//                green = true;
//            }
//        }
//        if(t!=1){
//            if(green){
//                painter.setBrush(QBrush(colorGreen));
//            }else{
//                painter.setBrush(QBrush(colorRed));
//            }
//        }else{
//           painter.setBrush(QBrush(color2));
//        }
//    }else{
//        if(t==0){
//            painter.setBrush(QBrush(color1));
//        }else if(t==1){
//            painter.setBrush(QBrush(color2));
//        }else{
//            painter.setBrush(QBrush(color));
//        }
//    }

//    if(x>max_width-w-5){
//        ((IntField*)e->fieldByID("X"))->setValue(max_width-w-5);
//        x=max_width-w-5;
//    }
//    if(y>max_height-h-5){
//        ((IntField*)e->fieldByID("Y"))->setValue(max_height-h-5);
//        y=max_height-h-5;
//    }
//    if(x<5){
//        ((IntField*)e->fieldByID("X"))->setValue(5);
//        x=5;

    string label = "Пользователь";
    int i=5;
    QRect r1(x,y,w,h);
    QRect r12(x+5,y+5,w-10,h-10);
    QRect r2(x,y,w,20);
    if(focus){
        QRect rf(x-2,y-2,w+4,h+4);
        painter->drawRect(rf);
    }
    painter->drawRect(r1);
    painter->drawRect(r2);
    painter->drawText(r12,label.c_str());

    QRect tr(x+5,y+5+(i+1-5)*24,w-10,h-10);
    painter->drawText(tr,"ID");
    if(entity != NULL){
        QRect tr_id(x+45,y+5+(i+1-5)*24,w,h);
        painter->drawText(tr_id, QString::number(entity->getValue()->getId()));
    }
    i= 6;
    QRect tr2(x+5,y+5+(i+1-5)*24,w-10,h-10);
    painter->drawText(tr2,"ФИО");
    if(entity != NULL){
        QRect tr_fio(x+45,y+5+(i+1-5)*24,w - 40,h - 40);
        painter->drawText(tr_fio, entity->getValue()->getFio());
    }

}

void Node::drawRelation(Relation* r,QPainter *painter, bool focus){
//    Entity<User*>* eR = r->getEntR();
//    Entity<User*>* eL = r->getEntL();
////    this->calculateEntitie(eL);
////    this->calculateEntitie(eR);
//    int a = (rand() % 10) >= 5 ? 1 : -1;
//    int x1 = a * (rand() % 200);
//    int y1 = (-a) *(rand() % 200);
//    int w1 = 100;
//    int h1 = 100;
//    int t1 = 1;
//    a = (rand() % 10) >= 5 ? 1 : -1;
//    int x2 = a * (rand() % 200);
//    int y2 = (-a) *(rand() % 200);
//    int w2 = 100;
//    int h2 = 100;
//    int t2 = 2;

//    int alpha = 250;
//    int alpha0 = 25;
//    int alpha1 = 100;
//    int alpha2 = 250;
//    if((x1-w2-15<x2)&&(y1-h2-15<y2)&&(w1+x1+15>x2)&&(h1+y1+15>y2)){
//        alpha = 0;
//        alpha0 = 0;
//        alpha1 = 0;
//        alpha2 = 0;
//    }

//    QColor color(90,185,255,alpha);
//    QColor colorGreenAlpha(55,155,55,alpha0);
//    QColor colorBlackAlpha(0,0,0,alpha1);
//    QColor colorBlack(0,0,0,alpha2);
//    QPen penf = QPen(colorBlackAlpha, 1, Qt::SolidLine);

//    painter->setBrush(QBrush(color));

//    int indexR = 0;
//    int indexL = 0;
////    for(int j=0; j<eR->fieldCount() && indexR==0; j++){
////        if(eR->fieldAt(j)->getID()==r->getKey()){
////            indexR = j;
////        }
////    }
////    for(int j=0; j<eL->fieldCount() && indexL==0; j++){
////        if(eL->fieldAt(j)->getID()==r->getKey()){
////            indexL = j;
////        }
////    }
////    if(indexR<work_count-1){
////        indexR=work_count-1;
////    }
////    if(indexL<work_count-1){
////        indexL=work_count-1;
////    }

//    int work_count=5;
//    int x01=0;
//    int x02=0;
//    int y01=0;
//    int y02=0;
//    if(qAbs(x1-x2)>=w2 && qAbs(x1-x2)>=w1){
//        if(x1>x2){
//            x01=x1;
//            x02=x2+w2+1;
//        }else{
//            x02=x2;
//            x01=x1+w1+1;
//        }
//        y01 = y1+(indexR+1-work_count)*24+((indexR+1-(work_count-1))*24-(indexR+1-work_count)*24)/2;
//        y02 = y2+(indexL+1-work_count)*24+((indexL+1-(work_count-1))*24-(indexL+1-work_count)*24)/2;
//    }else{
//        if(y1>y2){
//            y01=y1;
//            y02=y2+h2+1;
//        }else{
//            y02=y2;
//            y01=y1+h1+1;
//        }
//        x01=x1+w1/2;
//        x02=x2+w2/2;
//    }
//    int x0 = 0;
//    int y0 = 0;
//    QPointF p1(x01,y01);
//    QPointF p2(x02,y02);
//    if(x01>x02){
//        x0 = x02 + (x01 - x02)/2;
//    }else{
//        x0 = x01 + (x02 - x01)/2;
//    }
//    if(y01>y02){
//        y0 = y02 + (y01 - y02)/2;
//    }else{
//        y0 = y01 + (y02 - y01)/2;
//    }
//    QPointF p0(x0,y0);
//    QPen pen1 = QPen(colorBlack, 1, Qt::DotLine);
//    QPen pen2 = QPen(colorBlack, 1, Qt::SolidLine);
//    QPen pen3 = QPen(colorBlack, 2, Qt::SolidLine);
//    QPen pen4 = QPen(colorBlack, 2, Qt::DotLine);
//    painter->setPen(pen2);
//    painter->drawLine(p1,p0);
//    painter->drawLine(p0,p2);
//    painter->drawEllipse(p0, 10, 10);
//    if(!r->isMulL()){
//        QRect tr(p0.x()-7,p0.y()-7,12,12);
//        painter->drawText(tr,"1");
//    }
//    if(!r->isMulR()){
//        QRect tr(p0.x()+3,p0.y()-7,12,12);
//        painter->drawText(tr,"1");
//    }
//    painter->setPen(pen2);
//    painter->drawLine(QPointF(p0.x(),p0.y()-10),QPointF(p0.x(),p0.y()+10));
////    if(focus){
////        if(t1!=1){
////            double distance = this->core->getDistanceOf(eR);
////            painter.setBrush(QBrush(colorGreenAlpha));
////            painter.setPen(penf);
////            painter.drawEllipse(QPoint(x1-1,y1-1), (int)qRound(distance), (int)qRound(distance));
////         }
////        if(t2!=1){
////            double distance = this->core->getDistanceOf(eL);
////            painter.setBrush(QBrush(colorGreenAlpha));
////            painter.setPen(penf);
////            painter.drawEllipse(QPoint(x2-1,y2-1), (int)qRound(distance), (int)qRound(distance));
////         }
////    }
}


Node* Node::getCenterNode(){
    return NULL;
}

void Node::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    update();
    QGraphicsItem::mousePressEvent(event);
}

void Node::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    UserServiceFacade userServiceFacade;
    graph->setSelectedNode(NULL);
    Node* node = graph->getNode();
    Node* selectedNode = this;
    if(node != selectedNode){
        int ownFriends = userServiceFacade.getNumOwnFriends(node->getEntity()->getValue(), selectedNode->getEntity()->getValue());
        int ownGroups = userServiceFacade.getNumOwnGroups(node->getEntity()->getValue(), selectedNode->getEntity()->getValue());
        Dialog &dialog = DialogSingleton::get();
        dialog.setNumCommonFriedns(ownFriends);
        dialog.setNumCommonGroups(ownGroups);
        graph->setSelectedNode(selectedNode);
    }
}


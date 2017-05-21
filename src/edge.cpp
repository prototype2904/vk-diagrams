#include "edge.h"
#include "node.h"

#include <math.h>

#include <QPainter>

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;


Edge::Edge(Node *sourceNode, Node *destNode)
    : Relation(QObject::tr("Дружит"),sourceNode->getEntity(), destNode->getEntity(), false, false, false, false)
{
    setAcceptedMouseButtons(0);
    this->source = sourceNode;
    this->dest = destNode;
}

Node *Edge::sourceNode() const
{
    return source;
}

Node *Edge::destNode() const
{
    return dest;
}

void Edge::adjust()
{
//    if (!source || !dest)
//        return;

//    QLineF line(mapFromItem(source, 0, 0), mapFromItem(dest, 0, 0));
//    qreal length = line.length();

//    prepareGeometryChange();

//    if (length > qreal(20.)) {
//        QPointF edgeOffset((line.dx() * 10) / length, (line.dy() * 10) / length);
//        sourcePoint = line.p1() + edgeOffset;
//        destPoint = line.p2() - edgeOffset;
//    } else {
//        sourcePoint = destPoint = line.p1();
//    }
}

QRectF Edge::boundingRect() const
{
    if (!source || !dest)
        return QRectF();

    qreal penWidth = 1;
    qreal extra = (penWidth + arrowSize) / 2.0;

    return QRectF(sourcePoint, QSizeF(destPoint.x() - sourcePoint.x(),
                                      destPoint.y() - sourcePoint.y()))
        .normalized()
        .adjusted(-extra, -extra, extra, extra);
}

void Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    Node* eR = source;
    Node* eL = dest;
//    this->calculateEntitie(eL);
//    this->calculateEntitie(eR);
    int x1 = eR->x();
    int y1 = eR->y();
    int w1 = Node::WIDTH;
    int h1 = Node::HEIGHT;
    int t1 = 1;
    int x2 = eL->x();
    int y2 = eL->y();
    int w2 = Node::WIDTH;
    int h2 = Node::HEIGHT;
    int t2 = 2;

    int alpha = 250;
    int alpha0 = 25;
    int alpha1 = 100;
    int alpha2 = 250;
    if((x1-w2-15<x2)&&(y1-h2-15<y2)&&(w1+x1+15>x2)&&(h1+y1+15>y2)){
        alpha = 0;
        alpha0 = 0;
        alpha1 = 0;
        alpha2 = 0;
    }

    QColor color(90,185,255,alpha);
    QColor colorGreenAlpha(55,155,55,alpha0);
    QColor colorBlackAlpha(0,0,0,alpha1);
    QColor colorBlack(0,0,0,alpha2);
    QPen penf = QPen(colorBlackAlpha, 1, Qt::SolidLine);

    painter->setBrush(QBrush(color));

    int indexR = 0;
    int indexL = 0;
//    for(int j=0; j<eR->fieldCount() && indexR==0; j++){
//        if(eR->fieldAt(j)->getID()==r->getKey()){
//            indexR = j;
//        }
//    }
//    for(int j=0; j<eL->fieldCount() && indexL==0; j++){
//        if(eL->fieldAt(j)->getID()==r->getKey()){
//            indexL = j;
//        }
//    }
//    if(indexR<work_count-1){
//        indexR=work_count-1;
//    }
//    if(indexL<work_count-1){
//        indexL=work_count-1;
//    }

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
    int x0 = 0;
    int y0 = 0;
    QPointF p1(x1,y1);
    QPointF p2(x2,y2);
    if(x1>x2){
        x0 = x2 + (x1 - x2)/2;
    }else{
        x0 = x1 + (x2 - x1)/2;
    }
    if(y1>y2){
        y0 = y2 + (y1 - y2)/2;
    }else{
        y0 = y1 + (y2 - y1)/2;
    }
    QPointF p0(x0,y0);
    QPen pen1 = QPen(colorBlack, 1, Qt::DotLine);
    QPen pen2 = QPen(colorBlack, 1, Qt::SolidLine);
    QPen pen3 = QPen(colorBlack, 2, Qt::SolidLine);
    QPen pen4 = QPen(colorBlack, 2, Qt::DotLine);
    painter->setPen(pen2);
    painter->drawLine(p1,p0);
    painter->drawLine(p0,p2);
    painter->drawEllipse(p0, 10, 10);
    if(!isMulL()){
        QRect tr(p0.x()-7,p0.y()-7,12,12);
        painter->drawText(tr,"1");
    }
    if(!isMulR()){
        QRect tr(p0.x()+3,p0.y()-7,12,12);
        painter->drawText(tr,"1");
    }
    painter->setPen(pen2);
    painter->drawLine(QPointF(p0.x(),p0.y()-10),QPointF(p0.x(),p0.y()+10));
//    if(focus){
//        if(t1!=1){
//            double distance = this->core->getDistanceOf(eR);
//            painter.setBrush(QBrush(colorGreenAlpha));
//            painter.setPen(penf);
//            painter.drawEllipse(QPoint(x1-1,y1-1), (int)qRound(distance), (int)qRound(distance));
//         }
//        if(t2!=1){
//            double distance = this->core->getDistanceOf(eL);
//            painter.setBrush(QBrush(colorGreenAlpha));
//            painter.setPen(penf);
//            painter.drawEllipse(QPoint(x2-1,y2-1), (int)qRound(distance), (int)qRound(distance));
//         }
//    }
}

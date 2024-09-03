#include "ball.h"
#include <cmath>
#include <QPainter>
MyBall::MyBall(QPointF center, int radius) {
    top = QPointF(center.x(), center.y() - radius);
    bottom = QPointF(center.x(), center.y() + radius);
    left = QPointF(center.x() - radius, center.y());
    right = QPointF(center.x() + radius, center.y());
    topLeft = QPointF(center.x() - radius, center.y() - radius);
    this->radius = radius;
}
QRectF MyBall::boundingRect() const {
    int windowWidth = 1536;
    return QRectF(topLeft.x(), topLeft.y(), 2 * radius, 2 * radius);

}
void MyBall::updatePoints(float factorX, float factorY) {
    top.setX(top.x() + factorX);
    top.setY(top.y() + factorY);

    bottom.setX(bottom.x() + factorX);
    bottom.setY(bottom.y() + factorY);

    left.setX(left.x() + factorX);
    left.setY(left.y() + factorY);

    right.setX(right.x() + factorX);
    right.setY(right.y() + factorY);
}
void MyBall::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {

    QRectF rect = boundingRect();
    painter->setBrush(Qt::blue);
    painter->drawEllipse(rect);

}
QPointF& MyBall::getTop() {
    QPointF* p = new QPointF(top.x(), top.y());
    return *p;

}
QPointF& MyBall::getBottom() {
    QPointF* p = new QPointF(bottom.x(), bottom.y());
    return *p;

}
QPointF& MyBall::getRight() {
    QPointF* p = new QPointF(right.x(), right.y());
    return *p;

}
QPointF& MyBall::getLeft() {
    QPointF* p = new QPointF(left.x(), left.y());
    return *p;

}

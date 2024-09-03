#include <QPainter>
#include <QGraphicsItem>
#pragma once
class MyBall : public QGraphicsItem {



public:

	MyBall(QPointF center, int radius);

	QRectF boundingRect() const;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
	void updatePoints(float factorX, float factorY);
	QPointF& getTop();
	QPointF& getBottom();
	QPointF& getRight();
	QPointF& getLeft();

private:
	QPointF top;
	QPointF bottom;
	QPointF left;
	QPointF right;
	QPointF topLeft;
	int radius;

};

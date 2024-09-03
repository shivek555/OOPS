#include <QGraphicsScene>
#include <QGraphicsItem>

#pragma once
// Hold details of a point
struct Point {
    float x;
    float y;
    Point(float _x, float _y)
    {
        x = _x;
        y = _y;
    }
    Point()
    {
        x = 0;
        y = 0;
    }
};

// The main quadtree class
class Quad {
    // Hold details of the boundary of this node
    Point topLeft;
    Point botRight;
    Point center;
    int blockNum;
    QGraphicsRectItem* brick;
    // Children of this tree
    Quad* topLeftTree;
    Quad* topRightTree;
    Quad* botLeftTree;
    Quad* botRightTree;


    inline static QGraphicsScene* scene;

public:
    Quad(Point topL, Point botR);
    Quad(Point topL, Point botR, QGraphicsScene* sc);
    void divide(int depth, bool top = true);
    bool remove(Point, bool& flag);
    bool inBoundary(Point);
    bool isEmpty();
    void deleteAll();
private:
    void privDeleteAll(Quad* root);
};

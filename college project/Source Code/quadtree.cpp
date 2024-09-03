// C++ Implementation of Quad Tree
#include "quadtree.h"
#include <iostream>


using namespace std;

//Constructor
Quad::Quad(Point topL, Point botR)
{

    topLeftTree = NULL;
    topRightTree = NULL;
    botLeftTree = NULL;
    botRightTree = NULL;
    blockNum = -1;
    topLeft = topL;
    botRight = botR;
    center.x = (topL.x + botR.x) / 2;
    center.y = (topL.y + botR.y) / 2;
    brick = 0;
}

Quad::Quad(Point topL, Point botR, QGraphicsScene* sc)
{

    topLeftTree = NULL;
    topRightTree = NULL;
    botLeftTree = NULL;
    botRightTree = NULL;
    blockNum = -1;
    topLeft = topL;
    botRight = botR;
    center.x = (topL.x + botR.x) / 2;
    center.y = (topL.y + botR.y) / 2;
    scene = sc;
    brick = 0;
}
// Divide quadtree recursively
void Quad::divide(int depth, bool top) {

    if (depth == 0) {
        brick = scene->addRect(topLeft.x, topLeft.y, botRight.x - topLeft.x, botRight.y - topLeft.y,
            QPen(Qt::black), QBrush(Qt::white));
        return;
    }
    //Create top left Quad
    topLeftTree = new Quad(topLeft, center);
    //Divide top left Quad
    topLeftTree->divide(depth - 1, false);

    //Create top right Quad
    Point topCenter(center.x, topLeft.y);
    Point rightCenter(botRight.x, center.y);
    topRightTree = new Quad(topCenter, rightCenter);
    //Divide top right Quad
    topRightTree->divide(depth - 1, false);

    if (!top) {
        //Create bottom Right Quad
        botRightTree = new Quad(center, botRight);
        //Divide bottom Right Quad
        botRightTree->divide(depth - 1, false);

        //Create bottom left Quad
        Point botCenter(center.x, botRight.y);
        Point leftCenter(topLeft.x, center.y);
        botLeftTree = new Quad(leftCenter, botCenter);
        //Divide bottom left Quad
        botLeftTree->divide(depth - 1, false);
    }
}

// Check inside screen borders
bool Quad::inBoundary(Point p)
{
    return (p.x > topLeft.x && p.x < botRight.x
        && p.y > topLeft.y && p.y < botRight.y);
}

// Remove the quad if exist
bool Quad::remove(Point p, bool& flag) {
    int response;
    if (brick != NULL) {

        scene->removeItem(brick);
        delete brick;
        brick = NULL;
        flag = true;
        return 1;
    }
    if ((topLeft.x + botRight.x) / 2 > p.x) {
        // Indicates topLeftTree
        if ((topLeft.y + botRight.y) / 2 > p.y) {
            if (topLeftTree == NULL)
                return 0;
            response = topLeftTree->remove(p, flag);
            if (response == 1) {
                delete topLeftTree;
                topLeftTree = NULL;
            }
        }

        // Indicates botLeftTree
        else {
            if (botLeftTree == NULL)
                return 0;
            response = botLeftTree->remove(p, flag);
            if (response == 1) {
                delete botLeftTree;
                botLeftTree = NULL;
            }
        }
    }

    else {
        // Indicates topRightTree
        if ((topLeft.y + botRight.y) / 2 >= p.y) {
            if (topRightTree == NULL)
                return 0;
            response = topRightTree->remove(p, flag);
            if (response == 1) {
                delete topRightTree;
                topRightTree = NULL;
            }
        }

        // Indicates botRightTree
        else {
            if (botRightTree == NULL)
                return 0;
            response = botRightTree->remove(p, flag);
            if (response == 1) {
                delete botRightTree;
                botRightTree = NULL;
            }
        }
    }
    if (topLeftTree == 0 && topRightTree == 0 && botLeftTree == 0 && botRightTree == 0) {
        return 1;
    }
    else
        return 0;
}
bool Quad::isEmpty() {
    return(topLeftTree == 0 && topRightTree == 0 && botLeftTree == 0 && botRightTree == 0);
}

void Quad::deleteAll() {

    privDeleteAll(this);
}

void Quad::privDeleteAll(Quad* root) {
    if (root == 0) {
        return;
    }
    privDeleteAll(root->topLeftTree);
    privDeleteAll(root->topRightTree);
    privDeleteAll(root->botLeftTree);
    privDeleteAll(root->botRightTree);

    delete root;
    root = NULL;
}

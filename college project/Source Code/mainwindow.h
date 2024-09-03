#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsScene>
#include <QMainWindow>
#include <QScreen>
#include "quadtree.h"
#include "ball.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //void mouseMoveEvent(QMouseEvent*);
    bool eventFilter(QObject *obj, QEvent *event);
    void endGame(bool won);
    void resetBall();
public slots:
    void moveBall();
    void startGame();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    Quad* q;
    QGraphicsRectItem* paddle;
    MyBall* ball;
    QTimer* timer;
    QGraphicsEllipseItem* el;
    bool inGame;
    bool paused;
    int lives;
    float factorX;
    float factorY;
    QGraphicsRectItem* pauseMenu;
    QScreen* screen;
};

class mainwindow
{
};
#endif // MAINWINDOW_H

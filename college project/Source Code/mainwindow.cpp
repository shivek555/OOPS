#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainmenu.h"
#include <iostream>
#include "ball.h"
#include <QTimer>
#include <cmath>
#include <QKeyEvent>
#include <cstring>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    screen = QGuiApplication::primaryScreen();
    inGame = false;
    paused = false;
    int labelHeight = 500;
    int labelWidth = 500;
    ui->setupUi(this);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setFixedWidth(screen ->geometry().width());
    ui->graphicsView->setFixedHeight(screen ->geometry().height());
    QCursor::setPos(screen->geometry().width() / 2 - 25, 0);
    std::cout <<"Width is" << width();
    this ->setCursor(Qt::BlankCursor);
    qApp ->installEventFilter(this);
    setMouseTracking(true);
    ui -> label -> setFixedHeight(labelHeight);
    ui -> label -> setFixedWidth(labelWidth);
    ui -> label -> setAlignment(Qt::AlignCenter);
    QFont font = ui -> label -> font();
    font.setPointSize(30);
    ui -> label -> setFont(font);
    ui -> livesLabel -> move(screen ->geometry().width()-236,screen ->geometry().height()-49);
    ui -> livesLabel  -> setStyleSheet("color:red");
    ui -> livesLabel  -> setAlignment(Qt::AlignLeft);
    font.setPointSize(20);
    ui -> livesLabel -> setFont(font);
    ui -> pushButton ->setStyleSheet(
        "QPushButton:hover{background-color:green;}QPushButton{border-radius:20;background-color:gray;color:white}"
    );
    ui -> pushButton -> move(screen ->geometry().width()/2 - ui->pushButton_2->width()/2,screen ->geometry().height()/2 - ui->pushButton_2->height()/2 + 50);
    ui -> pushButton_2 ->setStyleSheet(
        "QPushButton:hover{background-color:green;}QPushButton{border-radius:20;background-color:gray;color:white}"
    );
    ui -> pushButton_3 ->setStyleSheet(
        "QPushButton:hover{background-color:red;}QPushButton{border-radius:20;background-color:gray;color:white}"
    );
   
    font.setPointSize(30);
    ui->endLabel->setFont(font);
    ui->endLabel->setFixedHeight(50);
    ui->endLabel->setFixedWidth(500);
    ui->endLabel->setDisabled(true);
    ui->endLabel->move(screen->geometry().width() / 2 - 500 / 2, screen->geometry().height() / 2 - 50 / 2);
    ui->endLabel->setAlignment(Qt::AlignCenter);

    timer = new QTimer();
    scene = new QGraphicsScene;
    QRect rc = ui -> graphicsView ->contentsRect();
    ui -> graphicsView ->setSceneRect(rc);
    ui -> graphicsView -> setScene(scene);
    ui -> graphicsView -> setRenderHint(QPainter::Antialiasing);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveBall()));
    startGame();
    //delete screen;
}

void MainWindow::moveBall(){
    bool flag = false;
    ball->moveBy(factorX,factorY);
    ball -> updatePoints(factorX,factorY);
    if(!q->inBoundary(Point(ball->getBottom().x(),ball->getBottom().y()))){
    if(lives == 1){
     endGame(false);
     return;
    }
    else{
        lives--;
        ui -> livesLabel -> setText(QString::fromStdString("Lives: " + std::to_string(lives)));
        resetBall();
        inGame = false;
        timer->stop();
    }
    }
    if(!q->inBoundary(Point(ball->getLeft().x(),ball->getLeft().y()))){
        factorX = -factorX;
        return;
    }
    if(!q->inBoundary(Point(ball->getTop().x(),ball->getTop().y()))){
        factorY = - factorY;
        return;
    }
    if(!q->inBoundary(Point(ball->getRight().x(),ball->getRight().y()))){
        factorX = -factorX;
        return;
    }
    q -> remove(Point(ball->getLeft().x(),ball->getLeft().y()),flag);
    if (flag){
        factorX = -factorX;
        return;
    }
    q -> remove(Point(ball->getRight().x(),ball->getRight().y()),flag);
    if (flag){
        factorX = -factorX;
        return;
    }
    q -> remove(Point(ball->getTop().x(),ball->getTop().y()),flag);
    if (flag){
        factorY = -factorY;
        return;
    }
    q -> remove(Point(ball->getBottom().x(),ball->getBottom().y()),flag);
    if (flag){
        factorY = -factorY;
        return;
    }
    if (paddle -> collidesWithItem(ball)){
      factorX = (ball->getBottom().x() - (paddle -> pos().x() + 75))/25;
      factorY = -sqrt(16 - factorX*factorX);
    }
    if(q->isEmpty()){
       endGame(true);
       return;
    }


    ui -> graphicsView -> update();
}
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
  if (event->type() == QEvent::MouseMove)
  {
      if(paddle != NULL && !paused){
          if(paddle -> pos().x() < 50)
              paddle->setPos(50,paddle->pos().y());
          else if(paddle -> pos().x() > screen ->geometry().width()-50 - 150)
               paddle->setPos(screen ->geometry().width()-50 - 150,paddle->pos().y());
          else
      paddle ->setPos(QCursor::pos().x()-50,paddle->pos().y());
      ui->graphicsView->update();
      }
  }
  if(!inGame &&!paused){
  if (event ->type() == QEvent::MouseButtonRelease){
          timer -> start(6);
          ui -> label ->clear();
          inGame = true;
  }}
  return false;
}
void MainWindow::startGame(){
    inGame = false;
    lives = 3;
    factorX = (rand() % 7) - 3;
    factorY = -sqrt(16-factorX*factorX);
    this -> setCursor(Qt::BlankCursor);
    ui -> label -> setStyleSheet("color:green");
    ui -> label -> move(screen ->geometry().width()/2-500/2,screen ->geometry().height()/2-500/2+200);
    ui -> label_2->setVisible(false);
    ui -> livesLabel -> setText(QString::fromStdString("Lives: " + std::to_string(lives)));
    ui -> label -> setText("Click on mouse to start");
    ui -> pushButton -> setVisible(false);
    ui -> pushButton -> setDisabled(true);
    ui -> pushButton_2 -> setVisible(false);
    ui -> pushButton_2 -> setDisabled(true);
    ui -> pushButton_3 -> setVisible(false);
    ui -> pushButton_3 -> setDisabled(true);
    ui -> endLabel ->setVisible(false);
    ball = new MyBall(QPointF(screen ->geometry().width()/2,screen ->geometry().height()-74),10);
    scene -> addRect(40,0,10,screen ->geometry().height()-64,QPen(Qt::black),QBrush(Qt::gray));
    scene -> addRect(screen ->geometry().width()-50,0,10,screen ->geometry().height()-64,QPen(Qt::black),QBrush(Qt::gray));
    scene -> addItem(ball);
    paddle = scene -> addRect(0,screen ->geometry().height()-64,150,15,QPen(Qt::black),QBrush(Qt::red));
    paddle -> setFlag(QGraphicsItem::ItemIsMovable);
    q = new Quad(Point(50,0),Point(screen ->geometry().width()-50,screen ->geometry().height()),scene);
    q->divide(3);
}
void MainWindow::endGame(bool won){
    timer -> stop();
    QFont font = ui -> label -> font();
    font.setPointSize(30);
    ui -> label -> setFont(font);
    ui -> label -> move(screen ->geometry().width()/2-500/2,screen ->geometry().height()/2-500/2);
    ui -> pushButton -> setVisible(true);
    ui -> pushButton -> setDisabled(false);
    ui -> pushButton_3 -> setVisible(true);
    ui -> pushButton_3 -> setDisabled(false);
    ui->livesLabel->clear();
    ui -> pushButton-> move(screen ->geometry().width()/2 - ui->pushButton_2->width()/2,screen ->geometry().height()/2 - ui->pushButton_2->height()/2+150);
    ui -> pushButton_3 -> move(screen ->geometry().width()/2 - ui->pushButton_2->width()/2,screen ->geometry().height()/2 - ui->pushButton_2->height()/2 + 200);
    delete paddle;
    delete ball;
    paddle = NULL;
    ball = NULL;
    this -> setCursor(Qt::ArrowCursor);
    scene ->clear();

    if(won){
        ui -> label -> setText("You Win");
        delete q;
        q = NULL;
    }
    else{
        ui -> label -> setStyleSheet("color:red");
        ui -> label -> setText("You Lose");
        q->deleteAll();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    startGame();
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if(event -> key() == Qt::Key_Escape && !paused && paddle!=0){
        timer -> stop();
        paused = true;
        ui->label_2-> setStyleSheet("color: red");
        ui -> label_2 -> setVisible(true);
        ui -> label_2 -> move(screen ->geometry().width()/2 - ui->pushButton_2->width()/2 + 4,screen ->geometry().height()/2 - ui->pushButton_2->height()/2 - 65);
        ui -> label_2 -> setAlignment(Qt::AlignCenter);
        ui -> pushButton_2 -> setVisible(true);
        ui -> pushButton_2 -> setDisabled(false);
        ui -> pushButton_3 -> setVisible(true);
        ui -> pushButton_3 -> setDisabled(false);
        ui -> pushButton_3 -> move(screen ->geometry().width()/2 - ui->pushButton_2->width()/2,screen ->geometry().height()/2 - ui->pushButton_2->height()/2 + 50);
        ui -> pushButton_2 -> move(screen ->geometry().width()/2 - ui->pushButton_2->width()/2,screen ->geometry().height()/2 - ui->pushButton_2->height()/2);
        this -> setCursor(Qt::ArrowCursor);
        pauseMenu = scene -> addRect(screen ->geometry().width()/2-200/2,screen ->geometry().height()/2-200/2,200,200,QPen(),QBrush(Qt::gray));
        pauseMenu -> setOpacity(0.5);

    }
}

void MainWindow::on_pushButton_2_clicked()
{
    timer -> start(6);
    this -> setCursor(Qt::BlankCursor);
    paused = false;
    scene ->removeItem(pauseMenu);
    ui -> label_2->setVisible(false);
    ui -> pushButton_2 -> setVisible(false);
    ui -> pushButton_2 -> setDisabled(true);
    ui -> pushButton_3 -> setVisible(false);
    ui -> pushButton_3 -> setDisabled(true);

}

void MainWindow::resetBall(){
    scene -> removeItem(ball);
    delete ball;
    ball = new MyBall(QPointF(screen ->geometry().width()/2,screen ->geometry().height()-74),10);
    scene->addItem(ball);
    factorX = (rand() % 7) - 3;
    factorY = -sqrt(16-factorX*factorX);
}


void MainWindow::on_pushButton_3_clicked()
{
    MainWindow::~MainWindow();
    MainMenu* w = new MainMenu();
    //w ->showFullScreen();
    //hide();
}


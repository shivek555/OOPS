#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "mainwindow.h"
#include <QScreen>
#include <iostream>
MainMenu::MainMenu(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    screen = QGuiApplication::primaryScreen();

    ui->setupUi(this);
    QGraphicsScene* scene = new QGraphicsScene();

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedWidth(screen->geometry().width());
    ui->graphicsView->setFixedHeight(screen->geometry().height());
    ui->graphicsView_2->setFixedWidth(screen->geometry().width() * 0.24);
    ui->graphicsView_3->setFixedWidth(screen->geometry().width() * 0.51);
    ui->graphicsView_3->move(screen->geometry().width() / 4, 0);
    ui->graphicsView_4->setFixedWidth(screen->geometry().width() * 0.235);
    ui->graphicsView_4->move((screen->geometry().width() * 0.77), 0);
    ui->label->setAlignment(Qt::AlignCenter);
    ui->label->setStyleSheet("color:gray");
    ui->pushButton_2->setStyleSheet("background-color:transparent;color:white");
    ui->pushButton->setStyleSheet("QPushButton{border-radius:100;background-color:green;color:white}");
    ui->pushButton->move(screen->geometry().width() / 2 - ui->pushButton->width() / 2, screen->geometry().height() / 2 + 48);
    ui->pushButton_2->move(screen->geometry().width() / 2 - ui->pushButton_2->width() / 2, screen->geometry().height() / 2 + 318);
    ui->label->move(screen->geometry().width() / 2 - ui->label->width() / 2, ui->label->y());
    QFont font = ui->label->font();
    font.setPointSize(screen->geometry().width() * 0.055);
    ui->label->setFont(font);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_pushButton_clicked()

{
    //MainMenu::~MainMenu();
    MainWindow* w = new MainWindow();
    w->showFullScreen();

}


void MainMenu::on_pushButton_2_clicked()
{
    exit(1);
}


/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QGraphicsView *graphicsView_2;
    QGraphicsView *graphicsView_3;
    QGraphicsView *graphicsView_4;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_2;

    void setupUi(QMainWindow *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName("MainMenu");
        MainMenu->resize(1536, 864);
        centralwidget = new QWidget(MainMenu);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setCursor(QCursor(Qt::CrossCursor));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(0, 0, 1536, 864));
        graphicsView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::NoBrush);
        graphicsView->setBackgroundBrush(brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        graphicsView->setForegroundBrush(brush1);
        graphicsView_2 = new QGraphicsView(centralwidget);
        graphicsView_2->setObjectName("graphicsView_2");
        graphicsView_2->setGeometry(QRect(0, 0, 250, 345));
        graphicsView_2->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        graphicsView_3 = new QGraphicsView(centralwidget);
        graphicsView_3->setObjectName("graphicsView_3");
        graphicsView_3->setGeometry(QRect(256, 0, 1024, 345));
        graphicsView_3->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        graphicsView_4 = new QGraphicsView(centralwidget);
        graphicsView_4->setObjectName("graphicsView_4");
        graphicsView_4->setGeometry(QRect(1286, 0, 250, 345));
        graphicsView_4->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(668, 480, 200, 200));
        QFont font;
        font.setPointSize(40);
        font.setBold(true);
        font.setStyleStrategy(QFont::PreferDefault);
        pushButton->setFont(font);
        pushButton->setCursor(QCursor(Qt::CrossCursor));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(283, 120, 970, 120));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Century Gothic")});
        font1.setPointSize(90);
        font1.setBold(true);
        label->setFont(font1);
        label->setCursor(QCursor(Qt::CrossCursor));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(708, 750, 120, 60));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Century Gothic")});
        font2.setPointSize(24);
        font2.setBold(true);
        pushButton_2->setFont(font2);
        pushButton_2->setCursor(QCursor(Qt::CrossCursor));
        MainMenu->setCentralWidget(centralwidget);

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QMainWindow *MainMenu)
    {
        MainMenu->setWindowTitle(QCoreApplication::translate("MainMenu", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainMenu", "Start", nullptr));
        label->setText(QCoreApplication::translate("MainMenu", "Brick Breaker\n"
"", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainMenu", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H

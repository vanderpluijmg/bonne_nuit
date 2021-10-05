/********************************************************************************
** Form generated from reading UI file 'gameWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>


class gameWindow : public QWidget
{
public:
    QFrame *Star1;
    QFrame *Star2;
    QFrame *Star3;
    QFrame *Star4;
    QFrame *Star5;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;

    explicit gameWindow(){
        setupUi(this);
        displayRose(3);
    }

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(1047, 811);
        Star1 = new QFrame(Form);
        Star1->setObjectName(QString::fromUtf8("Star1"));
        Star1->setGeometry(QRect(80, 200, 261, 171));
        Star1->setFrameShape(QFrame::StyledPanel);
        Star1->setFrameShadow(QFrame::Raised);
        Star2 = new QFrame(Form);
        Star2->setObjectName(QString::fromUtf8("Star2"));
        Star2->setGeometry(QRect(360, 100, 261, 171));
        Star2->setFrameShape(QFrame::StyledPanel);
        Star2->setFrameShadow(QFrame::Raised);
        Star3 = new QFrame(Form);
        Star3->setObjectName(QString::fromUtf8("Star3"));
        Star3->setGeometry(QRect(670, 220, 261, 171));
        Star3->setFrameShape(QFrame::StyledPanel);
        Star3->setFrameShadow(QFrame::Raised);
        Star4 = new QFrame(Form);
        Star4->setObjectName(QString::fromUtf8("Star4"));
        Star4->setGeometry(QRect(570, 460, 261, 171));
        Star4->setFrameShape(QFrame::StyledPanel);
        Star4->setFrameShadow(QFrame::Raised);
        Star5 = new QFrame(Form);
        Star5->setObjectName(QString::fromUtf8("frame"));
        Star5->setGeometry(QRect(220, 480, 261, 171));
        Star5->setFrameShape(QFrame::StyledPanel);
        Star5->setFrameShadow(QFrame::Raised);
        horizontalLayoutWidget = new QWidget(Form);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 10, 961, 111));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
        horizontalLayout->addItem(horizontalSpacer);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        horizontalLayout->addWidget(label);
        retranslateUi(Form);
        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        label->setText(QCoreApplication::translate("Form", "DiceRool", nullptr));
    } // retranslateUi

    void displayRose(int rosePlace){
        QPixmap rosePicture ("src/ressources/images/img/drop.png");
        auto label = new QLabel(Star5);
        label->setPixmap(rosePicture);
    }
};





#endif // GAMEWINDOW_H

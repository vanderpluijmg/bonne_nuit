#include "winnerWidget.h"
#include "../View.h"
#include <QScreen>

winnerWidget::winnerWidget(int winnerN) {
    setUp(this, winnerN);
    QObject::connect(this->quit,&QPushButton::clicked, this, &winnerWidget::quitGame);
}

void winnerWidget::setUp(QWidget* winner, int winnerH) {
    auto g= QGuiApplication::primaryScreen()->geometry();
    int w = g.width();
    int h = g.height();
    if (winner->objectName().isEmpty())
        winner->setObjectName(QString::fromUtf8("winner"));
    winner->resize(w, h);
    quit = new QPushButton(winner);
    quit->setObjectName(QString::fromUtf8("quit"));
    quit->setGeometry(QRect(w*43/100, h*45/100, w*15/100, h*5/100));
    quit->setStyleSheet("font-family:'MS Shell Dlg 2'; font-size:20pt; font-weight:400; font-style:normal;");
    quit->setText("Quit to desktop");
    quit->setEnabled(true);

    congratulations = new QLabel(winner);
    congratulations->setObjectName(QString::fromUtf8("congratulations"));
    congratulations->setGeometry(QRect(w*46.5/100, h*19/100, 421, w*20/100));
    congratulations->setStyleSheet("font-family:'MS Shell Dlg 2'; font-size:20pt; font-weight:400; font-style:normal;");
    color = new QPushButton(winner);
    color->setObjectName(QString::fromUtf8("color"));
    color->setGeometry(QRect(w*49/100, h*22/100, 421, w*20/100));
    QIcon icon;
    View::getStarPicture(winnerH, icon);
    color->setFixedSize(icon.actualSize(icon.availableSizes().first()));
    color->setIcon(icon);
    color->setIconSize(icon.availableSizes().first());

    win = new QLabel(winner);
    win->setObjectName(QString::fromUtf8("win"));
    win->setGeometry(QRect(w*47.5/100, h*25/100, 421, w*20/100));
    win->setStyleSheet("font-family:'MS Shell Dlg 2'; font-size:20pt; font-weight:400; font-style:normal;");

    label = new QLabel(winner);
    label->setObjectName(QString::fromUtf8("label"));
    QString nameOfPlayer = QString("Player " + QString::number(winnerH+1));
    label->setText(nameOfPlayer);
    label->setGeometry(QRect(w*48/100, h*22/100, 421, w*20/100));
    label->setStyleSheet("font-family:'MS Shell Dlg 2'; font-size:20pt; font-weight:400; font-style:normal;");
    retranslateUi(winner);
    QMetaObject::connectSlotsByName(winner);

}

void winnerWidget::retranslateUi(QWidget *winner) const {
    winner->setWindowTitle(QCoreApplication::translate("winner", "Form", nullptr));
    congratulations->setText(QCoreApplication::translate("winner", "Congratulations", nullptr));
    color->setText(QCoreApplication::translate("winner", "", nullptr));
    win->setText(QCoreApplication::translate("winner", "You won !", nullptr));

}

void winnerWidget::quitGame() {
    exit (0);
}

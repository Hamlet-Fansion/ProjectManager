//
// Created by Hamlet on 2021/2/14.
//

// You may need to build the project (run Qt uic code generator) to get "ui_AboutWidget.h" resolved

#include "aboutwidget.h"
#include "ui_aboutwidget.h"

AboutWidget::AboutWidget(QWidget *parent) :
        QWidget(parent), ui(new Ui::AboutWidget) {
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
    this->installEventFilter(this);
    ui->label->setOpenExternalLinks(true);
    ui->label->setStyleSheet("background-color: rgb" + colors[current_index]);
    ++current_index;
}

AboutWidget::~AboutWidget() {
    delete ui;
}

void AboutWidget::showEvent(QShowEvent *) {
    this->show();
    this->activateWindow();
}

bool AboutWidget::eventFilter(QObject *object, QEvent *event) {
    if (object == this && event->type() == QEvent::WindowDeactivate) {
        this->close();
        return true;
    }
    return QWidget::eventFilter(object, event);
}

void AboutWidget::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton || event->button() == Qt::RightButton) {
        ui->label->setStyleSheet("background-color: rgb" + colors[current_index]);
        ++current_index;
        if (current_index == colors.size())
            current_index = 0;
    }
}

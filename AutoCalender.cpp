//
// Created by Hamlet on 2021/2/12.
//

#include "AutoCalender.h"

AutoCalender::AutoCalender(QWidget *parent) : QCalendarWidget(parent) {
    this->setWindowTitle("日期选择");
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool); // 没有任务栏图标
    this->resize(300, 240);
    this->installEventFilter(this); // 注册事件过滤器，使eventFilter可用
}

void AutoCalender::showEvent(QShowEvent *) {
    auto pos_calender = this->geometry();
    auto pos_cursor = QCursor::pos();
    pos_calender.moveTo(pos_cursor.x() - pos_calender.width() / 2, pos_cursor.y() + 15);
    this->setGeometry(pos_calender);
    this->show();
    this->activateWindow(); // 能将此窗口设置为当前使用窗口
}

// 这个功能真的太厉害了，感谢不屈的我发现了这个功能
bool AutoCalender::eventFilter(QObject *object, QEvent *event) { // 窗口被deactivate的时候触发
    if (object == this && event->type() == QEvent::WindowDeactivate) {
        this->close();
        return true;
    }
    return QCalendarWidget::eventFilter(object, event);
}
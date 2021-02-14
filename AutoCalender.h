//
// Created by Hamlet on 2021/2/12.
//

#ifndef PROJECTMANAGER_AUTOCALENDER_H
#define PROJECTMANAGER_AUTOCALENDER_H

#include <QCalendarWidget>
#include <QEvent>
// 一个很简洁的日历选择器，弹出在鼠标的下面，focus on其他窗口时会自动关闭
class AutoCalender : public QCalendarWidget { // 重写了显示以及关闭的方法
Q_OBJECT
public:
    explicit AutoCalender(QWidget *parent = nullptr);

protected:
    void showEvent(QShowEvent *) override;

    bool eventFilter(QObject *object, QEvent *event) override;
};

#endif //PROJECTMANAGER_AUTOCALENDER_H

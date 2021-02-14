//
// Created by Hamlet on 2021/2/14.
//

#ifndef PROJECTMANAGER_ABOUTWIDGET_H
#define PROJECTMANAGER_ABOUTWIDGET_H

#include <vector>
#include <QWidget>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class AboutWidget; }
QT_END_NAMESPACE

class AboutWidget : public QWidget {
Q_OBJECT

public:
    explicit AboutWidget(QWidget *parent = nullptr);

    ~AboutWidget() override;

protected:
    void showEvent(QShowEvent *) override;

    bool eventFilter(QObject *object, QEvent *event) override;

    void mousePressEvent(QMouseEvent *) override;

private:
    Ui::AboutWidget *ui;
    int current_index{0};
    std::vector<QString> colors{"(255, 255, 255)", "(255, 165, 201)", "(157, 186, 255)",
                                "(255, 170, 127)", "(185, 255, 191)", "(210, 164, 255)",
                                "(242, 255, 184)", "(184, 255, 237)", "(255, 192, 192)"};
};

#endif //PROJECTMANAGER_ABOUTWIDGET_H

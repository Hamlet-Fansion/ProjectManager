//
// Created by Hamlet on 2021/2/12.
//
#ifndef PROJECTMANAGER_FILTERWIDGET_H
#define PROJECTMANAGER_FILTERWIDGET_H

#include <set>
#include <QWidget>
#include <QCheckBox>
#include "AutoCalender.h"

QT_BEGIN_NAMESPACE
namespace Ui { class FilterWidget; }
QT_END_NAMESPACE

class FilterWidget : public QWidget {
Q_OBJECT

public:
    explicit FilterWidget(QWidget *parent = nullptr);

    ~FilterWidget() override;

    void reset(std::set<QString>& dir_names, std::set<QString>& label_names);

    std::vector<std::vector<QString>> get_filter_options();

    bool need_clear_all{false};
    void select_all();

protected:
    void showEvent(QShowEvent *) override;

    void closeEvent(QCloseEvent *) override;

    bool eventFilter(QObject *object, QEvent *event) override;

signals:
    void filter_button_clicked(); // 这个信号不能实现，否则就会失效

private slots:

    void send_filter_button_clicked_message();

    void change_state(int);

    void dir_choose_all();

    void path_choose_all();

    void dir_checkBox_consider();

    void path_checkBox_consider();

    void on_toolButton_clicked();

    void on_pushButton_clear_all_clicked();

    void on_pushButton_select_all_clicked();

    void on_pushButton_filter_clicked();

    void calender_set_data();

private:
    Ui::FilterWidget *ui;
    AutoCalender *calender;
    std::vector<QCheckBox *> checkBoxes_dir;
    std::vector<QCheckBox *> checkBoxes_label;

    bool need_recover{true};
    std::vector<bool> button_states;

    void check_all(bool state);
};

#endif //PROJECTMANAGER_FILTERWIDGET_H

// 2021.2.14几经试错，在几乎崩溃之际，终于解决了错误，我发现：
// 在使用vector<QWidget *>这类数据结构时，想要删除一个元素，必须使用v[i].deleteLater(); v.erase(v.begin()+i);
// 而不能想当然地v[i].deleteLater(); v.pop_back();，即使我是从后往前倒着遍历也不行

//
// Created by Hamlet on 2021/2/12.
//

// You may need to build the project (run Qt uic code generator) to get "ui_FilterWidget.h" resolved

#include "filterwidget.h"
#include "ui_filterwidget.h"
#include <QScrollBar>

FilterWidget::FilterWidget(QWidget *parent) :
        QWidget(parent), ui(new Ui::FilterWidget), calender(new AutoCalender) {
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
    this->installEventFilter(this);

    // 丑死了
//    this->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");

    connect(calender, SIGNAL(selectionChanged()), this, SLOT(calender_set_data()));
    connect(ui->checkBox_time, SIGNAL(stateChanged(int)), this, SLOT(change_state(int)));
    connect(ui->checkBox_dir, SIGNAL(clicked()), this, SLOT(dir_choose_all()));
    connect(ui->checkBox_label, SIGNAL(clicked()), this, SLOT(path_choose_all()));

    ui->radioButton_before->setChecked(true); // 默认选中
    ui->dateEdit->setDate(QDate::currentDate());
    change_state(0);
}

FilterWidget::~FilterWidget() {
    delete ui;
    delete calender;
}

void FilterWidget::change_state(int state) {
    if (state) {
        ui->dateEdit->setReadOnly(false);
        ui->toolButton->setVisible(true);
        ui->radioButton_before->setVisible(true);
        ui->radioButton_after->setVisible(true);
    } else {
        ui->dateEdit->setReadOnly(true);
        ui->toolButton->setVisible(false);
        ui->radioButton_before->setVisible(false);
        ui->radioButton_after->setVisible(false);
    }
}

bool FilterWidget::eventFilter(QObject *object, QEvent *event) {
    if (!calender->isActiveWindow() && object == this && event->type() == QEvent::WindowDeactivate) {
        this->close();
        return true;
    }
    return QWidget::eventFilter(object, event);
}

void FilterWidget::showEvent(QShowEvent *) {
    this->show();
    this->activateWindow();

    if (need_clear_all) {
        on_pushButton_select_all_clicked(); // 清空filter时是全选状态
        need_clear_all = false;
    }

    need_recover = true;
    button_states.clear();
    button_states.push_back(ui->checkBox_time->isChecked());
    for (const auto &i:checkBoxes_dir)
        button_states.push_back(i->isChecked());
    for (const auto &i:checkBoxes_label)
        button_states.push_back(i->isChecked());
    // 设置页面滚动到最顶部
    auto *scrollBar = ui->scrollArea->horizontalScrollBar();
    if (scrollBar) {
        scrollBar->setValue(scrollBar->minimum());
    }
}

void FilterWidget::reset(std::set<QString> &dir_names, std::set<QString> &label_names) {
    // 保证原先选中的之后还是选中状态
    for (int i = (int) checkBoxes_dir.size() - 1; i != -1; --i) {
        auto it = std::find(dir_names.begin(), dir_names.end(), checkBoxes_dir[i]->text()); // exception
        if (it != dir_names.end())
            dir_names.erase(it);
        else {
            disconnect(checkBoxes_dir[i], SIGNAL(stateChanged(int)), this, SLOT(dir_checkBox_consider()));
            checkBoxes_dir[i]->deleteLater(); // deleteLater绝对有问题
            checkBoxes_dir.erase(checkBoxes_dir.begin() + i); // 啊，好了！不能用pop_back()，用erase()才行！！！
        }
    }
    for (int i = (int) checkBoxes_label.size() - 1; i != -1; --i) {
        auto it = std::find(label_names.begin(), label_names.end(), checkBoxes_label[i]->text()); // exception
        if (it != label_names.end())
            label_names.erase(it);
        else {
            disconnect(checkBoxes_label[i], SIGNAL(stateChanged(int)), this, SLOT(path_checkBox_consider()));
            checkBoxes_label[i]->deleteLater();
            checkBoxes_label.erase(checkBoxes_label.begin() + i);
        }
    }
    for (const auto &i:dir_names) {
        auto *check = new QCheckBox(ui->groupBox_parent_dir);
        checkBoxes_dir.push_back(check);
        check->setText(i);
        ui->verticalLayout_dir->addWidget(check);
        connect(check, SIGNAL(stateChanged(int)), this, SLOT(dir_checkBox_consider()));
    }
    for (const auto &i:label_names) {
        auto *check = new QCheckBox(ui->groupBox_label);
        checkBoxes_label.push_back(check);
        check->setText(i);
        ui->verticalLayout_label->addWidget(check);
        connect(check, SIGNAL(stateChanged(int)), this, SLOT(path_checkBox_consider()));
    }

}

void FilterWidget::on_toolButton_clicked() {
    calender->show();
}

void FilterWidget::calender_set_data() {
    ui->dateEdit->setDate(calender->selectedDate());
    calender->close();
    this->activateWindow();
}

void FilterWidget::on_pushButton_clear_all_clicked() {
    check_all(false);
}

void FilterWidget::on_pushButton_select_all_clicked() {
    check_all(true);
}

void FilterWidget::on_pushButton_filter_clicked() {
    // 进行筛选操作：实现在manager.h里的filter()里了
    need_recover = false;
    this->close();
    send_filter_button_clicked_message();
}

void FilterWidget::closeEvent(QCloseEvent *) {
    this->close();

    if (need_recover) {
        if (button_states.empty())
            return;
        int i = 0;
        ui->checkBox_time->setChecked(button_states[0]);
        for (const auto &j:checkBoxes_dir) {
            ++i;
            j->setChecked(button_states[i]);
        }
        for (const auto &j:checkBoxes_label) {
            ++i;
            j->setChecked(button_states[i]);
        }
    }
}

std::vector<std::vector<QString>> FilterWidget::get_filter_options() {
    std::vector<std::vector<QString>> result;
    std::vector<QString> item;
    if (ui->checkBox_time->isChecked()) {
        item.emplace_back("true");
        item.push_back(ui->dateEdit->text());
        if (ui->radioButton_before->isChecked())
            item.emplace_back("before");
        else
            item.emplace_back("after");
    } else
        item.emplace_back("false");
    result.push_back(item);
    item.clear();
    for (const auto &i:checkBoxes_dir)
        if (i->isChecked())
            item.push_back(i->text());
    result.push_back(item);
    item.clear();
    for (const auto &i:checkBoxes_label)
        if (i->isChecked())
            item.push_back(i->text());
    result.push_back(item);
    return result;
}

void FilterWidget::send_filter_button_clicked_message() {
    emit filter_button_clicked();
}

void FilterWidget::dir_choose_all() {
    bool state = ui->checkBox_dir->isChecked();
    for (const auto &i:checkBoxes_dir)
        i->setChecked(state);
}

void FilterWidget::path_choose_all() {
    bool state = ui->checkBox_label->isChecked();
    for (const auto &i:checkBoxes_label)
        i->setChecked(state);
}

void FilterWidget::check_all(bool state) {
    for (const auto &i:checkBoxes_dir)
        i->setChecked(state);
    for (const auto &i:checkBoxes_label) {
        i->setChecked(state); // exception
        // 我觉得可能是因为这个对象之前被销毁了，不知为什么没有pop掉，再次使用它导致错误，但我根本不知道如何解决
        // 当前的一个思路就是试遍所有出错的情况，看看有没有想法
    }
}

void FilterWidget::dir_checkBox_consider() {
    bool all_checked{true};
    for (const auto &i:checkBoxes_dir)
        if (!i->isChecked()) {
            all_checked = false;
            break;
        }
    if (all_checked)
        ui->checkBox_dir->setChecked(true);
    else
        ui->checkBox_dir->setChecked(false);
}

void FilterWidget::path_checkBox_consider() {
    bool all_checked{true};
    for (const auto &i:checkBoxes_label)
        if (!i->isChecked()) {
            all_checked = false;
            break;
        }
    if (all_checked)
        ui->checkBox_label->setChecked(true);
    else
        ui->checkBox_label->setChecked(false);
}

void FilterWidget::select_all() {
    on_pushButton_select_all_clicked(); // 清空filter时是全选状态
}

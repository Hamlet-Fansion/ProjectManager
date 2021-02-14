//
// Created by Hamlet on 2021/2/10.
//

#ifndef PROJECTMANAGER_MANAGER_H
#define PROJECTMANAGER_MANAGER_H

#include <filesystem>
#include <nlohmann/json.hpp>
#include <QMainWindow>
#include <QCloseEvent>
#include "Project.h"
#include "AutoCalender.h"
#include "filterwidget.h"
#include "aboutwidget.h"

using json = nlohmann::json;

QT_BEGIN_NAMESPACE
namespace Ui { class Manager; }
QT_END_NAMESPACE

class Manager : public QMainWindow {
Q_OBJECT

public:
    explicit Manager(QWidget *parent = nullptr);

    ~Manager() override;

    void open_document(const QString &file_name); // 打开一个文件，读入到data中

private slots:
    void show_about_action();

    void new_document_action();

    void open_document_action();

    void close_document();

    void save_data(); // 保存data.json

    void sort(); // 排序

    void filter(); // 过滤

    void search(const QString&); // 查找

    void show_current_project(); // 浏览项目切换时的动作

    void calender_set_date(); // 从calender widget设置日期

    void change_extension(); // 修改README文件后缀

    void on_pushButton_edit_save_clicked();

    void on_pushButton_open_clicked();

    void on_pushButton_remove_clicked();

    void on_pushButton_add_label_clicked();

    void on_pushButton_delete_label_clicked();

    void on_toolButton_date_clicked();

    void on_pushButton_readme_edit_save_clicked();

    void on_pushButton_readme_new_clicked();

    void on_pushButton_external_clicked();

    void on_pushButton_readme_delete_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_delete_clicked();

    void on_toolButton_filter_clicked();

protected:
    void closeEvent(QCloseEvent *) override;
    bool eventFilter(QObject *object, QEvent *event) override;

private:
    Ui::Manager *ui;
    AboutWidget *aboutWidget;
    AutoCalender *calender;
    FilterWidget *filterWidget;
    std::filesystem::path data_path;
    std::filesystem::path readme_path;
    json data;
    Project projects;
    Label labels;
    bool file_opened{false};
    bool file_saved{true};
    bool mod_edited_metadata{false};
    bool mod_edited_readme{false};
    int last_index{0};

    void load_document(); // 加载data的全部项目到界面中
    void mod_document_opened(bool mod);
    void mod_edit_metadata(bool mod); // 元数据框里面切换编辑和readonly模式，true为可以编辑，false为只读
    void mod_edit_readme(bool mod); // 编辑模式和保存模式切换
    void set_readme_editable_mod(bool mod); // 设置是否能进行编辑和保存，true可以，false不可以
    void ask_save_metadata(); // 询问是否保存
    void ask_save_readme();
    void ask_save_data();
    void reload_filterWidget_page(); // 重新刷新filterWidget页面
};

#endif //PROJECTMANAGER_MANAGER_H
// 2021/2/11剩下：
// √ 1.新建项目、删除项目 # 还不能确定是否成功
// √ 2.完成sorter 半√（中文排序问题）, filter 半√（多次删除出错问题、仅剩一项时删除出错问题）, finder
// 3.完成菜单栏、关于框（做秀丽一点）(calender widget)
// 4.创造图标，rc文件（关联文件、应用信息、关联文件图标）
// 5.installer

// 唯一没有解决的：中文路径问题，现在的想法：1.完全用Qt读取文件；2.使用全局unicode字符集（如何）
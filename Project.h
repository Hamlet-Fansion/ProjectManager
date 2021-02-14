//
// Created by Hamlet on 2021/2/10.
//

#ifndef PROJECTMANAGER_PROJECT_H
#define PROJECTMANAGER_PROJECT_H

#include <filesystem>
#include <vector>
#include <map>
#include <nlohmann/json.hpp>
#include <QDate>
#include <QTableWidget>
#include <QTableWidgetItem>

using json = nlohmann::json;

enum class Sorter { // 如何使用类似 A::f | A::p，这样的复合词，这样可以更灵活一点
    positiveChronologicalOrder, // 按时间正序
    reverseChronologicalOrder,  // 按时间倒序
    positiveNominalOrder,       // 按名称正序
    reverseNominalOrder         // 按名称倒序
};

//enum class Filter {
//    filterByTime,          // 筛选时间
//    filterByParentDir,     // 筛选父文件夹
//    filterByLabel          // 筛选标签
//};

class Project { // 用来表示所有项目，内容物为QTableWidgetItem*，暂时设定固定的大小(-1,3)
    // 这一次使用二叠vector的方法表示model，下次就不用QTableWidget了，直接用QListView，使用我自己构造的model
public:
    Project() = default;

    ~Project() = default;

    void
    add_row(int data_index, const std::string &name, const std::string &date, const std::vector<std::string> &label);

    void change_row(int row, const std::string &name, const std::string &date, const std::vector<std::string> &label);

    void set_row_all(QTableWidget *table);

    void add_default_row(QTableWidget *table);

    int delete_current_project(QTableWidget *table); // 返回的是data.json需要删除的索引

    void hidden_project(QTableWidget *table, int row);

    void clear_all(QTableWidget *table);

    void sort(Sorter sort_mod); // 对项目进行排序，有四种模式（见Sorter）

    void filter(const json& data, QTableWidget *table, const std::vector<std::vector<QString>> &options); // 对项目进行筛选

    void search(QTableWidget *table, const QString& name);

    void non_filter(QTableWidget *table);

    std::vector<int> showing_items; // 就相当于一个记录的元素指针的作用，它的所有元素代表了所有项目，对应的值是这个项目在data.json中的索引

    int showing_number{0}; // 当前显示在屏幕上的项目个数

    bool non_filter_mod{true}; // 真的太烦人了，就为了在Project和filterWidget之间传递信息

private:
    std::vector<std::vector<QTableWidgetItem *>> projects;
};

class Label {
public:
    Label() = default;

    ~Label() = default;

    void set_column_all(QTableWidget *table, const std::vector<std::string> &names); // 直接读取并设置

    void add_item_editing(QTableWidget *table); // 新建一个项目，并且切换到编辑状态

    void delete_current_item(QTableWidget *table); // 删除当前选则的项目（只能删一个）

    std::vector<std::string> get_content(); // 获取当前全部的值

private:
    std::vector<QTableWidgetItem *> labels;
};

#endif //PROJECTMANAGER_PROJECT_H

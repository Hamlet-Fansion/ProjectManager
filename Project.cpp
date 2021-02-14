//
// Created by Hamlet on 2021/2/10.
//

#include "Project.h"
#include <QCollator>

class Nominal_collator {
public:
    bool operator()(const QString &a, const QString &b) const { // 这个const非常重要
        int result = collator.compare(a, b); // compare跟我原先想的不一样，我一开始真的想当然了
        return result < 0;
    }

private:
    QCollator collator{QLocale::Chinese};
};

void Project::add_row(int data_index, const std::string &name, const std::string &date,
                      const std::vector<std::string> &label) {
    showing_items.push_back(data_index);
    ++showing_number;
    std::string format;
    for (const auto &i:label)
        format += (i + ", ");
    format = format.substr(0, format.size() - 2);
    projects.push_back({new QTableWidgetItem(QString::fromStdString(name)),
                        new QTableWidgetItem(QString::fromStdString(date)),
                        new QTableWidgetItem(QString::fromStdString(format))});
}

void Project::set_row_all(QTableWidget *table) {
    table->setRowCount(projects.size());
    table->setColumnCount(3);
    for (int row = 0; row != projects.size(); ++row)
        for (int column = 0; column != 3; ++column)
            table->setItem(row, column, projects[row][column]);
}

void
Project::change_row(int row, const std::string &name, const std::string &date, const std::vector<std::string> &label) {
    std::string format;
    if (!label.empty()) {
        for (const auto &i:label)
            format += (i + ", ");
        format = format.substr(0, format.size() - 2);
    }
    projects[row][0]->setText(QString::fromStdString(name));
    projects[row][1]->setText(QString::fromStdString(date));
    projects[row][2]->setText(QString::fromStdString(format));
}

void Project::clear_all(QTableWidget *table) {
    non_filter(table);
    for (int i = (int) projects.size() - 1; i > 0; --i)
        table->removeRow(i);
    table->clear();
    QStringList header;
    header << "名称" << "时间" << "标签";
    table->setHorizontalHeaderLabels(header);
    projects.clear();
    showing_items.clear();
    showing_number = 0;
}

void Project::sort(Sorter sort_mod) { // 虽然有些重复，但是看起来清晰呀
    switch (sort_mod) {
        case Sorter::positiveChronologicalOrder: {
            std::map<QDate, int> m;
            std::vector<std::vector<QString>> temp;
            std::vector<int> temp_int;
            for (int i = 0; i != showing_number; ++i) {
                m.insert(std::pair<QDate, int>(QDate::fromString(projects[i][1]->text(), "yyyy/M/d"), i));
                temp_int.push_back(showing_items[i]);
                temp.push_back({projects[i][0]->text(), projects[i][1]->text(), projects[i][2]->text()});
            }
            int i = 0;
            for (const auto &m_i:m) {
                projects[i][0]->setText(temp[m_i.second][0]);
                projects[i][1]->setText(temp[m_i.second][1]);
                projects[i][2]->setText(temp[m_i.second][2]);
                showing_items[i] = temp_int[m_i.second];
                ++i;
            }
            break;
        }
        case Sorter::reverseChronologicalOrder: {
            std::map<QDate, int> m;
            std::vector<std::vector<QString>> temp;
            std::vector<int> temp_int;
            for (int i = 0; i != showing_number; ++i) {
                m.insert(std::pair<QDate, int>(QDate::fromString(projects[i][1]->text(), "yyyy/M/d"), i));
                temp_int.push_back(showing_items[i]);
                temp.push_back({projects[i][0]->text(), projects[i][1]->text(), projects[i][2]->text()});
            }
            int i = (int) m.size() - 1;
            for (const auto &m_i:m) {
                projects[i][0]->setText(temp[m_i.second][0]);
                projects[i][1]->setText(temp[m_i.second][1]);
                projects[i][2]->setText(temp[m_i.second][2]);
                showing_items[i] = temp_int[m_i.second];
                --i;
            }
            break;
        }
        case Sorter::positiveNominalOrder: {
            std::map<QString, int, Nominal_collator> m;
            std::vector<std::vector<QString>> temp;
            std::vector<int> temp_int;
            for (int i = 0; i != showing_number; ++i) {
                m.insert(std::pair<QString, int>(projects[i][0]->text().toUpper(), i));
                temp_int.push_back(showing_items[i]);
                temp.push_back({projects[i][0]->text(), projects[i][1]->text(), projects[i][2]->text()});
            }
            int i = 0;
            for (const auto &m_i:m) {
                projects[i][0]->setText(temp[m_i.second][0]);
                projects[i][1]->setText(temp[m_i.second][1]);
                projects[i][2]->setText(temp[m_i.second][2]);
                showing_items[i] = temp_int[m_i.second];
                ++i;
            }
            break;
        }
        case Sorter::reverseNominalOrder: {
            std::map<QString, int, Nominal_collator> m;
            std::vector<std::vector<QString>> temp;
            std::vector<int> temp_int;
            for (int i = 0; i != showing_number; ++i) {
                m.insert(std::pair<QString, int>(projects[i][0]->text().toUpper(), i));
                temp_int.push_back(showing_items[i]);
                temp.push_back({projects[i][0]->text(), projects[i][1]->text(), projects[i][2]->text()});
            }
            int i = (int) m.size() - 1;
            for (const auto &m_i:m) {
                projects[i][0]->setText(temp[m_i.second][0]);
                projects[i][1]->setText(temp[m_i.second][1]);
                projects[i][2]->setText(temp[m_i.second][2]);
                showing_items[i] = temp_int[m_i.second];
                --i;
            }
            break;
        }
    }
}

void Project::add_default_row(QTableWidget *table) {
    non_filter(table);
    projects.push_back({new QTableWidgetItem("新建项"),
                        new QTableWidgetItem("新建项"),
                        new QTableWidgetItem("新建项")});
    int number = projects.size();
    table->setRowCount(number);
    for (int i = 0; i != 3; ++i)
        table->setItem(number - 1, i, projects[number - 1][i]);
    showing_items.push_back(number - 1);
    ++showing_number;
}

int Project::delete_current_project(QTableWidget *table) {
    int current_index = table->currentRow();
    if (current_index == 0 && showing_number == 1)
        non_filter(table);
    if (table->rowCount() == 1) {
        table->clear();
        QStringList header;
        header << "名称" << "时间" << "标签";
        table->setHorizontalHeaderLabels(header);
    } else
        table->removeRow(current_index);
    projects.erase(projects.begin() + current_index);
    int current_data_index = showing_items[current_index];
    showing_items.erase(showing_items.begin() + current_index);
    --showing_number;
    for (int i = 0; i != showing_items.size(); ++i) // 所有大于current_data_index的索引在删除掉current_data_index后都会减一
        if (showing_items[i] > current_data_index)
            --showing_items[i];
    return current_data_index;
}

void Project::filter(const json &data, QTableWidget *table, const std::vector<std::vector<QString>> &options) {
    non_filter(table);
    bool filter_time{options[0][0] == "true"};
    bool filter_time_before{false};
    if (filter_time)
        filter_time_before = options[0][2] == "before";
    QDate date;
    if (filter_time)
        date = QDate::fromString(options[0][1], "yyyy/M/d");
    for (int i = (int) showing_number - 1; i != -1; --i) {
        if (filter_time) {
            QDate project_date{QDate::fromString(projects[i][1]->text(), "yyyy/M/d")};
            if ((filter_time_before && project_date > date) || (!filter_time_before && project_date < date)) {
                hidden_project(table, i);
                continue;
            }
        }
        bool need_delete{true};
        for (const auto &j:options[1])
            if (std::filesystem::path(data[showing_items[i]]["path"].get<std::string>()).parent_path().string() ==
                j.toStdString()) {
                need_delete = false;
                break;
            }
        if (need_delete) {
            hidden_project(table, i);
            continue;
        }
        need_delete = true;
        for (const auto &j:options[2])
            if (projects[i][2]->text().contains(j, Qt::CaseSensitive)) {
                need_delete = false;
                break;
            }
        if (need_delete) {
            hidden_project(table, i);
            continue;
        }
    }
    non_filter_mod = false;
}

void Project::hidden_project(QTableWidget *table, int row) { // 这样一次删一个还是太低效了，下次搞个直接隐藏多个行
    if (row < 0 || row >= showing_number)
        return;
    int index = showing_number - 1;
    if (row != index) {
        std::vector<QString> temp{projects[index][0]->text(), projects[index][1]->text(), projects[index][2]->text()};
        int temp_index = showing_items[index];
        projects[index][0]->setText(projects[row][0]->text());
        projects[index][1]->setText(projects[row][1]->text());
        projects[index][2]->setText(projects[row][2]->text());
        showing_items[index] = showing_items[row];
        for (int i = row; i != index - 1; ++i) {
            projects[i][0]->setText(projects[i + 1][0]->text());
            projects[i][1]->setText(projects[i + 1][1]->text());
            projects[i][2]->setText(projects[i + 1][2]->text());
            showing_items[i] = showing_items[i + 1];
        }
        projects[index - 1][0]->setText(temp[0]);
        projects[index - 1][1]->setText(temp[1]);
        projects[index - 1][2]->setText(temp[2]);
        showing_items[index - 1] = temp_index;
    }
    table->setRowHidden(index, true);
    --showing_number; // 减去显示项目数1
}

void Project::non_filter(QTableWidget *table) {
    for (int i = 0; i != projects.size(); ++i)
        table->setRowHidden(i, false);
    showing_number = showing_items.size(); // 在这里更新showing_number
    non_filter_mod = true;
}

void Project::search(QTableWidget *table, const QString &name) {
    if (name.isEmpty())
        return;
    for (int i = (int) showing_number - 1; i != -1; --i)
        if (!projects[i][0]->text().contains(name, Qt::CaseInsensitive))
            hidden_project(table, i);
}

void Label::set_column_all(QTableWidget *table, const std::vector<std::string> &names) {
    if (names.size() > labels.size())
        for (int i = labels.size(); i != names.size(); ++i)
            labels.push_back(new QTableWidgetItem());
    else if (names.size() < labels.size())
        for (int i = (int) labels.size() - 1; i != names.size() - 1; --i) {
            table->removeRow(i);
            labels.pop_back();
        }
    table->setRowCount(names.size());
//    table->setColumnCount(1);
    for (int i = 0; i != names.size(); ++i) {
        labels[i]->setText(QString::fromStdString(names[i]));
        table->setItem(i, 0, labels[i]);
    }
}

void Label::add_item_editing(QTableWidget *table) {
    int rows_index = table->rowCount();
    table->setRowCount(rows_index + 1);
    labels.push_back(new QTableWidgetItem());
    table->setItem(rows_index, 0, labels[rows_index]);
    table->setCurrentCell(rows_index, 0);
    table->editItem(labels[rows_index]);
}

void Label::delete_current_item(QTableWidget *table) {
    if (table->rowCount() > 0 && table->currentRow() >= 0) {
        int current_index = table->currentRow();
        table->removeRow(current_index);
        labels.erase(labels.begin() + current_index);
    }
}

std::vector<std::string> Label::get_content() {
    std::vector<std::string> result;
    for (const auto &i:labels)
        result.push_back(i->text().toStdString());
    return result;
}

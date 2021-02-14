//
// Created by Hamlet on 2021/2/10.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Manager.h" resolved

#include <fstream>
#include <QDesktopServices>
#include <QMessageBox>
#include <QFileDialog>
#include "ui_manager.h"
#include "manager.h"
#include "file.h"

Manager::Manager(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::Manager), calender(new AutoCalender), filterWidget(new FilterWidget),
        aboutWidget(new AboutWidget) {
    ui->setupUi(this);
    // 让窗口出现在正中间
    this->move(this->screen()->availableGeometry().center() - this->rect().center());
    this->installEventFilter(this);

    connect(calender, SIGNAL(selectionChanged()), this, SLOT(calender_set_date()));
    connect(ui->tableWidget_overview, SIGNAL(itemSelectionChanged()), this, SLOT(show_current_project()));
    connect(ui->action_new, SIGNAL(triggered()), this, SLOT(new_document_action()));
    connect(ui->action_open, SIGNAL(triggered()), this, SLOT(open_document_action()));
    connect(ui->action_save, SIGNAL(triggered()), this, SLOT(save_data()));
    connect(ui->action_close, SIGNAL(triggered()), this, SLOT(close_document()));
    connect(ui->action_exit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->action_about, SIGNAL(triggered()), this, SLOT(show_about_action()));
    connect(ui->comboBox_sorter, SIGNAL(currentIndexChanged(int)), this, SLOT(sort()));
    connect(ui->comboBox_format, SIGNAL(currentIndexChanged(int)), this, SLOT(change_extension()));
    connect(filterWidget, SIGNAL(filter_button_clicked()), this, SLOT(filter()));
    connect(ui->lineEdit_searcher, SIGNAL(textChanged(const QString &)), this, SLOT(search(const QString &)));

    mod_document_opened(false);
    ui->pushButton_add->setEnabled(false);
}

Manager::~Manager() {
    delete ui;
    delete calender;
}

void Manager::open_document(const QString &file_name) {
    data_path = std::filesystem::path(file_name.toStdString());
    if (std::filesystem::exists(data_path)) {
        std::ifstream file{data_path};
        file >> data;
    }
    load_document();
    ui->comboBox_sorter->setCurrentIndex(0);
    filterWidget->select_all(); // 只有这里select_all()，searcher才起作用，我也不知道为什么（相当于点开一次filterWidget）
    ui->pushButton_add->setEnabled(true);
    file_opened = true;
    mod_document_opened(!projects.showing_items.empty());
}

void Manager::load_document() {
    projects.clear_all(ui->tableWidget_overview); // 加载页面时清空显示的项目
    int data_index = 0;
    for (const auto &i:data) {
        std::vector<std::string> label;
        for (const auto &j:i["label"])
            label.push_back(j.get<std::string>());
        projects.add_row(data_index, i["name"], i["date"], label);
        ++data_index;
    }
    projects.set_row_all(ui->tableWidget_overview);
    ui->statusbar->showMessage(QString::fromStdString(data_path.string()));
    reload_filterWidget_page(); // 加载filterwidget页面
    mod_edit_metadata(false); // 默认非编辑模式（只读模式）
    mod_edit_readme(false); // 默认非编辑模式（只读模式）
    set_readme_editable_mod(false); // 默认需要新建readme
    projects.sort(Sorter::positiveChronologicalOrder); // 默认设置按时间正序
    ui->tableWidget_overview->setCurrentCell(0, 0); // 默认设置打开第一行的项目
}

void Manager::show_current_project() {
    if (!projects.showing_items.empty()) {
        ask_save_metadata();
        ask_save_readme();
        int current_index = ui->tableWidget_overview->currentRow();
        auto &i = data[projects.showing_items[current_index]];
        ui->lineEdit_name->setText(QString::fromStdString(i["name"].get<std::string>()));
        ui->dateEdit_date->setDate(
                QDate::fromString(QString::fromStdString(i["date"].get<std::string>()), "yyyy/M/d"));
        ui->lineEdit_path->setText(QString::fromStdString(i["path"].get<std::string>()));
        ui->textEdit_description->setText(QString::fromStdString(i["desc"].get<std::string>()));
        std::vector<std::string> label;
        for (const auto &j:i["label"])
            label.push_back(j.get<std::string>());
        labels.set_column_all(ui->tableWidget_label, label);

        readme_path = File::search_readme(i["path"].get<std::string>());
        if (!readme_path.empty()) {
            if (readme_path.extension() == ".txt")
                ui->comboBox_format->setCurrentIndex(0);
            else
                ui->comboBox_format->setCurrentIndex(1);
            set_readme_editable_mod(true);
            QFile file{readme_path}; // 这是我使用QFile的一个尝试，我希望将来全部使用它，或许能解决中文路径的问题
            file.open(QIODevice::ReadOnly);
            QString text = QTextStream(&file).readAll();
            file.close();
            ui->textEdit_readme->setPlainText(text);
            ui->textEdit_readme->moveCursor(QTextCursor::Start);
        } else
            set_readme_editable_mod(false);
        last_index = current_index;
    }
}

void Manager::mod_edit_metadata(bool mod) {
    if (mod) { // 转换为编辑模式
        if (file_saved) {
            file_saved = false;
            ui->statusbar->showMessage(QString::fromStdString(data_path.filename().string() + " - 未保存"));
        }
        mod_edited_metadata = true;
        ui->pushButton_edit_save->setText("保存");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/Save.png"), QSize(), QIcon::Normal, QIcon::Off);
        ui->pushButton_edit_save->setIcon(icon);
        ui->toolButton_date->setEnabled(true);
        ui->pushButton_remove->setEnabled(true);
        ui->pushButton_add_label->setEnabled(true);
        ui->pushButton_delete_label->setEnabled(true);
        ui->lineEdit_name->setReadOnly(false);
        ui->dateEdit_date->setReadOnly(false);
        ui->lineEdit_path->setReadOnly(false);
        ui->textEdit_description->setReadOnly(false);
        ui->tableWidget_label->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed);
        ui->toolButton_date->setVisible(true);
        ui->pushButton_remove->setVisible(true);
        ui->pushButton_add_label->setVisible(true);
        ui->pushButton_delete_label->setVisible(true);
    } else {
        mod_edited_metadata = false;
        ui->pushButton_edit_save->setText("编辑");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/Pencil.png"), QSize(), QIcon::Normal, QIcon::Off);
        ui->pushButton_edit_save->setIcon(icon);
        ui->toolButton_date->setEnabled(false);
        ui->pushButton_remove->setEnabled(false);
        ui->pushButton_add_label->setEnabled(false);
        ui->pushButton_delete_label->setEnabled(false);
        ui->lineEdit_name->setReadOnly(true);
        ui->dateEdit_date->setReadOnly(true);
        ui->lineEdit_path->setReadOnly(true);
        ui->textEdit_description->setReadOnly(true);
        ui->tableWidget_label->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->toolButton_date->setVisible(false);
        ui->pushButton_remove->setVisible(false);
        ui->pushButton_add_label->setVisible(false);
        ui->pushButton_delete_label->setVisible(false);
    }
}

void Manager::on_pushButton_edit_save_clicked() {
    if (mod_edited_metadata) { // 进行保存
        mod_edit_metadata(false);
        auto &i = data[projects.showing_items[last_index]];
        std::string from{i["path"].get<std::string>()}, to{ui->lineEdit_path->text().toStdString()};
        if (from != to) {
            bool result = File::move_all(from, to); // 不能出现中文的问题
            if (result)
                i["path"] = to;
            else {
                QMessageBox msgBox;
                msgBox.setWindowTitle("注意");
                msgBox.setText("项目文件夹移动未完成");
                msgBox.setInformativeText("目前暂不支持移动到该文件夹的子文件夹，以及父文件夹不同并且不存在的文件夹");
                msgBox.exec();
                ui->lineEdit_path->setText(QString::fromStdString(i["path"].get<std::string>()));
            }
        }
        i["name"] = ui->lineEdit_name->text().toStdString();
        i["date"] = ui->dateEdit_date->text().toStdString();
        i["desc"] = ui->textEdit_description->toPlainText().toStdString();
        i["label"] = labels.get_content();
        std::vector<std::string> label;
        for (const auto &j:i["label"])
            label.push_back(j.get<std::string>());
        projects.change_row(last_index, i["name"], i["date"], label);
        sort(); // 重新排序
        reload_filterWidget_page(); // 重新更新filterwidget内容
    } else { // 进行编辑
        mod_edit_metadata(true);
    }
}

void Manager::on_pushButton_open_clicked() {
    std::filesystem::path pth{ui->lineEdit_path->text().toStdString()};
    bool need_attention{false};
    if (std::filesystem::exists(pth)) {
        bool is_open = QDesktopServices::openUrl(
                QUrl(QString::fromStdString(R"(file:)" + pth.string()), QUrl::TolerantMode));
        if (!is_open)
            need_attention = true;
    } else
        need_attention = true;
    if (need_attention) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("注意");
        msgBox.setText("文件夹不存在！");
        msgBox.exec();
    }
}

void Manager::on_pushButton_add_label_clicked() {
    labels.add_item_editing(ui->tableWidget_label);
}

void Manager::on_pushButton_delete_label_clicked() {
    labels.delete_current_item(ui->tableWidget_label);
}

void Manager::on_toolButton_date_clicked() {
    calender->show();
}

void Manager::calender_set_date() {
    ui->dateEdit_date->setDate(calender->selectedDate());
    calender->close();
}

void Manager::on_pushButton_remove_clicked() {
    QString dir = QFileDialog::getExistingDirectory(this, "选择文件夹", QString::fromStdString(
            std::filesystem::path(ui->lineEdit_path->text().toStdString()).parent_path().string()));
    if (dir != "")
        ui->lineEdit_path->setText(dir.replace('/', '\\'));
}

void Manager::save_data() {
    ask_save_metadata();
    ask_save_readme();
    std::ofstream file{data_path};
    file << data;
    file_saved = true;
    ui->statusbar->showMessage(QString::fromStdString(data_path.filename().string() + " - 已保存"));
}

void Manager::ask_save_metadata() {
    if (file_opened && mod_edited_metadata) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("提示");
        msgBox.setText("您可能对项目元数据进行了改动");
        msgBox.setInformativeText("您想要保存吗？");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();
        switch (ret) {
            case QMessageBox::Save:
                // Save was clicked
                on_pushButton_edit_save_clicked();
                break;
            case QMessageBox::Discard:
                // Don't Save was clicked
                mod_edit_metadata(false);
                break;
            default:
                // should never be reached
                break;
        }
    }
}

void Manager::sort() {
    ask_save_metadata();
    if (ui->tableWidget_overview->rowCount() != 1)
        switch (ui->comboBox_sorter->currentIndex()) {
            case 0:
                projects.sort(Sorter::positiveChronologicalOrder);
                break;
            case 1:
                projects.sort(Sorter::reverseChronologicalOrder);
                break;
            case 2:
                projects.sort(Sorter::positiveNominalOrder);
                break;
            case 3:
                projects.sort(Sorter::reverseNominalOrder);
                break;
        }
    if (projects.showing_number != 0) {
        bool found_project{false};
        for (int j = 0; j != projects.showing_number; ++j)
            if (data[projects.showing_items[j]]["name"].get<std::string>() == ui->lineEdit_name->text().toStdString()) {
                ui->tableWidget_overview->setCurrentCell(j, 0);
                found_project = true;
                break;
            }
        if (!found_project)
            ui->tableWidget_overview->setCurrentCell(0, 0);
        show_current_project();
    } else {
        ui->lineEdit_name->setText("");
        ui->dateEdit_date->setDate(QDate::currentDate());
        ui->lineEdit_path->setText("");
        ui->textEdit_description->setText("");
        std::vector<std::string> label;
        labels.set_column_all(ui->tableWidget_label, {});
        set_readme_editable_mod(false);
    }
}

void Manager::mod_edit_readme(bool mod) {
    if (mod) { // 进行保存
        mod_edited_readme = true;
        ui->pushButton_readme_edit_save->setText("保存");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/Save.png"), QSize(), QIcon::Normal, QIcon::Off);
        ui->pushButton_readme_edit_save->setIcon(icon);
        ui->textEdit_readme->setReadOnly(false);
    } else { // 进行编辑
        mod_edited_readme = false;
        ui->pushButton_readme_edit_save->setText("编辑");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/Pencil.png"), QSize(), QIcon::Normal, QIcon::Off);
        ui->pushButton_readme_edit_save->setIcon(icon);
        ui->textEdit_readme->setReadOnly(true);
    }
}

void Manager::on_pushButton_readme_edit_save_clicked() {
    if (mod_edited_readme) { // 进行保存
        mod_edit_readme(false);
        // 进行保存操作
        std::ofstream file{readme_path};
        file << ui->textEdit_readme->toPlainText().toStdString();
    } else { // 进行编辑
        mod_edit_readme(true);
    }
}

void Manager::set_readme_editable_mod(bool mod) {
    if (mod) { // 可以编辑和保存
        ui->textEdit_readme->clear();
        ui->stackedWidget->setCurrentIndex(1);
        ui->pushButton_readme_new->setEnabled(false);
        ui->pushButton_readme_new->setVisible(false);
        ui->pushButton_readme_delete->setEnabled(true);
        ui->pushButton_readme_delete->setVisible(true);
        ui->pushButton_readme_edit_save->setEnabled(true);
        ui->pushButton_readme_edit_save->setVisible(true);
        ui->pushButton_external->setEnabled(true);
        ui->pushButton_external->setVisible(true);
    } else { // 恢复空页面
        ui->stackedWidget->setCurrentIndex(0);
        ui->pushButton_readme_new->setEnabled(true);
        ui->pushButton_readme_new->setVisible(true);
        ui->pushButton_readme_delete->setEnabled(false);
        ui->pushButton_readme_delete->setVisible(false);
        ui->pushButton_readme_edit_save->setEnabled(false);
        ui->pushButton_readme_edit_save->setVisible(false);
        ui->pushButton_external->setEnabled(false);
        ui->pushButton_external->setVisible(false);
        ui->comboBox_format->setCurrentIndex(0);
    }
}

void Manager::on_pushButton_readme_new_clicked() {
    ask_save_metadata();
    readme_path = File::create_file(ui->lineEdit_path->text().toStdString(), "README",
                                    ui->comboBox_format->currentText().toStdString());
    set_readme_editable_mod(true);
    mod_edit_readme(true);
}

void Manager::ask_save_readme() {
    if (file_opened && mod_edited_readme) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("提示");
        msgBox.setText("您可能对项目README进行了改动");
        msgBox.setInformativeText("您想要保存吗？");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();
        switch (ret) {
            case QMessageBox::Save:
                // Save was clicked
                on_pushButton_readme_edit_save_clicked();
                break;
            case QMessageBox::Discard:
                // Don't Save was clicked
                mod_edit_readme(false);
                break;
            default:
                // should never be reached
                break;
        }
    }
}

void Manager::on_pushButton_external_clicked() {
    ask_save_readme();
    QDesktopServices::openUrl(QUrl(QString::fromStdString(R"(file:)" + readme_path.string()), QUrl::TolerantMode));
}

void Manager::on_pushButton_readme_delete_clicked() {
    QMessageBox msgBox;
    msgBox.setWindowTitle("警告");
    msgBox.setText("您确认删除README文件吗？");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);
    int ret = msgBox.exec();
    if (ret == QMessageBox::Yes) {
        // will delete readme
        File::remove_file(readme_path);
        readme_path.clear();

        set_readme_editable_mod(false);
        if (mod_edited_readme)
            mod_edit_readme(false);
    }
}

void Manager::change_extension() {
    if (!readme_path.empty())
        readme_path = File::change_extension(readme_path, ui->comboBox_format->currentText().toStdString());
}

void Manager::closeEvent(QCloseEvent *event) {
    ask_save_metadata();
    ask_save_readme();
    ask_save_data();
}

void Manager::ask_save_data() {
    if (!file_saved && file_opened) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("提示");
        msgBox.setText("您可能对项目文件进行了改动");
        msgBox.setInformativeText("您想要保存吗？");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();
        if (ret == QMessageBox::Save)
            save_data();
    }
}

void Manager::on_pushButton_add_clicked() {
    mod_document_opened(true);
    projects.add_default_row(ui->tableWidget_overview);
    ui->dateEdit_date->setDate(QDate::currentDate());
    json new_j = {
            {"name",  ""},
            {"date",  ui->dateEdit_date->text().toStdString()},
            {"path",  ""},
            {"label", {}},
            {"desc",  ""}
    };
    data.push_back(new_j);
    ui->tableWidget_overview->setCurrentCell(ui->tableWidget_overview->rowCount() - 1, 0);
    on_pushButton_edit_save_clicked();
    ui->lineEdit_name->setFocus();
}

void Manager::on_pushButton_delete_clicked() {
    QMessageBox msgBox;
    msgBox.setWindowTitle("警告");
    msgBox.setText("您确认删除该项目的数据信息吗？");
    msgBox.setInformativeText("（该项目的实际文件不会删除）");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);
    int ret = msgBox.exec();
    if (ret == QMessageBox::No)
        return;

    if (mod_edited_metadata)
        on_pushButton_edit_save_clicked();
    ask_save_readme();
    if (file_saved) {
        file_saved = false;
        ui->statusbar->showMessage(QString::fromStdString(data_path.filename().string() + " - 未保存"));
    }
    int index = projects.delete_current_project(ui->tableWidget_overview);
    data.erase(data.begin() + index);
    reload_filterWidget_page();
    if (projects.showing_number == 0)
        mod_document_opened(false);
}

void Manager::on_toolButton_filter_clicked() {
    ask_save_metadata();
    if (projects.non_filter_mod)
        filterWidget->need_clear_all = true;
    filterWidget->move(this->geometry().center() - filterWidget->rect().center());
    filterWidget->show();
}

void Manager::reload_filterWidget_page() {
    // 需要获得全部项（包括没有显示的）
    std::set<QString> dir_names, label_names;
    for (const auto &i:data) {
        dir_names.insert(
                QString::fromStdString(std::filesystem::path(i["path"].get<std::string>()).parent_path().string()));
        for (const auto &j:i["label"])
            label_names.insert(QString::fromStdString(j.get<std::string>()));
    }
    filterWidget->reset(dir_names, label_names);
}

bool Manager::eventFilter(QObject *object, QEvent *event) {
    if (object == this && event->type() == QEvent::WindowActivate) {
        filterWidget->close();
        return true;
    }
    return QMainWindow::eventFilter(object, event);
}

void Manager::filter() {
    if (!ui->lineEdit_searcher->text().isEmpty())
        search(ui->lineEdit_searcher->text());
    else {
        projects.filter(data, ui->tableWidget_overview, filterWidget->get_filter_options());
        sort();
    }
}

void Manager::search(const QString &name) {
    projects.filter(data, ui->tableWidget_overview, filterWidget->get_filter_options());
    projects.search(ui->tableWidget_overview, name);
    sort();
}

void Manager::mod_document_opened(bool mod) {
    if (mod) {
        ui->toolButton_filter->setEnabled(true);
        ui->lineEdit_searcher->setEnabled(true);
        ui->pushButton_delete->setEnabled(true);
        ui->pushButton_edit_save->setEnabled(true);
        ui->pushButton_readme_new->setEnabled(true);
        ui->pushButton_open->setEnabled(true);
    } else {
        set_readme_editable_mod(false);
        ui->lineEdit_name->setText("");
        ui->dateEdit_date->setDate(QDate::currentDate());
        ui->lineEdit_path->setText("");
        ui->textEdit_description->setText("");
        std::vector<std::string> label;
        labels.set_column_all(ui->tableWidget_label, {});

        ui->toolButton_filter->setEnabled(false);
        ui->lineEdit_searcher->setEnabled(false);
        ui->pushButton_delete->setEnabled(false);
        ui->pushButton_edit_save->setEnabled(false);
        ui->pushButton_readme_new->setEnabled(false);
        ui->pushButton_open->setEnabled(false);
    }
}

void Manager::close_document() {
    if (file_opened) {
        ask_save_metadata();
        ask_save_readme();
        ask_save_data();

        projects.clear_all(ui->tableWidget_overview);
        data.clear();
        data_path.clear();
        mod_document_opened(false);
        ui->pushButton_add->setEnabled(false);
        file_opened = false;
    }
}

void Manager::open_document_action() {
    QString dir = !data_path.empty() ? QString::fromStdString(data_path.parent_path().string()) : ".";
    QString fileName = QFileDialog::getOpenFileName(this, "打开文件", dir, "Project Manager files (*.pm);;All files (*.*)");
    if (!fileName.isEmpty()) {
        close_document();
        open_document(fileName);
    }
}

void Manager::new_document_action() {
    QString dir = !data_path.empty() ? QString::fromStdString(data_path.parent_path().string()) : ".";
    QString fileName = QFileDialog::getSaveFileName(this, "新建文件", dir, "Project Manager files (*.pm);;All files (*.*)");
    if (!fileName.isEmpty()) {
        close_document();
        open_document(fileName);
    }
}

void Manager::show_about_action() {
    aboutWidget->move(this->geometry().center() - aboutWidget->rect().center());
    aboutWidget->show();
}

// 编写本项目得到的新的感悟：
// 我已经能够比较清晰地开发Qt程序，即图形层、逻辑层、核心功能层分开编写
// 但是在std::string和qstring上却用得比较混淆，以后应该：
// 图形层、逻辑层尽量完全使用QString（以及其它带Q的），核心功能层尽量完全用标准库的
// https://www.zhihu.com/question/22572053，鉴于某些方面Qt可能做得更好，或许以后都要带Q的（QtCore里面那些东西）
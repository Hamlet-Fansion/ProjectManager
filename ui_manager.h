/********************************************************************************
** Form generated from reading UI file 'manager.ui'
**
** Created by: Qt User Interface Compiler version 6.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Manager
{
public:
    QAction *action_new;
    QAction *action_save;
    QAction *action_exit;
    QAction *action_help;
    QAction *action_about;
    QAction *action_open;
    QAction *action_close;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_12;
    QGroupBox *groupBox_overview;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_sorter;
    QComboBox *comboBox_sorter;
    QLabel *label_filter;
    QToolButton *toolButton_filter;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tableWidget_overview;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_add;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_searcher;
    QLineEdit *lineEdit_searcher;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox_metadata;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_name;
    QLineEdit *lineEdit_name;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_date;
    QDateEdit *dateEdit_date;
    QToolButton *toolButton_date;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_path;
    QLineEdit *lineEdit_path;
    QPushButton *pushButton_open;
    QPushButton *pushButton_remove;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_description;
    QTextEdit *textEdit_description;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_delete;
    QPushButton *pushButton_edit_save;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableWidget_label;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton_add_label;
    QPushButton *pushButton_delete_label;
    QSpacerItem *horizontalSpacer_6;
    QGroupBox *groupBox_readme;
    QVBoxLayout *verticalLayout_4;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_empty;
    QSpacerItem *verticalSpacer_3;
    QWidget *page_2;
    QGridLayout *gridLayout;
    QTextEdit *textEdit_readme;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_format;
    QComboBox *comboBox_format;
    QPushButton *pushButton_readme_new;
    QPushButton *pushButton_readme_delete;
    QPushButton *pushButton_readme_edit_save;
    QPushButton *pushButton_external;
    QSpacerItem *horizontalSpacer_7;
    QMenuBar *menubar;
    QMenu *menu_start;
    QMenu *menu_help;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Manager)
    {
        if (Manager->objectName().isEmpty())
            Manager->setObjectName(QString::fromUtf8("Manager"));
        Manager->resize(934, 609);
        action_new = new QAction(Manager);
        action_new->setObjectName(QString::fromUtf8("action_new"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/New.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_new->setIcon(icon);
        action_save = new QAction(Manager);
        action_save->setObjectName(QString::fromUtf8("action_save"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/Save.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_save->setIcon(icon1);
        action_exit = new QAction(Manager);
        action_exit->setObjectName(QString::fromUtf8("action_exit"));
        action_help = new QAction(Manager);
        action_help->setObjectName(QString::fromUtf8("action_help"));
        action_about = new QAction(Manager);
        action_about->setObjectName(QString::fromUtf8("action_about"));
        action_open = new QAction(Manager);
        action_open->setObjectName(QString::fromUtf8("action_open"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/Open.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_open->setIcon(icon2);
        action_close = new QAction(Manager);
        action_close->setObjectName(QString::fromUtf8("action_close"));
        centralwidget = new QWidget(Manager);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_12 = new QHBoxLayout(centralwidget);
        horizontalLayout_12->setSpacing(13);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        groupBox_overview = new QGroupBox(centralwidget);
        groupBox_overview->setObjectName(QString::fromUtf8("groupBox_overview"));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font.setPointSize(11);
        groupBox_overview->setFont(font);
        verticalLayout = new QVBoxLayout(groupBox_overview);
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_sorter = new QLabel(groupBox_overview);
        label_sorter->setObjectName(QString::fromUtf8("label_sorter"));

        horizontalLayout->addWidget(label_sorter);

        comboBox_sorter = new QComboBox(groupBox_overview);
        comboBox_sorter->addItem(QString());
        comboBox_sorter->addItem(QString());
        comboBox_sorter->addItem(QString());
        comboBox_sorter->addItem(QString());
        comboBox_sorter->setObjectName(QString::fromUtf8("comboBox_sorter"));
        comboBox_sorter->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(comboBox_sorter);

        label_filter = new QLabel(groupBox_overview);
        label_filter->setObjectName(QString::fromUtf8("label_filter"));

        horizontalLayout->addWidget(label_filter);

        toolButton_filter = new QToolButton(groupBox_overview);
        toolButton_filter->setObjectName(QString::fromUtf8("toolButton_filter"));
        toolButton_filter->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icon/Magnifier.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_filter->setIcon(icon3);

        horizontalLayout->addWidget(toolButton_filter);

        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget_overview = new QTableWidget(groupBox_overview);
        if (tableWidget_overview->columnCount() < 3)
            tableWidget_overview->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_overview->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_overview->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_overview->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget_overview->setObjectName(QString::fromUtf8("tableWidget_overview"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget_overview->sizePolicy().hasHeightForWidth());
        tableWidget_overview->setSizePolicy(sizePolicy);
        tableWidget_overview->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        tableWidget_overview->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tableWidget_overview->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_overview->setAlternatingRowColors(true);
        tableWidget_overview->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_overview->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_overview->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableWidget_overview->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableWidget_overview->setShowGrid(false);
        tableWidget_overview->setSortingEnabled(false);
        tableWidget_overview->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget_overview->horizontalHeader()->setHighlightSections(false);
        tableWidget_overview->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_overview->horizontalHeader()->setStretchLastSection(true);
        tableWidget_overview->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableWidget_overview);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_add = new QPushButton(groupBox_overview);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));
        pushButton_add->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_add->setIcon(icon);

        horizontalLayout_2->addWidget(pushButton_add);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_searcher = new QLabel(groupBox_overview);
        label_searcher->setObjectName(QString::fromUtf8("label_searcher"));

        horizontalLayout_2->addWidget(label_searcher);

        lineEdit_searcher = new QLineEdit(groupBox_overview);
        lineEdit_searcher->setObjectName(QString::fromUtf8("lineEdit_searcher"));

        horizontalLayout_2->addWidget(lineEdit_searcher);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_12->addWidget(groupBox_overview);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        groupBox_metadata = new QGroupBox(centralwidget);
        groupBox_metadata->setObjectName(QString::fromUtf8("groupBox_metadata"));
        QFont font1;
        font1.setPointSize(11);
        groupBox_metadata->setFont(font1);
        horizontalLayout_9 = new QHBoxLayout(groupBox_metadata);
        horizontalLayout_9->setSpacing(10);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(6, 6, 6, 6);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_name = new QLabel(groupBox_metadata);
        label_name->setObjectName(QString::fromUtf8("label_name"));

        horizontalLayout_6->addWidget(label_name);

        lineEdit_name = new QLineEdit(groupBox_metadata);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setReadOnly(true);

        horizontalLayout_6->addWidget(lineEdit_name);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_date = new QLabel(groupBox_metadata);
        label_date->setObjectName(QString::fromUtf8("label_date"));

        horizontalLayout_7->addWidget(label_date);

        dateEdit_date = new QDateEdit(groupBox_metadata);
        dateEdit_date->setObjectName(QString::fromUtf8("dateEdit_date"));
        dateEdit_date->setReadOnly(true);

        horizontalLayout_7->addWidget(dateEdit_date);

        toolButton_date = new QToolButton(groupBox_metadata);
        toolButton_date->setObjectName(QString::fromUtf8("toolButton_date"));
        toolButton_date->setEnabled(false);
        toolButton_date->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icon/Calendar.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_date->setIcon(icon4);

        horizontalLayout_7->addWidget(toolButton_date);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_path = new QLabel(groupBox_metadata);
        label_path->setObjectName(QString::fromUtf8("label_path"));

        horizontalLayout_3->addWidget(label_path);

        lineEdit_path = new QLineEdit(groupBox_metadata);
        lineEdit_path->setObjectName(QString::fromUtf8("lineEdit_path"));
        lineEdit_path->setReadOnly(true);

        horizontalLayout_3->addWidget(lineEdit_path);


        horizontalLayout_5->addLayout(horizontalLayout_3);

        pushButton_open = new QPushButton(groupBox_metadata);
        pushButton_open->setObjectName(QString::fromUtf8("pushButton_open"));
        pushButton_open->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icon/Folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_open->setIcon(icon5);

        horizontalLayout_5->addWidget(pushButton_open);

        pushButton_remove = new QPushButton(groupBox_metadata);
        pushButton_remove->setObjectName(QString::fromUtf8("pushButton_remove"));
        pushButton_remove->setEnabled(false);
        pushButton_remove->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icon/Move.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_remove->setIcon(icon6);

        horizontalLayout_5->addWidget(pushButton_remove);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_description = new QLabel(groupBox_metadata);
        label_description->setObjectName(QString::fromUtf8("label_description"));

        horizontalLayout_10->addWidget(label_description);

        textEdit_description = new QTextEdit(groupBox_metadata);
        textEdit_description->setObjectName(QString::fromUtf8("textEdit_description"));
        textEdit_description->setReadOnly(true);

        horizontalLayout_10->addWidget(textEdit_description);


        verticalLayout_2->addLayout(horizontalLayout_10);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(8);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton_delete = new QPushButton(groupBox_metadata);
        pushButton_delete->setObjectName(QString::fromUtf8("pushButton_delete"));
        pushButton_delete->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icon/Delete2.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_delete->setIcon(icon7);

        horizontalLayout_4->addWidget(pushButton_delete);

        pushButton_edit_save = new QPushButton(groupBox_metadata);
        pushButton_edit_save->setObjectName(QString::fromUtf8("pushButton_edit_save"));
        pushButton_edit_save->setEnabled(true);
        pushButton_edit_save->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icon/Pencil.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_edit_save->setIcon(icon8);

        horizontalLayout_4->addWidget(pushButton_edit_save);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_4);


        horizontalLayout_9->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tableWidget_label = new QTableWidget(groupBox_metadata);
        if (tableWidget_label->columnCount() < 1)
            tableWidget_label->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_label->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        tableWidget_label->setObjectName(QString::fromUtf8("tableWidget_label"));
        tableWidget_label->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        tableWidget_label->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_label->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_label->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_label->setAlternatingRowColors(true);
        tableWidget_label->setSelectionMode(QAbstractItemView::ContiguousSelection);
        tableWidget_label->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableWidget_label->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableWidget_label->setShowGrid(true);
        tableWidget_label->setGridStyle(Qt::SolidLine);
        tableWidget_label->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget_label->horizontalHeader()->setHighlightSections(false);
        tableWidget_label->horizontalHeader()->setStretchLastSection(true);
        tableWidget_label->verticalHeader()->setVisible(false);

        verticalLayout_3->addWidget(tableWidget_label);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        pushButton_add_label = new QPushButton(groupBox_metadata);
        pushButton_add_label->setObjectName(QString::fromUtf8("pushButton_add_label"));
        pushButton_add_label->setEnabled(false);
        pushButton_add_label->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icon/Plus.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_add_label->setIcon(icon9);

        horizontalLayout_8->addWidget(pushButton_add_label);

        pushButton_delete_label = new QPushButton(groupBox_metadata);
        pushButton_delete_label->setObjectName(QString::fromUtf8("pushButton_delete_label"));
        pushButton_delete_label->setEnabled(false);
        pushButton_delete_label->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icon/Minus.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_delete_label->setIcon(icon10);

        horizontalLayout_8->addWidget(pushButton_delete_label);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);


        verticalLayout_3->addLayout(horizontalLayout_8);


        horizontalLayout_9->addLayout(verticalLayout_3);

        horizontalLayout_9->setStretch(0, 3);
        horizontalLayout_9->setStretch(1, 1);

        verticalLayout_6->addWidget(groupBox_metadata);

        groupBox_readme = new QGroupBox(centralwidget);
        groupBox_readme->setObjectName(QString::fromUtf8("groupBox_readme"));
        groupBox_readme->setFont(font1);
        verticalLayout_4 = new QVBoxLayout(groupBox_readme);
        verticalLayout_4->setSpacing(10);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(6, 6, 6, 6);
        stackedWidget = new QStackedWidget(groupBox_readme);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_5 = new QVBoxLayout(page);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 107, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);

        label_empty = new QLabel(page);
        label_empty->setObjectName(QString::fromUtf8("label_empty"));

        verticalLayout_5->addWidget(label_empty);

        verticalSpacer_3 = new QSpacerItem(20, 106, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        gridLayout = new QGridLayout(page_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(5, 5, 5, 2);
        textEdit_readme = new QTextEdit(page_2);
        textEdit_readme->setObjectName(QString::fromUtf8("textEdit_readme"));
        textEdit_readme->setReadOnly(true);

        gridLayout->addWidget(textEdit_readme, 0, 0, 1, 1);

        stackedWidget->addWidget(page_2);

        verticalLayout_4->addWidget(stackedWidget);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(5, -1, 0, -1);
        label_format = new QLabel(groupBox_readme);
        label_format->setObjectName(QString::fromUtf8("label_format"));

        horizontalLayout_11->addWidget(label_format);

        comboBox_format = new QComboBox(groupBox_readme);
        comboBox_format->addItem(QString());
        comboBox_format->addItem(QString());
        comboBox_format->setObjectName(QString::fromUtf8("comboBox_format"));
        comboBox_format->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_11->addWidget(comboBox_format);

        pushButton_readme_new = new QPushButton(groupBox_readme);
        pushButton_readme_new->setObjectName(QString::fromUtf8("pushButton_readme_new"));
        pushButton_readme_new->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_readme_new->setIcon(icon);

        horizontalLayout_11->addWidget(pushButton_readme_new);

        pushButton_readme_delete = new QPushButton(groupBox_readme);
        pushButton_readme_delete->setObjectName(QString::fromUtf8("pushButton_readme_delete"));
        pushButton_readme_delete->setEnabled(false);
        pushButton_readme_delete->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_readme_delete->setIcon(icon7);

        horizontalLayout_11->addWidget(pushButton_readme_delete);

        pushButton_readme_edit_save = new QPushButton(groupBox_readme);
        pushButton_readme_edit_save->setObjectName(QString::fromUtf8("pushButton_readme_edit_save"));
        pushButton_readme_edit_save->setEnabled(false);
        pushButton_readme_edit_save->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_readme_edit_save->setIcon(icon8);

        horizontalLayout_11->addWidget(pushButton_readme_edit_save);

        pushButton_external = new QPushButton(groupBox_readme);
        pushButton_external->setObjectName(QString::fromUtf8("pushButton_external"));
        pushButton_external->setEnabled(false);
        pushButton_external->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_external->setIcon(icon6);

        horizontalLayout_11->addWidget(pushButton_external);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_7);


        verticalLayout_4->addLayout(horizontalLayout_11);


        verticalLayout_6->addWidget(groupBox_readme);

        verticalLayout_6->setStretch(0, 1);
        verticalLayout_6->setStretch(1, 3);

        horizontalLayout_12->addLayout(verticalLayout_6);

        horizontalLayout_12->setStretch(0, 2);
        horizontalLayout_12->setStretch(1, 3);
        Manager->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Manager);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 934, 22));
        menu_start = new QMenu(menubar);
        menu_start->setObjectName(QString::fromUtf8("menu_start"));
        menu_help = new QMenu(menubar);
        menu_help->setObjectName(QString::fromUtf8("menu_help"));
        Manager->setMenuBar(menubar);
        statusbar = new QStatusBar(Manager);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Manager->setStatusBar(statusbar);

        menubar->addAction(menu_start->menuAction());
        menubar->addAction(menu_help->menuAction());
        menu_start->addAction(action_new);
        menu_start->addAction(action_open);
        menu_start->addSeparator();
        menu_start->addAction(action_save);
        menu_start->addSeparator();
        menu_start->addAction(action_close);
        menu_start->addSeparator();
        menu_start->addAction(action_exit);
        menu_help->addAction(action_help);
        menu_help->addAction(action_about);

        retranslateUi(Manager);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Manager);
    } // setupUi

    void retranslateUi(QMainWindow *Manager)
    {
        Manager->setWindowTitle(QCoreApplication::translate("Manager", "Project Manager", nullptr));
#if QT_CONFIG(tooltip)
        Manager->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        action_new->setText(QCoreApplication::translate("Manager", "\346\226\260\345\273\272", nullptr));
#if QT_CONFIG(shortcut)
        action_new->setShortcut(QCoreApplication::translate("Manager", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        action_save->setText(QCoreApplication::translate("Manager", "\344\277\235\345\255\230", nullptr));
#if QT_CONFIG(shortcut)
        action_save->setShortcut(QCoreApplication::translate("Manager", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        action_exit->setText(QCoreApplication::translate("Manager", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(shortcut)
        action_exit->setShortcut(QCoreApplication::translate("Manager", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        action_help->setText(QCoreApplication::translate("Manager", "\345\270\256\345\212\251", nullptr));
#if QT_CONFIG(shortcut)
        action_help->setShortcut(QCoreApplication::translate("Manager", "F12", nullptr));
#endif // QT_CONFIG(shortcut)
        action_about->setText(QCoreApplication::translate("Manager", "\345\205\263\344\272\216", nullptr));
        action_open->setText(QCoreApplication::translate("Manager", "\346\211\223\345\274\200", nullptr));
#if QT_CONFIG(shortcut)
        action_open->setShortcut(QCoreApplication::translate("Manager", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        action_close->setText(QCoreApplication::translate("Manager", "\345\205\263\351\227\255", nullptr));
#if QT_CONFIG(shortcut)
        action_close->setShortcut(QCoreApplication::translate("Manager", "Ctrl+F4", nullptr));
#endif // QT_CONFIG(shortcut)
        groupBox_overview->setTitle(QCoreApplication::translate("Manager", "\351\241\271\347\233\256\346\265\217\350\247\210", nullptr));
        label_sorter->setText(QCoreApplication::translate("Manager", "\346\216\222\345\272\217: ", nullptr));
        comboBox_sorter->setItemText(0, QCoreApplication::translate("Manager", "\346\214\211\346\227\266\351\227\264\346\255\243\345\272\217", nullptr));
        comboBox_sorter->setItemText(1, QCoreApplication::translate("Manager", "\346\214\211\346\227\266\351\227\264\345\200\222\345\272\217", nullptr));
        comboBox_sorter->setItemText(2, QCoreApplication::translate("Manager", "\346\214\211\345\220\215\347\247\260\346\255\243\345\272\217", nullptr));
        comboBox_sorter->setItemText(3, QCoreApplication::translate("Manager", "\346\214\211\345\220\215\347\247\260\345\200\222\345\272\217", nullptr));

        label_filter->setText(QCoreApplication::translate("Manager", "    \347\255\233\351\200\211: ", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_filter->setToolTip(QCoreApplication::translate("Manager", "\347\255\233\351\200\211\351\241\271\347\233\256", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_filter->setText(QCoreApplication::translate("Manager", "...", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_overview->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Manager", "\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_overview->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Manager", "\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_overview->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Manager", "\346\240\207\347\255\276", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_add->setToolTip(QCoreApplication::translate("Manager", "\346\267\273\345\212\240\351\241\271\347\233\256", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_add->setText(QCoreApplication::translate("Manager", "\346\267\273\345\212\240", nullptr));
        label_searcher->setText(QCoreApplication::translate("Manager", "\346\220\234\347\264\242\357\274\232", nullptr));
        lineEdit_searcher->setPlaceholderText(QCoreApplication::translate("Manager", "\351\241\271\347\233\256\345\220\215\347\247\260", nullptr));
        groupBox_metadata->setTitle(QCoreApplication::translate("Manager", "\345\205\203\346\225\260\346\215\256", nullptr));
        label_name->setText(QCoreApplication::translate("Manager", "\345\220\215\347\247\260\357\274\232", nullptr));
        lineEdit_name->setText(QString());
        lineEdit_name->setPlaceholderText(QCoreApplication::translate("Manager", "ProjectName", nullptr));
        label_date->setText(QCoreApplication::translate("Manager", "\346\227\266\351\227\264\357\274\232", nullptr));
        dateEdit_date->setDisplayFormat(QCoreApplication::translate("Manager", "yyyy/M/d", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_date->setToolTip(QCoreApplication::translate("Manager", "\346\211\223\345\274\200\346\227\245\346\234\237\351\200\211\346\213\251\346\241\206", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_date->setText(QCoreApplication::translate("Manager", "...", nullptr));
        label_path->setText(QCoreApplication::translate("Manager", "\344\275\215\347\275\256\357\274\232", nullptr));
        lineEdit_path->setPlaceholderText(QCoreApplication::translate("Manager", "Path_to_Project", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_open->setToolTip(QCoreApplication::translate("Manager", "\346\211\223\345\274\200\346\226\207\344\273\266\345\244\271", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_open->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_remove->setToolTip(QCoreApplication::translate("Manager", "\347\247\273\345\212\250\346\226\207\344\273\266\345\244\271", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_remove->setText(QString());
        label_description->setText(QCoreApplication::translate("Manager", "\346\217\217\350\277\260\357\274\232", nullptr));
        textEdit_description->setPlaceholderText(QCoreApplication::translate("Manager", "Description of project...", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_delete->setToolTip(QCoreApplication::translate("Manager", "\345\210\240\351\231\244\351\241\271\347\233\256", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_delete->setText(QCoreApplication::translate("Manager", "\345\210\240\351\231\244\351\241\271\347\233\256", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_edit_save->setToolTip(QCoreApplication::translate("Manager", "\347\274\226\350\276\221/\344\277\235\345\255\230\351\241\271\347\233\256\345\205\203\346\225\260\346\215\256", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_edit_save->setText(QCoreApplication::translate("Manager", "\347\274\226\350\276\221", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_label->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Manager", "\346\240\207\347\255\276", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_add_label->setToolTip(QCoreApplication::translate("Manager", "\346\226\260\345\273\272\346\240\207\347\255\276", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_add_label->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_delete_label->setToolTip(QCoreApplication::translate("Manager", "\345\210\240\351\231\244\346\240\207\347\255\276", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_delete_label->setText(QString());
        groupBox_readme->setTitle(QCoreApplication::translate("Manager", "README", nullptr));
        label_empty->setText(QCoreApplication::translate("Manager", "<html><head/><body><p align=\"center\">\347\251\272\346\226\207\344\273\266</p></body></html>", nullptr));
        label_format->setText(QCoreApplication::translate("Manager", "\346\226\207\344\273\266\346\240\274\345\274\217\357\274\232", nullptr));
        comboBox_format->setItemText(0, QCoreApplication::translate("Manager", ".txt", nullptr));
        comboBox_format->setItemText(1, QCoreApplication::translate("Manager", ".md", nullptr));

#if QT_CONFIG(tooltip)
        pushButton_readme_new->setToolTip(QCoreApplication::translate("Manager", "\346\226\260\345\273\272README", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_readme_new->setText(QCoreApplication::translate("Manager", "\346\226\260\345\273\272", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_readme_delete->setToolTip(QCoreApplication::translate("Manager", "\345\210\240\351\231\244README", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_readme_delete->setText(QCoreApplication::translate("Manager", "\345\210\240\351\231\244", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_readme_edit_save->setToolTip(QCoreApplication::translate("Manager", "\347\274\226\350\276\221/\344\277\235\345\255\230README", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_readme_edit_save->setText(QCoreApplication::translate("Manager", "\347\274\226\350\276\221", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_external->setToolTip(QCoreApplication::translate("Manager", "\344\275\277\347\224\250\351\273\230\350\256\244\347\274\226\350\276\221\345\231\250\346\211\223\345\274\200", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_external->setText(QString());
        menu_start->setTitle(QCoreApplication::translate("Manager", "\345\274\200\345\247\213", nullptr));
        menu_help->setTitle(QCoreApplication::translate("Manager", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Manager: public Ui_Manager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGER_H

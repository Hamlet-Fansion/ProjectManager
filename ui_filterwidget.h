/********************************************************************************
** Form generated from reading UI file 'filterwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERWIDGET_H
#define UI_FILTERWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FilterWidget
{
public:
    QVBoxLayout *verticalLayout_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_time;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBox_time;
    QDateEdit *dateEdit;
    QToolButton *toolButton;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButton_before;
    QRadioButton *radioButton_after;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_parent_dir;
    QVBoxLayout *verticalLayout_dir;
    QCheckBox *checkBox_dir;
    QGroupBox *groupBox_label;
    QVBoxLayout *verticalLayout_label;
    QCheckBox *checkBox_label;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_clear_all;
    QPushButton *pushButton_select_all;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_filter;

    void setupUi(QWidget *FilterWidget)
    {
        if (FilterWidget->objectName().isEmpty())
            FilterWidget->setObjectName(QString::fromUtf8("FilterWidget"));
        FilterWidget->resize(439, 335);
        QFont font;
        font.setPointSize(11);
        FilterWidget->setFont(font);
        verticalLayout_3 = new QVBoxLayout(FilterWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(FilterWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShadow(QFrame::Raised);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 437, 279));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        groupBox_time = new QGroupBox(scrollAreaWidgetContents);
        groupBox_time->setObjectName(QString::fromUtf8("groupBox_time"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_time);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        checkBox_time = new QCheckBox(groupBox_time);
        checkBox_time->setObjectName(QString::fromUtf8("checkBox_time"));

        horizontalLayout_2->addWidget(checkBox_time);

        dateEdit = new QDateEdit(groupBox_time);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));

        horizontalLayout_2->addWidget(dateEdit);

        toolButton = new QToolButton(groupBox_time);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/Calendar.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);

        horizontalLayout_2->addWidget(toolButton);

        label_3 = new QLabel(groupBox_time);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        label = new QLabel(groupBox_time);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        label_2 = new QLabel(groupBox_time);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        radioButton_before = new QRadioButton(groupBox_time);
        radioButton_before->setObjectName(QString::fromUtf8("radioButton_before"));

        verticalLayout_2->addWidget(radioButton_before);

        radioButton_after = new QRadioButton(groupBox_time);
        radioButton_after->setObjectName(QString::fromUtf8("radioButton_after"));

        verticalLayout_2->addWidget(radioButton_after);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(groupBox_time);

        groupBox_parent_dir = new QGroupBox(scrollAreaWidgetContents);
        groupBox_parent_dir->setObjectName(QString::fromUtf8("groupBox_parent_dir"));
        verticalLayout_dir = new QVBoxLayout(groupBox_parent_dir);
        verticalLayout_dir->setObjectName(QString::fromUtf8("verticalLayout_dir"));
        checkBox_dir = new QCheckBox(groupBox_parent_dir);
        checkBox_dir->setObjectName(QString::fromUtf8("checkBox_dir"));
        QFont font1;
        font1.setPointSize(9);
        checkBox_dir->setFont(font1);

        verticalLayout_dir->addWidget(checkBox_dir);


        verticalLayout->addWidget(groupBox_parent_dir);

        groupBox_label = new QGroupBox(scrollAreaWidgetContents);
        groupBox_label->setObjectName(QString::fromUtf8("groupBox_label"));
        verticalLayout_label = new QVBoxLayout(groupBox_label);
        verticalLayout_label->setObjectName(QString::fromUtf8("verticalLayout_label"));
        checkBox_label = new QCheckBox(groupBox_label);
        checkBox_label->setObjectName(QString::fromUtf8("checkBox_label"));
        checkBox_label->setFont(font1);

        verticalLayout_label->addWidget(checkBox_label);


        verticalLayout->addWidget(groupBox_label);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(11, 9, 11, 11);
        pushButton_clear_all = new QPushButton(FilterWidget);
        pushButton_clear_all->setObjectName(QString::fromUtf8("pushButton_clear_all"));
        pushButton_clear_all->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(pushButton_clear_all);

        pushButton_select_all = new QPushButton(FilterWidget);
        pushButton_select_all->setObjectName(QString::fromUtf8("pushButton_select_all"));
        pushButton_select_all->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(pushButton_select_all);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_filter = new QPushButton(FilterWidget);
        pushButton_filter->setObjectName(QString::fromUtf8("pushButton_filter"));
        pushButton_filter->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(pushButton_filter);


        verticalLayout_3->addLayout(horizontalLayout);


        retranslateUi(FilterWidget);

        QMetaObject::connectSlotsByName(FilterWidget);
    } // setupUi

    void retranslateUi(QWidget *FilterWidget)
    {
        FilterWidget->setWindowTitle(QCoreApplication::translate("FilterWidget", "\347\255\233\351\200\211\351\241\271\347\233\256", nullptr));
        groupBox_time->setTitle(QCoreApplication::translate("FilterWidget", "\347\255\233\351\200\211\346\227\266\351\227\264", nullptr));
        checkBox_time->setText(QString());
        toolButton->setText(QCoreApplication::translate("FilterWidget", "...", nullptr));
        label_3->setText(QString());
        label->setText(QString());
        label_2->setText(QString());
        radioButton_before->setText(QCoreApplication::translate("FilterWidget", "\346\255\244\346\227\245\346\234\237\345\217\212\344\273\245\345\211\215", nullptr));
        radioButton_after->setText(QCoreApplication::translate("FilterWidget", "\346\255\244\346\227\245\346\234\237\345\217\212\344\273\245\345\220\216", nullptr));
        groupBox_parent_dir->setTitle(QCoreApplication::translate("FilterWidget", "\347\255\233\351\200\211\347\210\266\346\226\207\344\273\266\345\244\271", nullptr));
        checkBox_dir->setText(QCoreApplication::translate("FilterWidget", "\345\205\250\351\200\211", nullptr));
        groupBox_label->setTitle(QCoreApplication::translate("FilterWidget", "\347\255\233\351\200\211\346\240\207\347\255\276", nullptr));
        checkBox_label->setText(QCoreApplication::translate("FilterWidget", "\345\205\250\351\200\211", nullptr));
        pushButton_clear_all->setText(QCoreApplication::translate("FilterWidget", "\346\270\205\347\251\272", nullptr));
        pushButton_select_all->setText(QCoreApplication::translate("FilterWidget", "\345\205\250\351\200\211", nullptr));
        pushButton_filter->setText(QCoreApplication::translate("FilterWidget", "\347\255\233\351\200\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FilterWidget: public Ui_FilterWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERWIDGET_H

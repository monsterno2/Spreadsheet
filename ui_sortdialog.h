/********************************************************************************
** Form generated from reading UI file 'sortdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SORTDIALOG_H
#define UI_SORTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_sortdialog
{
public:
    QGridLayout *gridLayout_4;
    QGroupBox *primarygroupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *primaryColumncombo;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QComboBox *primaryOrdercombo;
    QVBoxLayout *verticalLayout;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QSpacerItem *verticalSpacer;
    QPushButton *moreButton;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *secondarygroupBox;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QComboBox *secondaryColumncombo;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_4;
    QComboBox *secondaryOrdercombo;
    QGroupBox *tertiarygroupBox;
    QGridLayout *gridLayout_3;
    QLabel *label_5;
    QComboBox *tertiaryColumncombo;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_6;
    QComboBox *tertiaryOrdercombo;

    void setupUi(QDialog *sortdialog)
    {
        if (sortdialog->objectName().isEmpty())
            sortdialog->setObjectName(QString::fromUtf8("sortdialog"));
        sortdialog->resize(294, 330);
        gridLayout_4 = new QGridLayout(sortdialog);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        primarygroupBox = new QGroupBox(sortdialog);
        primarygroupBox->setObjectName(QString::fromUtf8("primarygroupBox"));
        gridLayout = new QGridLayout(primarygroupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(primarygroupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        primaryColumncombo = new QComboBox(primarygroupBox);
        primaryColumncombo->setObjectName(QString::fromUtf8("primaryColumncombo"));

        gridLayout->addWidget(primaryColumncombo, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(29, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        label_2 = new QLabel(primarygroupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        primaryOrdercombo = new QComboBox(primarygroupBox);
        primaryOrdercombo->setObjectName(QString::fromUtf8("primaryOrdercombo"));

        gridLayout->addWidget(primaryOrdercombo, 1, 1, 1, 2);


        gridLayout_4->addWidget(primarygroupBox, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        okButton = new QPushButton(sortdialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setDefault(true);

        verticalLayout->addWidget(okButton);

        cancelButton = new QPushButton(sortdialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        verticalLayout->addWidget(cancelButton);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        moreButton = new QPushButton(sortdialog);
        moreButton->setObjectName(QString::fromUtf8("moreButton"));
        moreButton->setCheckable(true);
        moreButton->setDefault(false);

        verticalLayout->addWidget(moreButton);


        gridLayout_4->addLayout(verticalLayout, 0, 1, 2, 1);

        verticalSpacer_2 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_2, 1, 0, 1, 1);

        secondarygroupBox = new QGroupBox(sortdialog);
        secondarygroupBox->setObjectName(QString::fromUtf8("secondarygroupBox"));
        gridLayout_2 = new QGridLayout(secondarygroupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_3 = new QLabel(secondarygroupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        secondaryColumncombo = new QComboBox(secondarygroupBox);
        secondaryColumncombo->setObjectName(QString::fromUtf8("secondaryColumncombo"));

        gridLayout_2->addWidget(secondaryColumncombo, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        label_4 = new QLabel(secondarygroupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        secondaryOrdercombo = new QComboBox(secondarygroupBox);
        secondaryOrdercombo->setObjectName(QString::fromUtf8("secondaryOrdercombo"));

        gridLayout_2->addWidget(secondaryOrdercombo, 1, 1, 1, 2);


        gridLayout_4->addWidget(secondarygroupBox, 2, 0, 1, 1);

        tertiarygroupBox = new QGroupBox(sortdialog);
        tertiarygroupBox->setObjectName(QString::fromUtf8("tertiarygroupBox"));
        gridLayout_3 = new QGridLayout(tertiarygroupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_5 = new QLabel(tertiarygroupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 0, 0, 1, 1);

        tertiaryColumncombo = new QComboBox(tertiarygroupBox);
        tertiaryColumncombo->setObjectName(QString::fromUtf8("tertiaryColumncombo"));

        gridLayout_3->addWidget(tertiaryColumncombo, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        label_6 = new QLabel(tertiarygroupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 1, 0, 1, 1);

        tertiaryOrdercombo = new QComboBox(tertiarygroupBox);
        tertiaryOrdercombo->setObjectName(QString::fromUtf8("tertiaryOrdercombo"));

        gridLayout_3->addWidget(tertiaryOrdercombo, 1, 1, 1, 2);


        gridLayout_4->addWidget(tertiarygroupBox, 3, 0, 1, 1);

        QWidget::setTabOrder(primaryColumncombo, primaryOrdercombo);
        QWidget::setTabOrder(primaryOrdercombo, secondaryColumncombo);
        QWidget::setTabOrder(secondaryColumncombo, secondaryOrdercombo);
        QWidget::setTabOrder(secondaryOrdercombo, tertiaryColumncombo);
        QWidget::setTabOrder(tertiaryColumncombo, tertiaryOrdercombo);
        QWidget::setTabOrder(tertiaryOrdercombo, okButton);
        QWidget::setTabOrder(okButton, cancelButton);
        QWidget::setTabOrder(cancelButton, moreButton);

        retranslateUi(sortdialog);
        QObject::connect(okButton, SIGNAL(clicked()), sortdialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), sortdialog, SLOT(reject()));
        QObject::connect(moreButton, SIGNAL(toggled(bool)), secondarygroupBox, SLOT(setVisible(bool)));
        QObject::connect(moreButton, SIGNAL(toggled(bool)), tertiarygroupBox, SLOT(setVisible(bool)));

        QMetaObject::connectSlotsByName(sortdialog);
    } // setupUi

    void retranslateUi(QDialog *sortdialog)
    {
        sortdialog->setWindowTitle(QApplication::translate("sortdialog", "Dialog", 0, QApplication::UnicodeUTF8));
        primarygroupBox->setTitle(QApplication::translate("sortdialog", "&Primary Key", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("sortdialog", "Column:", 0, QApplication::UnicodeUTF8));
        primaryColumncombo->clear();
        primaryColumncombo->insertItems(0, QStringList()
         << QApplication::translate("sortdialog", "\357\274\256one", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("sortdialog", "Order:", 0, QApplication::UnicodeUTF8));
        primaryOrdercombo->clear();
        primaryOrdercombo->insertItems(0, QStringList()
         << QApplication::translate("sortdialog", "\357\274\241scending", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("sortdialog", "Descending", 0, QApplication::UnicodeUTF8)
        );
        okButton->setText(QApplication::translate("sortdialog", "OK", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("sortdialog", "Cancel", 0, QApplication::UnicodeUTF8));
        moreButton->setText(QApplication::translate("sortdialog", "&More", 0, QApplication::UnicodeUTF8));
        secondarygroupBox->setTitle(QApplication::translate("sortdialog", "&Secondary Key", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("sortdialog", "Column:", 0, QApplication::UnicodeUTF8));
        secondaryColumncombo->clear();
        secondaryColumncombo->insertItems(0, QStringList()
         << QApplication::translate("sortdialog", "\357\274\256one", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("sortdialog", "Order:", 0, QApplication::UnicodeUTF8));
        secondaryOrdercombo->clear();
        secondaryOrdercombo->insertItems(0, QStringList()
         << QApplication::translate("sortdialog", "\357\274\241scending", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("sortdialog", "Descending", 0, QApplication::UnicodeUTF8)
        );
        tertiarygroupBox->setTitle(QApplication::translate("sortdialog", "&Tertiary Key", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("sortdialog", "Column:", 0, QApplication::UnicodeUTF8));
        tertiaryColumncombo->clear();
        tertiaryColumncombo->insertItems(0, QStringList()
         << QApplication::translate("sortdialog", "\357\274\256one", 0, QApplication::UnicodeUTF8)
        );
        label_6->setText(QApplication::translate("sortdialog", "Order:", 0, QApplication::UnicodeUTF8));
        tertiaryOrdercombo->clear();
        tertiaryOrdercombo->insertItems(0, QStringList()
         << QApplication::translate("sortdialog", "\357\274\241scending", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("sortdialog", "Descending", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class sortdialog: public Ui_sortdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SORTDIALOG_H

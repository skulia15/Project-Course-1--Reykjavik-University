/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QComboBox *Dropdown_Menu;
    QLineEdit *Input_Filter_Scientists;
    QHBoxLayout *horizontalLayout_4;
    QTableWidget *table_showAllScientists;
    QPushButton *button_add_scientist;
    QPushButton *button_delete_scientist;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(531, 417);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Dropdown_Menu = new QComboBox(centralWidget);
        Dropdown_Menu->setObjectName(QStringLiteral("Dropdown_Menu"));

        verticalLayout->addWidget(Dropdown_Menu);

        Input_Filter_Scientists = new QLineEdit(centralWidget);
        Input_Filter_Scientists->setObjectName(QStringLiteral("Input_Filter_Scientists"));

        verticalLayout->addWidget(Input_Filter_Scientists);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        table_showAllScientists = new QTableWidget(centralWidget);
        table_showAllScientists->setObjectName(QStringLiteral("table_showAllScientists"));
        table_showAllScientists->setSelectionMode(QAbstractItemView::ExtendedSelection);
        table_showAllScientists->setSelectionBehavior(QAbstractItemView::SelectRows);
        table_showAllScientists->setSortingEnabled(true);
        table_showAllScientists->horizontalHeader()->setStretchLastSection(true);

        horizontalLayout_4->addWidget(table_showAllScientists);


        verticalLayout->addLayout(horizontalLayout_4);

        button_add_scientist = new QPushButton(centralWidget);
        button_add_scientist->setObjectName(QStringLiteral("button_add_scientist"));

        verticalLayout->addWidget(button_add_scientist);

        button_delete_scientist = new QPushButton(centralWidget);
        button_delete_scientist->setObjectName(QStringLiteral("button_delete_scientist"));
        button_delete_scientist->setEnabled(false);

        verticalLayout->addWidget(button_delete_scientist);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 531, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        Dropdown_Menu->clear();
        Dropdown_Menu->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Scientists", 0)
         << QApplication::translate("MainWindow", "Computers", 0)
         << QApplication::translate("MainWindow", "Relations", 0)
        );
#ifndef QT_NO_TOOLTIP
        Dropdown_Menu->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Choose repository</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        Input_Filter_Scientists->setPlaceholderText(QApplication::translate("MainWindow", "Filter scientists..", 0));
        button_add_scientist->setText(QApplication::translate("MainWindow", "Add", 0));
        button_delete_scientist->setText(QApplication::translate("MainWindow", "Delete", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'library.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIBRARY_H
#define UI_LIBRARY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_library
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *library)
    {
        if (library->objectName().isEmpty())
            library->setObjectName(QStringLiteral("library"));
        library->resize(400, 300);
        menuBar = new QMenuBar(library);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        library->setMenuBar(menuBar);
        mainToolBar = new QToolBar(library);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        library->addToolBar(mainToolBar);
        centralWidget = new QWidget(library);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        library->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(library);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        library->setStatusBar(statusBar);

        retranslateUi(library);

        QMetaObject::connectSlotsByName(library);
    } // setupUi

    void retranslateUi(QMainWindow *library)
    {
        library->setWindowTitle(QApplication::translate("library", "library", 0));
    } // retranslateUi

};

namespace Ui {
    class library: public Ui_library {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIBRARY_H

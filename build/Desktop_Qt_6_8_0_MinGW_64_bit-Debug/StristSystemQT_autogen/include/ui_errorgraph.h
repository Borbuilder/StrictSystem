/********************************************************************************
** Form generated from reading UI file 'errorgraph.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERRORGRAPH_H
#define UI_ERRORGRAPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_ErrorGraph
{
public:
    QCustomPlot *widget;

    void setupUi(QWidget *ErrorGraph)
    {
        if (ErrorGraph->objectName().isEmpty())
            ErrorGraph->setObjectName("ErrorGraph");
        ErrorGraph->resize(601, 448);
        widget = new QCustomPlot(ErrorGraph);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 10, 581, 431));

        retranslateUi(ErrorGraph);

        QMetaObject::connectSlotsByName(ErrorGraph);
    } // setupUi

    void retranslateUi(QWidget *ErrorGraph)
    {
        ErrorGraph->setWindowTitle(QCoreApplication::translate("ErrorGraph", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ErrorGraph: public Ui_ErrorGraph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERRORGRAPH_H

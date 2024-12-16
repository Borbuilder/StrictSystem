/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLabel *label_16;
    QCheckBox *checkBox_2;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QCheckBox *checkBox;
    QPushButton *pushButton_2;
    QTableWidget *tableWidget;
    QCustomPlot *widget;
    QLabel *label_4;
    QCustomPlot *widget_2;
    QLabel *label_5;
    QPushButton *pushButton_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLabel *label_9;
    QLineEdit *lineEdit_6;
    QLabel *label_10;
    QLineEdit *lineEdit_7;
    QLabel *label_11;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QLabel *label_12;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *lineEdit_13;
    QLineEdit *lineEdit_14;
    QLineEdit *lineEdit_15;
    QLineEdit *lineEdit_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1187, 862);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(0, 0, 236, 181));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Modern No. 20")});
        font.setPointSize(12);
        font.setBold(false);
        label->setFont(font);
        label->setTextFormat(Qt::TextFormat::AutoText);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Modern No. 20")});
        font1.setPointSize(12);
        label_2->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        lineEdit_2 = new QLineEdit(formLayoutWidget);
        lineEdit_2->setObjectName("lineEdit_2");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_2);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName("label_3");
        label_3->setFont(font1);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        lineEdit_3 = new QLineEdit(formLayoutWidget);
        lineEdit_3->setObjectName("lineEdit_3");

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_3);

        label_16 = new QLabel(formLayoutWidget);
        label_16->setObjectName("label_16");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_16);

        checkBox_2 = new QCheckBox(formLayoutWidget);
        checkBox_2->setObjectName("checkBox_2");

        formLayout->setWidget(4, QFormLayout::FieldRole, checkBox_2);

        pushButton = new QPushButton(formLayoutWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setFont(font1);

        formLayout->setWidget(5, QFormLayout::FieldRole, pushButton);

        lineEdit = new QLineEdit(formLayoutWidget);
        lineEdit->setObjectName("lineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        checkBox = new QCheckBox(formLayoutWidget);
        checkBox->setObjectName("checkBox");

        formLayout->setWidget(3, QFormLayout::FieldRole, checkBox);

        pushButton_2 = new QPushButton(formLayoutWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(6, QFormLayout::SpanningRole, pushButton_2);

        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(0, 530, 1181, 281));
        widget = new QCustomPlot(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(250, 30, 461, 451));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(340, 10, 261, 20));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Modern No. 20")});
        font2.setPointSize(10);
        label_4->setFont(font2);
        widget_2 = new QCustomPlot(centralwidget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(720, 30, 461, 451));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(830, 10, 261, 20));
        label_5->setFont(font2);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(240, 490, 941, 41));
        pushButton_3->setFont(font2);
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(10, 190, 221, 341));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 219, 339));
        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(70, 0, 71, 21));
        label_7 = new QLabel(scrollAreaWidgetContents);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(0, 20, 71, 20));
        label_8 = new QLabel(scrollAreaWidgetContents);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(0, 40, 71, 20));
        lineEdit_4 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(70, 20, 131, 21));
        lineEdit_5 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(70, 40, 131, 21));
        label_9 = new QLabel(scrollAreaWidgetContents);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(0, 60, 71, 20));
        lineEdit_6 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(70, 60, 131, 21));
        label_10 = new QLabel(scrollAreaWidgetContents);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(0, 80, 71, 20));
        lineEdit_7 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(70, 80, 131, 21));
        label_11 = new QLabel(scrollAreaWidgetContents);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(0, 110, 71, 20));
        lineEdit_8 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(70, 110, 131, 21));
        lineEdit_9 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_9->setObjectName("lineEdit_9");
        lineEdit_9->setGeometry(QRect(70, 160, 131, 21));
        label_12 = new QLabel(scrollAreaWidgetContents);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(0, 160, 71, 20));
        lineEdit_10 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_10->setObjectName("lineEdit_10");
        lineEdit_10->setGeometry(QRect(70, 210, 131, 21));
        lineEdit_11 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_11->setObjectName("lineEdit_11");
        lineEdit_11->setGeometry(QRect(70, 260, 131, 21));
        lineEdit_12 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_12->setObjectName("lineEdit_12");
        lineEdit_12->setGeometry(QRect(100, 310, 101, 21));
        label_13 = new QLabel(scrollAreaWidgetContents);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(0, 210, 71, 20));
        label_14 = new QLabel(scrollAreaWidgetContents);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(0, 260, 71, 20));
        label_15 = new QLabel(scrollAreaWidgetContents);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(0, 310, 101, 20));
        lineEdit_13 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_13->setObjectName("lineEdit_13");
        lineEdit_13->setGeometry(QRect(70, 130, 131, 21));
        lineEdit_14 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_14->setObjectName("lineEdit_14");
        lineEdit_14->setGeometry(QRect(70, 180, 131, 21));
        lineEdit_15 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_15->setObjectName("lineEdit_15");
        lineEdit_15->setGeometry(QRect(70, 230, 131, 21));
        lineEdit_16 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_16->setObjectName("lineEdit_16");
        lineEdit_16->setGeometry(QRect(70, 280, 131, 21));
        label_17 = new QLabel(scrollAreaWidgetContents);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(50, 130, 16, 20));
        label_18 = new QLabel(scrollAreaWidgetContents);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(50, 180, 16, 20));
        label_19 = new QLabel(scrollAreaWidgetContents);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(50, 230, 16, 20));
        label_20 = new QLabel(scrollAreaWidgetContents);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(50, 280, 16, 20));
        scrollArea->setWidget(scrollAreaWidgetContents);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1187, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">\320\233\320\265\320\262\320\260\321\217 \320\263\321\200\320\260\320\275\320\270\321\206\320\260:</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">\320\237\321\200\320\260\320\262\320\260\321\217 \320\263\321\200\320\260\320\275\320\270\321\206\320\260:</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">\320\250\320\260\320\263</span></p></body></html>", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">\320\222\320\260\321\200\320\270\320\260\320\275\321\202 \321\200\320\265-\320\270\321\217</span></p></body></html>", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "\320\221\320\265\320\267 \320\272\320\276\320\275\321\202\321\200\320\276\320\273\321\217", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\321\201\321\202\320\270", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "\320\241 \320\272\320\276\320\275\321\202-\320\265\320\274 \321\210\320\260\320\263\320\260", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\321\210\320\270\321\202\321\214 \321\201\320\270\321\201\321\202\320\265\320\274\321\203", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">\320\223\321\200\320\260\321\204\320\270\320\272 \321\207\320\270\321\201\320\273\320\265\320\275\320\275\320\276\320\263\320\276 \321\200\320\265\321\210\320\265\320\275\320\270\321\217 (</span><span style=\" font-size:11pt; color:#aa0000;\">V1</span><span style=\" font-size:11pt;\">,</span><span style=\" font-size:11pt; color:#0000ff;\"> V2</span><span style=\" font-size:11pt;\">)</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">\320\223\321\200\320\260\321\204\320\270\320\272 \320\270\321\201\321\202\320\270\320\275\320\275\320\276\320\263\320\276 \321\200\320\265\321\210\320\265\320\275\320\270\321\217 (</span><span style=\" font-size:11pt; color:#aa0000;\">U1</span><span style=\" font-size:11pt;\">, </span><span style=\" font-size:11pt; color:#0000ff;\">U2</span><span style=\" font-size:11pt;\">)</span></p></body></html>", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\262\320\265\321\201\321\202\320\270 \320\263\321\200\320\260\321\204\320\270\320\272 \320\263\320\273\320\276\320\261\320\260\320\273\321\214\320\275\320\276\320\271 \n"
"\320\277\320\276\320\263\321\200\320\265\321\210\320\275\320\276\321\201\321\202\320\270", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">\320\241\320\277\321\200\320\260\320\262\320\272\320\260:</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; color:#000000;\">V1 \320\275\320\260\321\207 = </span></p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; color:#000000;\">V2 \320\275\320\260\321\207 = </span></p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; color:#000000;\">V1 \320\272\320\276\320\275 = </span></p></body></html>", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; color:#000000;\">V2 \320\272\320\276\320\275 = </span></p></body></html>", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; color:#000000;\">MAX |E1|:</span></p></body></html>", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; color:#000000;\">MAX |E2|:</span></p></body></html>", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; color:#000000;\">MIN |E1|:</span></p></body></html>", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; color:#000000;\">MIN |E2|:</span></p></body></html>", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">\320\222\321\201\320\265\320\263\320\276 \321\210\320\260\320\263\320\276\320\262:</span></p></body></html>", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; color:#000000;\">X:</span></p></body></html>", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; color:#000000;\">X:</span></p></body></html>", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; color:#000000;\">X:</span></p></body></html>", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; color:#000000;\">X:</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

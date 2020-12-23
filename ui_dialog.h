/********************************************************************************
** Form generated from reading ui file 'dialog.ui'
**
** Created: Mon Sep 28 13:33:38 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QDate>
#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCalendarWidget>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayoutTop;
    QCalendarWidget *calendarWidget;
    QGridLayout *gridLayoutSub;
    QPushButton *pushButtonD00;
    QPushButton *pushButtonA00;
    QPushButton *pushButtonB00;
    QPushButton *pushButtonC00;
    QSpinBox *spinBox00;
    QLineEdit *lineEdit00;
    QPushButton *pushButtonA01;
    QPushButton *pushButtonA02;
    QPushButton *pushButtonA03;
    QPushButton *pushButtonA04;
    QPushButton *pushButtonA05;
    QPushButton *pushButtonA06;
    QPushButton *pushButtonA07;
    QPushButton *pushButtonA08;
    QPushButton *pushButtonA09;
    QPushButton *pushButtonB01;
    QPushButton *pushButtonB02;
    QPushButton *pushButtonB03;
    QPushButton *pushButtonB04;
    QPushButton *pushButtonB05;
    QPushButton *pushButtonB06;
    QPushButton *pushButtonB07;
    QPushButton *pushButtonB08;
    QPushButton *pushButtonB09;
    QSpinBox *spinBox01;
    QSpinBox *spinBox02;
    QSpinBox *spinBox03;
    QSpinBox *spinBox04;
    QSpinBox *spinBox05;
    QSpinBox *spinBox06;
    QSpinBox *spinBox07;
    QSpinBox *spinBox08;
    QSpinBox *spinBox09;
    QPushButton *pushButtonC01;
    QPushButton *pushButtonC02;
    QPushButton *pushButtonC03;
    QPushButton *pushButtonC04;
    QPushButton *pushButtonC05;
    QPushButton *pushButtonC06;
    QPushButton *pushButtonC07;
    QPushButton *pushButtonC08;
    QPushButton *pushButtonC09;
    QLineEdit *lineEdit01;
    QLineEdit *lineEdit02;
    QLineEdit *lineEdit03;
    QLineEdit *lineEdit04;
    QLineEdit *lineEdit05;
    QLineEdit *lineEdit06;
    QLineEdit *lineEdit07;
    QLineEdit *lineEdit08;
    QLineEdit *lineEdit09;
    QPushButton *pushButtonD01;
    QPushButton *pushButtonD02;
    QPushButton *pushButtonD03;
    QPushButton *pushButtonD04;
    QPushButton *pushButtonD05;
    QPushButton *pushButtonD06;
    QPushButton *pushButtonD07;
    QPushButton *pushButtonD08;
    QPushButton *pushButtonD09;
    QPushButton *label00;
    QPushButton *label01;
    QPushButton *label02;
    QPushButton *label03;
    QPushButton *label04;
    QPushButton *label05;
    QPushButton *label06;
    QPushButton *label07;
    QPushButton *label08;
    QPushButton *label09;
    QLabel *label;
    QLineEdit *lineEdit;
    QVBoxLayout *verticalLayout;
    QGroupBox *importGroup;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButtonImportProj;
    QPushButton *pushButtonImportData;
    QGroupBox *exportGroup;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButtonExportComment;
    QPushButton *pushButtonExportData;
    QLineEdit *lineEditLeft;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(1172, 245);
        gridLayoutWidget = new QWidget(Dialog);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(9, 9, 1417, 259));
        gridLayoutTop = new QGridLayout(gridLayoutWidget);
        gridLayoutTop->setSpacing(6);
        gridLayoutTop->setMargin(11);
        gridLayoutTop->setObjectName(QString::fromUtf8("gridLayoutTop"));
        gridLayoutTop->setContentsMargins(0, 0, 0, 0);
        calendarWidget = new QCalendarWidget(gridLayoutWidget);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setFocusPolicy(Qt::NoFocus);
        calendarWidget->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        calendarWidget->setMinimumDate(QDate(2009, 1, 1));
        calendarWidget->setGridVisible(true);
        calendarWidget->setHorizontalHeaderFormat(QCalendarWidget::SingleLetterDayNames);
        calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        calendarWidget->setNavigationBarVisible(true);

        gridLayoutTop->addWidget(calendarWidget, 0, 0, 3, 1);

        gridLayoutSub = new QGridLayout();
        gridLayoutSub->setSpacing(2);
        gridLayoutSub->setObjectName(QString::fromUtf8("gridLayoutSub"));
        pushButtonD00 = new QPushButton(gridLayoutWidget);
        pushButtonD00->setObjectName(QString::fromUtf8("pushButtonD00"));
        pushButtonD00->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonD00, 7, 0, 1, 1);

        pushButtonA00 = new QPushButton(gridLayoutWidget);
        pushButtonA00->setObjectName(QString::fromUtf8("pushButtonA00"));
        pushButtonA00->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonA00, 2, 0, 1, 1);

        pushButtonB00 = new QPushButton(gridLayoutWidget);
        pushButtonB00->setObjectName(QString::fromUtf8("pushButtonB00"));
        pushButtonB00->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonB00, 3, 0, 1, 1);

        pushButtonC00 = new QPushButton(gridLayoutWidget);
        pushButtonC00->setObjectName(QString::fromUtf8("pushButtonC00"));
        pushButtonC00->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonC00, 5, 0, 1, 1);

        spinBox00 = new QSpinBox(gridLayoutWidget);
        spinBox00->setObjectName(QString::fromUtf8("spinBox00"));
        spinBox00->setMaximum(2400);

        gridLayoutSub->addWidget(spinBox00, 4, 0, 1, 1);

        lineEdit00 = new QLineEdit(gridLayoutWidget);
        lineEdit00->setObjectName(QString::fromUtf8("lineEdit00"));
        lineEdit00->setEnabled(false);
        lineEdit00->setFocusPolicy(Qt::NoFocus);
        lineEdit00->setAlignment(Qt::AlignCenter);
        lineEdit00->setReadOnly(true);

        gridLayoutSub->addWidget(lineEdit00, 6, 0, 1, 1);

        pushButtonA01 = new QPushButton(gridLayoutWidget);
        pushButtonA01->setObjectName(QString::fromUtf8("pushButtonA01"));
        pushButtonA01->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonA01, 2, 1, 1, 1);

        pushButtonA02 = new QPushButton(gridLayoutWidget);
        pushButtonA02->setObjectName(QString::fromUtf8("pushButtonA02"));
        pushButtonA02->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonA02, 2, 2, 1, 1);

        pushButtonA03 = new QPushButton(gridLayoutWidget);
        pushButtonA03->setObjectName(QString::fromUtf8("pushButtonA03"));
        pushButtonA03->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonA03, 2, 3, 1, 1);

        pushButtonA04 = new QPushButton(gridLayoutWidget);
        pushButtonA04->setObjectName(QString::fromUtf8("pushButtonA04"));
        pushButtonA04->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonA04, 2, 4, 1, 1);

        pushButtonA05 = new QPushButton(gridLayoutWidget);
        pushButtonA05->setObjectName(QString::fromUtf8("pushButtonA05"));
        pushButtonA05->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonA05, 2, 5, 1, 1);

        pushButtonA06 = new QPushButton(gridLayoutWidget);
        pushButtonA06->setObjectName(QString::fromUtf8("pushButtonA06"));
        pushButtonA06->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonA06, 2, 6, 1, 1);

        pushButtonA07 = new QPushButton(gridLayoutWidget);
        pushButtonA07->setObjectName(QString::fromUtf8("pushButtonA07"));
        pushButtonA07->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonA07, 2, 7, 1, 1);

        pushButtonA08 = new QPushButton(gridLayoutWidget);
        pushButtonA08->setObjectName(QString::fromUtf8("pushButtonA08"));
        pushButtonA08->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonA08, 2, 8, 1, 1);

        pushButtonA09 = new QPushButton(gridLayoutWidget);
        pushButtonA09->setObjectName(QString::fromUtf8("pushButtonA09"));
        pushButtonA09->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonA09, 2, 9, 1, 1);

        pushButtonB01 = new QPushButton(gridLayoutWidget);
        pushButtonB01->setObjectName(QString::fromUtf8("pushButtonB01"));
        pushButtonB01->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonB01, 3, 1, 1, 1);

        pushButtonB02 = new QPushButton(gridLayoutWidget);
        pushButtonB02->setObjectName(QString::fromUtf8("pushButtonB02"));
        pushButtonB02->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonB02, 3, 2, 1, 1);

        pushButtonB03 = new QPushButton(gridLayoutWidget);
        pushButtonB03->setObjectName(QString::fromUtf8("pushButtonB03"));
        pushButtonB03->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonB03, 3, 3, 1, 1);

        pushButtonB04 = new QPushButton(gridLayoutWidget);
        pushButtonB04->setObjectName(QString::fromUtf8("pushButtonB04"));
        pushButtonB04->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonB04, 3, 4, 1, 1);

        pushButtonB05 = new QPushButton(gridLayoutWidget);
        pushButtonB05->setObjectName(QString::fromUtf8("pushButtonB05"));
        pushButtonB05->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonB05, 3, 5, 1, 1);

        pushButtonB06 = new QPushButton(gridLayoutWidget);
        pushButtonB06->setObjectName(QString::fromUtf8("pushButtonB06"));
        pushButtonB06->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonB06, 3, 6, 1, 1);

        pushButtonB07 = new QPushButton(gridLayoutWidget);
        pushButtonB07->setObjectName(QString::fromUtf8("pushButtonB07"));
        pushButtonB07->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonB07, 3, 7, 1, 1);

        pushButtonB08 = new QPushButton(gridLayoutWidget);
        pushButtonB08->setObjectName(QString::fromUtf8("pushButtonB08"));
        pushButtonB08->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonB08, 3, 8, 1, 1);

        pushButtonB09 = new QPushButton(gridLayoutWidget);
        pushButtonB09->setObjectName(QString::fromUtf8("pushButtonB09"));
        pushButtonB09->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonB09, 3, 9, 1, 1);

        spinBox01 = new QSpinBox(gridLayoutWidget);
        spinBox01->setObjectName(QString::fromUtf8("spinBox01"));
        spinBox01->setMaximum(2400);

        gridLayoutSub->addWidget(spinBox01, 4, 1, 1, 1);

        spinBox02 = new QSpinBox(gridLayoutWidget);
        spinBox02->setObjectName(QString::fromUtf8("spinBox02"));
        spinBox02->setMaximum(2400);

        gridLayoutSub->addWidget(spinBox02, 4, 2, 1, 1);

        spinBox03 = new QSpinBox(gridLayoutWidget);
        spinBox03->setObjectName(QString::fromUtf8("spinBox03"));
        spinBox03->setMaximum(2400);

        gridLayoutSub->addWidget(spinBox03, 4, 3, 1, 1);

        spinBox04 = new QSpinBox(gridLayoutWidget);
        spinBox04->setObjectName(QString::fromUtf8("spinBox04"));
        spinBox04->setMaximum(2400);

        gridLayoutSub->addWidget(spinBox04, 4, 4, 1, 1);

        spinBox05 = new QSpinBox(gridLayoutWidget);
        spinBox05->setObjectName(QString::fromUtf8("spinBox05"));
        spinBox05->setMaximum(2400);

        gridLayoutSub->addWidget(spinBox05, 4, 5, 1, 1);

        spinBox06 = new QSpinBox(gridLayoutWidget);
        spinBox06->setObjectName(QString::fromUtf8("spinBox06"));
        spinBox06->setMaximum(2400);

        gridLayoutSub->addWidget(spinBox06, 4, 6, 1, 1);

        spinBox07 = new QSpinBox(gridLayoutWidget);
        spinBox07->setObjectName(QString::fromUtf8("spinBox07"));
        spinBox07->setMaximum(2400);

        gridLayoutSub->addWidget(spinBox07, 4, 7, 1, 1);

        spinBox08 = new QSpinBox(gridLayoutWidget);
        spinBox08->setObjectName(QString::fromUtf8("spinBox08"));
        spinBox08->setMaximum(2400);

        gridLayoutSub->addWidget(spinBox08, 4, 8, 1, 1);

        spinBox09 = new QSpinBox(gridLayoutWidget);
        spinBox09->setObjectName(QString::fromUtf8("spinBox09"));
        spinBox09->setMaximum(2400);

        gridLayoutSub->addWidget(spinBox09, 4, 9, 1, 1);

        pushButtonC01 = new QPushButton(gridLayoutWidget);
        pushButtonC01->setObjectName(QString::fromUtf8("pushButtonC01"));
        pushButtonC01->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonC01, 5, 1, 1, 1);

        pushButtonC02 = new QPushButton(gridLayoutWidget);
        pushButtonC02->setObjectName(QString::fromUtf8("pushButtonC02"));
        pushButtonC02->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonC02, 5, 2, 1, 1);

        pushButtonC03 = new QPushButton(gridLayoutWidget);
        pushButtonC03->setObjectName(QString::fromUtf8("pushButtonC03"));
        pushButtonC03->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonC03, 5, 3, 1, 1);

        pushButtonC04 = new QPushButton(gridLayoutWidget);
        pushButtonC04->setObjectName(QString::fromUtf8("pushButtonC04"));
        pushButtonC04->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonC04, 5, 4, 1, 1);

        pushButtonC05 = new QPushButton(gridLayoutWidget);
        pushButtonC05->setObjectName(QString::fromUtf8("pushButtonC05"));
        pushButtonC05->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonC05, 5, 5, 1, 1);

        pushButtonC06 = new QPushButton(gridLayoutWidget);
        pushButtonC06->setObjectName(QString::fromUtf8("pushButtonC06"));
        pushButtonC06->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonC06, 5, 6, 1, 1);

        pushButtonC07 = new QPushButton(gridLayoutWidget);
        pushButtonC07->setObjectName(QString::fromUtf8("pushButtonC07"));
        pushButtonC07->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonC07, 5, 7, 1, 1);

        pushButtonC08 = new QPushButton(gridLayoutWidget);
        pushButtonC08->setObjectName(QString::fromUtf8("pushButtonC08"));
        pushButtonC08->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonC08, 5, 8, 1, 1);

        pushButtonC09 = new QPushButton(gridLayoutWidget);
        pushButtonC09->setObjectName(QString::fromUtf8("pushButtonC09"));
        pushButtonC09->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonC09, 5, 9, 1, 1);

        lineEdit01 = new QLineEdit(gridLayoutWidget);
        lineEdit01->setObjectName(QString::fromUtf8("lineEdit01"));
        lineEdit01->setEnabled(false);
        lineEdit01->setFocusPolicy(Qt::NoFocus);
        lineEdit01->setAlignment(Qt::AlignCenter);
        lineEdit01->setReadOnly(true);

        gridLayoutSub->addWidget(lineEdit01, 6, 1, 1, 1);

        lineEdit02 = new QLineEdit(gridLayoutWidget);
        lineEdit02->setObjectName(QString::fromUtf8("lineEdit02"));
        lineEdit02->setEnabled(false);
        lineEdit02->setFocusPolicy(Qt::NoFocus);
        lineEdit02->setAlignment(Qt::AlignCenter);
        lineEdit02->setReadOnly(true);

        gridLayoutSub->addWidget(lineEdit02, 6, 2, 1, 1);

        lineEdit03 = new QLineEdit(gridLayoutWidget);
        lineEdit03->setObjectName(QString::fromUtf8("lineEdit03"));
        lineEdit03->setEnabled(false);
        lineEdit03->setFocusPolicy(Qt::NoFocus);
        lineEdit03->setAlignment(Qt::AlignCenter);
        lineEdit03->setReadOnly(true);

        gridLayoutSub->addWidget(lineEdit03, 6, 3, 1, 1);

        lineEdit04 = new QLineEdit(gridLayoutWidget);
        lineEdit04->setObjectName(QString::fromUtf8("lineEdit04"));
        lineEdit04->setEnabled(false);
        lineEdit04->setFocusPolicy(Qt::NoFocus);
        lineEdit04->setAlignment(Qt::AlignCenter);
        lineEdit04->setReadOnly(true);

        gridLayoutSub->addWidget(lineEdit04, 6, 4, 1, 1);

        lineEdit05 = new QLineEdit(gridLayoutWidget);
        lineEdit05->setObjectName(QString::fromUtf8("lineEdit05"));
        lineEdit05->setEnabled(false);
        lineEdit05->setFocusPolicy(Qt::NoFocus);
        lineEdit05->setAlignment(Qt::AlignCenter);
        lineEdit05->setReadOnly(true);

        gridLayoutSub->addWidget(lineEdit05, 6, 5, 1, 1);

        lineEdit06 = new QLineEdit(gridLayoutWidget);
        lineEdit06->setObjectName(QString::fromUtf8("lineEdit06"));
        lineEdit06->setEnabled(false);
        lineEdit06->setFocusPolicy(Qt::NoFocus);
        lineEdit06->setAlignment(Qt::AlignCenter);
        lineEdit06->setReadOnly(true);

        gridLayoutSub->addWidget(lineEdit06, 6, 6, 1, 1);

        lineEdit07 = new QLineEdit(gridLayoutWidget);
        lineEdit07->setObjectName(QString::fromUtf8("lineEdit07"));
        lineEdit07->setEnabled(false);
        lineEdit07->setFocusPolicy(Qt::NoFocus);
        lineEdit07->setAlignment(Qt::AlignCenter);
        lineEdit07->setReadOnly(true);

        gridLayoutSub->addWidget(lineEdit07, 6, 7, 1, 1);

        lineEdit08 = new QLineEdit(gridLayoutWidget);
        lineEdit08->setObjectName(QString::fromUtf8("lineEdit08"));
        lineEdit08->setEnabled(false);
        lineEdit08->setFocusPolicy(Qt::NoFocus);
        lineEdit08->setAlignment(Qt::AlignCenter);
        lineEdit08->setReadOnly(true);

        gridLayoutSub->addWidget(lineEdit08, 6, 8, 1, 1);

        lineEdit09 = new QLineEdit(gridLayoutWidget);
        lineEdit09->setObjectName(QString::fromUtf8("lineEdit09"));
        lineEdit09->setEnabled(false);
        lineEdit09->setFocusPolicy(Qt::NoFocus);
        lineEdit09->setAlignment(Qt::AlignCenter);
        lineEdit09->setReadOnly(true);

        gridLayoutSub->addWidget(lineEdit09, 6, 9, 1, 1);

        pushButtonD01 = new QPushButton(gridLayoutWidget);
        pushButtonD01->setObjectName(QString::fromUtf8("pushButtonD01"));
        pushButtonD01->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonD01, 7, 1, 1, 1);

        pushButtonD02 = new QPushButton(gridLayoutWidget);
        pushButtonD02->setObjectName(QString::fromUtf8("pushButtonD02"));
        pushButtonD02->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonD02, 7, 2, 1, 1);

        pushButtonD03 = new QPushButton(gridLayoutWidget);
        pushButtonD03->setObjectName(QString::fromUtf8("pushButtonD03"));
        pushButtonD03->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonD03, 7, 3, 1, 1);

        pushButtonD04 = new QPushButton(gridLayoutWidget);
        pushButtonD04->setObjectName(QString::fromUtf8("pushButtonD04"));
        pushButtonD04->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonD04, 7, 4, 1, 1);

        pushButtonD05 = new QPushButton(gridLayoutWidget);
        pushButtonD05->setObjectName(QString::fromUtf8("pushButtonD05"));
        pushButtonD05->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonD05, 7, 5, 1, 1);

        pushButtonD06 = new QPushButton(gridLayoutWidget);
        pushButtonD06->setObjectName(QString::fromUtf8("pushButtonD06"));
        pushButtonD06->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonD06, 7, 6, 1, 1);

        pushButtonD07 = new QPushButton(gridLayoutWidget);
        pushButtonD07->setObjectName(QString::fromUtf8("pushButtonD07"));
        pushButtonD07->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonD07, 7, 7, 1, 1);

        pushButtonD08 = new QPushButton(gridLayoutWidget);
        pushButtonD08->setObjectName(QString::fromUtf8("pushButtonD08"));
        pushButtonD08->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonD08, 7, 8, 1, 1);

        pushButtonD09 = new QPushButton(gridLayoutWidget);
        pushButtonD09->setObjectName(QString::fromUtf8("pushButtonD09"));
        pushButtonD09->setFocusPolicy(Qt::NoFocus);

        gridLayoutSub->addWidget(pushButtonD09, 7, 9, 1, 1);

        label00 = new QPushButton(gridLayoutWidget);
        label00->setObjectName(QString::fromUtf8("label00"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label00->sizePolicy().hasHeightForWidth());
        label00->setSizePolicy(sizePolicy);
        label00->setFocusPolicy(Qt::NoFocus);
        label00->setFlat(true);

        gridLayoutSub->addWidget(label00, 0, 0, 1, 1);

        label01 = new QPushButton(gridLayoutWidget);
        label01->setObjectName(QString::fromUtf8("label01"));
        sizePolicy.setHeightForWidth(label01->sizePolicy().hasHeightForWidth());
        label01->setSizePolicy(sizePolicy);
        label01->setFocusPolicy(Qt::NoFocus);
        label01->setFlat(true);

        gridLayoutSub->addWidget(label01, 0, 1, 1, 1);

        label02 = new QPushButton(gridLayoutWidget);
        label02->setObjectName(QString::fromUtf8("label02"));
        sizePolicy.setHeightForWidth(label02->sizePolicy().hasHeightForWidth());
        label02->setSizePolicy(sizePolicy);
        label02->setFocusPolicy(Qt::NoFocus);
        label02->setFlat(true);

        gridLayoutSub->addWidget(label02, 0, 2, 1, 1);

        label03 = new QPushButton(gridLayoutWidget);
        label03->setObjectName(QString::fromUtf8("label03"));
        sizePolicy.setHeightForWidth(label03->sizePolicy().hasHeightForWidth());
        label03->setSizePolicy(sizePolicy);
        label03->setFocusPolicy(Qt::NoFocus);
        label03->setFlat(true);

        gridLayoutSub->addWidget(label03, 0, 3, 1, 1);

        label04 = new QPushButton(gridLayoutWidget);
        label04->setObjectName(QString::fromUtf8("label04"));
        sizePolicy.setHeightForWidth(label04->sizePolicy().hasHeightForWidth());
        label04->setSizePolicy(sizePolicy);
        label04->setFocusPolicy(Qt::NoFocus);
        label04->setFlat(true);

        gridLayoutSub->addWidget(label04, 0, 4, 1, 1);

        label05 = new QPushButton(gridLayoutWidget);
        label05->setObjectName(QString::fromUtf8("label05"));
        sizePolicy.setHeightForWidth(label05->sizePolicy().hasHeightForWidth());
        label05->setSizePolicy(sizePolicy);
        label05->setFocusPolicy(Qt::NoFocus);
        label05->setFlat(true);

        gridLayoutSub->addWidget(label05, 0, 5, 1, 1);

        label06 = new QPushButton(gridLayoutWidget);
        label06->setObjectName(QString::fromUtf8("label06"));
        sizePolicy.setHeightForWidth(label06->sizePolicy().hasHeightForWidth());
        label06->setSizePolicy(sizePolicy);
        label06->setFocusPolicy(Qt::NoFocus);
        label06->setFlat(true);

        gridLayoutSub->addWidget(label06, 0, 6, 1, 1);

        label07 = new QPushButton(gridLayoutWidget);
        label07->setObjectName(QString::fromUtf8("label07"));
        sizePolicy.setHeightForWidth(label07->sizePolicy().hasHeightForWidth());
        label07->setSizePolicy(sizePolicy);
        label07->setFocusPolicy(Qt::NoFocus);
        label07->setFlat(true);

        gridLayoutSub->addWidget(label07, 0, 7, 1, 1);

        label08 = new QPushButton(gridLayoutWidget);
        label08->setObjectName(QString::fromUtf8("label08"));
        sizePolicy.setHeightForWidth(label08->sizePolicy().hasHeightForWidth());
        label08->setSizePolicy(sizePolicy);
        label08->setFocusPolicy(Qt::NoFocus);
        label08->setFlat(true);

        gridLayoutSub->addWidget(label08, 0, 8, 1, 1);

        label09 = new QPushButton(gridLayoutWidget);
        label09->setObjectName(QString::fromUtf8("label09"));
        sizePolicy.setHeightForWidth(label09->sizePolicy().hasHeightForWidth());
        label09->setSizePolicy(sizePolicy);
        label09->setFocusPolicy(Qt::NoFocus);
        label09->setFlat(true);

        gridLayoutSub->addWidget(label09, 0, 9, 1, 1);


        gridLayoutTop->addLayout(gridLayoutSub, 0, 3, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFocusPolicy(Qt::NoFocus);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayoutTop->addWidget(label, 1, 1, 1, 1);

        lineEdit = new QLineEdit(gridLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        lineEdit->setFocusPolicy(Qt::StrongFocus);

        gridLayoutTop->addWidget(lineEdit, 1, 3, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        importGroup = new QGroupBox(gridLayoutWidget);
        importGroup->setObjectName(QString::fromUtf8("importGroup"));
        verticalLayout_2 = new QVBoxLayout(importGroup);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setMargin(2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pushButtonImportProj = new QPushButton(importGroup);
        pushButtonImportProj->setObjectName(QString::fromUtf8("pushButtonImportProj"));
        pushButtonImportProj->setFocusPolicy(Qt::NoFocus);

        verticalLayout_2->addWidget(pushButtonImportProj);

        pushButtonImportData = new QPushButton(importGroup);
        pushButtonImportData->setObjectName(QString::fromUtf8("pushButtonImportData"));
        pushButtonImportData->setFocusPolicy(Qt::NoFocus);

        verticalLayout_2->addWidget(pushButtonImportData);


        verticalLayout->addWidget(importGroup);

        exportGroup = new QGroupBox(gridLayoutWidget);
        exportGroup->setObjectName(QString::fromUtf8("exportGroup"));
        verticalLayout_3 = new QVBoxLayout(exportGroup);
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setMargin(2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        pushButtonExportComment = new QPushButton(exportGroup);
        pushButtonExportComment->setObjectName(QString::fromUtf8("pushButtonExportComment"));
        pushButtonExportComment->setFocusPolicy(Qt::NoFocus);

        verticalLayout_3->addWidget(pushButtonExportComment);

        pushButtonExportData = new QPushButton(exportGroup);
        pushButtonExportData->setObjectName(QString::fromUtf8("pushButtonExportData"));
        sizePolicy.setHeightForWidth(pushButtonExportData->sizePolicy().hasHeightForWidth());
        pushButtonExportData->setSizePolicy(sizePolicy);
        pushButtonExportData->setFocusPolicy(Qt::NoFocus);

        verticalLayout_3->addWidget(pushButtonExportData);


        verticalLayout->addWidget(exportGroup);

        lineEditLeft = new QLineEdit(gridLayoutWidget);
        lineEditLeft->setObjectName(QString::fromUtf8("lineEditLeft"));
        lineEditLeft->setEnabled(false);
        lineEditLeft->setFocusPolicy(Qt::NoFocus);
        lineEditLeft->setAlignment(Qt::AlignCenter);
        lineEditLeft->setReadOnly(true);

        verticalLayout->addWidget(lineEditLeft);


        gridLayoutTop->addLayout(verticalLayout, 0, 1, 1, 1);

        QWidget::setTabOrder(lineEdit, spinBox00);
        QWidget::setTabOrder(spinBox00, spinBox01);
        QWidget::setTabOrder(spinBox01, spinBox02);
        QWidget::setTabOrder(spinBox02, spinBox03);
        QWidget::setTabOrder(spinBox03, spinBox04);
        QWidget::setTabOrder(spinBox04, spinBox05);
        QWidget::setTabOrder(spinBox05, spinBox06);
        QWidget::setTabOrder(spinBox06, spinBox07);
        QWidget::setTabOrder(spinBox07, spinBox08);
        QWidget::setTabOrder(spinBox08, spinBox09);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "QT-Gyomu10", 0, QApplication::UnicodeUTF8));
        pushButtonD00->setText(QApplication::translate("Dialog", "+%", 0, QApplication::UnicodeUTF8));
        pushButtonA00->setText(QApplication::translate("Dialog", "+100", 0, QApplication::UnicodeUTF8));
        pushButtonB00->setText(QApplication::translate("Dialog", "+15", 0, QApplication::UnicodeUTF8));
        pushButtonC00->setText(QApplication::translate("Dialog", "+Left", 0, QApplication::UnicodeUTF8));
        pushButtonA01->setText(QApplication::translate("Dialog", "+100", 0, QApplication::UnicodeUTF8));
        pushButtonA02->setText(QApplication::translate("Dialog", "+100", 0, QApplication::UnicodeUTF8));
        pushButtonA03->setText(QApplication::translate("Dialog", "+100", 0, QApplication::UnicodeUTF8));
        pushButtonA04->setText(QApplication::translate("Dialog", "+100", 0, QApplication::UnicodeUTF8));
        pushButtonA05->setText(QApplication::translate("Dialog", "+100", 0, QApplication::UnicodeUTF8));
        pushButtonA06->setText(QApplication::translate("Dialog", "+100", 0, QApplication::UnicodeUTF8));
        pushButtonA07->setText(QApplication::translate("Dialog", "+100", 0, QApplication::UnicodeUTF8));
        pushButtonA08->setText(QApplication::translate("Dialog", "+100", 0, QApplication::UnicodeUTF8));
        pushButtonA09->setText(QApplication::translate("Dialog", "+100", 0, QApplication::UnicodeUTF8));
        pushButtonB01->setText(QApplication::translate("Dialog", "+15", 0, QApplication::UnicodeUTF8));
        pushButtonB02->setText(QApplication::translate("Dialog", "+15", 0, QApplication::UnicodeUTF8));
        pushButtonB03->setText(QApplication::translate("Dialog", "+15", 0, QApplication::UnicodeUTF8));
        pushButtonB04->setText(QApplication::translate("Dialog", "+15", 0, QApplication::UnicodeUTF8));
        pushButtonB05->setText(QApplication::translate("Dialog", "+15", 0, QApplication::UnicodeUTF8));
        pushButtonB06->setText(QApplication::translate("Dialog", "+15", 0, QApplication::UnicodeUTF8));
        pushButtonB07->setText(QApplication::translate("Dialog", "+15", 0, QApplication::UnicodeUTF8));
        pushButtonB08->setText(QApplication::translate("Dialog", "+15", 0, QApplication::UnicodeUTF8));
        pushButtonB09->setText(QApplication::translate("Dialog", "+15", 0, QApplication::UnicodeUTF8));
        pushButtonC01->setText(QApplication::translate("Dialog", "+Left", 0, QApplication::UnicodeUTF8));
        pushButtonC02->setText(QApplication::translate("Dialog", "+Left", 0, QApplication::UnicodeUTF8));
        pushButtonC03->setText(QApplication::translate("Dialog", "+Left", 0, QApplication::UnicodeUTF8));
        pushButtonC04->setText(QApplication::translate("Dialog", "+Left", 0, QApplication::UnicodeUTF8));
        pushButtonC05->setText(QApplication::translate("Dialog", "+Left", 0, QApplication::UnicodeUTF8));
        pushButtonC06->setText(QApplication::translate("Dialog", "+Left", 0, QApplication::UnicodeUTF8));
        pushButtonC07->setText(QApplication::translate("Dialog", "+Left", 0, QApplication::UnicodeUTF8));
        pushButtonC08->setText(QApplication::translate("Dialog", "+Left", 0, QApplication::UnicodeUTF8));
        pushButtonC09->setText(QApplication::translate("Dialog", "+Left", 0, QApplication::UnicodeUTF8));
        pushButtonD01->setText(QApplication::translate("Dialog", "+%", 0, QApplication::UnicodeUTF8));
        pushButtonD02->setText(QApplication::translate("Dialog", "+%", 0, QApplication::UnicodeUTF8));
        pushButtonD03->setText(QApplication::translate("Dialog", "+%", 0, QApplication::UnicodeUTF8));
        pushButtonD04->setText(QApplication::translate("Dialog", "+%", 0, QApplication::UnicodeUTF8));
        pushButtonD05->setText(QApplication::translate("Dialog", "+%", 0, QApplication::UnicodeUTF8));
        pushButtonD06->setText(QApplication::translate("Dialog", "+%", 0, QApplication::UnicodeUTF8));
        pushButtonD07->setText(QApplication::translate("Dialog", "+%", 0, QApplication::UnicodeUTF8));
        pushButtonD08->setText(QApplication::translate("Dialog", "+%", 0, QApplication::UnicodeUTF8));
        pushButtonD09->setText(QApplication::translate("Dialog", "+%", 0, QApplication::UnicodeUTF8));
        label00->setText(QApplication::translate("Dialog", "proj#", 0, QApplication::UnicodeUTF8));
        label01->setText(QApplication::translate("Dialog", "proj#", 0, QApplication::UnicodeUTF8));
        label02->setText(QApplication::translate("Dialog", "proj#", 0, QApplication::UnicodeUTF8));
        label03->setText(QApplication::translate("Dialog", "proj#", 0, QApplication::UnicodeUTF8));
        label04->setText(QApplication::translate("Dialog", "proj#", 0, QApplication::UnicodeUTF8));
        label05->setText(QApplication::translate("Dialog", "proj#", 0, QApplication::UnicodeUTF8));
        label06->setText(QApplication::translate("Dialog", "proj#", 0, QApplication::UnicodeUTF8));
        label07->setText(QApplication::translate("Dialog", "proj#", 0, QApplication::UnicodeUTF8));
        label08->setText(QApplication::translate("Dialog", "proj#", 0, QApplication::UnicodeUTF8));
        label09->setText(QApplication::translate("Dialog", "proj#", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "Comment:", 0, QApplication::UnicodeUTF8));
        importGroup->setTitle(QApplication::translate("Dialog", "Import", 0, QApplication::UnicodeUTF8));
        pushButtonImportProj->setText(QApplication::translate("Dialog", "Project", 0, QApplication::UnicodeUTF8));
        pushButtonImportData->setText(QApplication::translate("Dialog", "Datasheet", 0, QApplication::UnicodeUTF8));
        exportGroup->setTitle(QApplication::translate("Dialog", "Export", 0, QApplication::UnicodeUTF8));
        pushButtonExportComment->setText(QApplication::translate("Dialog", "Comment", 0, QApplication::UnicodeUTF8));
        pushButtonExportData->setText(QApplication::translate("Dialog", "Datasheet", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Dialog);
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H

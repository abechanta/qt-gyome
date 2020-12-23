#include <QClipboard>
#include <QDate>
#include <QDebug>
#include <QEvent>
#include <QFont>
#include <QKeyEvent>
#include <QMap>
#include <QMessageBox>
#include <QObject>
#include <QResizeEvent>
#include <QTextCharFormat>
#include <QSettings>
#include <QVector>
#include <QWheelEvent>
#include "dialog.h"
#include "editdialog.h"
#include "gyomu.h"
#include "minute.h"
#include "popdialog.h"
#include "ui_dialog.h"

#if 0	// TODO
・mingw32 のリンク
・LGPL 対応
#endif

#define CONNECT_MACRO(ix)\
	uiLabel.push_back(ui->label ## ix);\
	connect(ui->label ## ix, SIGNAL(clicked()), this, SLOT(editLabel ## ix()));\
	uiPushButtonA.push_back(ui->pushButtonA ## ix);\
	connect(ui->pushButtonA ## ix, SIGNAL(clicked()), this, SLOT(addDayDataLarge ## ix()));\
	uiPushButtonB.push_back(ui->pushButtonB ## ix);\
	connect(ui->pushButtonB ## ix, SIGNAL(clicked()), this, SLOT(addDayData ## ix()));\
	uiPushButtonC.push_back(ui->pushButtonC ## ix);\
	connect(ui->pushButtonC ## ix, SIGNAL(clicked()), this, SLOT(addDayDataLeft ## ix()));\
	uiSpinBox.push_back(ui->spinBox ## ix);\
	connect(ui->spinBox ## ix, SIGNAL(valueChanged(const int &)), this, SLOT(checkDayData ## ix(const int &)));\
	uiLineEdit.push_back(ui->lineEdit ## ix);\
	uiPushButtonD.push_back(ui->pushButtonD ## ix);\
	connect(ui->pushButtonD ## ix, SIGNAL(clicked()), this, SLOT(addDayWeight ## ix()))

const char *Dialog::programVer = "0.02";

Dialog::Dialog(QWidget *parent)
	: QDialog(parent), ui(new Ui::Dialog), popDialog(new PopDialog(parent)), editDialog(new EditDialog(parent)), bKeyShift(false), bKeyAlt(false), gyomu(new Gyomu)
{
    ui->setupUi(this);
	loadWindowSettings();

//	ui->calendarWidget->setFocusProxy(this);		// for test
//	ui->calendarWidget->installEventFilter(this);	// for test

	connect(ui->pushButtonImportProj, SIGNAL(clicked()), this, SLOT(execProjDialog()));
	connect(ui->pushButtonImportData, SIGNAL(clicked()), this, SLOT(execDataDialog()));
	connect(ui->pushButtonExportComment, SIGNAL(clicked()), this, SLOT(copyComment()));
	connect(ui->pushButtonExportData, SIGNAL(clicked()), this, SLOT(copyData()));
	connect(ui->lineEdit, SIGNAL(textEdited(QString)), this, SLOT(setDayComment_slot()));
	connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(accept()));
	connect(ui->calendarWidget, SIGNAL(selectionChanged()), this, SLOT(setCurrentDate_slot()));
	connect(ui->calendarWidget, SIGNAL(currentPageChanged(int,int)), this, SLOT(setCurrentDate_slot()));
	CONNECT_MACRO(00);
	CONNECT_MACRO(01);
	CONNECT_MACRO(02);
	CONNECT_MACRO(03);
	CONNECT_MACRO(04);
	CONNECT_MACRO(05);
	CONNECT_MACRO(06);
	CONNECT_MACRO(07);
	CONNECT_MACRO(08);
	CONNECT_MACRO(09);

	QDate date = QDate::currentDate();
	QString text;
	if (!gyomu->loadProj()) {
		text.append(tr("<b>'Project List' loading failed.</b><br />"));
		text.append(tr("Please import project list by clicking 'Import/Project', first.<br />"));
		text.append(tr("<br />"));
	}
	if (!gyomu->loadData(date)) {
		text.append(tr("<b>'Gyomu Datasheet' loading failed.</b><br />"));
		text.append(tr("You can import gyomu datasheet by clicking 'Import/Datasheet' in order to specify projects you concern.<br />"));
		text.append(tr("<br />"));
	}
	gyomu->setCurrentDate(date);
	date.setYMD(date.year(), date.month(), date.daysInMonth());
	ui->calendarWidget->setMaximumDate(date);
	setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);
	updateUi(true);
	if (!text.isEmpty()) {
		QMessageBox::information(this, tr("QT-Gyomu"), text);
	}
}

Dialog::~Dialog()
{
	gyomu->saveData(gyomu->getCurrentDate());
	gyomu->saveProj();

//	ui->calendarWidget->removeEventFilter(this);	// for test
	saveWindowSettings();
    delete ui;
}

//
// User Interface
//

void Dialog::loadWindowSettings()
{
	QSettings settings("Sega.Local", "QT-Gyomu");
	restoreGeometry(settings.value("geometry").toByteArray());
}

void Dialog::saveWindowSettings()
{
	QSettings settings("Sega.Local", "QT-Gyomu");
	settings.setValue("geometry", saveGeometry());
}

void Dialog::resizeEvent(QResizeEvent *event)
{
	QRect rect = ui->gridLayoutWidget->geometry();
	rect.setWidth(event->size().width() - 19);
	rect.setHeight(event->size().height() - 19);
	ui->gridLayoutWidget->setGeometry(rect);
}

void Dialog::keyPressEvent(QKeyEvent *event)
{
	qDebug() << __FUNCTION__ << event;
	switch (event->key()) {
	case Qt::Key_Up:
#if 1	// この記述では Ctrl+Up をうまく検出できない、、、
//		qDebug() << __FUNCTION__ << "Key_Up";
//		if (!bKeyAlt) {
//			return;
//		}
#endif
		{
			QDate currentDate = gyomu->getCurrentDate();
			QDate tmpDate = currentDate.addDays(-1);
			if (currentDate.month() == tmpDate.month()) {
//				gyomu->setDayComment(ui->lineEdit->text());
				gyomu->setCurrentDate(tmpDate);
				updateUi(false);
				ui->calendarWidget->setSelectedDate(gyomu->getCurrentDate());
			}
		}
		break;

	case Qt::Key_Down:
#if 1	// この記述では Ctrl+Down をうまく検出できない、、、
//		qDebug() << __FUNCTION__ << "Key_Down";
//		if (!bKeyAlt) {
//			return;
//		}
#endif
		{
			QDate currentDate = gyomu->getCurrentDate();
			QDate tmpDate = currentDate.addDays(1);
			if (currentDate.month() == tmpDate.month()) {
//				gyomu->setDayComment(ui->lineEdit->text());
				gyomu->setCurrentDate(tmpDate);
				updateUi(false);
				ui->calendarWidget->setSelectedDate(gyomu->getCurrentDate());
			}
		}
		break;

	case Qt::Key_PageUp:
		{
			setDayComment();
			QDate newDate = gyomu->getCurrentDate().addMonths(-1);
			ui->calendarWidget->setSelectedDate(newDate);
			//updateUi();	// invoked by SLOT(currentPageChanged)
		}
		break;

	case Qt::Key_PageDown:
		{
			setDayComment();
			QDate newDate = gyomu->getCurrentDate().addMonths(1);
			ui->calendarWidget->setSelectedDate(newDate);
			//updateUi();	// invoked by SLOT(currentPageChanged)
		}
		break;

	case Qt::Key_Shift:
		{
			bKeyShift = true;
			updateButton(bKeyShift);
		}
		break;

	case Qt::Key_Alt:
		{
			bKeyAlt = true;
			updateUi(false);
		}
		break;

	default:
		QDialog::keyPressEvent(event);
		return;
	}
}

void Dialog::keyReleaseEvent(QKeyEvent *event)
{
	switch (event->key()) {
	case Qt::Key_Shift:
		{
			bKeyShift = false;
			updateButton(bKeyShift);
		}
		break;

	case Qt::Key_Alt:
		{
			bKeyAlt = false;
			updateUi(false);
		}
		break;

	default:
		QDialog::keyReleaseEvent(event);
		return;
	}
}

void Dialog::wheelEvent(QWheelEvent *event)
{
	qDebug() << __FUNCTION__;
	int numDegrees = event->delta() / 8;
	int numSteps = numDegrees / 15;
	QDate currentDate = gyomu->getCurrentDate();
	QDate tmpDate;
	if (numSteps < 0) {
		tmpDate = currentDate.addDays(1);
	} else if (numSteps > 0) {
		tmpDate = currentDate.addDays(-1);
	} else {
		return;
	}
	if (currentDate.month() != tmpDate.month()) {
		return;
	}

//	gyomu->setDayComment(ui->lineEdit->text());
	gyomu->setCurrentDate(tmpDate);
	updateUi(false);
	ui->calendarWidget->setSelectedDate(gyomu->getCurrentDate());
}

bool Dialog::eventFilter(QObject *object, QEvent *event)
{
	qDebug() << __FUNCTION__ << event;
	if (object == ui->calendarWidget) {
		qDebug() << "hit!!!";
		if (
			(event->type() == QEvent::Wheel) ||
			(event->type() == QEvent::LayoutRequest)
		) {
			qDebug() << "HIT!!!";
			event->ignore();
			return true;
		}
	}
	return false;
}

void Dialog::updateUi(bool bPageChanged)
{
	//
	// window title
	//
	setWindowTitle(QString(tr("QT-Gyomu10 ver.%1 (p.%2/2)")).arg(programVer).arg(bKeyAlt ? '2' : '1'));

	//
	// calendar
	//
	QTextCharFormat comp;
	comp.setFontWeight(QFont::Black);
	comp.setFontItalic(true);
	QTextCharFormat normal;
	comp.setFontWeight(QFont::Normal);

	if (bPageChanged) {
		QDate currentDate = gyomu->getCurrentDate();

		QDate date;
		date.setYMD(gyomu->getCurrentDate().year(), gyomu->getCurrentDate().month(), 1);
		for (int ii = 1; ii <= gyomu->getCurrentDate().daysInMonth(); ii++) {
			gyomu->setCurrentDate(date);
			ui->calendarWidget->setDateTextFormat(date, (gyomu->getDayTotalData() != 0) || (gyomu->getDayTotalWeight() != 0) ? comp : normal);
			date = date.addDays(1);
		}

		gyomu->setCurrentDate(currentDate);

	} else {
		ui->calendarWidget->setDateTextFormat(gyomu->getCurrentDate(), (gyomu->getDayTotalData() != 0) || (gyomu->getDayTotalWeight() != 0) ? comp : normal);

	}

	//
	// project string
	//
	for (int ii = 0; ii < 10; ii++) {
		QStringList proj = gyomu->getProjSelected(getBias() + ii);
		QString label;
		label.append((proj.count() > 0) && !proj[0].isEmpty() ? proj[0] : QString("proj#"));
		if (proj.count() > 3) {
			label.append("\n").append(proj[3]);
		}
		uiLabel[ii]->setText(label);
	}

	//
	// leftover
	//
	ui->lineEditLeft->setText(
		QString(tr("%1/%2")).arg(gyomu->getDayLeftData()).arg(gyomu->getDayInputData())
	);

	//
	// spinbox / lineedit
	//
	for (int ii = 0; ii < 10; ii++) {
		uiSpinBox[ii]->setValue(gyomu->getDayData(getBias() + ii));
		uiLineEdit[ii]->setText(
			QString(tr("%1/%2(%3%)")).arg(gyomu->getDayWeight(getBias() + ii)).arg(gyomu->getDayTotalWeight()).arg(gyomu->getDayPercent(getBias() + ii))
		);
	}

	//
	// comment
	//
	ui->lineEdit->setText(gyomu->getDayComment());

	ui->calendarWidget->update();
}

void Dialog::updateButton(bool bShift)
{
	QString textA(bShift ? tr("-100") : tr("+100"));
	for (int ii = 0; ii < 10; ii++) {
		uiPushButtonA[ii]->setText(textA);
	}

	QString textB(bShift ? tr("-15") : tr("+15"));
	for (int ii = 0; ii < 10; ii++) {
		uiPushButtonB[ii]->setText(textB);
	}

	QString textD(bShift ? tr("-%") : tr("+%"));
	for (int ii = 0; ii < 10; ii++) {
		uiPushButtonD[ii]->setText(textD);
	}
}

//
// Public Slots
//

void Dialog::accept()
{
	setDayComment();
	QDialog::accept();
}

void Dialog::execProjDialog()
{
	QString text;
	text.append(tr("<br />How to use:<br />"));
	text.append(tr("1) On Microsoft Excel, open your 'gyomu.xls' file, and select 'proj#' sheet.<br />"));
	text.append(tr("2) On Microsoft Excel, select all cells and Ctrl-C in order to copy-all into clipboard.<br />"));
	text.append(tr("3) On this dialog, type Ctrl-V in order to paste from clipboard.<br />"));
	popDialog->show(tr("QT-Gyomu: Import Project List"), text);

	if (popDialog->exec() == QDialog::Accepted) {
		QString text = popDialog->getText();
		if (gyomu->importProj(text)) {
			popDialog->clearText();
			updateUi(false);
		}
	}
}

void Dialog::execDataDialog()
{
	QString text;
	text.append(tr("<br />How to use:<br />"));
	text.append(tr("1) On Microsoft Excel, open your 'gyomu.xls' file which has been imported from POSITIVE system, and select 'gyomu' sheet.<br />"));
	text.append(tr("2) On Microsoft Excel, select all cells and Ctrl-C in order to copy-all into clipboard.<br />"));
	text.append(tr("3) On this dialog, type Ctrl-V in order to paste from clipboard.<br />"));
	popDialog->show(tr("QT-Gyomu: Import Datasheet"), text);

	if (popDialog->exec() == QDialog::Accepted) {
		QString text = popDialog->getText();
		QDate date;
#if 0
		bool bLoaded = false;
		gyomu->getDateFromText(text, date);
		if (
			(gyomu->getCurrentDate().year() != date.year()) ||
			(gyomu->getCurrentDate().month() != date.month())
		) {
			bLoaded = setCurrentPage(date);
			ui->calendarWidget->setSelectedDate(date);
		}
#else
		gyomu->getDateFromText(text, date);
		bool bLoaded = setCurrentPage(date);
		ui->calendarWidget->setSelectedDate(date);
#endif
		if (gyomu->importData(text, !bLoaded)) {
			popDialog->clearText();
			updateUi(true);
		}
	}
}

void Dialog::copyComment()
{
	QClipboard *clipboard = QApplication::clipboard();
	clipboard->setText(gyomu->exportComment());

	QString text;
	text.append(tr("<b>'Comment List' copied into clipboard.</b><br />"));
	text.append(tr("1) On Microsoft Excel, open your 'gyomu.xls' file, and select 'gyomu' sheet.<br />"));
	text.append(tr("2) On Microsoft Excel, type Ctrl-V at 'C8' cell in order to paste from clipboard.<br />"));
	QMessageBox::information(this, tr("QT-Gyomu: Export Comment"), text);
}

void Dialog::copyData()
{
	QClipboard *clipboard = QApplication::clipboard();
	QVector<int> miss;
	clipboard->setText(gyomu->exportData(miss));

	QString text;
	text.append(tr("<b>'Filled Datasheet' copied into clipboard.</b><br />"));
	text.append(tr("1) On Microsoft Excel, open your 'gyomu.xls' file, and select 'gyomu' sheet.<br />"));
	text.append(tr("2) On Microsoft Excel, type Ctrl-V at 'X7' cell in order to paste from clipboard.<br />"));
	text.append(tr("<br />"));
	if (!miss.isEmpty()) {
		text.append(tr("<b>Information</b><br />"));
		text.append(tr("Some minutes have left on day(s) below:<br />"));
		QVector<int>::const_iterator ptr;
		for (ptr = miss.begin(); ptr != miss.end(); ++ptr) {
			text.append(QString(tr("%1 ")).arg(*ptr));
		}
	}
	QMessageBox::information(this, tr("QT-Gyomu: Export Filled Datasheet"), text);
}

void Dialog::editLabel(int pj)
{
	QStringList currentProj = gyomu->getProjSelected(getBias() + pj);
	QStringList projCode = gyomu->getProjColumn(0);
	QStringList projComment = gyomu->getProjColumn(3);
	editDialog->show(currentProj[0], projCode, projComment);

	if (editDialog->exec() == QDialog::Accepted) {
		QString text = editDialog->getText();
		gyomu->setProjSelected(getBias() + pj, text);
		updateUi(false);
	}
}

//
// Data Access
//

bool Dialog::setCurrentPage(const QDate &date)
{
	gyomu->saveData(gyomu->getCurrentDate());
	gyomu->setCurrentDate(date);
	bool bLoaded = gyomu->loadData(gyomu->getCurrentDate());
	if (!bLoaded) {
#if 1
//		QString text;
//		text.append(tr("<b>'Gyomu Datasheet' loading failed.</b><br />"));
//		text.append(tr("Use same list as 'Selected Project List' of previous page, instead.<br />"));
//		text.append(tr("<br />"));
//		QMessageBox::information(this, tr("QT-Gyomu"), text);
#endif
	}

	if (gyomu->isRestorableProjSelected()) {
		//
		// automatically import projSelected from previous page
		//
		QString text;
		text.append(tr("<b>'Selected Project List' is empty.</b><br />"));
		text.append(tr("Will you use the same list of previous page, instead?<br />"));
		text.append(tr("<br />"));
		QMessageBox::StandardButton button = QMessageBox::information(this, tr("QT-Gyomu"), text, QMessageBox::Ok, QMessageBox::Cancel);
		if (button == QMessageBox::Ok) {
			gyomu->restoreProjSelected();
		}
	}
	return bLoaded;
}

void Dialog::setCurrentDate()
{
	QDate selectedDate = ui->calendarWidget->selectedDate();
	QDate shownDate = QDate(ui->calendarWidget->yearShown(), ui->calendarWidget->monthShown(), 1);
	qDebug() << __FUNCTION__ << "shownDate=" << shownDate << "selectedDate=" << selectedDate << "currentDate=" << gyomu->getCurrentDate();
	if (
		(gyomu->getCurrentDate().year() != shownDate.year()) ||
		(gyomu->getCurrentDate().month() != shownDate.month())
	) {
		setCurrentPage(shownDate);
		ui->calendarWidget->setSelectedDate(shownDate);
		updateUi(true);
	} else if (
		(gyomu->getCurrentDate().year() != selectedDate.year()) ||
		(gyomu->getCurrentDate().month() != selectedDate.month())
	) {
		setCurrentPage(selectedDate);
		updateUi(true);
	} else {
		gyomu->setCurrentDate(selectedDate);
		updateUi(false);
	}
}

void Dialog::setDayComment()
{
	qDebug() << __FUNCTION__;
	gyomu->setDayComment(ui->lineEdit->text());
}

void Dialog::addDayData(int pj, int dataDelta)
{
	gyomu->addDayData(getBias() + pj, dataDelta);
	uiSpinBox[pj]->setValue(gyomu->getDayData(getBias() + pj));
	updateUi(false);
}

void Dialog::checkDayData(int pj, int value)
{
	int data = Minute(value, value - gyomu->getDayData(getBias() + pj)).value();
	gyomu->setDayData(getBias() + pj, data);
	uiSpinBox[pj]->setValue(gyomu->getDayData(getBias() + pj));
	updateUi(false);
}

void Dialog::addDayWeight(int pj, int valueDelta)
{
	gyomu->addDayWeight(getBias() + pj, valueDelta);
	uiLineEdit[pj]->setText(
		QString(tr("%1/%2(%3%)")).arg(gyomu->getDayWeight(getBias() + pj)).arg(gyomu->getDayTotalWeight()).arg(gyomu->getDayPercent(getBias() + pj))
	);
	updateUi(false);
}

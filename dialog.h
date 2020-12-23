#ifndef DIALOG_H
#define DIALOG_H

#include <QtGui/QDialog>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QDate>
#include <QEvent>
#include <QKeyEvent>
#include <QMap>
#include <QObject>
#include <QResizeEvent>
#include <QSize>
#include <QVector>
#include <QWheelEvent>
#include "gyomu.h"
#include "editdialog.h"
#include "popdialog.h"

namespace Ui
{
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
	static const char *programVer;

public slots:
	virtual void accept();
	void execProjDialog();
	void execDataDialog();
	void copyComment();
	void copyData();
	void editLabel(int pj);
	void setCurrentDate_slot() { setCurrentDate(); }
	void setDayComment_slot() { setDayComment(); }
	void editLabel00() { editLabel(0); }
	void editLabel01() { editLabel(1); }
	void editLabel02() { editLabel(2); }
	void editLabel03() { editLabel(3); }
	void editLabel04() { editLabel(4); }
	void editLabel05() { editLabel(5); }
	void editLabel06() { editLabel(6); }
	void editLabel07() { editLabel(7); }
	void editLabel08() { editLabel(8); }
	void editLabel09() { editLabel(9); }
	void addDayData00() { addDayData(0, getSign() * 15); }
	void addDayData01() { addDayData(1, getSign() * 15); }
	void addDayData02() { addDayData(2, getSign() * 15); }
	void addDayData03() { addDayData(3, getSign() * 15); }
	void addDayData04() { addDayData(4, getSign() * 15); }
	void addDayData05() { addDayData(5, getSign() * 15); }
	void addDayData06() { addDayData(6, getSign() * 15); }
	void addDayData07() { addDayData(7, getSign() * 15); }
	void addDayData08() { addDayData(8, getSign() * 15); }
	void addDayData09() { addDayData(9, getSign() * 15); }
	void addDayDataLarge00() { addDayData(0, getSign() * 100); }
	void addDayDataLarge01() { addDayData(1, getSign() * 100); }
	void addDayDataLarge02() { addDayData(2, getSign() * 100); }
	void addDayDataLarge03() { addDayData(3, getSign() * 100); }
	void addDayDataLarge04() { addDayData(4, getSign() * 100); }
	void addDayDataLarge05() { addDayData(5, getSign() * 100); }
	void addDayDataLarge06() { addDayData(6, getSign() * 100); }
	void addDayDataLarge07() { addDayData(7, getSign() * 100); }
	void addDayDataLarge08() { addDayData(8, getSign() * 100); }
	void addDayDataLarge09() { addDayData(9, getSign() * 100); }
	void addDayDataLeft00() { addDayData(0, gyomu->getDayLeftData()); }
	void addDayDataLeft01() { addDayData(1, gyomu->getDayLeftData()); }
	void addDayDataLeft02() { addDayData(2, gyomu->getDayLeftData()); }
	void addDayDataLeft03() { addDayData(3, gyomu->getDayLeftData()); }
	void addDayDataLeft04() { addDayData(4, gyomu->getDayLeftData()); }
	void addDayDataLeft05() { addDayData(5, gyomu->getDayLeftData()); }
	void addDayDataLeft06() { addDayData(6, gyomu->getDayLeftData()); }
	void addDayDataLeft07() { addDayData(7, gyomu->getDayLeftData()); }
	void addDayDataLeft08() { addDayData(8, gyomu->getDayLeftData()); }
	void addDayDataLeft09() { addDayData(9, gyomu->getDayLeftData()); }
	void addDayWeight00() { addDayWeight(0, getSign() * 1); }
	void addDayWeight01() { addDayWeight(1, getSign() * 1); }
	void addDayWeight02() { addDayWeight(2, getSign() * 1); }
	void addDayWeight03() { addDayWeight(3, getSign() * 1); }
	void addDayWeight04() { addDayWeight(4, getSign() * 1); }
	void addDayWeight05() { addDayWeight(5, getSign() * 1); }
	void addDayWeight06() { addDayWeight(6, getSign() * 1); }
	void addDayWeight07() { addDayWeight(7, getSign() * 1); }
	void addDayWeight08() { addDayWeight(8, getSign() * 1); }
	void addDayWeight09() { addDayWeight(9, getSign() * 1); }
	void checkDayData00(int value) { checkDayData(0, value); }
	void checkDayData01(int value) { checkDayData(1, value); }
	void checkDayData02(int value) { checkDayData(2, value); }
	void checkDayData03(int value) { checkDayData(3, value); }
	void checkDayData04(int value) { checkDayData(4, value); }
	void checkDayData05(int value) { checkDayData(5, value); }
	void checkDayData06(int value) { checkDayData(6, value); }
	void checkDayData07(int value) { checkDayData(7, value); }
	void checkDayData08(int value) { checkDayData(8, value); }
	void checkDayData09(int value) { checkDayData(9, value); }

private:
	//
	// User Interface
	//
	Ui::Dialog	*ui;
	PopDialog	*popDialog;
	EditDialog	*editDialog;
	QVector<QPushButton *>	uiLabel;
	QVector<QPushButton *>	uiPushButtonA;
	QVector<QPushButton *>	uiPushButtonB;
	QVector<QPushButton *>	uiPushButtonC;
	QVector<QSpinBox *>		uiSpinBox;
	QVector<QPushButton *>	uiPushButtonD;
	QVector<QLineEdit *>	uiLineEdit;
	bool		bKeyShift;
	bool		bKeyAlt;

	//
	// User Interface
	//
	void loadWindowSettings();
	void saveWindowSettings();
	virtual void resizeEvent(QResizeEvent *event);
	virtual void keyPressEvent(QKeyEvent *event);
	virtual void keyReleaseEvent(QKeyEvent *event);
	virtual void wheelEvent(QWheelEvent *event);
	virtual bool eventFilter(QObject *object, QEvent *event);
	void updateUi(bool bPageChanged);
	void updateButton(bool bShift);
	int getSign() { return bKeyShift ? -1 : +1; }
	int getBias() { return bKeyAlt ? 10 : 0; }

	//
	// Data Access
	//
	Gyomu		*gyomu;

	bool setCurrentPage(const QDate &date);
	void setCurrentDate();
	void setDayComment();
	void addDayData(int pj, int dataDelta);
	void checkDayData(int pj, int value);
	void addDayWeight(int pj, int valueDelta);
};

#endif // DIALOG_H

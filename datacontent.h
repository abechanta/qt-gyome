#ifndef DATACONTENT_H
#define DATACONTENT_H

#include <QDate>
#include <QString>
#include <QVector>
#include "daycontent.h"

class DataContent
{
public:
    DataContent();
	bool load(const QDate &date);
	bool save(const QDate &date);
	void clear(const QDate &date);
	bool getDateFromText(const QString &text, QDate &date);
	bool import(const QString &text, bool bOverwrite);

	bool isEmptyProjSelected();
	bool isRestorableProjSelected();
	void restoreProjSelected();
	QString getProjSelected(int pj);
	bool setProjSelected(int pj, const QString &text);

	QString getDayComment(int day);
	bool setDayComment(int day, const QString &text);
	int getDayLeftMinute(int day);
	int getDayInputMinute(int day);
	int getDayTotalMinute(int day);
	int getDayTotalWeight(int day);
	int getDayMinute(int day, int pj);
	bool setDayMinute(int day, int pj, int value);
	int getDayWeight(int day, int pj);
	bool setDayWeight(int day, int pj, int value);
	int getDayPercent(int day, int pj);
	int getDayMinuteByWeight(int day, int pj);

	static int minuteFromData(int value);
	static int dataFromMinute(int value);

private:
	QVector<QString>	projSelected;
	QVector<QString>	projBackup;
	QVector<DayContent>	dataContent;

	static const char	*defaultVer;
	static QString getDataName(const QDate &date);
};

#endif // DATACONTENT_H

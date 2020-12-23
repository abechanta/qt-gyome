#ifndef GYOMU_H
#define GYOMU_H

#include <QDate>
#include <QString>
#include <QStringList>
#include "datacontent.h"
#include "projcontent.h"

class Gyomu
{
public:
	Gyomu();
	~Gyomu();

	bool loadProj();
	bool saveProj();
	bool importProj(const QString &text);

	bool loadData(const QDate &date);
	bool saveData(const QDate &date);
	bool isRestorableProjSelected();
	void restoreProjSelected();
	bool getDateFromText(const QString &text, QDate &date);
	bool importData(const QString &text, bool bOverwrite);
	QString exportComment();
	QString exportData(QVector<int> &miss);

	int getProjCount();
	QStringList getProjColumn(int column);
	QStringList getProjSelected(int pj);
	bool setProjSelected(int pj, const QString &text);

	QString getDayComment();
	bool setDayComment(const QString &text);
	int getDayLeftData();
	int getDayInputData();
	int getDayTotalData();
	int getDayTotalWeight();
	int getDayData(int pj);
	bool setDayData(int pj, int data);
	int addDayData(int pj, int dataDelta);
	int getDayWeight(int pj);
	bool setDayWeight(int pj, int value);
	int addDayWeight(int pj, int valueDelta);
	int getDayPercent(int pj);
	int getDayDataByWeight(int pj);

	const QDate &getCurrentDate() const;
	bool setCurrentDate(const QDate &date);

private:
	ProjContent	*projContent;
	DataContent	*dataContent;
	QDate		currentDate;
};

#endif // GYOMU_H

#include <QDate>
#include <QDebug>
#include <QString>
#include "gyomu.h"

Gyomu::Gyomu()
	: projContent(new ProjContent), dataContent(new DataContent), currentDate(QDate().currentDate())
{
}

Gyomu::~Gyomu()
{
	delete dataContent;
	delete projContent;
}

bool Gyomu::loadProj()
{
	return projContent->load();
}

bool Gyomu::saveProj()
{
	return projContent->save();
}

bool Gyomu::importProj(const QString &text)
{
	return projContent->import(text);
}

bool Gyomu::loadData(const QDate &date)
{
	if (!dataContent->load(date)) {
		dataContent->clear(date);
		currentDate = date;
		return false;
	}
	return true;
}

bool Gyomu::saveData(const QDate &date)
{
	return dataContent->save(date);
}

bool Gyomu::isRestorableProjSelected()
{
	return dataContent->isRestorableProjSelected();
}

void Gyomu::restoreProjSelected()
{
	dataContent->restoreProjSelected();
}

bool Gyomu::getDateFromText(const QString &text, QDate &date)
{
	return dataContent->getDateFromText(text, date);
}

bool Gyomu::importData(const QString &text, bool bOverwrite)
{
	return dataContent->import(text, bOverwrite);
}

QString Gyomu::exportComment()
{
	QString text;
	for (int ii = 1; ii <= currentDate.daysInMonth(); ii++) {
		text.append(QString("%1\n").arg(dataContent->getDayComment(ii)));
	}
	return text;
}

QString Gyomu::exportData(QVector<int> &miss)
{
	miss.clear();
	QString text;

	for (int pj = 0; pj < 40; pj++) {
		if (pj != 0) {
			text.append('\t');
		}
		text.append(dataContent->getProjSelected(pj));
	}
	text.append("\n");

	for (int ii = 1; ii <= currentDate.daysInMonth(); ii++) {
		int minuteTotal = 0;

		for (int pj = 0; pj < 40; pj++) {
			if (pj != 0) {
				text.append('\t');
			}
			int minute = dataContent->getDayMinute(ii, pj) + dataContent->getDayMinuteByWeight(ii, pj);
			minuteTotal += minute;
			if (minute > 0) {
				text.append(QString("%1").arg(DataContent::dataFromMinute(minute)));
			}
		}
		text.append("\n");

		if (dataContent->getDayInputMinute(ii) != minuteTotal) {
			miss.push_back(ii);
		}
	}
	return text;
}

int Gyomu::getProjCount()
{
	return projContent->getProjCount();
}

QStringList Gyomu::getProjColumn(int column)
{
	return projContent->getProjColumn(column);
}

QStringList Gyomu::getProjSelected(int pj)
{
	return projContent->getProj(dataContent->getProjSelected(pj));
}

bool Gyomu::setProjSelected(int pj, const QString &text)
{
	return dataContent->setProjSelected(pj, text);
}

QString	Gyomu::getDayComment()
{
	return dataContent->getDayComment(currentDate.day());
}

bool Gyomu::setDayComment(const QString &text)
{
	return dataContent->setDayComment(currentDate.day(), text);
}

int Gyomu::getDayLeftData()
{
	return DataContent::dataFromMinute(dataContent->getDayLeftMinute(currentDate.day()));
}

int Gyomu::getDayInputData()
{
	return DataContent::dataFromMinute(dataContent->getDayInputMinute(currentDate.day()));
}

int Gyomu::getDayTotalData()
{
	return DataContent::dataFromMinute(dataContent->getDayTotalMinute(currentDate.day()));
}

int Gyomu::getDayTotalWeight()
{
	return dataContent->getDayTotalWeight(currentDate.day());
}

int Gyomu::getDayData(int pj)
{
	return DataContent::dataFromMinute(dataContent->getDayMinute(currentDate.day(), pj));
}

bool Gyomu::setDayData(int pj, int data)
{
	return dataContent->setDayMinute(currentDate.day(), pj, DataContent::minuteFromData(data));
}

int Gyomu::addDayData(int pj, int dataDelta)
{
	int minute = dataContent->getDayMinute(currentDate.day(), pj);
	minute += DataContent::minuteFromData(dataDelta);
	if (minute < 0) {
		minute = 0;
	}
	return dataContent->setDayMinute(currentDate.day(), pj, minute);
}

int Gyomu::getDayWeight(int pj)
{
	return dataContent->getDayWeight(currentDate.day(), pj);
}

bool Gyomu::setDayWeight(int pj, int value)
{
	return dataContent->setDayWeight(currentDate.day(), pj, value);
}

int Gyomu::addDayWeight(int pj, int valueDelta)
{
	int value = dataContent->getDayWeight(currentDate.day(), pj);
	value += valueDelta;
	if (value < 0) {
		value = 0;
	}
	return dataContent->setDayWeight(currentDate.day(), pj, value);
}

int Gyomu::getDayPercent(int pj)
{
	return dataContent->getDayPercent(currentDate.day(), pj);
}

int Gyomu::getDayDataByWeight(int pj)
{
	return DataContent::dataFromMinute(dataContent->getDayMinuteByWeight(currentDate.day(), pj));
}

const QDate &Gyomu::getCurrentDate() const
{
	return currentDate;
}

bool Gyomu::setCurrentDate(const QDate &date)
{
	if (
		(currentDate.year() != date.year()) ||
		(currentDate.month() != date.month())
	) {
		qDebug() << __FILE__ << ":" << "page changed.";
	}

	currentDate = date;
	return true;
}

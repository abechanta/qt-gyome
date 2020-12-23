#include <QDataStream>
#include <QDate>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QRegExp>
#include <QString>
#include <QStringList>
#include "datacontent.h"

const int TOP_DATE			= ('A' - 'A');
const int WEIGHT_DAY		= ('A' - 'A');
const int WEIGHT_COMMENT	= ('C' - 'A');
const int WEIGHT_TOTAL		= ('G' - 'A');
const int WEIGHT_LEFT		= ('X' - 6 - 'A');
const char	*DataContent::defaultVer = "2009/5/13";

DataContent::DataContent()
{
}

bool DataContent::load(const QDate &date)
{
	QFile data(getDataName(date));
	if (!data.open(QIODevice::ReadOnly)) {
		qDebug() << __FILE__ << ":" << "open failed.";
		return false;
	}

	QDataStream in(&data);
	in.setVersion(QDataStream::Qt_4_5);

	QString readVer;
	in >> readVer;
	if (readVer.compare(QString(defaultVer)) != 0) {
		qDebug() << __FILE__ << ":" << "load format mismatch.";
		return false;
	}

	projBackup = projSelected;
	in >> projSelected >> dataContent;
	if (projSelected.isEmpty() || dataContent.isEmpty()) {
		qDebug() << __FILE__ << ":" << "load failed.";
		return false;
	}

	qDebug() << __FILE__ << ":" << "load succeeded.";
#if 0
	qDebug() << "projSelected=" << projSelected;
	if (dataContent.count() >= 3) {
		qDebug() << "dataContent[1]="
				<< "comment" << dataContent[1].comment
				<< "inputMinute" << dataContent[1].inputMinute
				<< "totalMinute" << dataContent[1].totalMinute
				<< "totalWeight" << dataContent[1].totalWeight
				<< "minute" << dataContent[1].minute.size() << dataContent[1].minute
				<< "weight" << dataContent[1].weight.size() << dataContent[1].weight
				<< "percent" << dataContent[1].percent.size() << dataContent[1].percent
				<< "minuteByWeight" << dataContent[1].minuteByWeight.size() << dataContent[1].minuteByWeight;
		qDebug() << "dataContent[2]="
				<< "comment" << dataContent[2].comment
				<< "inputMinute" << dataContent[2].inputMinute
				<< "totalMinute" << dataContent[2].totalMinute
				<< "totalWeight" << dataContent[2].totalWeight
				<< "minute" << dataContent[2].minute.size() << dataContent[2].minute
				<< "weight" << dataContent[2].weight.size() << dataContent[2].weight
				<< "percent" << dataContent[2].percent.size() << dataContent[2].percent
				<< "minuteByWeight" << dataContent[2].minuteByWeight.size() << dataContent[2].minuteByWeight;
		qDebug() << "dataContent[3]="
				<< "comment" << dataContent[3].comment
				<< "inputMinute" << dataContent[3].inputMinute
				<< "totalMinute" << dataContent[3].totalMinute
				<< "totalWeight" << dataContent[3].totalWeight
				<< "minute" << dataContent[3].minute.size() << dataContent[3].minute
				<< "weight" << dataContent[3].weight.size() << dataContent[3].weight
				<< "percent" << dataContent[3].percent.size() << dataContent[3].percent
				<< "minuteByWeight" << dataContent[3].minuteByWeight.size() << dataContent[3].minuteByWeight;
	}
#endif

	//
	// make backup
	//
	data.copy(getDataName(date).append('~'));

	return true;
}

bool DataContent::save(const QDate &date)
{
	QFile data(getDataName(date));
	if (!data.open(QIODevice::WriteOnly)) {
		qDebug() << __FILE__ << ":" << "open failed.";
		return false;
	}

	QDataStream out(&data);
	out.setVersion(QDataStream::Qt_4_5);
	out << QString(defaultVer) << projSelected << dataContent;

	qDebug() << __FILE__ << ":" << "save succeeded.";
#if 0
	qDebug() << "projSelected=" << projSelected;
	if (dataContent.count() >= 3) {
		qDebug() << "dataContent[1]="
				<< "comment" << dataContent[1].comment
				<< "inputMinute" << dataContent[1].inputMinute
				<< "totalMinute" << dataContent[1].totalMinute
				<< "totalWeight" << dataContent[1].totalWeight
				<< "minute" << dataContent[1].minute.size() << dataContent[1].minute
				<< "weight" << dataContent[1].weight.size() << dataContent[1].weight
				<< "percent" << dataContent[1].percent.size() << dataContent[1].percent
				<< "minuteByWeight" << dataContent[1].minuteByWeight.size() << dataContent[1].minuteByWeight;
		qDebug() << "dataContent[2]="
				<< "comment" << dataContent[2].comment
				<< "inputMinute" << dataContent[2].inputMinute
				<< "totalMinute" << dataContent[2].totalMinute
				<< "totalWeight" << dataContent[2].totalWeight
				<< "minute" << dataContent[2].minute.size() << dataContent[2].minute
				<< "weight" << dataContent[2].weight.size() << dataContent[2].weight
				<< "percent" << dataContent[2].percent.size() << dataContent[2].percent
				<< "minuteByWeight" << dataContent[2].minuteByWeight.size() << dataContent[2].minuteByWeight;
		qDebug() << "dataContent[3]="
				<< "comment" << dataContent[3].comment
				<< "inputMinute" << dataContent[3].inputMinute
				<< "totalMinute" << dataContent[3].totalMinute
				<< "totalWeight" << dataContent[3].totalWeight
				<< "minute" << dataContent[3].minute.size() << dataContent[3].minute
				<< "weight" << dataContent[3].weight.size() << dataContent[3].weight
				<< "percent" << dataContent[3].percent.size() << dataContent[3].percent
				<< "minuteByWeight" << dataContent[3].minuteByWeight.size() << dataContent[3].minuteByWeight;
	}
#endif
	return true;
}

void DataContent::clear(const QDate &date)
{
	projSelected.clear();
	dataContent.clear();
	dataContent.resize(date.daysInMonth() + 1);
}

bool DataContent::getDateFromText(const QString &text, QDate &date)
{
	QStringList content = text.split('\n');
	QStringList::const_iterator line = content.begin();

	if (content.count() <= 1) {
		qDebug() << __FILE__ << ":" << "no input presented.";
		date.currentDate();
		return false;
	}

	//
	// get currentDate
	//
	int year, month;
	QStringList word = line->split('\t');
	word[TOP_DATE].remove(QRegExp("[^0-9]"));
	year = word[TOP_DATE].left(4).toInt();
	month = word[TOP_DATE].mid(4).toInt();

	date.setDate(year, month, 1);
	return true;
}

bool DataContent::import(const QString &text, bool bOverwrite)
{
	if (bOverwrite) {
		projSelected.clear();
		dataContent.clear();
	}

	QStringList content = text.split('\n');
	QStringList::const_iterator line = content.begin();

	if (content.count() <= 1) {
		qDebug() << __FILE__ << ":" << "no input presented.";
		return false;
	}

	//
	// skip lines to find top of the weights
	//
	for (; line != content.end(); ++line) {
		QStringList word = line->split('\t');
		if ((word.count() > WEIGHT_DAY) && (word[WEIGHT_DAY].compare("1") == 0)) {
			break;
		}
	}
	if (line == content.end()) {
		qDebug() << __FILE__ << ":" << "invalid input presented.";
		return false;
	}

	//
	// get project# from prev-line
	//
	if (bOverwrite) {
		if (line == content.begin()) {
			qDebug() << __FILE__ << ":" << "invalid input presented.";
			return false;
		}

		QStringList word = line[-1].split('\t');
		if (word.count() > WEIGHT_LEFT) {
			QStringList::const_iterator ptr;
			for (ptr = word.begin() + WEIGHT_LEFT; ptr != word.end(); ++ptr) {
				if (ptr->compare(QString("proj#")) == 0) {
					break;
				}
				projSelected.push_back(*ptr);
			}
		}
	}

	//
	// get dataContent
	//
	for (; line != content.end(); ++line) {
		QStringList word = line->split('\t');
		if (word[0].isEmpty()) {
			// found bottom of the minutes
			break;
		}
		if (word.count() <= WEIGHT_LEFT) {
			qDebug() << __FILE__ << ":" << "invalid line presented." << word;
			continue;
		}

		int day = word[WEIGHT_DAY].toInt();
		if (dataContent.size() <= day) {
			dataContent.resize(day + 1);
		}

		DayContent dc;
		if (!bOverwrite) {
			dc = dataContent[day];
		}

		dc.inputMinute = minuteFromData(word[WEIGHT_TOTAL].toInt());
		if (bOverwrite) {
			dc.comment = word[WEIGHT_COMMENT];
			dc.totalMinute = 0;
			dc.totalWeight = 0;
			dc.minute.clear();
			dc.weight.clear();
			dc.percent.clear();
			dc.minuteByWeight.clear();
			QStringList::const_iterator ptr;
			for (ptr = word.begin() + WEIGHT_LEFT; ptr != word.end(); ++ptr) {
				dc.minute.push_back(minuteFromData(ptr->toInt()));
				dc.weight.push_back(0);
			}
		}
		dc.adjust();

		dataContent[day] = dc;
	}

	qDebug() << __FILE__ << ":" << QString("valid input presented: %1 day(s) converted.").arg(dataContent.size() - 1);
#if 0
	qDebug() << "projSelected=" << projSelected;
	if (dataContent.count() >= 3) {
		qDebug() << "dataContent[1]="
				<< "comment" << dataContent[1].comment
				<< "inputMinute" << dataContent[1].inputMinute
				<< "totalMinute" << dataContent[1].totalMinute
				<< "totalWeight" << dataContent[1].totalWeight
				<< "minute" << dataContent[1].minute.size() << dataContent[1].minute
				<< "weight" << dataContent[1].weight.size() << dataContent[1].weight
				<< "percent" << dataContent[1].percent.size() << dataContent[1].percent
				<< "minuteByWeight" << dataContent[1].minuteByWeight.size() << dataContent[1].minuteByWeight;
		qDebug() << "dataContent[2]="
				<< "comment" << dataContent[2].comment
				<< "inputMinute" << dataContent[2].inputMinute
				<< "totalMinute" << dataContent[2].totalMinute
				<< "totalWeight" << dataContent[2].totalWeight
				<< "minute" << dataContent[2].minute.size() << dataContent[2].minute
				<< "weight" << dataContent[2].weight.size() << dataContent[2].weight
				<< "percent" << dataContent[2].percent.size() << dataContent[2].percent
				<< "minuteByWeight" << dataContent[2].minuteByWeight.size() << dataContent[2].minuteByWeight;
		qDebug() << "dataContent[3]="
				<< "comment" << dataContent[3].comment
				<< "inputMinute" << dataContent[3].inputMinute
				<< "totalMinute" << dataContent[3].totalMinute
				<< "totalWeight" << dataContent[3].totalWeight
				<< "minute" << dataContent[3].minute.size() << dataContent[3].minute
				<< "weight" << dataContent[3].weight.size() << dataContent[3].weight
				<< "percent" << dataContent[3].percent.size() << dataContent[3].percent
				<< "minuteByWeight" << dataContent[3].minuteByWeight.size() << dataContent[3].minuteByWeight;
	}
#endif
	return true;
}

bool DataContent::isEmptyProjSelected()
{
	for (QVector<QString>::const_iterator ptr = projSelected.begin(); ptr != projSelected.end(); ++ptr) {
		if (!ptr->isEmpty()) {
			return false;
		}
	}
	return true;
}

bool DataContent::isRestorableProjSelected()
{
	if (!isEmptyProjSelected()) {
		return false;
	}
	for (QVector<QString>::const_iterator ptr = projBackup.begin(); ptr != projBackup.end(); ++ptr) {
		if (!ptr->isEmpty()) {
			return true;
		}
	}
	return false;
}

void DataContent::restoreProjSelected()
{
	projSelected = projBackup;
}

QString DataContent::getProjSelected(int pj)
{
	if (projSelected.size() <= pj) {
		projSelected.resize(pj + 1);
	}
	return projSelected[pj];
}

bool DataContent::setProjSelected(int pj, const QString &text)
{
	if (projSelected.size() <= pj) {
		projSelected.resize(pj + 1);
	}
	projSelected[pj] = text;
	return true;
}

QString DataContent::getDayComment(int day)
{
	if (dataContent.size() <= day) {
		dataContent.resize(day + 1);
	}
	return dataContent[day].comment;
}

bool DataContent::setDayComment(int day, const QString &text)
{
	if (dataContent.size() <= day) {
		dataContent.resize(day + 1);
	}
	dataContent[day].comment = text;
	return true;
}

int DataContent::getDayLeftMinute(int day)
{
	if (dataContent.size() <= day) {
		dataContent.resize(day + 1);
	}
	return dataContent[day].inputMinute - dataContent[day].totalMinute;
}

int DataContent::getDayInputMinute(int day)
{
	if (dataContent.size() <= day) {
		dataContent.resize(day + 1);
	}
	return dataContent[day].inputMinute;
}

int DataContent::getDayTotalMinute(int day)
{
	if (dataContent.size() <= day) {
		dataContent.resize(day + 1);
	}
	return dataContent[day].totalMinute;
}

int DataContent::getDayTotalWeight(int day)
{
	if (dataContent.size() <= day) {
		dataContent.resize(day + 1);
	}
	return dataContent[day].totalWeight;
}

int DataContent::getDayMinute(int day, int pj)
{
	if (dataContent.size() <= day) {
		dataContent.resize(day + 1);
	}
	if (dataContent[day].minute.size() <= pj) {
		dataContent[day].minute.resize(pj + 1);
	}
	return dataContent[day].minute[pj];
}

bool DataContent::setDayMinute(int day, int pj, int value)
{
	if (dataContent.size() <= day) {
		dataContent.resize(day + 1);
	}
	if (dataContent[day].minute.size() <= day) {
		dataContent[day].minute.resize(pj + 1);
	}
	dataContent[day].totalMinute += value - dataContent[day].minute[pj];
	dataContent[day].minute[pj] = value;
	dataContent[day].adjustWeight();
	return true;
}

int DataContent::getDayWeight(int day, int pj)
{
	if (dataContent.size() <= day) {
		dataContent.resize(day + 1);
	}
	if (dataContent[day].weight.size() <= pj) {
		dataContent[day].weight.resize(pj + 1);
	}
	return dataContent[day].weight[pj];
}

bool DataContent::setDayWeight(int day, int pj, int value)
{
	if (dataContent.size() <= day) {
		dataContent.resize(day + 1);
	}
	if (dataContent[day].weight.size() <= pj) {
		dataContent[day].weight.resize(pj + 1);
	}
	dataContent[day].totalWeight += value - dataContent[day].weight[pj];
	dataContent[day].weight[pj] = value;
	dataContent[day].adjustWeight();
	return true;
}

int DataContent::getDayPercent(int day, int pj)
{
	if (dataContent.size() <= day) {
		dataContent.resize(day + 1);
	}
	if (dataContent[day].percent.size() <= pj) {
		dataContent[day].percent.resize(pj + 1);
	}
	return dataContent[day].percent[pj];
}

int DataContent::getDayMinuteByWeight(int day, int pj)
{
	if (dataContent.size() <= day) {
		dataContent.resize(day + 1);
	}
	if (dataContent[day].minuteByWeight.size() <= pj) {
		dataContent[day].minuteByWeight.resize(pj + 1);
	}
	return dataContent[day].minuteByWeight[pj];
}

int DataContent::minuteFromData(int value)
{
	int hour = value / 100;
	int minute = value - hour * 100;
	return hour * 60 + minute;
}

int DataContent::dataFromMinute(int value)
{
	int hour = value / 60;
	int minute = value - hour * 60;
	return hour * 100 + minute;
}

QString DataContent::getDataName(const QDate &date)
{
	Q_ASSERT(date.year() >= 2000);
#if 0
	QString dataName = QDir::homePath();
#else
	QString dataName = QDir::currentPath();
#endif
	return dataName.append(QString("\\qt-gyomu%1%2.db").arg(date.year()).arg(date.month(), 2, 10, QChar('0')));
}

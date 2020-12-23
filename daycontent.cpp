#include <QDataStream>
#include <QString>
#include <QVector>
#include "daycontent.h"

DayContent::DayContent()
	: comment(), inputMinute(0), totalMinute(0), totalWeight(0), minute(), weight(), percent(), minuteByWeight()
{
}

void DayContent::clear()
{
	*this = DayContent();
}

void DayContent::adjust()
{
	totalMinute = 0;
	totalWeight = 0;
	minute.resize(40);
	weight.resize(40);

	//
	// sum up
	//
	for (int ii = 0; ii < minute.size(); ii++) {
		totalMinute += minute[ii];
		totalWeight += weight[ii];
	}

	adjustWeight();
}

void DayContent::adjustWeight()
{
	percent.clear();
	percent.resize(40);
	minuteByWeight.clear();
	minuteByWeight.resize(40);

	//
	// distribute by weight
	//
	int totalPercent = 100;
	int leftPercent = totalPercent;
	int totalMinuteByWeight = inputMinute - totalMinute;
	int leftMinuteByWeight = totalMinuteByWeight;

	if (
		(totalWeight <= 0) ||
		(leftMinuteByWeight < 0)
	) {
		return;
	}

	for (int ii = 0; ii < minute.size(); ii++) {
		if (percent.size() <= ii) {
			percent.resize(ii + 1);
		}
		percent[ii] = totalPercent * weight[ii] / totalWeight;
		leftPercent -= percent[ii];

		if (minuteByWeight.size() <= ii) {
			minuteByWeight.resize(ii + 1);
		}
		minuteByWeight[ii] = totalMinuteByWeight * weight[ii] / totalWeight;
		leftMinuteByWeight -= minuteByWeight[ii];
	}

	// distribute leftover
	while (leftPercent > 0) {
		for (int ii = 0; ii < minute.size(); ii++) {
			if (percent[ii] > 0) {
				percent[ii]++;
				if (--leftPercent <= 0) {
					break;
				}
			}
		}
	}

	while (leftMinuteByWeight > 0) {
		for (int ii = 0; ii < minute.size(); ii++) {
			if (minuteByWeight[ii] > 0) {
				minuteByWeight[ii]++;
				if (--leftMinuteByWeight <= 0) {
					break;
				}
			}
		}
	}
}

QDataStream &operator>>(QDataStream &left, DayContent &right)
{
	right.clear();
	left >> right.comment >> right.inputMinute >> right.minute >> right.weight;
	right.adjust();
	return left;
}

QDataStream &operator<<(QDataStream &left, const DayContent &right)
{
	left << right.comment << right.inputMinute << right.minute << right.weight;
	return left;
}

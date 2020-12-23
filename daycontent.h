#ifndef DAYCONTENT_H
#define DAYCONTENT_H

#include <QDataStream>
#include <QString>
#include <QVector>

class DayContent
{
public:
    DayContent();
	void clear();
	void adjust();
	void adjustWeight();

public:
	QString			comment;
	int				inputMinute;
	int				totalMinute;
	int				totalWeight;
	QVector<int>	minute;
	QVector<int>	weight;
	QVector<int>	percent;
	QVector<int>	minuteByWeight;
};

QDataStream &operator>>(QDataStream &left, DayContent &right);
QDataStream &operator<<(QDataStream &left, const DayContent &right);

#endif // DAYCONTENT_H

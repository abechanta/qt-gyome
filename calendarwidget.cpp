#include <QDate>
#include <QDebug>
#include <QWheelEvent>
#include "calendarwidget.h"

CalendarWidget::CalendarWidget(QWidget *parent)
		: QCalendarWidget(parent)
{
}

#if 1
CalendarWidget::~CalendarWidget()
{
}
#endif

#if 0
void CalendarWidget::wheelEvent(QWheelEvent *event)
{
	qDebug() << __FUNCTION__;
	int numDegrees = event->delta() / 8;
	int numSteps = numDegrees / 15;
	QDate currentDate = selectedDate();
	if (numSteps < 0) {
		QDate tmpDate = currentDate.addDays(1);
		if (currentDate.month() == tmpDate.month()) {
			currentDate = tmpDate;
		}
	} else if (numSteps > 0) {
		QDate tmpDate = currentDate.addDays(-1);
		if (currentDate.month() == tmpDate.month()) {
			currentDate = tmpDate;
		}
	}
	setSelectedDate(currentDate);
}
#endif

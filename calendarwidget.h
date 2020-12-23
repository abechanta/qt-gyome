#ifndef CALENDARWIDGET_H
#define CALENDARWIDGET_H

#include <QtGui/QCalendarWidget>
#include <QWheelEvent>

class CalendarWidget : public QCalendarWidget
{
	Q_OBJECT

public:
	CalendarWidget(QWidget *parent = 0);
	~CalendarWidget();
protected:
//	virtual void wheelEvent(QWheelEvent *event);
};
#endif // CALENDARWIDGET_H

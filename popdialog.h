#ifndef POPDIALOG_H
#define POPDIALOG_H

#include <QtGui/QDialog>
#include <QtGui/QLabel>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QString>

class PopDialog : public QDialog
{
	Q_OBJECT

public:
	PopDialog(QWidget *parent);
	void show(const QString &title, const QString &explanation);
	void clearText();
	QString getText();

public slots:
	void accept();

private:
	QPlainTextEdit	*textEdit;
	QLabel			*textLabel;
	QPushButton		*acceptButton;
	QPushButton		*cancelButton;
};

#endif // POPDIALOG_H

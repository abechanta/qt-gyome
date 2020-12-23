#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <QtGui/QDialog>
#include <QtGui/QComboBox>
#include <QtGui/QPushButton>
#include <QString>
#include <QStringList>

class EditDialog : public QDialog
{
	Q_OBJECT

public:
	EditDialog(QWidget *parent);
	void show(const QString &text, const QStringList &projCode, const QStringList &projComment);
	void clearText();
	QString getText();

public slots:
	void accept();
	void enableButton();

private:
	QComboBox		*textEdit;
	QPushButton		*acceptButton;
	QPushButton		*cancelButton;
};

#endif // EDITDIALOG_H

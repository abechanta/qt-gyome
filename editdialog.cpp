#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QDebug>
#include <QMessageBox>
#include <QString>
#include "editdialog.h"

#define ALLOW_EMPTY_INPUT

EditDialog::EditDialog(QWidget *parent)
	: QDialog(parent)
{
	QLabel *label = new QLabel(tr("Choose Project:"));
	textEdit = new QComboBox();
	textEdit->setEditable(true);
	acceptButton = new QPushButton(tr("&Select"));
	cancelButton = new QPushButton(tr("&Cancel"));

	QHBoxLayout *hLayout = new QHBoxLayout();
	hLayout->addWidget(acceptButton);
	hLayout->addWidget(cancelButton);

	QVBoxLayout *vLayout = new QVBoxLayout();
	vLayout->addWidget(label);
	vLayout->addWidget(textEdit);
	vLayout->addLayout(hLayout);

	setLayout(vLayout);
	setWindowModality(Qt::ApplicationModal);
	setWindowTitle(tr("QT-Gyomu: Select Project"));

	connect(acceptButton, SIGNAL(clicked()), this, SLOT(accept()));
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
#if !defined(ALLOW_EMPTY_INPUT)
	connect(textEdit, SIGNAL(editTextChanged(QString)), this, SLOT(enableButton()));
#endif
}

void EditDialog::show(const QString &text, const QStringList &projCode, const QStringList &projComment)
{
	textEdit->clear();
	QStringList::const_iterator ptr1 = projCode.begin();
	QStringList::const_iterator ptr2 = projComment.begin();
	int cursor = -1;
	for (int ii = 0; ii < projCode.count(); ii++) {
		QString line = QString("%1: %2").arg(*ptr1).arg(*ptr2);
		textEdit->addItem(line);
		if (text.compare(*ptr1) == 0) {
			cursor = ii;
		}
		ptr1++;
		ptr2++;
	}
	if (cursor == -1) {
		textEdit->insertItem(0, text);
		textEdit->setCurrentIndex(0);
	} else {
		textEdit->setCurrentIndex(cursor);
	}

#if !defined(ALLOW_EMPTY_INPUT)
	acceptButton->setEnabled(!textEdit->currentText().isEmpty());
#endif
	QDialog::show();
}

void EditDialog::clearText()
{
	textEdit->clear();
}

QString EditDialog::getText()
{
	QString line = textEdit->currentText();
	int ix = line.indexOf(':');
	if (ix != -1) {
		line.truncate(ix);
	}
	return line;
}

void EditDialog::accept()
{
	QString text = textEdit->currentText();
#if !defined(ALLOW_EMPTY_INPUT)
	if (text.isEmpty()) {
		QMessageBox::information(this, tr("QT-Gyomu"), tr("Invalid Text."));
		return;
	}
#endif

	hide();
	QDialog::accept();
}

void EditDialog::enableButton()
{
#if !defined(ALLOW_EMPTY_INPUT)
	acceptButton->setEnabled(!textEdit->currentText().isEmpty());
#endif
}

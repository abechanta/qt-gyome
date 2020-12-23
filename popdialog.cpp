#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QMessageBox>
#include <QString>
#include "popdialog.h"

PopDialog::PopDialog(QWidget *parent)
	: QDialog(parent)
{
	QLabel *label = new QLabel(tr("Import:"));
	textEdit = new QPlainTextEdit();
	textLabel = new QLabel();
	acceptButton = new QPushButton(tr("I&mport"));
	acceptButton->setFocusPolicy(Qt::NoFocus);
	cancelButton = new QPushButton(tr("&Cancel"));
	cancelButton->setFocusPolicy(Qt::NoFocus);

	QHBoxLayout *hLayout = new QHBoxLayout();
	hLayout->addWidget(acceptButton);
	hLayout->addWidget(cancelButton);

	QVBoxLayout *vLayout = new QVBoxLayout();
	vLayout->addWidget(label);
	vLayout->addWidget(textEdit);
	vLayout->addWidget(textLabel);
	vLayout->addLayout(hLayout);

	setLayout(vLayout);
	setWindowModality(Qt::ApplicationModal);
	setWindowTitle(tr("QT-Gyomu: "));

	connect(acceptButton, SIGNAL(clicked()), this, SLOT(accept()));
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
}

void PopDialog::show(const QString &title, const QString &explanation)
{
	setWindowTitle(title);
	textLabel->setText(explanation);
	QDialog::show();
}

void PopDialog::clearText()
{
	textEdit->clear();
}

QString PopDialog::getText()
{
	return textEdit->toPlainText();
}

void PopDialog::accept()
{
	QString text = textEdit->toPlainText();
	if (text.isEmpty()) {
		QMessageBox::information(this, tr("QT-Gyomu"), tr("Invalid Text."));
		return;
	}

	hide();
	QDialog::accept();
}

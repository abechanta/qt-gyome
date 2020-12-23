#include <QtGui/QApplication>
#include <QDebug>
#include <QLibraryInfo>
#include <QLocale>
#include <QTranslator>
#include "dialog.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTranslator myTranslator;
	myTranslator.load("qt-gyomu_" + QLocale::system().name());
	a.installTranslator(&myTranslator);

	Dialog w;
	w.show();
	return a.exec();
}

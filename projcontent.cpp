#include <QDataStream>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QMap>
#include <QString>
#include <QStringList>
#include "projcontent.h"

const char	*ProjContent::defaultVer = "2009/5/13";

ProjContent::ProjContent()
{
}

bool ProjContent::load()
{
	QFile pref(getPrefName());
	if (!pref.open(QIODevice::ReadOnly)) {
		qDebug() << __FILE__ << ":" << "open failed.";
		return false;
	}

	QDataStream in(&pref);
	in.setVersion(QDataStream::Qt_4_5);

	QString readVer;
	in >> readVer;
	if (readVer.compare(QString(defaultVer)) != 0) {
		qDebug() << __FILE__ << ":" << "load format mismatch.";
		return false;
	}

	in >> projContent;
	if (projContent.size() <= 1) {	// なぜか "" が登録されているので
		qDebug() << __FILE__ << ":" << "load failed.";
		return false;
	}

	qDebug() << __FILE__ << ":" << "load succeeded.";
	qDebug() << "projContent:" << projContent;
	return true;
}

bool ProjContent::save() const
{
	QFile pref(getPrefName());
	if (!pref.open(QIODevice::WriteOnly)) {
		qDebug() << __FILE__ << ":" << "open failed.";
		return false;
	}

	QDataStream out(&pref);
	out.setVersion(QDataStream::Qt_4_5);
	out << QString(defaultVer) << projContent;

	qDebug() << __FILE__ << ":" << "save succeeded.";
	return true;
}

void ProjContent::clear()
{
	projContent.clear();
}

bool ProjContent::import(const QString &content)
{
	QStringList line = content.split('\n');
	QStringList word;
	bool bMulti = false;
	for (QStringList::const_iterator ptr = line.begin(); ptr != line.end(); ++ptr) {
		QStringList wordTmp = ptr->split('\t');
//		qDebug() << "ptr=" << *ptr;
//		qDebug() << "word=" << word;
//		qDebug() << "wordTmp=" << wordTmp;
		if (wordTmp.isEmpty() || wordTmp.front().isEmpty()) {
			if (!word.isEmpty()) {
				projContent[word[0]] = QStringList(word);
				qDebug() << "#" << projContent.count() << "#" << projContent[word[0]];
				word.clear();
			}
			continue;
		}

		if (bMulti && !word.isEmpty()) {
			// concatinate both list
			bMulti = false;
			QString back = word.back();
			word.pop_back();
			QString front = wordTmp.front();
			wordTmp.pop_front();

			back.append('\n');
			back.append(front);
			word.push_back(back);
			word += wordTmp;
		} else {
			word = wordTmp;
		}

		if (!word.isEmpty()) {
			// detect multiline
			QString back = word.back();
			bMulti = (back.indexOf('"') == 0) && !back.endsWith('"');
			if (!bMulti) {
				projContent[word[0]] = QStringList(word);
				qDebug() << "#" << projContent.count() << "#" << projContent[word[0]];
				word.clear();
			}
		}
	}

	qDebug() << __FILE__ << ":" << QString("import succeeded: %1 project(s) imported.").arg(projContent.size());
	return true;
}

int ProjContent::getProjCount()
{
	return projContent.count();
}

QStringList ProjContent::getProjColumn(int column)
{
	QStringList list;
	QMap<QString, QStringList>::const_iterator ptr = projContent.begin();
	for (; ptr != projContent.end(); ++ptr) {
		QStringList tmp = ptr.value();
		list.push_back(tmp.count() > column ? tmp[column] : QString());
	}
	return list;
}

QStringList ProjContent::getProj(const QString &proj)
{
	QMap<QString, QStringList>::const_iterator ptr = projContent.find(proj);
	if (ptr == projContent.end()) {
		QStringList list;
		list.push_back(proj);
		return list;
	}
	return *ptr;
}

QString ProjContent::getPrefName()
{
#if 0
	QString prefName = QDir::homePath();
#else
	QString prefName = QDir::currentPath();
#endif
	return prefName.append("\\qt-gyomu.db");
}

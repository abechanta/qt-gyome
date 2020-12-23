#ifndef PROJCONTENT_H
#define PROJCONTENT_H

#include <QMap>
#include <QString>
#include <QStringList>

class ProjContent
{
public:
    ProjContent();
	bool load();
	bool save() const;
	void clear();
	bool import(const QString &content);

	int getProjCount();
	QStringList getProjColumn(int column);
	QStringList getProj(const QString &proj);

private:
	QMap<QString, QStringList>	projContent;

	static const char	*defaultVer;
	static QString getPrefName();
};

#endif // PROJCONTENT_H

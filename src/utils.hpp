#pragma once

#include "darkpalette.hpp"

#include <QApplication>
#include <QGroupBox>
#include <QJsonObject>
#include <QJsonValue>
#include <QPainter>
#include <QPainterPath>
#include <QStringList>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QVBoxLayout>

class Utils
{
public:
	enum DataRole
	{
		RoleTrackId = 0x0100,   // 256
		RoleArtistId = 0x0101,  // 257
		RoleAlbumId = 0x0102,   // 258
		RoleIndex = 0x0103,     // 259
		RolePlaylistId = 0x0104 // 260
	};

	enum class MaskShape
	{
		App,
		Pie
	};

	enum Palette
	{
		paletteApp = 0,   // Default app palette
		paletteStyle = 1, // Palette from current style
		paletteDark = 2,  // Custom dark palette
	};

	static QJsonValue getProperty(const QJsonObject &json, const QStringList &names);

	static QTreeWidgetItem *treeItem(
		QTreeWidget *tree, const QString &name, const QString &toolTip = QString::Null(),
		const QStringList &childrenItems = QStringList(QString::Null()));

	static QPixmap mask(
		const QPixmap &source, MaskShape shape = MaskShape::App,
		const QVariant &data = QVariant());

	static QWidget *layoutToWidget(QLayout *layout);

	static void applyPalette(Palette palette);

	static QString formatTime(int ms);

	static QGroupBox *createGroupBox(QVector<QWidget*> &widgets, QWidget *parent);

	static bool darkBackground;

private:
	Utils() = default;
};
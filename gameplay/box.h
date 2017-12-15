#ifndef ARKANOID_BOX_H
#define ARKANOID_BOX_H

#include "boxitem.h"
#include <QtCore/QMap>
#include <QtCore/QRect>

/*------- Box -------------------------------------------*/
class Box
{
public:
	Box();
	~Box();

	enum Side
	{
		Left = 1,
		Right,
		Top,
		Bottom
	};

	void setRect(const QRect &r);
	QRect rect() const;

	void setTransparency(Side side, bool transparency = false);
	bool transparency(Side side) const;

	BoxItem *appendItem(BoxItem::ItemType type);
	const QMap<BoxItem::ItemType, BoxItem *> &items() const;
	QList<BoxItem *> items(BoxItem::ItemType type) const;

private:
	QRect m_rect;
	QMap<Side, bool> m_transparency;
	QMap<BoxItem::ItemType, BoxItem *> m_items;
};

#endif // ARKANOID_BOX_H

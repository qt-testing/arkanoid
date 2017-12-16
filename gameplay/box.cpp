#include "box.h"
#include "ballboxitem.h"
#include "padboxitem.h"

/*------- Box -------------------------------------------*/
Box::Box()
{
	m_transparency.insert(Left, false);
	m_transparency.insert(Right, false);
	m_transparency.insert(Top, true);
	m_transparency.insert(Bottom, false);
}

Box::~Box()
{
    foreach (BoxItem *item, m_items) {
        delete item;
    }
}

void Box::setRect(const QRect &r)
{
	m_rect = r;
}

QRect Box::rect() const
{
	return m_rect;
}

void Box::setTransparency(Side side, bool transparency)
{
	m_transparency.insert(side, transparency);
}

bool Box::transparency(Side side) const
{
	return m_transparency[side];
}

BoxItem *Box::appendItem(BoxItem::ItemType type)
{
	BoxItem *item = 0;

	if (type == BoxItem::Pad) {
		item = new PadBoxItem();
	} else if (type == BoxItem::Ball) {
		item = new BallBoxItem();
	}

	m_items.insertMulti(type, item);

	return item;
}

const QMap<BoxItem::ItemType, BoxItem *> &Box::items() const
{
	return m_items;
}

QList<BoxItem *> Box::items(BoxItem::ItemType type) const
{
	return m_items.values(type);
}

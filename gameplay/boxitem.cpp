#include "boxitem.h"

/*------- BoxItem ---------------------------------------*/
BoxItem::BoxItem()
{
	m_type = ItemTypeNotDedined;
}

BoxItem::~BoxItem()
{
}

void BoxItem::setGeometry(const QRect &r)
{
	m_rect = r;
}

QRect BoxItem::rect() const
{
	return m_rect;
}

void BoxItem::setPosition(const QPoint &p)
{
	m_position = p;
}

QPoint BoxItem::position() const
{
	return m_position;
}

void BoxItem::move(int dx, int dy)
{
	m_position += QPoint(dx, dy);
}

void BoxItem::move()
{
	m_position += m_velocity;
}

BoxItem::ItemType BoxItem::type() const
{
	return m_type;
}

void BoxItem::setVelocity(QPoint velocity)
{
	m_velocity = velocity;
}

QPoint BoxItem::velocity() const
{
	return m_velocity;
}

#ifndef ARKANOID_BOXITEM_H
#define ARKANOID_BOXITEM_H

#include <QtCore/QRect>

/*------- BoxItem ---------------------------------------*/
class BoxItem
{
public:
	BoxItem();
	~BoxItem();

	enum ItemType
	{
		ItemTypeNotDedined = 0,
		Pad,
		Ball,
		Brick
	};

	void setGeometry(const QRect &r);
	QRect rect() const;

	void setPosition(const QPoint &p);
	QPoint position() const;

	void setVelocity(QPoint velocity);
	QPoint velocity() const;

	void move(int dx, int dy);
	void move();

	ItemType type() const;

protected:
	QRect m_rect;
	QPoint m_position;
	QPoint m_velocity;
	ItemType m_type;
};

#endif // ARKANOID_BOXITEM_H

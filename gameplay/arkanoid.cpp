#include "arkanoid.h"
#include "padboxitem.h"

/*------- Arkanoid --------------------------------------*/
Arkanoid::Arkanoid(QObject *parent)
	: QObject(parent)
{
	PadBoxItem *pad = static_cast<PadBoxItem *>(m_box.appendItem(BoxItem::Pad));
	pad->setGeometry(QRect(0, 0, 100, 20));
	pad->setPosition(QPoint(0, 0));
	pad->setVelocity(QPoint(7, 0));

	m_animation.setBox(&m_box);
	m_animation.setControl(&m_control);
	m_animation.start();
}

Arkanoid::~Arkanoid()
{
}

void Arkanoid::setGeometry(const QRect &r)
{
	m_box.setRect(r);
}

const Box &Arkanoid::box() const
{
	return m_box;
}

Control &Arkanoid::control()
{
	return m_control;
}

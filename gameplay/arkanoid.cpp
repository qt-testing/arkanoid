#include "arkanoid.h"
#include "ballboxitem.h"
#include "padboxitem.h"
#include <QTime>

/*------- Arkanoid --------------------------------------*/
Arkanoid::Arkanoid(QObject *parent)
	: QObject(parent)
{
	m_animation.setBox(&m_box);
	m_animation.setControl(&m_control);
}

Arkanoid::~Arkanoid()
{
}

void Arkanoid::start()
{
	if (m_animation.isActive()) {
		return;
	}

	int boxWidth = m_box.rect().width();
	int boxHeight = m_box.rect().height();
	int padWidth = 150;
	int ballSize = 20;

	qsrand(QTime::currentTime().msec() + 1);
	int ballXVelocity = qrand() % 20 - 10;
	qsrand(QTime::currentTime().msec() + 2);
	int ballYVelocity = qrand() % 20 - 10;

	ballXVelocity = ballXVelocity == 0 ? ballXVelocity + 1 : ballXVelocity;
	ballYVelocity = ballYVelocity == 0 ? ballYVelocity + 1 : ballYVelocity;

	BoxItem *item = m_box.appendItem(BoxItem::Pad);
	item->setGeometry(QRect(0, 0, padWidth, 20));
	item->setPosition(QPoint((boxWidth - padWidth) / 2, 0));
	item->setVelocity(QPoint(7, 0));

	item = m_box.appendItem(BoxItem::Ball);
	item->setGeometry(QRect(0, 0, ballSize, ballSize));
	item->setPosition(QPoint((boxWidth - ballSize) / 2, (boxHeight - ballSize) / 2));
	item->setVelocity(QPoint(ballXVelocity, ballYVelocity));

	m_animation.start();
}

void Arkanoid::stop()
{
	m_animation.stop();
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

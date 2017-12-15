#include "drawer.h"

/*------- ArkWidget -------------------------------------*/
Drawer::Drawer(QWidget *parent)
	: QWidget(parent)
{
	m_pArkanoid = 0;

	connect(&m_timer, SIGNAL(timeout),
			SLOT(repaint()));
}

Drawer::~Drawer()
{
}

void Drawer::setArkanoid(const Arkanoid *arkanoid)
{
	m_pArkanoid = arkanoid;
}

const Arkanoid *Drawer::arkanoid() const
{
	return m_pArkanoid;
}

void Drawer::startAnimation()
{
	m_timer.start(1000 / 120);
}

void Drawer::stopAnimation()
{
	m_timer.stop();
}

bool Drawer::isAnimationActive() const
{
	return m_timer.isActive();
}

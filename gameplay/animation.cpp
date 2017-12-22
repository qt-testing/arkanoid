#include "animation.h"
#include "box.h"
#include "padboxitem.h"
#include <control.h>
#include <systemcounter.h>
#include <QElapsedTimer>

/*------- Animation -------------------------------------*/
Animation::Animation(QObject *parent)
	: QObject(parent)
{
	connect(&m_timer, SIGNAL(timeout()),
			SLOT(animate()));
}

Animation::~Animation()
{
}

void Animation::setBox(Box *box)
{
	m_pBox = box;
}

void Animation::setControl(const Control *control)
{
	m_pControl = control;
}

void Animation::start()
{
	m_timer.start(1000 / 120);
}

void Animation::stop()
{
	m_timer.stop();
}

bool Animation::isActive() const
{
	return m_timer.isActive();
}

void Animation::animate()
{
	QElapsedTimer timer;
	timer.start();

	int boxWidth = m_pBox->rect().width();
	int boxHeight = m_pBox->rect().height();

	if (m_pControl->actionState(ArkanoidNamespace::ControlActionRight)) {
		QList<BoxItem *> items = m_pBox->items(BoxItem::Pad);
		foreach (BoxItem *item, items) {
			int padWidth = item->rect().width();

			if (item->position().x() + padWidth >= boxWidth) {
				item->setPosition(QPoint(boxWidth - padWidth, item->position().y()));
			} else {
				item->move(abs(item->velocity().x()), item->velocity().y());
			}
		}
	} else if (m_pControl->actionState(ArkanoidNamespace::ControlActionLeft)) {
		QList<BoxItem *> items = m_pBox->items(BoxItem::Pad);
		foreach (BoxItem *item, items) {
			if (item->position().x() <= 0) {
				item->setPosition(QPoint(0, item->position().y()));
			} else {
				item->move(-abs(item->velocity().x()), item->velocity().y());
			}
		}
	}

	QList<BoxItem *> items = m_pBox->items(BoxItem::Ball);
	foreach (BoxItem *item, items) {
		QPoint pos = item->position();
		int ballSize = item->rect().width();

		if (pos.x() >= boxWidth - ballSize) {
			item->setPosition(QPoint(boxWidth - ballSize, pos.y()));
			item->setVelocity(QPoint(-abs(item->velocity().x()), item->velocity().y()));
		}

		if (pos.x() <= 0) {
			item->setPosition(QPoint(0, pos.y()));
			item->setVelocity(QPoint(abs(item->velocity().x()), item->velocity().y()));
		}

		if (pos.y() >= boxHeight - ballSize) {
			item->setPosition(QPoint(pos.x(), boxHeight - ballSize));
			item->setVelocity(QPoint(item->velocity().x(), -abs(item->velocity().y())));
		}

		if (pos.y() <= 0) {
			item->setPosition(QPoint(pos.x(), 0));
			item->setVelocity(QPoint(item->velocity().x(), abs(item->velocity().y())));
		}

		item->move();
	}

	SystemCounter::instance()->appendTime("Animation::animate", timer.nsecsElapsed());
}

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

	QPoint curPos;
	QPoint nextPos;

	if (m_pControl->actionState(ArkanoidNamespace::ControlActionRight)) {
		QList<BoxItem *> items = m_pBox->items(BoxItem::Pad);
		foreach (BoxItem *item, items) {
			int padWidth = item->rect().width();

			nextPos = item->position();
			nextPos += QPoint(abs(item->velocity().x()), item->velocity().y());

			if (nextPos.x() + padWidth >= boxWidth) {
				nextPos.setX(boxWidth - padWidth);
			}

			item->setPosition(nextPos);
		}
	} else if (m_pControl->actionState(ArkanoidNamespace::ControlActionLeft)) {
		QList<BoxItem *> items = m_pBox->items(BoxItem::Pad);
		foreach (BoxItem *item, items) {
			nextPos = item->position();
			nextPos += QPoint(-abs(item->velocity().x()), item->velocity().y());

			if (nextPos.x() <= 0) {
				nextPos.setX(0);
			}

			item->setPosition(nextPos);
		}
	}

	QList<BoxItem *> items = m_pBox->items(BoxItem::Ball);
	foreach (BoxItem *item, items) {
		int ballSize = item->rect().width();
		QPoint velocity = item->velocity();

		curPos = item->position();
		nextPos = (curPos += item->velocity());

		if (nextPos.x() >= boxWidth - ballSize) {
			int xdif = nextPos.x() - (boxWidth - ballSize);
			nextPos.setX(boxWidth - ballSize - xdif);
			velocity.setX(-abs(velocity.x()));
		} else if (nextPos.x() <= 0) {
			int xdif = -nextPos.x();
			nextPos.setX(xdif);
			velocity.setX(abs(velocity.x()));
		}

		if (nextPos.y() >= boxHeight - ballSize) {
			int ydif = nextPos.y() - (boxHeight - ballSize);
			nextPos.setY(boxHeight - ballSize - ydif);
			velocity.setY(-abs(velocity.y()));
		} else if (nextPos.y() <= 0) {
			int ydif = -nextPos.y();
			nextPos.setY(ydif);
			velocity.setY(abs(velocity.y()));
		}

		item->setVelocity(velocity);
		item->setPosition(nextPos);
	}

	SystemCounter::instance()->appendTime("Animation::animate", timer.nsecsElapsed());
}

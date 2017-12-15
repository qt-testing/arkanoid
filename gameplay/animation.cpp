#include "animation.h"
#include "box.h"
#include "padboxitem.h"
// #include <cmath>
#include <control.h>

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

void Animation::animate()
{
	if (m_pControl->actionState(ArkanoidNamespace::ControlActionRight)) {
		QList<BoxItem *> items = m_pBox->items(BoxItem::Pad);
		foreach (BoxItem *item, items) {
			int boxRightSidePos = m_pBox->rect().right();
			int padWidth = item->rect().width();

			if (item->position().x() + padWidth >= boxRightSidePos) {
				item->setPosition(QPoint(boxRightSidePos - padWidth, item->position().y()));
			} else {
				item->move(abs(item->velocity().x()), item->velocity().y());
			}
		}
	} else if (m_pControl->actionState(ArkanoidNamespace::ControlActionLeft)) {
		QList<BoxItem *> items = m_pBox->items(BoxItem::Pad);
		foreach (BoxItem *item, items) {
			int boxLeftSidePos = m_pBox->rect().left();

			if (item->position().x() <= boxLeftSidePos) {
				item->setPosition(QPoint(boxLeftSidePos, item->position().y()));
			}

			item->move(-abs(item->velocity().x()), item->velocity().y());
		}
	}
}

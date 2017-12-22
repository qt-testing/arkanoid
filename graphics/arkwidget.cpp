#include "arkwidget.h"
#include <arkanoid.h>
#include <padboxitem.h>
#include <systemcounter.h>
#include <QElapsedTimer>
#include <QtGui/QPainter>

/*------- ArkWidget -------------------------------------*/
ArkWidget::ArkWidget(QWidget *parent)
	: Drawer(parent)
{
	m_boxPen.setWidth(5);
	m_boxPen.setColor(QColor(255, 0, 0));
}

ArkWidget::~ArkWidget()
{
}

void ArkWidget::paintEvent(QPaintEvent *event)
{
	Q_UNUSED(event);

	if (!m_pArkanoid) {
		return;
	}

	QElapsedTimer timer;
	timer.start();

	QPainter painter(this);

	const Box &box = m_pArkanoid->box();
	const QRect &r = box.rect();

	QMatrix m;
	m.translate(0.0, r.height());
	m.scale(1.0, -1.0);
	painter.setMatrix(m);

	painter.setPen(m_boxPen);

	if (!box.transparency(Box::Left)) {
		painter.drawLine(r.bottomLeft(), r.topLeft());
	}

	if (!box.transparency(Box::Right)) {
		painter.drawLine(r.bottomRight(), r.topRight());
	}

	if (!box.transparency(Box::Bottom)) {
		painter.drawLine(r.bottomLeft(), r.bottomRight());
	}

	if (!box.transparency(Box::Top)) {
		painter.drawLine(r.topLeft(), r.topRight());
	}

	QMap<BoxItem::ItemType, BoxItem *> items = box.items();

	foreach (BoxItem *item, items) {
		BoxItem::ItemType type = item->type();

		QRect r = item->rect();
		r.moveTo(item->position());

		if (type == BoxItem::Pad) {
			painter.drawRect(r);
		} else if (type == BoxItem::Ball) {
			painter.drawEllipse(r);
		}
	}

	SystemCounter::instance()->appendTime("ArkWidget::paintEvent", timer.nsecsElapsed());
}

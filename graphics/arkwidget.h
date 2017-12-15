#ifndef ARKANOID_ARKWIDGET_H
#define ARKANOID_ARKWIDGET_H

#include "drawer.h"
#include <QtCore/QTimer>
#include <QtGui/QPen>

/*------- ArkWidget -------------------------------------*/
class ArkWidget : public Drawer
{
public:
	ArkWidget(QWidget *parent);
	~ArkWidget();

protected:
	void paintEvent(QPaintEvent *event);

private:
	QPen m_boxPen;
};

#endif // ARKANOID_ARKWIDGET_H

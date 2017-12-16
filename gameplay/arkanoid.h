#ifndef ARKANOID_ARKANOID_H
#define ARKANOID_ARKANOID_H

#include "arkanoidnamespace.h"
#include "animation.h"
#include "box.h"
#include <control.h>

/*------- Arkanoid --------------------------------------*/
class Arkanoid : public QObject
{
	Q_OBJECT

public:
	Arkanoid(QObject *parent = 0);
	~Arkanoid();

	void start();
	void stop();

	void setGeometry(const QRect &r);

	const Box &box() const;

	Control &control();

private:
	Animation m_animation;
	Box m_box;
	Control m_control;
};

#endif // ARKANOID_ARKANOID_H

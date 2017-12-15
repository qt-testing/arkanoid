#ifndef ARKANOID_CONTROL_H
#define ARKANOID_CONTROL_H

#include "arkanoidnamespace.h"
#include <QMap>

/*------- Control ---------------------------------------*/
class Control
{
public:
	Control();
	~Control();

	void move(ArkanoidNamespace::ControlAction action, bool apply = true);

	bool actionState(ArkanoidNamespace::ControlAction action) const;

private:
	QMap<ArkanoidNamespace::ControlAction, bool> m_actions;
};

#endif // ARKANOID_CONTROL_H

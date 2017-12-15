#include "control.h"

/*------- Control ---------------------------------------*/
Control::Control()
{
	m_actions.insert(ArkanoidNamespace::ControlActionLeft, false);
	m_actions.insert(ArkanoidNamespace::ControlActionRight, false);
	m_actions.insert(ArkanoidNamespace::ControlActionUp, false);
	m_actions.insert(ArkanoidNamespace::ControlActionDown, false);
}

Control::~Control()
{
}

void Control::move(ArkanoidNamespace::ControlAction action, bool apply)
{
	m_actions.insert(action, apply);
}

bool Control::actionState(ArkanoidNamespace::ControlAction action) const
{
	return m_actions[action];
}

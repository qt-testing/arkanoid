#ifndef ARKANOID_DRAWER_H
#define ARKANOID_DRAWER_H

#include <QTimer>
#include <QWidget>

class Arkanoid;

/*------- Drawer ----------------------------------------*/
class Drawer : public QWidget
{
public:
	Drawer(QWidget *parent = 0);
	~Drawer();

	void setArkanoid(const Arkanoid *arkanoid);
	const Arkanoid *arkanoid() const;

	void startAnimation();
	void stopAnimation();

	bool isAnimationActive() const;

protected:
	const Arkanoid *m_pArkanoid;
	QTimer m_timer;
};

#endif // ARKANOID_DRAWER_H

#ifndef ARKANOID_ANIMATION_H
#define ARKANOID_ANIMATION_H

#include <QTimer>

class Box;
class Control;

/*------- Animation -------------------------------------*/
class Animation : public QObject
{
	Q_OBJECT

public:
	Animation(QObject *parent = 0);
	~Animation();

	void setBox(Box *box);
	void setControl(const Control *control);

	void start();
	void stop();

	bool isActive() const;

private slots:
	void animate();

private:
	Box *m_pBox;
	const Control *m_pControl;
	QTimer m_timer;
};

#endif // ARKANOID_ANIMATION_H

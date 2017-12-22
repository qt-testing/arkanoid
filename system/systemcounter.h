#ifndef ARKANOID_SYSTEMCOUNTER_H
#define ARKANOID_SYSTEMCOUNTER_H

#include <QThread>

class SystemCounterWorker;

/*------- SystemCounter ---------------------------------*/
class SystemCounter : public QObject
{
	Q_OBJECT

public:
	SystemCounter(QObject *parent = 0);
	~SystemCounter();

	static SystemCounter *instance();

	void appendTime(const QString &name, qint64 nsec);

signals:
	void signalAppendTime(const QString &name, qint64 nsec);

private:
	static SystemCounter *m_pSystemCounter;
	QThread m_thread;
	SystemCounterWorker *m_pWorker;
};

#endif // ARKANOID_SYSTEMCOUNTER_H

#include "systemcounter.h"
#include "systemcounterworker.h"

SystemCounter *SystemCounter::m_pSystemCounter = 0;

/*------- SystemCounter ---------------------------------*/
SystemCounter::SystemCounter(QObject *parent)
	: QObject(parent)
{
	m_pWorker = new SystemCounterWorker();
	m_pWorker->moveToThread(&m_thread);

	connect(&m_thread, SIGNAL(finished()), m_pWorker, SLOT(deleteLater()));

	connect(this, SIGNAL(signalAppendTime(const QString &, qint64)),
			m_pWorker, SLOT(appendTime(const QString &, qint64)));

	m_thread.start();
}

SystemCounter::~SystemCounter()
{
	m_thread.quit();
	m_thread.wait();
}

SystemCounter *SystemCounter::instance()
{
	if (!m_pSystemCounter) {
		m_pSystemCounter = new SystemCounter();
	}

	return m_pSystemCounter;
}

void SystemCounter::appendTime(const QString &name, qint64 nsec)
{
	emit signalAppendTime(name, nsec);
}

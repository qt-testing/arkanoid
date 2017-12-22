#include "systemcounterworker.h"
#include <QDebug>

/*------- SystemCounterWorker ---------------------------*/
SystemCounterWorker::SystemCounterWorker(QObject *parent)
	: QObject(parent)
{
	connect(&m_timer, SIGNAL(timeout()),
			SLOT(onTimer()));

	m_timer.start(1000);
}

SystemCounterWorker::~SystemCounterWorker()
{
}

void SystemCounterWorker::appendTime(const QString &name, qint64 nsec)
{
	if (!m_times.contains(name)) {
		QVector<qint64> array;
		array.append(nsec);
		m_times.insert(name, array);
	} else {
		m_times[name].append(nsec);
	}
}

void SystemCounterWorker::onTimer()
{
	QStringList names = m_times.keys();

	foreach (const QString name, names) {
		const QVector<qint64> &array = m_times[name];
		int count = array.count();
		qint64 var = 0;

		foreach (qint64 time, array) {
			var += time;
		}

		qDebug() << name << count << double(var) / count / 1000.0;
	}

	m_times.clear();
}

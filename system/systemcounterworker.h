#ifndef ARKANOID_SYSTEMCOUNTERWORKER_H
#define ARKANOID_SYSTEMCOUNTERWORKER_H

#include <QMap>
#include <QTimer>
#include <QVector>

/*------- SystemCounterWorker ---------------------------*/
class SystemCounterWorker : public QObject
{
	Q_OBJECT

public:
	SystemCounterWorker(QObject *parent = 0);
	~SystemCounterWorker();

private slots:
	void appendTime(const QString &name, qint64 nsec);
	void onTimer();

private:
	QMap<QString, QVector<qint64> > m_times;
	QTimer m_timer;
};

#endif // ARKANOID_SYSTEMCOUNTERWORKER_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <arkwidget.h>
#include <QDebug>
#include <QtGui/QKeyEvent>
#include <QtGui/QPainter>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	statusBar()->hide();

	m_pDrawer = new ArkWidget(this);
	m_pDrawer->setArkanoid(&m_arkanoid);
	m_pDrawer->startAnimation();

	setCentralWidget(m_pDrawer);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
	QMainWindow::keyPressEvent(event);

	Control &control = m_arkanoid.control();

	if (event->key() == Qt::Key_F &&
		event->modifiers() & Qt::ControlModifier) {
		if (isFullScreen()) {
			showNormal();
		} else {
			showFullScreen();
		}
	} else if (event->key() == Qt::Key_Right && !event->isAutoRepeat()) {
		control.move(ArkanoidNamespace::ControlActionRight);
	} else if (event->key() == Qt::Key_Left) {
		control.move(ArkanoidNamespace::ControlActionLeft);
	}
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
	QMainWindow::keyReleaseEvent(event);

	Control &control = m_arkanoid.control();

	if (event->key() == Qt::Key_Right && !event->isAutoRepeat()) {
		control.move(ArkanoidNamespace::ControlActionRight, false);
	} else if (event->key() == Qt::Key_Left) {
		control.move(ArkanoidNamespace::ControlActionLeft, false);
	}
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton) {
		if (isFullScreen()) {
			showNormal();
		} else {
			showFullScreen();
		}
	}
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
	QMainWindow::resizeEvent(event);

	m_arkanoid.setGeometry(centralWidget()->geometry());
}

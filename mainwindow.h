#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <arkanoid.h>
#include <QtWidgets/QAction>
#include <QtWidgets/QMainWindow>
#include <QShortcut>

namespace Ui {
	class MainWindow;
}

class Drawer;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

protected:
	void keyPressEvent(QKeyEvent *event);
	void keyReleaseEvent(QKeyEvent *event);
	void mouseDoubleClickEvent(QMouseEvent *event);
	void resizeEvent(QResizeEvent *event);

private:
	Ui::MainWindow *ui;
	Arkanoid m_arkanoid;
	Drawer *m_pDrawer;
};

#endif // MAINWINDOW_H

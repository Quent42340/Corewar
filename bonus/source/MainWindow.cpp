/*
 * =====================================================================================
 *
 *       Filename:  MainWindow.cpp
 *
 *    Description:  
 *
 *        Created:  23/02/2016 18:14:06
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <QKeyEvent>
#include <QHBoxLayout>

#include "GLWidget.hpp"
#include "Keyboard.hpp"
#include "MainWindow.hpp"
#include "PlayerWidget.hpp"

MainWindow::MainWindow() : QMainWindow(nullptr, Qt::Dialog) {
	setWindowTitle("Corewar launcher");
	resize(width, height);
	
	QSurfaceFormat format;
	format.setDepthBufferSize(24);
	format.setStencilBufferSize(8);
	format.setVersion(3, 3);
	format.setProfile(QSurfaceFormat::CoreProfile);
	format.setSwapBehavior(QSurfaceFormat::SingleBuffer);
	
	if (format.swapInterval() != 1)
		qWarning() << "Warning: Unable to enable VSync";
	
	m_widget = new GLWidget;
	m_widget->setFormat(format);
	
	m_playerWidget = new PlayerWidget;
	m_playerWidget->setMinimumSize(width / 5, 0);
	
	QWidget *layoutWidget = new QWidget(this);
	layoutWidget->resize(width, height);
	
	QHBoxLayout *layout = new QHBoxLayout(layoutWidget);
	layout->addWidget(m_widget, 1);
	layout->addWidget(m_playerWidget);
	
	Keyboard::setKeyMap(&m_keys);
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
	Keyboard::onKeyPressed(event->key());
	if (event->key() == Qt::Key_Escape) {
		close();
	}
}

void MainWindow::keyReleaseEvent(QKeyEvent *event) {
	Keyboard::onKeyReleased(event->key());
}


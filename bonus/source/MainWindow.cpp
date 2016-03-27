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
#include <QHBoxLayout>
#include <QKeyEvent>

#include "CorewarRenderer.hpp"
#include "GLWidget.hpp"
#include "Keyboard.hpp"
#include "MainWindow.hpp"
#include "PlayerWidget.hpp"

MainWindow::MainWindow(t_application &app) : QMainWindow(nullptr, Qt::Dialog), m_app(app) {
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
	
	m_app.qt_data = this;
	m_app.death_callback = &handleDeath;
	m_app.st_callback = &handleStorage;
	
	m_glWidget = new GLWidget(m_app, this);
	m_glWidget->setFormat(format);
	
	QWidget *layoutWidget = new QWidget(this);
	layoutWidget->resize(width, height);
	
	QHBoxLayout *horizontalLayout = new QHBoxLayout(layoutWidget);
	horizontalLayout->addWidget(m_glWidget, 1);
	horizontalLayout->addWidget(&m_sideBar);
	
	Keyboard::setKeyMap(&m_keys);
	
	connect(&m_mediaPlayer.audioProbe(), SIGNAL(audioBufferProbed(QAudioBuffer)), m_glWidget, SLOT(processAudioBuffer(QAudioBuffer)));
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

void MainWindow::handleDeath(t_application *app, t_program *program) {
	MainWindow *window = static_cast<MainWindow*>(app->qt_data);
	
	CorewarRenderer *renderer = window->m_glWidget->corewarRenderer();
	renderer->playerDead(0);
}

void MainWindow::handleStorage(t_application *app, t_program *program, int index, int size) {
	MainWindow *window = static_cast<MainWindow*>(app->qt_data);
	
	CorewarRenderer *renderer = window->m_glWidget->corewarRenderer();
	renderer->memoryStored(0, index, size);
}


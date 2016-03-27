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
	
	m_glWidget = new GLWidget(m_app, this);
	m_glWidget->setFormat(format);
	
	m_sideBar = new SideBar(&m_mediaPlayer, m_glWidget, this);
	
	QWidget *layoutWidget = new QWidget(this);
	layoutWidget->resize(width, height);
	
	QHBoxLayout *horizontalLayout = new QHBoxLayout(layoutWidget);
	horizontalLayout->addWidget(m_glWidget, 1);
	horizontalLayout->addWidget(m_sideBar);
	
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
	renderer->playerDead(program->index);
	
	qDebug() << "Death";
}

void MainWindow::handleStorage(t_application *app, t_program *program, int index, int size) {
	MainWindow *window = static_cast<MainWindow*>(app->qt_data);
	
	CorewarRenderer *renderer = window->m_glWidget->corewarRenderer();
	renderer->memoryStored(program->index, index, size);
	
	qDebug() << "Memory stored for player" << program->index << "at index:" << index << "and size:" << size;
}


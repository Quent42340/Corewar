/*
 * =====================================================================================
 *
 *       Filename:  MainWindow.hpp
 *
 *    Description:  
 *
 *        Created:  23/02/2016 18:13:55
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MAINWINDOW_HPP_
#define MAINWINDOW_HPP_

#include <QMainWindow>
#include <QMap>

extern "C" {
#include "application.h"
}

#include "MediaPlayer.hpp"

class GLWidget;
class SideBar;

class MainWindow : public QMainWindow {
	Q_OBJECT
	
	public:
		MainWindow(t_application &app);
		
		void initSideBar();
		
		void keyPressEvent(QKeyEvent *event);
		void keyReleaseEvent(QKeyEvent *event);
		
		static void handleDeath(t_application *app, t_program *program);
		static void handleStorage(t_application *app, t_program *program, int index, int size);
		
		static const unsigned int width = 1600;
		static const unsigned int height = 1000;
		
	private:
		MediaPlayer m_mediaPlayer;
		
		GLWidget *m_glWidget;
		SideBar *m_sideBar;
		
		QMap<int, bool> m_keys;
		
		t_application &m_app;
};

#endif // MAINWINDOW_HPP_

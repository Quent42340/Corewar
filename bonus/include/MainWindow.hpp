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

#include "application.h"

#include "MediaPlayer.hpp"
#include "SideBar.hpp"

class GLWidget;

class MainWindow : public QMainWindow {
	Q_OBJECT
	
	public:
		MainWindow(t_application &app);
		
		void keyPressEvent(QKeyEvent *event);
		void keyReleaseEvent(QKeyEvent *event);
		
		static const unsigned int width = 1600;
		static const unsigned int height = 1000;
		
	private:
		MediaPlayer m_mediaPlayer;
		
		GLWidget *m_widget;
		SideBar m_sideBar{&m_mediaPlayer};
		
		QMap<int, bool> m_keys;
		
		t_application &m_app;
};

#endif // MAINWINDOW_HPP_

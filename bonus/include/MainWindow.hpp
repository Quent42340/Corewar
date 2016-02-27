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

class GLWidget;

class MainWindow : public QMainWindow {
	Q_OBJECT
	
	public:
		MainWindow();
		
		void keyPressEvent(QKeyEvent *event);
		void keyReleaseEvent(QKeyEvent *event);
		
		static const unsigned int width = 640;
		static const unsigned int height = 480;
		
	private:
		GLWidget *m_widget;
		
		QMap<int, bool> m_keys;
};

#endif // MAINWINDOW_HPP_

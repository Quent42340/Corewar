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
class PlayerWidget;

class MainWindow : public QMainWindow {
	Q_OBJECT
	
	public:
		MainWindow();
		
		void keyPressEvent(QKeyEvent *event);
		void keyReleaseEvent(QKeyEvent *event);
		
		static const unsigned int width = 1280;
		static const unsigned int height = 960;
		
	private:
		GLWidget *m_widget;
		PlayerWidget *m_playerWidget;
		
		QMap<int, bool> m_keys;
};

#endif // MAINWINDOW_HPP_

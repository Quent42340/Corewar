/*
 * =====================================================================================
 *
 *       Filename:  SideBar.hpp
 *
 *    Description:  
 *
 *        Created:  27/03/2016 15:21:35
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SIDEBAR_HPP_
#define SIDEBAR_HPP_

#include <QWidget>

class PlayerWidget;

class SideBar : public QWidget {
	Q_OBJECT
	
	public:
		SideBar(QWidget *parent = nullptr);
		
	private:
		PlayerWidget *m_playerWidgets[4];
};

#endif // SIDEBAR_HPP_

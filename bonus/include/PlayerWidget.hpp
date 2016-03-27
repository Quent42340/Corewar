/*
 * =====================================================================================
 *
 *       Filename:  PlayerWidget.hpp
 *
 *    Description:  
 *
 *        Created:  08/03/2016 19:58:59
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef PLAYERWIDGET_HPP_
#define PLAYERWIDGET_HPP_

#include <QGroupBox>
#include <QLabel>

#include "program.h"

class PlayerWidget : public QGroupBox {
	Q_OBJECT
	
	public:
		PlayerWidget(int playerID, QWidget *parent = nullptr);
		
	public slots:
		void updateInfo(t_program &program);
		
	private:
		QLabel m_commentLabel{"Empty comment"};
		QLabel m_processCountLabel{"0"};
		
		int m_playerID;
};

#endif // PLAYERWIDGET_HPP_

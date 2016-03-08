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

class PlayerWidget : public QWidget {
	public:
		PlayerWidget(QWidget *parent = nullptr);
		
	private:
		QGroupBox m_groupBox{"Player 1", this};
};

#endif // PLAYERWIDGET_HPP_

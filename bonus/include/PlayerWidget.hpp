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

class PlayerWidget : public QGroupBox {
	Q_OBJECT
	
	public:
		PlayerWidget(int playerID, QWidget *parent = nullptr);
		
	public slots:
		void updateInfo(int playerID, int processCount, int memoryOwned);
		
	private:
		QLabel m_processCountLabel{"0"};
		QLabel m_memoryOwnedLabel{"0"};
		
		int m_playerID;
};

#endif // PLAYERWIDGET_HPP_

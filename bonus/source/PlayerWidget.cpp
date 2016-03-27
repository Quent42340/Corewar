/*
 * =====================================================================================
 *
 *       Filename:  PlayerWidget.cpp
 *
 *    Description:  
 *
 *        Created:  08/03/2016 19:59:59
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <QGridLayout>

#include "PlayerWidget.hpp"

PlayerWidget::PlayerWidget(int playerID, QWidget *parent) : QGroupBox(parent) {
	m_playerID = playerID;
	setTitle("Player " + QString::number(m_playerID + 1));
	
	QGridLayout *layout = new QGridLayout(this);
	layout->addWidget(new QLabel("Processes: "), 0, 0);
	layout->addWidget(new QLabel("Memory owned: "), 1, 0);
	layout->addWidget(&m_processCountLabel, 0, 1, Qt::AlignRight);
	layout->addWidget(&m_memoryOwnedLabel, 1, 1, Qt::AlignRight);
}

void PlayerWidget::updateInfo(int playerID, int processCount, int memoryOwned) {
	if (playerID == m_playerID) {
		m_processCountLabel.setNum(processCount);
		m_memoryOwnedLabel.setNum(memoryOwned);
	}
}


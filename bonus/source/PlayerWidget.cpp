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
#include <QLabel>
#include <QVBoxLayout>

#include "PlayerWidget.hpp"

PlayerWidget::PlayerWidget(int playerID, QWidget *parent) : QWidget(parent) {
	m_playerID = playerID;
	m_groupBox.setTitle("Player " + QString::number(m_playerID));
	
	QVBoxLayout *layout = new QVBoxLayout(&m_groupBox);
	layout->addWidget(new QLabel("Processes: "));
	layout->addWidget(new QLabel("Memory owned: "));
}


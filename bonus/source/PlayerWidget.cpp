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
#include <QGridLayout>

#include "PlayerWidget.hpp"

PlayerWidget::PlayerWidget(int playerID, QWidget *parent) : QGroupBox(parent) {
	m_playerID = playerID;
	setTitle("Player " + QString::number(m_playerID));
	
	QGridLayout *layout = new QGridLayout(this);
	layout->addWidget(new QLabel("Processes: "), 0, 0);
	layout->addWidget(new QLabel("Memory owned: "), 1, 0);
	layout->addWidget(new QLabel("0"), 0, 1, Qt::AlignRight);
	layout->addWidget(new QLabel("0"), 1, 1, Qt::AlignRight);
}


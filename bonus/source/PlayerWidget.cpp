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

PlayerWidget::PlayerWidget(QWidget *parent) : QWidget(parent) {
	QVBoxLayout *layout = new QVBoxLayout(&m_groupBox);
	layout->addWidget(new QLabel("Processes: "));
	layout->addWidget(new QLabel("Memory owned: "));
}


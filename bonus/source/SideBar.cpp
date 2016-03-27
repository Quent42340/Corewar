/*
 * =====================================================================================
 *
 *       Filename:  SideBar.cpp
 *
 *    Description:  
 *
 *        Created:  27/03/2016 15:21:47
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <QVBoxLayout>

#include "MainWindow.hpp"
#include "PlayerWidget.hpp"
#include "SideBar.hpp"

SideBar::SideBar(QWidget *parent) : QWidget(parent) {
	QVBoxLayout *verticalLayout = new QVBoxLayout(this);
	
	setMinimumSize(MainWindow::width / 5, 0);
	
	for (int i = 0 ; i < 4 ; i++) {
		m_playerWidgets[i] = new PlayerWidget(i + 1, this);
		// m_playerWidgets[i]->setMinimumSize(MainWindow::width / 5, 0);
		verticalLayout->addWidget(m_playerWidgets[i]);
	}
}


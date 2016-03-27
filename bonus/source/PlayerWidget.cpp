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
	
	QFrame* line = new QFrame;
	line->setFrameShape(QFrame::HLine);
	line->setFrameShadow(QFrame::Sunken);
	
	QGridLayout *layout = new QGridLayout(this);
	layout->addWidget(&m_commentLabel, 0, 0, 1, 0);
	layout->addWidget(line, 1, 0, 1, 2);
	layout->addWidget(new QLabel("Processes: "), 2, 0);
	layout->addWidget(&m_processCountLabel, 2, 1, Qt::AlignRight);
}

void PlayerWidget::updateInfo(t_program &program) {
	if (program.index == m_playerID) {
		setTitle(program.info.prog_name);
		m_commentLabel.setText(program.info.comment);
		m_processCountLabel.setNum(program.process_amount);
	}
}


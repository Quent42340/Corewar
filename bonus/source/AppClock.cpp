/*
 * =====================================================================================
 *
 *       Filename:  AppClock.cpp
 *
 *    Description:  
 *
 *        Created:  27/02/2016 15:18:20
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <QThread>

#include "AppClock.hpp"

QTime AppClock::time;
u32 AppClock::ticks = 0;

AppClock::AppClock() {
	time.start();
}

u32 AppClock::getTicks(bool realTime) {
	if(realTime) {
		return time.elapsed();
	} else {
		return ticks;
	}
}

void AppClock::measureLastFrameDuration() {
	u32 now = getTicks(true) - m_timeDropped;
	u32 lastFrameDuration = now - m_lastFrameDate;
	
	m_lastFrameDate = now;
	m_lag += lastFrameDuration;
	
	if(m_lag >= 200) {
		m_timeDropped += m_lag - m_timestep;
		m_lag = m_timestep;
		m_lastFrameDate = getTicks(true) - m_timeDropped;
	}
}

void AppClock::update(std::function<void(void)> updateFunc) {
	m_numUpdates = 0;
	
	while(m_lag >= m_timestep && m_numUpdates < 10) {
		ticks += m_timestep;
		
		updateFunc();
		
		m_lag -= m_timestep;
		m_numUpdates++;
	}
}

void AppClock::draw(std::function<void(void)> drawFunc) {
	if(m_numUpdates > 0) {
		drawFunc();
	}
	
	u32 lastFrameDuration = getTicks(true) - m_timeDropped - m_lastFrameDate;
	
	if(lastFrameDuration < m_timestep) {
		QThread::msleep(m_timestep - lastFrameDuration);
	}
	
	measureLastFrameDuration();
}


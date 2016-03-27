/*
 * =====================================================================================
 *
 *       Filename:  AppClock.hpp
 *
 *    Description:  
 *
 *        Created:  27/02/2016 15:16:30
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef APPCLOCK_HPP_
#define APPCLOCK_HPP_

#include <functional>

#include <QTime>

#include "IntTypes.hpp"

class AppClock {
	public:
		AppClock();
		
		static u32 getTicks(bool realTime = false);
		
		void measureLastFrameDuration();
		
		void update(std::function<void(void)> updateFunc);
		
		void draw(std::function<void(void)> drawFunc);
		
	private:
		static QTime time;
		static u32 ticks;
		
		u32 m_lastFrameDate = 0;
		u32 m_lag = 0;
		u32 m_timeDropped = 0;
		u32 m_lastFrameDuration = 0;
		
		u8 m_timestep = 6;
		u8 m_numUpdates = 0;
};

#endif // APPCLOCK_HPP_

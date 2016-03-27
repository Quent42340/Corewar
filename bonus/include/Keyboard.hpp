/*
 * =====================================================================================
 *
 *       Filename:  Keyboard.hpp
 *
 *    Description:  
 *
 *        Created:  26/02/2016 16:19:15
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef KEYBOARD_HPP_
#define KEYBOARD_HPP_

#include <QMap>

class Keyboard {
	public:
		static bool isKeyPressed(int key);
		
		static void onKeyPressed(int key);
		static void onKeyReleased(int key);
		
		static void setKeyMap(QMap<int, bool> *keyMap);
		
	private:
		static QMap<int, bool> *keys;
};

#endif // KEYBOARD_HPP_

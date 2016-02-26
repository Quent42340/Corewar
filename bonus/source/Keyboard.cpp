/*
 * =====================================================================================
 *
 *       Filename:  Keyboard.cpp
 *
 *    Description:  
 *
 *        Created:  26/02/2016 16:21:57
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Keyboard.hpp"

QMap<int, bool> *Keyboard::keys = nullptr;

bool Keyboard::isKeyPressed(int key) {
	return (*keys)[key];
}

void Keyboard::onKeyPressed(int key) {
	(*keys)[key] = true;
}

void Keyboard::onKeyReleased(int key) {
	(*keys)[key] = false;
}

void Keyboard::setKeyMap(QMap<int, bool> *keyMap) {
	keys = keyMap;
}


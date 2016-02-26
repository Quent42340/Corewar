/*
 * =====================================================================================
 *
 *       Filename:  Camera.cpp
 *
 *    Description:  
 *
 *        Created:  25/02/2016 17:56:46
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Camera.hpp"
#include "Keyboard.hpp"

Camera::Camera() {
}

void Camera::update() {
	if (Keyboard::isKeyPressed(Qt::Key_Up)) {
		m_viewMatrix.translate(0, -1);
	}
	if (Keyboard::isKeyPressed(Qt::Key_Down)) {
		m_viewMatrix.translate(0, 1);
	}
	if (Keyboard::isKeyPressed(Qt::Key_Left)) {
		m_viewMatrix.translate(-1, 0);
	}
	if (Keyboard::isKeyPressed(Qt::Key_Right)) {
		m_viewMatrix.translate(1, 0);
	}
}


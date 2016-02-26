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
	float direction = -1;
	
	if (Keyboard::isKeyPressed(Qt::Key_Up))    m_angleV += 0.5f;
	if (Keyboard::isKeyPressed(Qt::Key_Down))  m_angleV -= 0.5f;
	if (Keyboard::isKeyPressed(Qt::Key_Left))  m_angleH -= 0.5f;
	if (Keyboard::isKeyPressed(Qt::Key_Right)) m_angleH += 0.5f;
	if (Keyboard::isKeyPressed(Qt::Key_Z))     direction = 0.0f;
	if (Keyboard::isKeyPressed(Qt::Key_S))     direction = 180.0f;
	if (Keyboard::isKeyPressed(Qt::Key_Q))     direction = -90.0f;
	if (Keyboard::isKeyPressed(Qt::Key_D))     direction = 90.0f;
	if (Keyboard::isKeyPressed(Qt::Key_R))     m_v.setY(1);
	if (Keyboard::isKeyPressed(Qt::Key_F))     m_v.setY(-1);
	
	while(m_angleH >= 180.0) {
		m_angleH -= 360.0;
	}
	while(m_angleH < -180.0) {
		m_angleH += 360.0;
	}
	
	if(m_angleV > 89.9) {
		m_angleV = 89.9;
	}
	else if(m_angleV < -89.9) {
		m_angleV = -89.9;
	}
	
	if (direction != -1) {
		m_v.setX(cos((direction + m_angleH) * M_PI / 180.0f));
		m_v.setZ(sin((direction + m_angleH) * M_PI / 180.0f));
	}
	
	m_pos += m_v;
	m_v = QVector3D(0, 0, 0);
	
	m_viewMatrix.setToIdentity();
	m_viewMatrix.lookAt(m_pos,
	                    QVector3D(pointTargetedX(), pointTargetedY(), pointTargetedZ()),
						QVector3D(0, 1, 0));
}


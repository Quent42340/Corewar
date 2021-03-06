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
#include "CorewarRenderer.hpp"
#include "Keyboard.hpp"
#include "Panel.hpp"

Camera::Camera() {
	m_viewMatrix.lookAt(m_pos,
				QVector3D(pointTargetedX(), pointTargetedY(), pointTargetedZ()),
				QVector3D(0, 1, 0));
}

void Camera::update() {
	float direction = -1;
	bool angleChanged = false;
	
	if (Keyboard::isKeyPressed(Qt::Key_O)) { m_angleV += 0.3f; angleChanged = true; }
	if (Keyboard::isKeyPressed(Qt::Key_K)) { m_angleH -= 0.3f; angleChanged = true; }
	if (Keyboard::isKeyPressed(Qt::Key_L)) { m_angleV -= 0.3f; angleChanged = true; }
	if (Keyboard::isKeyPressed(Qt::Key_M)) { m_angleH += 0.3f; angleChanged = true; }
	
	if (Keyboard::isKeyPressed(Qt::Key_Z)) direction = 0.0f;
	if (Keyboard::isKeyPressed(Qt::Key_S)) direction = 180.0f;
	if (Keyboard::isKeyPressed(Qt::Key_Q)) direction = -90.0f;
	if (Keyboard::isKeyPressed(Qt::Key_D)) direction = 90.0f;
	
	if (Keyboard::isKeyPressed(Qt::Key_R)) m_v.setY(0.05);
	if (Keyboard::isKeyPressed(Qt::Key_F)) m_v.setY(-0.05);
	
	while (m_angleH >= 180.0) {
		m_angleH -= 360.0;
	}
	while (m_angleH < -180.0) {
		m_angleH += 360.0;
	}
	
	if (m_angleV > 89.9) {
		m_angleV = 89.9;
	}
	else if (m_angleV < -89.9) {
		m_angleV = -89.9;
	}
	
	if (direction != -1) {
		m_v.setX(0.16 * cos((direction + m_angleH) * M_PI / 180.0f));
		m_v.setZ(0.16 * sin((direction + m_angleH) * M_PI / 180.0f));
	}
	
	if (!m_v.isNull() || angleChanged) {
		m_pos += m_v;
		m_v = QVector3D(0, 0, 0);
	}
	
	m_viewMatrix.setToIdentity();
	m_viewMatrix.lookAt(m_pos,
			QVector3D(pointTargetedX(), pointTargetedY(), pointTargetedZ()),
			QVector3D(0, 1, 0));
}

void Camera::updateMovement() {
	float boardWidth = (Panel::width + 0.001) * CorewarRenderer::size - Panel::height;
	float boardDepth = (Panel::depth + 0.001) * CorewarRenderer::size - Panel::height;
	
	m_movementAngle += 0.06;
	
	m_pos = QVector3D(boardWidth * 1.1 * cos(m_movementAngle * M_PI / 180.0f) + boardWidth / 2, m_pos.y(),
	                  boardDepth * 1.1 * sin(m_movementAngle * M_PI / 180.0f) + boardWidth / 2);
	
	m_viewMatrix.setToIdentity();
	m_viewMatrix.lookAt(m_pos,
	        QVector3D(boardWidth / 2, 0, boardDepth / 2),
	        QVector3D(0, 1, 0));
}


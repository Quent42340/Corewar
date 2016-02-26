/*
 * =====================================================================================
 *
 *       Filename:  Camera.hpp
 *
 *    Description:  
 *
 *        Created:  25/02/2016 17:56:24
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include <QMatrix4x4>

class Camera {
	public:
		Camera();
		
		void update();
		
		float pointTargetedX() const { return m_pos.x() + cos(m_angleH * M_PI / 180.0f) * cos(m_angleV * M_PI / 180.0f); }
		float pointTargetedY() const { return m_pos.y() + sin(m_angleV * M_PI / 180.0f); }
		float pointTargetedZ() const { return m_pos.z() + sin(m_angleH * M_PI / 180.0f) * cos(m_angleV * M_PI / 180.0f) - 0.00001; }
		
		const QMatrix4x4 &viewMatrix() const { return m_viewMatrix; }
		
	private:
		QVector3D m_pos{320, 500, 960};
		QVector3D m_v{0, 0, 0};
		
		float m_angleH = -90.0f;
		float m_angleV = -30.0f;
		
		QMatrix4x4 m_viewMatrix;
};

#endif // CAMERA_HPP_

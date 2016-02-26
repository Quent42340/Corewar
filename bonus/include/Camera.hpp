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
		
		const QMatrix4x4 &viewMatrix() const { return m_viewMatrix; }
		
	private:
		QMatrix4x4 m_viewMatrix;
};

#endif // CAMERA_HPP_

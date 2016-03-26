/*
 * =====================================================================================
 *
 *       Filename:  CorewarRenderer.hpp
 *
 *    Description:  
 *
 *        Created:  25/02/2016 15:32:16
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef COREWARRENDERER_HPP_
#define COREWARRENDERER_HPP_

#include <array>

#include "Panel.hpp"

class Camera;

class CorewarRenderer {
	public:
		CorewarRenderer();
		
		void draw(QOpenGLShaderProgram &shader, Camera &camera);
		
		void reactToMusic(float n);
		
	private:
		std::vector<Panel> m_panels;
		
		float m_maxDistance = 0;
};

#endif // COREWARRENDERER_HPP_

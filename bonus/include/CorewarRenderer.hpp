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
		
	private:
		std::vector<Panel> m_panels;
};

#endif // COREWARRENDERER_HPP_

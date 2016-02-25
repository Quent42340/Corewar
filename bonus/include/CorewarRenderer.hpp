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

#include "Panel.hpp"

class CorewarRenderer {
	public:
		void draw(QOpenGLShaderProgram &shader);
		
	private:
		Panel m_panel1{0, 0};
		Panel m_panel2{1, 0};
		Panel m_panel3{0, 1};
		Panel m_panel4{1, 1};
};

#endif // COREWARRENDERER_HPP_

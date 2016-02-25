/*
 * =====================================================================================
 *
 *       Filename:  CorewarRenderer.cpp
 *
 *    Description:  
 *
 *        Created:  25/02/2016 15:32:30
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */

#include "CorewarRenderer.hpp"

void CorewarRenderer::draw(QOpenGLShaderProgram &shader) {
	m_panel1.draw(shader);
	m_panel2.draw(shader);
	m_panel3.draw(shader);
	m_panel4.draw(shader);
}


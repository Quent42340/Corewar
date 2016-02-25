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

CorewarRenderer::CorewarRenderer() {
	for (int x = 0 ; x < 5 ; ++x) {
		for (int y = 0 ; y < 5 ; ++y) {
			m_panels.emplace_back(x, y);
		}
	}
}

void CorewarRenderer::draw(QOpenGLShaderProgram &shader) {
	for (Panel &panel : m_panels) {
		panel.draw(shader);
	}
}


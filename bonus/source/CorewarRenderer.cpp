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
#include "Camera.hpp"
#include "CorewarRenderer.hpp"

CorewarRenderer::CorewarRenderer() {
	for (int x = 0 ; x < 32 ; ++x) {
		for (int y = 0 ; y < 25 ; ++y) {
			m_panels.emplace_back(x, y);
		}
	}
}

void CorewarRenderer::draw(QOpenGLShaderProgram &shader, Camera &camera) {
	shader.setUniformValue("u_viewMatrix", camera.viewMatrix());
	
	for (Panel &panel : m_panels) {
		panel.draw(shader);
	}
}


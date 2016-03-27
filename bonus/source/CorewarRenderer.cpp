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
	for (int y = 0 ; y < size ; ++y) {
		for (int x = 0 ; x < size ; ++x) {
			m_panels.emplace_back(x, y);
		}
	}
}

void CorewarRenderer::initPanels() {
	for (Panel &panel : m_panels)
		panel.init();
}

void CorewarRenderer::draw(QOpenGLShaderProgram &shader, Camera &camera) {
	shader.setUniformValue("u_viewMatrix", camera.viewMatrix());
	
	for (Panel &panel : m_panels) {
		panel.draw(shader);
	}
}

void CorewarRenderer::reactToMusic(float n) {
	for (Panel &panel : m_panels) {
		float distanceFromCenter = sqrt(pow(size / 2 - (int)panel.x(), 2) + pow(size / 2 - (int)panel.y(), 2));
		m_maxDistance = (m_maxDistance > distanceFromCenter) ? m_maxDistance : distanceFromCenter;
		
		panel.setScale(1.0f + fabs(m_maxDistance - distanceFromCenter * n * 4));
	}
}

void CorewarRenderer::memoryStored(int playerID, int index, int size) {
	Color colors[5] = {
		Color::red,
		Color::blue,
		Color::green,
		Color::cyan,
		Color::black
	};
	
	for (int i = index ; i < index + size ; ++i) {
		m_panels[i].updateColor(colors[playerID]);
	}
}

void CorewarRenderer::playerDead(int playerID) {
	(void)playerID;
}


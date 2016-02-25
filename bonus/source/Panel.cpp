/*
 * =====================================================================================
 *
 *       Filename:  Panel.cpp
 *
 *    Description:  
 *
 *        Created:  24/02/2016 14:18:17
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <QDebug>

#include "Panel.hpp"

Panel::Panel() {
	float points[] = {
		100.0f, 20.0f, 0.0f, 1.0f,
		75.0f, 75.0f, 0.0f, 1.0f,
		125.0f, 75.0f, 0.0f, 1.0f
	};
	
	m_vertexBuffer.create();
	m_vertexBuffer.setUsagePattern(QOpenGLBuffer::DynamicDraw);
	m_vertexBuffer.bind();
	m_vertexBuffer.allocate(points, 3 * 4 * sizeof(float));
}

void Panel::draw(QOpenGLShaderProgram &shader) {
	shader.setAttributeBuffer("vertex", GL_FLOAT, 0, 4);
	shader.enableAttributeArray("vertex");
	
	glDrawArrays(GL_TRIANGLES, 0, 3);
	
	shader.disableAttributeArray("vertex");
}


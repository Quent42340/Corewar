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
	GLfloat points[] = {
		0.0f,  0.0f,   0.0f,
		width, 0.0f,   0.0f,
		0.0f,  height, 0.0f,
		width, height, 0.0f,
	};
	
	GLfloat colors[] = {
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 1.0f
	};
	
	m_vertexBuffer.create();
	m_vertexBuffer.setUsagePattern(QOpenGLBuffer::DynamicDraw);
	m_vertexBuffer.bind();
	m_vertexBuffer.allocate(points, 2 * 6 * 3 * sizeof(GLfloat));
	m_vertexBuffer.write(6 * 3 * sizeof(GLfloat), colors, 6 * 3 * sizeof(GLfloat));
}

void Panel::draw(QOpenGLShaderProgram &shader) {
	GLubyte indices[] = {
		0, 1, 2,
		2, 1, 3
	};
	
	shader.setAttributeBuffer("vertex", GL_FLOAT, 0, 3);
	shader.setAttributeBuffer("color", GL_FLOAT, 6 * 3 * sizeof(GLfloat), 3);
	
	shader.enableAttributeArray("vertex");
	shader.enableAttributeArray("color");
	
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, indices);
	
	shader.disableAttributeArray("color");
	shader.disableAttributeArray("vertex");
}


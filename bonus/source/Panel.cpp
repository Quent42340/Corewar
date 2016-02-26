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

Panel::Panel(unsigned int x, unsigned int y) {
	GLfloat points[] = {
		0.0f,  0.0f, 0.0f,
		width, 0.0f, 0.0f,
		0.0f,  0.0f, height,
		width, 0.0f, height,
	};
	
	GLfloat colors[] = {
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 1.0f
	};
	
	m_x = x;
	m_y = y;
	
	m_vertexBuffer.create();
	m_vertexBuffer.setUsagePattern(QOpenGLBuffer::DynamicDraw);
	m_vertexBuffer.bind();
	m_vertexBuffer.allocate(points, 2 * 6 * 3 * sizeof(GLfloat));
	m_vertexBuffer.write(6 * 3 * sizeof(GLfloat), colors, 6 * 3 * sizeof(GLfloat));
	
	m_modelMatrix.translate(m_x * (width + 2), 0.0f, m_y * (height + 2));
}

#include <cmath>

void Panel::draw(QOpenGLShaderProgram &shader) {
	// FIXME: Maybe I should use an IBO here
	GLubyte indices[] = {
		2, 1, 0,
		3, 1, 2
	};
	
	// m_modelMatrix.rotate(rand() % 4, 0, 1, 0);
	// m_modelMatrix.translate(rand() % 2, 0, rand() % 2);
	// m_modelMatrix.translate(-(rand() % 2), 0, -(rand() % 2));
	
	shader.setUniformValue("u_modelMatrix", m_modelMatrix);
	
	shader.setAttributeBuffer("vertex", GL_FLOAT, 0, 3);
	shader.setAttributeBuffer("color", GL_FLOAT, 6 * 3 * sizeof(GLfloat), 3);
	
	shader.enableAttributeArray("vertex");
	shader.enableAttributeArray("color");
	
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, indices);
	
	shader.disableAttributeArray("color");
	shader.disableAttributeArray("vertex");
}


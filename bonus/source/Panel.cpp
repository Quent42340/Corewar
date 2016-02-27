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
		0.0f,  10.0f, 0.0f,
		width, 10.0f, 0.0f,
		0.0f,  10.0f, depth,
		width, 10.0f, depth,
		
		0.0f,  0.0f, 0.0f,
		width, 0.0f, 0.0f,
		0.0f,  0.0f, depth,
		width, 0.0f, depth,
	};
	
	GLfloat colors[] = {
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 1.0f,
		
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
	m_vertexBuffer.allocate(points, 4 * 6 * 3 * sizeof(GLfloat));
	m_vertexBuffer.write(2 * 6 * 3 * sizeof(GLfloat), colors, 2 * 6 * 3 * sizeof(GLfloat));
	
	m_modelMatrix.translate(m_x * (width + 10), 0.0f, m_y * (depth + 10));
}

#include <cmath>

void Panel::draw(QOpenGLShaderProgram &shader) {
	// FIXME: Maybe I should use an IBO here
	GLubyte indices[] = {
		// y > 0
		2, 1, 0,
		3, 1, 2, 
		
		// y < 0
		4, 5, 6,
		6, 5, 7,
		
		// x < 0
		4, 2, 0,
		2, 4, 6,
		
		// x > 0
		1, 3, 5,
		7, 5, 3,
		
		// z < 0
		0, 1, 4,
		4, 1, 5,
		
		// z > 0
		6, 3, 2,
		7, 3, 6,
	};
	
	// m_modelMatrix.rotate(rand() % 4, 0, 0, 1);
	// m_modelMatrix.translate(rand() % 2, 0, rand() % 2);
	// m_modelMatrix.translate(-(rand() % 2), 0, -(rand() % 2));
	
	shader.setUniformValue("u_modelMatrix", m_modelMatrix);
	
	shader.setAttributeBuffer("vertex", GL_FLOAT, 0, 3);
	shader.setAttributeBuffer("color", GL_FLOAT, 2 * 6 * 3 * sizeof(GLfloat), 3);
	
	shader.enableAttributeArray("vertex");
	shader.enableAttributeArray("color");
	
	glDrawElements(GL_TRIANGLES, 6 * 6, GL_UNSIGNED_BYTE, indices);
	
	shader.disableAttributeArray("color");
	shader.disableAttributeArray("vertex");
}


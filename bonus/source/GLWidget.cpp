/*
 * =====================================================================================
 *
 *       Filename:  GLWidget.cpp
 *
 *    Description:  
 *
 *        Created:  23/02/2016 19:00:29
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "GLWidget.hpp"

void GLWidget::initializeGL() {
	initializeOpenGLFunctions();
	
	glEnable(GL_DEPTH_TEST);
	
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	
	if (!prepareShaderProgram("shaders/core.v.glsl", "shaders/core.f.glsl")) {
		qCritical() << "Error: Could not load shaders";
		return;
	}
	
	if (!m_shader.bind()) {
		qWarning() << "Warning: Could not bind shader program to context";
		return;
	}
	
	m_vao.create();
	m_vao.bind();
	
	float points[] = {
		100.0f, 20.0f, 0.0f, 1.0f,
		75.0f, 75.0f, 0.0f, 1.0f,
		125.0f, 75.0f, 0.0f, 1.0f
	};
	
	m_vertexBuffer.create();
	m_vertexBuffer.setUsagePattern(QOpenGLBuffer::DynamicDraw);
	if (!m_vertexBuffer.bind()) {
		qWarning() << "Warning: Could not bind vertex buffer to the context";
		return;
	}
	
	m_vertexBuffer.allocate(points, 3 * 4 * sizeof(float));
	
	m_shader.setAttributeBuffer("vertex", GL_FLOAT, 0, 4);
	m_shader.enableAttributeArray("vertex");
	
	m_projMatrix.ortho(0.0f, width(), height(), 0.0f, -1.0f, 1.0f);
}

void GLWidget::resizeGL(int width, int height) {
	glViewport(0, 0, width, height);
	
	m_projMatrix.setToIdentity();
	m_projMatrix.ortho(0.0f, width, height, 0.0f, -1.0f, 1.0f);
}

void GLWidget::paintGL() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	m_shader.setUniformValue("u_projectionMatrix", m_projMatrix);
	
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

bool GLWidget::prepareShaderProgram(const QString &vertexShaderPath, const QString &fragmentShaderPath) {
	bool result = m_shader.addShaderFromSourceFile(QOpenGLShader::Vertex, vertexShaderPath);
	if (!result)
		qWarning() << "Warning: " << m_shader.log();
	
	result = m_shader.addShaderFromSourceFile(QOpenGLShader::Fragment, fragmentShaderPath);
	if (!result)
		qWarning() << "Warning: " << m_shader.log();
	
	result = m_shader.link();
	if (!result)
		qWarning() << "Warning: Could not link shader program:" << m_shader.log();
	
	return result;
}


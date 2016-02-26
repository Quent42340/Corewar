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
#include "CorewarRenderer.hpp"
#include "GLWidget.hpp"

void GLWidget::initializeGL() {
	initializeOpenGLFunctions();
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	glEnable(GL_TEXTURE_2D);
	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	
	// glClearColor(0.196078, 0.6, 0.8, 1.0); // Skyblue
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
	
	m_renderer.reset(new CorewarRenderer);
	
	// m_projMatrix.ortho(0.0f, width(), height(), 0.0f, -1.0f, 1.0f);
	m_projMatrix.perspective(45.0f, 640.0f / 480.0f, 0.1f, 1000.0f);
	m_shader.setUniformValue("u_projectionMatrix", m_projMatrix);

	startTimer(1000 / 60);
}

void GLWidget::timerEvent(QTimerEvent *) {
	m_camera.update();
	
	update();
}

void GLWidget::resizeGL(int width, int height) {
	glViewport(0, 0, width, height);
	
	m_projMatrix.setToIdentity();
	// m_projMatrix.ortho(0.0f, width, height, 0.0f, -1.0f, 1.0f);
	m_projMatrix.perspective(45.0f, 640.0f / 480.0f, 0.1f, 1000.0f);
	m_shader.setUniformValue("u_projectionMatrix", m_projMatrix);
}

void GLWidget::paintGL() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	m_renderer->draw(m_shader, m_camera);
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


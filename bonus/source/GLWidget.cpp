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
extern "C" {
#include "run.h"
}

#include "AppClock.hpp"
#include "CorewarRenderer.hpp"
#include "GLWidget.hpp"

void GLWidget::initializeGL() {
	initializeOpenGLFunctions();
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	glEnable(GL_TEXTURE_2D);
	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	
	glHint(GL_GENERATE_MIPMAP_HINT, GL_NICEST);
	
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
	
	m_projMatrix.perspective(45.0f, width() / float(height()), 0.01f, 1000.0f);
	m_shader.setUniformValue("u_projectionMatrix", m_projMatrix);
	
	m_timer.start();
	connect(&m_timer, SIGNAL(timeout()), this, SLOT(process()));
}

void GLWidget::process() {
	m_clock.update([&] {
		tick(&m_app);
		
		// m_camera.update();
		m_camera.updateMovement();
	});
	
	m_clock.draw([&] {
		update();
	});
}

void GLWidget::processAudioBuffer(const QAudioBuffer &buffer) {
	const qint16 *data = buffer.constData<qint16>();
	
	qint64 sum = 0;
	for(int i = buffer.frameCount() - 101 ; i < buffer.frameCount() ; ++i) {
		sum += pow(data[i], 2);
	}
	
	sum /= 100;
	sum = sqrt(sum);
	
	m_renderer->reactToMusic((float(sum) + INT16_MAX + 1) / UINT16_MAX);
}

void GLWidget::resizeGL(int width, int height) {
	glViewport(0, 0, width, height);
	
	m_projMatrix.setToIdentity();
	m_projMatrix.perspective(45.0f, width / float(height), 0.01f, 1000.0f);
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


/*
 * =====================================================================================
 *
 *       Filename:  GLWidget.hpp
 *
 *    Description:  
 *
 *        Created:  23/02/2016 18:59:34
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef GLWIDGET_HPP_
#define GLWIDGET_HPP_

#include <memory>

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLWidget>

#include <QAudioBuffer>
#include <QTimer>

#include "application.h"

#include "AppClock.hpp"
#include "Camera.hpp"

class CorewarRenderer;

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions {
	Q_OBJECT
	
	public:
		GLWidget(t_application &app, QWidget *parent = nullptr);
		
		const t_application &app() const { return m_app; }
		
		CorewarRenderer *corewarRenderer() const { return m_renderer.get(); }
		
		void setFreeMovement(bool freeMovement) { m_freeMovement = freeMovement; }
		
	signals:
		void kikooModeStateUpdated(int state);
		void programUpdated(t_program &program);
		
	public slots:
		void process();
		void processAudioBuffer(const QAudioBuffer &buffer);
		
	protected:
		virtual void initializeGL();
		virtual void resizeGL(int width, int height);
		virtual void paintGL();
		
	private:
		bool prepareShaderProgram(const QString &vertexShaderPath, const QString &fragmentShaderPath);
		
		QMatrix4x4 m_projMatrix;
		
		QOpenGLVertexArrayObject m_vao;
		QOpenGLShaderProgram m_shader;
		
		Camera m_camera;
		std::shared_ptr<CorewarRenderer> m_renderer{nullptr};
		
		AppClock m_clock;
		QTimer m_timer;
		
		t_application &m_app;
		bool m_isAppRunning = true;
		
		bool m_freeMovement = false;
};

#endif // GLWIDGET_HPP_

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

#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLWidget>

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions {
	Q_OBJECT
	
	public:
		GLWidget(QWidget *parent = nullptr)
			: QOpenGLWidget(parent), m_vertexBuffer(QOpenGLBuffer::VertexBuffer) {}
	
	protected:
		virtual void initializeGL();
		virtual void resizeGL(int width, int height);
		virtual void paintGL();
	
	private:
		bool prepareShaderProgram(const QString &vertexShaderPath, const QString &fragmentShaderPath);
		
		QOpenGLVertexArrayObject m_vao;
		QOpenGLShaderProgram m_shader;
		QOpenGLBuffer m_vertexBuffer;
		QMatrix4x4 m_projMatrix;
};

#endif // GLWIDGET_HPP_

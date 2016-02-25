/*
 * =====================================================================================
 *
 *       Filename:  Panel.hpp
 *
 *    Description:  
 *
 *        Created:  24/02/2016 14:17:52
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef PANEL_HPP_
#define PANEL_HPP_

#include <QOpenGLBuffer>
#include <QOpenGLShader>

class Panel {
	public:
		Panel(unsigned int x, unsigned int y);
		
		void draw(QOpenGLShaderProgram &shader);
		
		static constexpr GLfloat width = 50.0f;
		static constexpr GLfloat height = 50.0f;
		
	private:
		QOpenGLBuffer m_vertexBuffer{QOpenGLBuffer::VertexBuffer};
		QMatrix4x4 m_modelMatrix;
		
		unsigned int m_x;
		unsigned int m_y;
};

#endif // PANEL_HPP_

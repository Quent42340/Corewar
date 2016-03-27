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

#include "Color.hpp"

class Panel {
	public:
		Panel(unsigned int x, unsigned int y);
		
		void init();
		
		void updateVertices();
		void updateColor();
		
		void draw(QOpenGLShaderProgram &shader);
		
		unsigned int x() const { return m_x; }
		unsigned int y() const { return m_y; }
		
		void setColor(const Color &color) { m_color = color; }
		void setScale(float scale) { m_scale = scale; }
		
		static constexpr GLfloat width = 25.0f / 35.0f;
		static constexpr GLfloat height = 10.0f / 35.0f;
		static constexpr GLfloat depth = 35.0f / 35.0f;
		
	private:
		QOpenGLBuffer m_vertexBuffer{QOpenGLBuffer::VertexBuffer};
		QMatrix4x4 m_modelMatrix;
		
		unsigned int m_x;
		unsigned int m_y;
		
		Color m_color{Color::text};
		
		float m_scale = 1.0f;
};

#endif // PANEL_HPP_

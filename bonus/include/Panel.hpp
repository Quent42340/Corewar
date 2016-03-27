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
		void updateColor(const Color &color);
		
		void draw(QOpenGLShaderProgram &shader);
		
		unsigned int x() const { return m_x; }
		unsigned int y() const { return m_y; }
		
		int playerID() const { return m_playerID; }
		
		void setPlayerID(int playerID) { m_playerID = playerID; }
		void setScale(float scale) { if (m_scale != -1) m_scale = scale; }
		void setRandomColors(bool randomColors) { m_randomColors = randomColors; }
		
		// static constexpr GLfloat width = 25.0f / 35.0f;
		static constexpr GLfloat width = 35.0f / 35.0f;
		static constexpr GLfloat height = 10.0f / 35.0f;
		static constexpr GLfloat depth = 35.0f / 35.0f;
		
	private:
		QOpenGLBuffer m_vertexBuffer{QOpenGLBuffer::VertexBuffer};
		QMatrix4x4 m_modelMatrix;
		
		unsigned int m_x;
		unsigned int m_y;
		
		float m_scale = 1.0f;
		
		Color m_color = Color::text;
		
		bool m_randomColors = false;
		
		int m_playerID = -1;
};

#endif // PANEL_HPP_

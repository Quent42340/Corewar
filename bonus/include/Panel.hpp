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
		
		float scale() const { return m_scale; }
		
		const Color &color() const { return m_color; }
		
		bool isEnabled() const { return m_isEnabled; }
		int playerID() const { return m_playerID; }
		
		void setColor(const Color &color) { m_color = color; }
		void setDead(bool isDead) { m_isDead = isDead; }
		void setEnabled(bool isEnabled) { m_isEnabled = isEnabled; }
		void setPlayerID(int playerID) { m_playerID = playerID; }
		void setScale(float scale) { m_scale = scale; }
		void setRandomColors(bool randomColors) { m_randomColors = randomColors; }
		
		static constexpr GLfloat width = 35.0f / 35.0f;
		static constexpr GLfloat height = 10.0f / 35.0f;
		static constexpr GLfloat depth = 35.0f / 35.0f;
		
	private:
		QOpenGLBuffer m_vertexBuffer{QOpenGLBuffer::VertexBuffer};
		QMatrix4x4 m_modelMatrix;
		
		unsigned int m_x;
		unsigned int m_y;
		
		float m_scale = 1.0f;
		
		Color m_color = Color::cyan;
		
		bool m_isDead = false;
		bool m_randomColors = false;
		bool m_isEnabled = true;
		
		int m_playerID = -1;
};

#endif // PANEL_HPP_

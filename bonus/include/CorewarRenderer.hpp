/*
 * =====================================================================================
 *
 *       Filename:  CorewarRenderer.hpp
 *
 *    Description:  
 *
 *        Created:  25/02/2016 15:32:16
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef COREWARRENDERER_H_
# define COREWARRENDERER_H_

# include "Panel.hpp"

class CorewarRenderer {
	public:
		void draw(QOpenGLShaderProgram &shader);
		
	private:
		Panel m_panel;
};

#endif /* !COREWARRENDERER_H_ */

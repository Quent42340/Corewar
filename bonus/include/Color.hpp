/*
 * =====================================================================================
 *
 *       Filename:  Color.hpp
 *
 *    Description:  
 *
 *        Created:  27/02/2016 12:52:05
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef COLOR_HPP_
#define COLOR_HPP_

#include <GL/gl.h>

#include "IntTypes.hpp"

class Color {
	public:
		Color() = default;
		Color(u8 _r, u8 g, u8 _b, u8 _a = 255);
		
		Color operator-(const Color &color);
		
		bool operator==(const Color &color) {
			return r == color.r && g == color.g && b == color.b && a == color.a;
		}
		
		bool operator!=(const Color &color) {
			return !(*this == color);
		}
		
		GLfloat r = 1.0f;
		GLfloat g = 1.0f;
		GLfloat b = 1.0f;
		GLfloat a = 1.0f;
		
		static Color black;
		static Color white;
		static Color text;
		static Color blue;
		static Color red;
};

#endif // COLOR_HPP_

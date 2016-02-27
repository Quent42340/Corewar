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

#include <cinttypes>

class Color {
	public:
		Color() = default;
		Color(uint8_t _r, uint8_t g, uint8_t _b, uint8_t _a = 255);
		
		Color operator-(const Color &color);
		
		bool operator==(const Color &color) {
			return r == color.r && g == color.g && b == color.b && a == color.a;
		}
		
		bool operator!=(const Color &color) {
			return !(*this == color);
		}
		
		float r = 1.0f;
		float g = 1.0f;
		float b = 1.0f;
		float a = 1.0f;
		
		static Color black;
		static Color white;
		static Color text;
		static Color blue;
		static Color red;
};

#endif // COLOR_HPP_

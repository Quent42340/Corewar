/*
 * =====================================================================================
 *
 *       Filename:  Color.cpp
 *
 *    Description:  
 *
 *        Created:  27/02/2016 12:53:56
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Color.hpp"

Color Color::black(0, 0, 0);
Color Color::white(255, 255, 255);
Color Color::text(248, 208, 136);
Color Color::blue(32, 168, 248);
Color Color::red(232, 8, 24);

Color::Color(uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a) {
	r = _r / 255.0f;
	g = _g / 255.0f;
	b = _b / 255.0f;
	a = _a / 255.0f;
}

Color Color::operator-(const Color &color) {
	return Color(r - color.r, g - color.g, b - color.b, a - color.a);
}


/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Created:  23/02/2016 17:47:55
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */

#include <QApplication>

#include "MainWindow.hpp"

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	
	MainWindow window;
	window.show();
	
	return app.exec();
}


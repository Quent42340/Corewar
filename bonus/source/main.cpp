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

extern "C" {
#include "args.h"
}

#include "MainWindow.hpp"

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	t_application my_app;
	
	t_args args;
	int exit_code = 0;
	if (!args_init(&args, argv + 1)) {
		MainWindow window(my_app);
		my_app.qt_data = &window;
		
		args.death_callback = &MainWindow::handleDeath;
		args.st_callback = &MainWindow::handleStorage;
		
		if (!application_init(&my_app, &args)) {
			window.initSideBar();
			window.show();
			
			exit_code = app.exec();
		}
		
		application_free(&my_app);
	}
	
	args_free(&args);
	
	return exit_code;
}


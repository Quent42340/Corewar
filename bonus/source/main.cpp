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
	t_args args;
	t_application my_app;
	
	int exit_code = 0;
	if (!args_init(&args, argv + 1) && !application_init(&my_app, &args)) {
		args_free(&args);

		QApplication app(argc, argv);
		
		MainWindow window(my_app);
		window.show();
		
		exit_code = app.exec();

		application_free(&my_app);
	}
	
	return exit_code;
}


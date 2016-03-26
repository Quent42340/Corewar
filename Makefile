##
## Makefile for  in /blinux_home/bazin_q/rendu/gfx_incendie
## 
## Made by Quentin Bazin
## Login   <bazin_q@epitech.net>
## 
## Started on  Fri Dec 04 20:35:14 2015 Quentin Bazin
## Last update Sun Dec 06 14:15:56 2015 Quentin Bazin
##

SUBDIRS	= asm corewar

all:
	@for dir in $(SUBDIRS); do echo "Compiling $$dir..."; make --no-print-directory -C $$dir; echo; done

clean:
	@for dir in $(SUBDIRS); do echo "Cleaning $$dir..."; make --no-print-directory -C $$dir clean; [ $$dir != "corewar" ] && echo || echo -n; done

fclean:
	@for dir in $(SUBDIRS); do echo "Cleaning $$dir..."; make --no-print-directory -C $$dir fclean; [ $$dir != "corewar" ] && echo || echo -n; done

re:
	@for dir in $(SUBDIRS); do echo "Compiling $$dir..."; make --no-print-directory -C $$dir re; [ $$dir != "corewar" ] && echo || echo -n; done

lexer:
	@for dir in $(SUBDIRS); do echo "Compiling $$dir..."; make --no-print-directory -C $$dir lexer; [ $$dir != "corewar" ] && echo || echo -n; done

lexer_debug: LEXER_DEBUG = 1
lexer_debug: all

.PHONY: all clean fclean re lexer

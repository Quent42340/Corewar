#---------------------------------------------------------------------------------
# Executable name
#---------------------------------------------------------------------------------
TARGET		= 	launcher

QT_LIBS		=	Core Gui Multimedia OpenGL Widgets Network WebKit WebKitWidgets

#---------------------------------------------------------------------------------
# Compiler executables
#---------------------------------------------------------------------------------
CC			=	gcc
CXX			=	g++

#---------------------------------------------------------------------------------
# Compiler flags
#---------------------------------------------------------------------------------
DEFINES		+=	-DQT_NO_DEBUG \
				$(foreach lib,$(QT_LIBS),-DQT_$(shell echo lib | tr "[:lower:]" "[:upper:]")_LIB)

CFLAGS		=	-g -Wall -Wextra -Wfatal-errors -Wno-variadic-macros -pedantic -MD
CXXFLAGS	=	$(CFLAGS) -std=c++11 -static-libstdc++ -fPIC $(DEFINES)

#---------------------------------------------------------------------------------
# Libraries
#---------------------------------------------------------------------------------
LIBS		=	$(foreach lib,$(QT_LIBS),-lQt5$(lib)) -lGL -lmy_printf -lmy

#---------------------------------------------------------------------------------
# Source folders
#---------------------------------------------------------------------------------
find_rec	=	$(shell find $(1) -type d)

BUILD		=	build
SOURCES		=	source external $(call find_rec,source) ../common\
				../corewar/source $(call find_rec,../corewar/source)
INCLUDES	=	include external $(call find_rec,include) ../corewar/include \
				../corewar/lib/libmy/include ../corewar/lib/libmy_printf/include

#---------------------------------------------------------------------------------
# Some more include paths
#---------------------------------------------------------------------------------
CXXFLAGS	+=	-I/usr/share/qt/mkspecs/linux-g++ \
				-I/usr/include/qt \
				$(foreach lib,$(QT_LIBS),-I/usr/include/qt/Qt$(lib))

#---------------------------------------------------------------------------------
# Additional folders for libraries
#---------------------------------------------------------------------------------
LIBDIRS		= ../corewar/lib/libmy ../corewar/lib/libmy_printf

ifneq ($(BUILD),$(notdir $(CURDIR)))

#---------------------------------------------------------------------------------
# Source files
#---------------------------------------------------------------------------------
CFILES			=	address.c \
					args.c \
					application.c \
					error.c \
					flag_handler.c \
					init.c \
					program.c \
					read_helper.c \
					my_mem.c \
					my_convert.c \
					str.c \
					instructions_basic.c \
					instructions_calcul.c \
					instructions_fork.c \
					instructions_ld.c \
					instructions_st.c \
					messages.c \
					run.c \
					run2.c \
					vm_copy.c \
					op.c

CPPFILES		=	AppClock.cpp \
					Camera.cpp \
					Color.cpp \
					CorewarRenderer.cpp \
					GLWidget.cpp \
					Keyboard.cpp \
					MainWindow.cpp \
					MediaPlayer.cpp \
					Panel.cpp \
					PlayerWidget.cpp \
					SideBar.cpp \
					main.cpp

HPPFILES		=	AppClock.hpp \
					Camera.hpp \
					Color.hpp \
					CorewarRenderer.hpp \
					GLWidget.hpp \
					IntTypes.hpp \
					Keyboard.hpp \
					MainWindow.hpp \
					MediaPlayer.hpp \
					Panel.hpp \
					PlayerWidget.hpp \
					SideBar.hpp

export OUTPUT	=	$(CURDIR)/$(TARGET)

export VPATH	=	$(foreach dir,$(SOURCES),$(CURDIR)/$(dir)) \
					$(foreach dir,$(INCLUDES),$(CURDIR)/$(dir))

export OFILES	=	$(CFILES:.c=.o) $(CPPFILES:.cpp=.oxx) \
					$(HPPFILES:.hpp=.moc.o)

export INCLUDE	=	$(foreach dir,$(INCLUDES),-I$(CURDIR)/$(dir))

export LIBPATHS	=	$(foreach dir,$(LIBDIRS),-L$(CURDIR)/$(dir))

#---------------------------------------------------------------------------------
# Use CXX for linking C++ projects, CC for standard C
#---------------------------------------------------------------------------------
ifeq ($(strip $(CPPFILES)),)
	export LD	=	$(CC)
else
	export LD	=	$(CXX)
endif

#---------------------------------------------------------------------------------
# Makefile targets
#---------------------------------------------------------------------------------
$(BUILD):
	@[ -d $@ ] || mkdir -p $@
	@make --no-print-directory -C $(BUILD) -f $(CURDIR)/Makefile
	@[ -e TODO ] && echo "Don't forget to read the TODO file." || echo -n
	@fixmes="$(shell cat $(shell find . -name "*.cpp" -or -name "*.hpp") | grep FIXME | wc -l)" && [ "$$fixmes" != "0" ] && echo $$fixmes "fixme(s) remaining." || echo -n

run:
	@./$(TARGET) $(RUN_ARGS)

debug:
	@./$(TARGET) $(RUN_ARGS)

clean:
	@echo "Cleaning temporary build files..."
	@rm -rf $(BUILD)

fclean: clean
	@echo "Cleaning executable..."
	@rm -f $(TARGET)

re: fclean $(BUILD)

.PHONY: $(BUILD) run clean fclean re

#---------------------------------------------------------------------------------
else
#---------------------------------------------------------------------------------
all: $(OUTPUT)
	@echo "Done for $(notdir $(OUTPUT))."

$(OUTPUT): $(OFILES)
	@echo "Linking $(notdir $@)..."
	@$(LD) $(OFILES) $(LIBPATHS) $(LIBS) -o $@ $(CXXFLAGS)

%.o: %.c
	@echo "=>" $(notdir $<)
	@$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDE)

%.oxx: %.cpp
	@echo "=>" $(notdir $<)
	@$(CXX) -c $< -o $@ $(CXXFLAGS) $(INCLUDE)

%.moc.cpp: %.hpp
	@echo "=>" $(notdir $<)
	@moc $< $(DEFINES) $(INCLUDE) -o $@ --no-notes

%.moc.cpp: %.h
	@echo "=>" $(notdir $<)
	@moc $< $(DEFINES) $(INCLUDE) -o $@ --no-notes

%.moc.o: %.moc.cpp
	@echo "=>" $(notdir $<)
	@$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

-include *.d

.PRECIOUS: %.moc.cpp

#---------------------------------------------------------------------------------
endif
#---------------------------------------------------------------------------------

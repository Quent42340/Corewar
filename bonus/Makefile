#---------------------------------------------------------------------------------
# Executable name
#---------------------------------------------------------------------------------
TARGET		=  launcher

#---------------------------------------------------------------------------------
# Compiler executables
#---------------------------------------------------------------------------------
CC			=	gcc
CXX			=	g++

#---------------------------------------------------------------------------------
# Compiler flags
#---------------------------------------------------------------------------------
DEFINES		+=	-DQT_NO_DEBUG \
				-DQT_OPENGL_LIB \
				-DQT_WIDGETS_LIB \
				-DQT_GUI_LIB \
				-DQT_CORE_LIB \
				-DQT_MULTIMEDIA_LIB

CFLAGS		=	-g -Wall -Wextra -Wfatal-errors -Wno-variadic-macros -pedantic
CXXFLAGS	=	$(CFLAGS) -std=c++11 -static-libstdc++ -MD -fPIC $(DEFINES)

#---------------------------------------------------------------------------------
# Libraries
#---------------------------------------------------------------------------------
LIBS		=	-lQt5Multimedia -lQt5OpenGL -lQt5Widgets -lQt5Gui -lQt5Core -lGL

#---------------------------------------------------------------------------------
# Source folders
#---------------------------------------------------------------------------------
find_rec	=	$(shell find $(1) -type d)

BUILD		=	build
SOURCES		=	source external $(call find_rec,source)
INCLUDES	=	include external $(call find_rec,include)

#---------------------------------------------------------------------------------
# Some more include paths
#---------------------------------------------------------------------------------
CXXFLAGS	+=	-I/usr/share/qt/mkspecs/linux-g++ \
				-I/usr/include/qt \
				-I/usr/include/qt/QtCore \
				-I/usr/include/qt/QtGui \
				-I/usr/include/qt/QtMultimedia \
				-I/usr/include/qt/QtOpenGL \
				-I/usr/include/qt/QtWidgets

#---------------------------------------------------------------------------------
# Additional folders for libraries
#---------------------------------------------------------------------------------
LIBDIRS		=

ifneq ($(BUILD),$(notdir $(CURDIR)))

#---------------------------------------------------------------------------------
# Source files
#---------------------------------------------------------------------------------
CFILES			=	$(sort $(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.c))))
CPPFILES		=	$(sort $(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.cpp))))
HFILES			=	$(sort $(foreach dir,$(INCLUDES),$(notdir $(wildcard $(dir)/*.h))))
HPPFILES		=	$(sort $(foreach dir,$(INCLUDES),$(notdir $(wildcard $(dir)/*.hpp))))

export OUTPUT	=	$(CURDIR)/$(TARGET)

export VPATH	=	$(foreach dir,$(SOURCES),$(CURDIR)/$(dir)) \
					$(foreach dir,$(INCLUDES),$(CURDIR)/$(dir))

export OFILES	=	$(CPPFILES:.cpp=.o) $(CFILES:.c=.o) \
					$(HPPFILES:.hpp=.moc.o) $(HFILES:.h=.moc.o)

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

%.o: %.cpp
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

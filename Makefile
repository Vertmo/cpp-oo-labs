##
# ENAC Airport Passenger Simulator
#
# @file
# @version 0.1

SRC_DIR := src
INCLUDE_DIR := include
OBJ_DIR := obj

INCLUDES := $(shell find $(INCLUDE_DIR) -type d)
SRCS := $(shell find $(SRC_DIR) | grep \.cpp$)
HEADERS := $(shell find $(INCLUDE_DIR) | grep \.hpp$)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

all: aps

aps.pro: $(SRCS) $(HEADERS)
	qmake -project -recursive -o $@
	echo INCLUDEPATH += include >> $@
	echo QT += widgets >> $@
	echo QT += svg >> $@
	echo OBJECTS_DIR = obj/ >> $@

Makefile.auto: aps.pro
	qmake -makefile -o $@ $^

aps compile_commands.json: Makefile.auto $(SRCS) $(HEADERS)
	bear -- make -f $< $@ -j4

run: aps
	./$^

clean:
	rm -rf $(OBJ_DIR) aps.pro Makefile.auto

realclean: clean
	rm -rf aps compile_commands.json

# end

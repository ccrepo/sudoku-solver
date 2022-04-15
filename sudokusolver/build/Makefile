#
# Makefile sudokusolver 
# 

all: prepare build

MAKEFILE_PATH = $(abspath $(lastword $(MAKEFILE_LIST)))
MAKEFILE_DIR  = $(dir $(MAKEFILE_PATH))

BUILD_ROOT = ..

BUILD_DIR   = $(PWD)
SRC_DIR     = $(BUILD_ROOT)/src
BIN_DIR     = $(BUILD_ROOT)/bin
OBJ_DIR     = $(BUILD_ROOT)/obj
TARGET_NAME = sudokusolver
TARGET_EXE  = $(BIN_DIR)/$(TARGET_NAME)
SUBDIRS     = $(shell find $(SRC_DIR) -type d | sort -r)
BUILDDIRS   = $(BIN_DIR)
SRC_FILES   = $(shell find $(SRC_DIR) -name *.cpp)
OBJ_FILES   = $(SRC_FILES:%.cpp=%.o)
INCL_DIRS   = $(addprefix -I, $(SUBDIRS))

CCC	    = g++

INCLUDES    = -I. $(INCL_DIRS) 
 
# NOTE: levels are -std=c++11 -std=c++14 -std=c++17 -std=c++2a
CPPFLAGS    = -Wall -g -std=c++2a

LDLIBS      = -lpthread

.cpp.o:
	$(CCC) -c $(CPPFLAGS) $< $(INCLUDES) -o $@

$(TARGET_EXE):  $(OBJ_FILES) 
	$(CCC) $(CPPFLAGS) -o $(TARGET_EXE) $(OBJ_FILES) $(LDLIBS)

prepare:
	@for builddir in $(BUILDDIRS); do if [ ! -d "$$builddir" ]; then \mkdir "$$builddir" ; echo making "$$builddir" ; fi; done
	@for builddir in $(BUILDDIRS); do if [ ! -d "$$builddir" ]; then \echo "could not create/read dir $$builddir"; exit 1; fi; done

build: $(TARGET_EXE)

clean:
	\rm -fr $(OBJ_FILES) $(TARGET_EXE)

# on MacOS use install make using 'brew install makedepend' 
# on Linux (debian) use apt install 'xutils-dev'
# or if 'gcc -M' instead.
depend:
	makedepend -DSUDOKUSOLVER_MAKEDEPENDS -Y $(INCLUDES) -- $(CPPFLAGS) -- $(SRC_FILES) 

.PHONEY: all
.PHONEY: prepare
.PHONEY: build
.PHONEY: clean
.PHONEY: depend

# DO NOT DELETE

../src/util/sudoku_const.o: ../src/util/sudoku_const.h
../src/util/sudoku_argument.o: ../src/util/sudoku_argument.h
../src/util/sudoku_thread.o: ../src/util/sudoku_thread.h
../src/util/sudoku_thread.o: ../src/util/sudoku_system.h
../src/util/sudoku_thread.o: ../src/system/sudoku_generic.h
../src/util/sudoku_thread.o: ../src/system/sudoku_linux.h
../src/util/sudoku_thread.o: ../src/system/sudoku_macos.h
../src/util/sudoku_thread.o: ../src/util/sudoku_configuration.h
../src/util/sudoku_thread.o: ../src/util/sudoku_const.h
../src/util/sudoku_thread.o: ../src/util/sudoku_log.h
../src/util/sudoku_thread.o: ../src/util/sudoku_variadic.h
../src/util/sudoku_value.o: ../src/util/sudoku_value.h
../src/util/sudoku_value.o: ../src/util/sudoku_const.h
../src/util/sudoku_variadic.o: ../src/util/sudoku_variadic.h
../src/util/sudoku_variadic.o: ../src/util/sudoku_system.h
../src/util/sudoku_variadic.o: ../src/system/sudoku_generic.h
../src/util/sudoku_variadic.o: ../src/system/sudoku_linux.h
../src/util/sudoku_variadic.o: ../src/system/sudoku_macos.h
../src/util/sudoku_variadic.o: ../src/util/sudoku_configuration.h
../src/util/sudoku_variadic.o: ../src/util/sudoku_const.h
../src/util/sudoku_variadic.o: ../src/util/sudoku_log.h
../src/util/sudoku_configuration.o: ../src/util/sudoku_configuration.h
../src/util/sudoku_configuration.o: ../src/util/sudoku_system.h
../src/util/sudoku_configuration.o: ../src/system/sudoku_generic.h
../src/util/sudoku_configuration.o: ../src/system/sudoku_linux.h
../src/util/sudoku_configuration.o: ../src/system/sudoku_macos.h
../src/util/sudoku_configuration.o: ../src/util/sudoku_const.h
../src/util/sudoku_time.o: ../src/util/sudoku_time.h
../src/util/sudoku_time.o: ../src/util/sudoku_const.h
../src/util/sudoku_time.o: ../src/util/sudoku_thread.h
../src/util/sudoku_time.o: ../src/util/sudoku_system.h
../src/util/sudoku_time.o: ../src/system/sudoku_generic.h
../src/util/sudoku_time.o: ../src/system/sudoku_linux.h
../src/util/sudoku_time.o: ../src/system/sudoku_macos.h
../src/util/sudoku_time.o: ../src/util/sudoku_configuration.h
../src/util/sudoku_time.o: ../src/util/sudoku_log.h
../src/util/sudoku_time.o: ../src/util/sudoku_variadic.h
../src/util/sudoku_log.o: ../src/util/sudoku_configuration.h
../src/util/sudoku_log.o: ../src/util/sudoku_system.h
../src/util/sudoku_log.o: ../src/system/sudoku_generic.h
../src/util/sudoku_log.o: ../src/system/sudoku_linux.h
../src/util/sudoku_log.o: ../src/system/sudoku_macos.h
../src/util/sudoku_log.o: ../src/util/sudoku_const.h ../src/util/sudoku_log.h
../src/util/sudoku_log.o: ../src/util/sudoku_variadic.h
../src/util/sudoku_log.o: ../src/util/sudoku_time.h
../src/util/sudoku_log.o: ../src/util/sudoku_thread.h
../src/util/sudoku_system.o: ../src/util/sudoku_system.h
../src/util/sudoku_system.o: ../src/system/sudoku_generic.h
../src/util/sudoku_system.o: ../src/system/sudoku_linux.h
../src/util/sudoku_system.o: ../src/system/sudoku_macos.h
../src/zone/sudoku_rank.o: ../src/zone/sudoku_rank.h
../src/zone/sudoku_rank.o: ../src/game/sudoku_zone.h
../src/zone/sudoku_rank.o: ../src/util/sudoku_const.h
../src/zone/sudoku_rank.o: ../src/util/sudoku_collection.h
../src/zone/sudoku_rank.o: ../src/game/sudoku_cell.h
../src/zone/sudoku_rank.o: ../src/util/sudoku_math.h ../src/game/sudoku_id.h
../src/zone/sudoku_rank.o: ../src/util/sudoku_log.h
../src/zone/sudoku_rank.o: ../src/util/sudoku_variadic.h
../src/zone/sudoku_rank.o: ../src/util/sudoku_system.h
../src/zone/sudoku_rank.o: ../src/system/sudoku_generic.h
../src/zone/sudoku_rank.o: ../src/system/sudoku_linux.h
../src/zone/sudoku_rank.o: ../src/system/sudoku_macos.h
../src/zone/sudoku_rank.o: ../src/util/sudoku_configuration.h
../src/zone/sudoku_column.o: ../src/zone/sudoku_column.h
../src/zone/sudoku_column.o: ../src/game/sudoku_zone.h
../src/zone/sudoku_column.o: ../src/util/sudoku_const.h
../src/zone/sudoku_column.o: ../src/util/sudoku_collection.h
../src/zone/sudoku_column.o: ../src/game/sudoku_cell.h
../src/zone/sudoku_column.o: ../src/util/sudoku_math.h
../src/zone/sudoku_column.o: ../src/game/sudoku_id.h ../src/util/sudoku_log.h
../src/zone/sudoku_column.o: ../src/util/sudoku_variadic.h
../src/zone/sudoku_column.o: ../src/util/sudoku_system.h
../src/zone/sudoku_column.o: ../src/system/sudoku_generic.h
../src/zone/sudoku_column.o: ../src/system/sudoku_linux.h
../src/zone/sudoku_column.o: ../src/system/sudoku_macos.h
../src/zone/sudoku_column.o: ../src/util/sudoku_configuration.h
../src/zone/sudoku_row.o: ../src/zone/sudoku_row.h ../src/game/sudoku_zone.h
../src/zone/sudoku_row.o: ../src/util/sudoku_const.h
../src/zone/sudoku_row.o: ../src/util/sudoku_collection.h
../src/zone/sudoku_row.o: ../src/game/sudoku_cell.h ../src/util/sudoku_math.h
../src/zone/sudoku_row.o: ../src/game/sudoku_id.h ../src/util/sudoku_log.h
../src/zone/sudoku_row.o: ../src/util/sudoku_variadic.h
../src/zone/sudoku_row.o: ../src/util/sudoku_system.h
../src/zone/sudoku_row.o: ../src/system/sudoku_generic.h
../src/zone/sudoku_row.o: ../src/system/sudoku_linux.h
../src/zone/sudoku_row.o: ../src/system/sudoku_macos.h
../src/zone/sudoku_row.o: ../src/util/sudoku_configuration.h
../src/zone/sudoku_factory.o: ../src/util/sudoku_const.h
../src/zone/sudoku_factory.o: ../src/zone/sudoku_factory.h
../src/zone/sudoku_factory.o: ../src/util/sudoku_collection.h
../src/zone/sudoku_block.o: ../src/zone/sudoku_block.h
../src/zone/sudoku_block.o: ../src/game/sudoku_zone.h
../src/zone/sudoku_block.o: ../src/util/sudoku_const.h
../src/zone/sudoku_block.o: ../src/util/sudoku_collection.h
../src/zone/sudoku_block.o: ../src/game/sudoku_cells.h
../src/zone/sudoku_block.o: ../src/game/sudoku_cell.h
../src/zone/sudoku_block.o: ../src/util/sudoku_math.h ../src/game/sudoku_id.h
../src/zone/sudoku_block.o: ../src/util/sudoku_log.h
../src/zone/sudoku_block.o: ../src/util/sudoku_variadic.h
../src/zone/sudoku_block.o: ../src/util/sudoku_system.h
../src/zone/sudoku_block.o: ../src/system/sudoku_generic.h
../src/zone/sudoku_block.o: ../src/system/sudoku_linux.h
../src/zone/sudoku_block.o: ../src/system/sudoku_macos.h
../src/zone/sudoku_block.o: ../src/util/sudoku_configuration.h
../src/zone/sudoku_block.o: ../src/util/sudoku_sequence.h
../src/zone/sudoku_stack.o: ../src/zone/sudoku_stack.h
../src/zone/sudoku_stack.o: ../src/game/sudoku_zone.h
../src/zone/sudoku_stack.o: ../src/util/sudoku_const.h
../src/zone/sudoku_stack.o: ../src/util/sudoku_collection.h
../src/game/sudoku_node.o: ../src/game/sudoku_node.h
../src/game/sudoku_node.o: ../src/util/sudoku_defn.h
../src/game/sudoku_node.o: ../src/game/sudoku_board.h
../src/game/sudoku_node.o: ../src/util/sudoku_const.h
../src/game/sudoku_node.o: ../src/game/sudoku_move.h ../src/game/sudoku_id.h
../src/game/sudoku_node.o: ../src/util/sudoku_collection.h
../src/game/sudoku_node.o: ../src/game/sudoku_cell.h
../src/game/sudoku_node.o: ../src/util/sudoku_math.h ../src/util/sudoku_log.h
../src/game/sudoku_node.o: ../src/util/sudoku_variadic.h
../src/game/sudoku_node.o: ../src/util/sudoku_system.h
../src/game/sudoku_node.o: ../src/system/sudoku_generic.h
../src/game/sudoku_node.o: ../src/system/sudoku_linux.h
../src/game/sudoku_node.o: ../src/system/sudoku_macos.h
../src/game/sudoku_node.o: ../src/util/sudoku_configuration.h
../src/game/sudoku_node.o: ../src/game/sudoku_cells.h
../src/game/sudoku_node.o: ../src/util/sudoku_sequence.h
../src/game/sudoku_cells.o: ../src/game/sudoku_cell.h
../src/game/sudoku_cells.o: ../src/util/sudoku_math.h
../src/game/sudoku_cells.o: ../src/util/sudoku_const.h
../src/game/sudoku_cells.o: ../src/game/sudoku_id.h
../src/game/sudoku_cells.o: ../src/util/sudoku_collection.h
../src/game/sudoku_cells.o: ../src/util/sudoku_log.h
../src/game/sudoku_cells.o: ../src/util/sudoku_variadic.h
../src/game/sudoku_cells.o: ../src/util/sudoku_system.h
../src/game/sudoku_cells.o: ../src/system/sudoku_generic.h
../src/game/sudoku_cells.o: ../src/system/sudoku_linux.h
../src/game/sudoku_cells.o: ../src/system/sudoku_macos.h
../src/game/sudoku_cells.o: ../src/util/sudoku_configuration.h
../src/game/sudoku_cell.o: ../src/util/sudoku_const.h
../src/game/sudoku_cell.o: ../src/util/sudoku_value.h
../src/game/sudoku_cell.o: ../src/util/sudoku_log.h
../src/game/sudoku_cell.o: ../src/util/sudoku_variadic.h
../src/game/sudoku_cell.o: ../src/util/sudoku_system.h
../src/game/sudoku_cell.o: ../src/system/sudoku_generic.h
../src/game/sudoku_cell.o: ../src/system/sudoku_linux.h
../src/game/sudoku_cell.o: ../src/system/sudoku_macos.h
../src/game/sudoku_cell.o: ../src/util/sudoku_configuration.h
../src/game/sudoku_cell.o: ../src/game/sudoku_zones.h
../src/game/sudoku_cell.o: ../src/game/sudoku_zone.h
../src/game/sudoku_cell.o: ../src/util/sudoku_collection.h
../src/game/sudoku_cell.o: ../src/zone/sudoku_block.h
../src/game/sudoku_cell.o: ../src/zone/sudoku_row.h
../src/game/sudoku_cell.o: ../src/zone/sudoku_column.h
../src/game/sudoku_cell.o: ../src/game/sudoku_cell.h
../src/game/sudoku_cell.o: ../src/util/sudoku_math.h ../src/game/sudoku_id.h
../src/game/sudoku_zones.o: ../src/game/sudoku_zones.h
../src/game/sudoku_zones.o: ../src/game/sudoku_zone.h
../src/game/sudoku_zones.o: ../src/util/sudoku_const.h
../src/game/sudoku_zones.o: ../src/util/sudoku_collection.h
../src/game/sudoku_zones.o: ../src/zone/sudoku_factory.h
../src/game/sudoku_zones.o: ../src/zone/sudoku_block.h
../src/game/sudoku_zones.o: ../src/zone/sudoku_row.h
../src/game/sudoku_zones.o: ../src/zone/sudoku_column.h
../src/game/sudoku_zones.o: ../src/zone/sudoku_rank.h
../src/game/sudoku_zones.o: ../src/zone/sudoku_stack.h
../src/game/sudoku_tree.o: ../src/game/sudoku_tree.h
../src/game/sudoku_tree.o: ../src/util/sudoku_defn.h
../src/game/sudoku_tree.o: ../src/game/sudoku_board.h
../src/game/sudoku_tree.o: ../src/util/sudoku_const.h
../src/game/sudoku_tree.o: ../src/game/sudoku_move.h ../src/game/sudoku_id.h
../src/game/sudoku_tree.o: ../src/util/sudoku_collection.h
../src/game/sudoku_tree.o: ../src/game/sudoku_cell.h
../src/game/sudoku_tree.o: ../src/util/sudoku_math.h ../src/util/sudoku_log.h
../src/game/sudoku_tree.o: ../src/util/sudoku_variadic.h
../src/game/sudoku_tree.o: ../src/util/sudoku_system.h
../src/game/sudoku_tree.o: ../src/system/sudoku_generic.h
../src/game/sudoku_tree.o: ../src/system/sudoku_linux.h
../src/game/sudoku_tree.o: ../src/system/sudoku_macos.h
../src/game/sudoku_tree.o: ../src/util/sudoku_configuration.h
../src/game/sudoku_tree.o: ../src/game/sudoku_cells.h
../src/game/sudoku_tree.o: ../src/util/sudoku_sequence.h
../src/game/sudoku_tree.o: ../src/game/sudoku_node.h
../src/game/sudoku_tree.o: ../src/game/sudoku_zones.h
../src/game/sudoku_tree.o: ../src/game/sudoku_zone.h
../src/game/sudoku_zone.o: ../src/game/sudoku_zone.h
../src/game/sudoku_zone.o: ../src/util/sudoku_const.h
../src/game/sudoku_zone.o: ../src/util/sudoku_collection.h
../src/game/sudoku_zone.o: ../src/zone/sudoku_block.h
../src/game/sudoku_zone.o: ../src/zone/sudoku_row.h
../src/game/sudoku_zone.o: ../src/zone/sudoku_column.h
../src/game/sudoku_zone.o: ../src/zone/sudoku_rank.h
../src/game/sudoku_zone.o: ../src/zone/sudoku_stack.h
../src/game/sudoku_id.o: ../src/game/sudoku_id.h ../src/util/sudoku_const.h
../src/game/sudoku_game.o: ../src/util/sudoku_log.h
../src/game/sudoku_game.o: ../src/util/sudoku_variadic.h
../src/game/sudoku_game.o: ../src/util/sudoku_system.h
../src/game/sudoku_game.o: ../src/system/sudoku_generic.h
../src/game/sudoku_game.o: ../src/system/sudoku_linux.h
../src/game/sudoku_game.o: ../src/system/sudoku_macos.h
../src/game/sudoku_game.o: ../src/util/sudoku_configuration.h
../src/game/sudoku_game.o: ../src/util/sudoku_const.h
../src/game/sudoku_game.o: ../src/game/sudoku_game.h
../src/game/sudoku_game.o: ../src/game/sudoku_tree.h
../src/game/sudoku_game.o: ../src/util/sudoku_defn.h
../src/game/sudoku_game.o: ../src/game/sudoku_board.h
../src/game/sudoku_game.o: ../src/game/sudoku_move.h ../src/game/sudoku_id.h
../src/game/sudoku_game.o: ../src/util/sudoku_collection.h
../src/game/sudoku_game.o: ../src/game/sudoku_cell.h
../src/game/sudoku_game.o: ../src/util/sudoku_math.h
../src/game/sudoku_game.o: ../src/game/sudoku_cells.h
../src/game/sudoku_game.o: ../src/util/sudoku_sequence.h
../src/game/sudoku_game.o: ../src/game/sudoku_node.h
../src/game/sudoku_game.o: ../src/game/sudoku_zones.h
../src/game/sudoku_game.o: ../src/game/sudoku_zone.h
../src/game/sudoku_game.o: ../src/util/sudoku_value.h
../src/game/sudoku_board.o: ../src/util/sudoku_const.h
../src/game/sudoku_board.o: ../src/util/sudoku_value.h
../src/game/sudoku_board.o: ../src/util/sudoku_log.h
../src/game/sudoku_board.o: ../src/util/sudoku_variadic.h
../src/game/sudoku_board.o: ../src/util/sudoku_system.h
../src/game/sudoku_board.o: ../src/system/sudoku_generic.h
../src/game/sudoku_board.o: ../src/system/sudoku_linux.h
../src/game/sudoku_board.o: ../src/system/sudoku_macos.h
../src/game/sudoku_board.o: ../src/util/sudoku_configuration.h
../src/game/sudoku_board.o: ../src/game/sudoku_board.h
../src/game/sudoku_board.o: ../src/util/sudoku_defn.h
../src/game/sudoku_board.o: ../src/game/sudoku_move.h ../src/game/sudoku_id.h
../src/game/sudoku_board.o: ../src/util/sudoku_collection.h
../src/game/sudoku_board.o: ../src/game/sudoku_cell.h
../src/game/sudoku_board.o: ../src/util/sudoku_math.h
../src/game/sudoku_board.o: ../src/game/sudoku_cells.h
../src/game/sudoku_board.o: ../src/util/sudoku_sequence.h
../src/game/sudoku_board.o: ../src/game/sudoku_zones.h
../src/game/sudoku_board.o: ../src/game/sudoku_zone.h
../src/game/sudoku_board.o: ../src/zone/sudoku_block.h
../src/game/sudoku_board.o: ../src/zone/sudoku_row.h
../src/game/sudoku_board.o: ../src/zone/sudoku_column.h
../src/game/sudoku_board.o: ../src/zone/sudoku_rank.h
../src/game/sudoku_board.o: ../src/zone/sudoku_stack.h
../src/game/sudoku_move.o: ../src/game/sudoku_move.h ../src/game/sudoku_id.h
../src/game/sudoku_move.o: ../src/util/sudoku_const.h
../src/sudokusolver.o: ../src/util/sudoku_argument.h ../src/util/sudoku_log.h
../src/sudokusolver.o: ../src/util/sudoku_variadic.h
../src/sudokusolver.o: ../src/util/sudoku_system.h
../src/sudokusolver.o: ../src/system/sudoku_generic.h
../src/sudokusolver.o: ../src/system/sudoku_linux.h
../src/sudokusolver.o: ../src/system/sudoku_macos.h
../src/sudokusolver.o: ../src/util/sudoku_configuration.h
../src/sudokusolver.o: ../src/util/sudoku_const.h ../src/game/sudoku_game.h
../src/sudokusolver.o: ../src/game/sudoku_tree.h ../src/util/sudoku_defn.h
../src/sudokusolver.o: ../src/game/sudoku_board.h ../src/game/sudoku_move.h
../src/sudokusolver.o: ../src/game/sudoku_id.h
../src/sudokusolver.o: ../src/util/sudoku_collection.h
../src/sudokusolver.o: ../src/game/sudoku_cell.h ../src/util/sudoku_math.h
../src/sudokusolver.o: ../src/game/sudoku_cells.h
../src/sudokusolver.o: ../src/util/sudoku_sequence.h
../src/sudokusolver.o: ../src/game/sudoku_node.h ../src/game/sudoku_zones.h
../src/sudokusolver.o: ../src/game/sudoku_zone.h ../src/util/sudoku_time.h
../src/sudokusolver.o: ../src/util/sudoku_thread.h ../src/util/sudoku_timer.h
../src/factory/sudoku_factory_rank.o: ../src/util/sudoku_const.h
../src/factory/sudoku_factory_rank.o: ../src/zone/sudoku_factory.h
../src/factory/sudoku_factory_rank.o: ../src/zone/sudoku_rank.h
../src/factory/sudoku_factory_rank.o: ../src/game/sudoku_zone.h
../src/factory/sudoku_factory_rank.o: ../src/util/sudoku_collection.h
../src/factory/sudoku_factory_rank.o: ../src/game/sudoku_board.h
../src/factory/sudoku_factory_rank.o: ../src/util/sudoku_defn.h
../src/factory/sudoku_factory_rank.o: ../src/game/sudoku_move.h
../src/factory/sudoku_factory_rank.o: ../src/game/sudoku_id.h
../src/factory/sudoku_factory_rank.o: ../src/game/sudoku_cell.h
../src/factory/sudoku_factory_rank.o: ../src/util/sudoku_math.h
../src/factory/sudoku_factory_rank.o: ../src/util/sudoku_log.h
../src/factory/sudoku_factory_rank.o: ../src/util/sudoku_variadic.h
../src/factory/sudoku_factory_rank.o: ../src/util/sudoku_system.h
../src/factory/sudoku_factory_rank.o: ../src/system/sudoku_generic.h
../src/factory/sudoku_factory_rank.o: ../src/system/sudoku_linux.h
../src/factory/sudoku_factory_rank.o: ../src/system/sudoku_macos.h
../src/factory/sudoku_factory_rank.o: ../src/util/sudoku_configuration.h
../src/factory/sudoku_factory_rank.o: ../src/game/sudoku_cells.h
../src/factory/sudoku_factory_rank.o: ../src/util/sudoku_sequence.h
../src/factory/sudoku_factory_column.o: ../src/util/sudoku_const.h
../src/factory/sudoku_factory_column.o: ../src/zone/sudoku_factory.h
../src/factory/sudoku_factory_column.o: ../src/zone/sudoku_column.h
../src/factory/sudoku_factory_column.o: ../src/game/sudoku_zone.h
../src/factory/sudoku_factory_column.o: ../src/util/sudoku_collection.h
../src/factory/sudoku_factory_column.o: ../src/game/sudoku_board.h
../src/factory/sudoku_factory_column.o: ../src/util/sudoku_defn.h
../src/factory/sudoku_factory_column.o: ../src/game/sudoku_move.h
../src/factory/sudoku_factory_column.o: ../src/game/sudoku_id.h
../src/factory/sudoku_factory_column.o: ../src/game/sudoku_cell.h
../src/factory/sudoku_factory_column.o: ../src/util/sudoku_math.h
../src/factory/sudoku_factory_column.o: ../src/util/sudoku_log.h
../src/factory/sudoku_factory_column.o: ../src/util/sudoku_variadic.h
../src/factory/sudoku_factory_column.o: ../src/util/sudoku_system.h
../src/factory/sudoku_factory_column.o: ../src/system/sudoku_generic.h
../src/factory/sudoku_factory_column.o: ../src/system/sudoku_linux.h
../src/factory/sudoku_factory_column.o: ../src/system/sudoku_macos.h
../src/factory/sudoku_factory_column.o: ../src/util/sudoku_configuration.h
../src/factory/sudoku_factory_column.o: ../src/game/sudoku_cells.h
../src/factory/sudoku_factory_column.o: ../src/util/sudoku_sequence.h
../src/factory/sudoku_factory_row.o: ../src/util/sudoku_const.h
../src/factory/sudoku_factory_row.o: ../src/zone/sudoku_factory.h
../src/factory/sudoku_factory_row.o: ../src/zone/sudoku_row.h
../src/factory/sudoku_factory_row.o: ../src/game/sudoku_zone.h
../src/factory/sudoku_factory_row.o: ../src/util/sudoku_collection.h
../src/factory/sudoku_factory_row.o: ../src/game/sudoku_board.h
../src/factory/sudoku_factory_row.o: ../src/util/sudoku_defn.h
../src/factory/sudoku_factory_row.o: ../src/game/sudoku_move.h
../src/factory/sudoku_factory_row.o: ../src/game/sudoku_id.h
../src/factory/sudoku_factory_row.o: ../src/game/sudoku_cell.h
../src/factory/sudoku_factory_row.o: ../src/util/sudoku_math.h
../src/factory/sudoku_factory_row.o: ../src/util/sudoku_log.h
../src/factory/sudoku_factory_row.o: ../src/util/sudoku_variadic.h
../src/factory/sudoku_factory_row.o: ../src/util/sudoku_system.h
../src/factory/sudoku_factory_row.o: ../src/system/sudoku_generic.h
../src/factory/sudoku_factory_row.o: ../src/system/sudoku_linux.h
../src/factory/sudoku_factory_row.o: ../src/system/sudoku_macos.h
../src/factory/sudoku_factory_row.o: ../src/util/sudoku_configuration.h
../src/factory/sudoku_factory_row.o: ../src/game/sudoku_cells.h
../src/factory/sudoku_factory_row.o: ../src/util/sudoku_sequence.h
../src/factory/sudoku_factory_block.o: ../src/util/sudoku_const.h
../src/factory/sudoku_factory_block.o: ../src/zone/sudoku_factory.h
../src/factory/sudoku_factory_block.o: ../src/zone/sudoku_block.h
../src/factory/sudoku_factory_block.o: ../src/game/sudoku_zone.h
../src/factory/sudoku_factory_block.o: ../src/util/sudoku_collection.h
../src/factory/sudoku_factory_block.o: ../src/game/sudoku_board.h
../src/factory/sudoku_factory_block.o: ../src/util/sudoku_defn.h
../src/factory/sudoku_factory_block.o: ../src/game/sudoku_move.h
../src/factory/sudoku_factory_block.o: ../src/game/sudoku_id.h
../src/factory/sudoku_factory_block.o: ../src/game/sudoku_cell.h
../src/factory/sudoku_factory_block.o: ../src/util/sudoku_math.h
../src/factory/sudoku_factory_block.o: ../src/util/sudoku_log.h
../src/factory/sudoku_factory_block.o: ../src/util/sudoku_variadic.h
../src/factory/sudoku_factory_block.o: ../src/util/sudoku_system.h
../src/factory/sudoku_factory_block.o: ../src/system/sudoku_generic.h
../src/factory/sudoku_factory_block.o: ../src/system/sudoku_linux.h
../src/factory/sudoku_factory_block.o: ../src/system/sudoku_macos.h
../src/factory/sudoku_factory_block.o: ../src/util/sudoku_configuration.h
../src/factory/sudoku_factory_block.o: ../src/game/sudoku_cells.h
../src/factory/sudoku_factory_block.o: ../src/util/sudoku_sequence.h
../src/factory/sudoku_factory_stack.o: ../src/util/sudoku_const.h
../src/factory/sudoku_factory_stack.o: ../src/zone/sudoku_factory.h
../src/factory/sudoku_factory_stack.o: ../src/zone/sudoku_stack.h
../src/factory/sudoku_factory_stack.o: ../src/game/sudoku_zone.h
../src/factory/sudoku_factory_stack.o: ../src/util/sudoku_collection.h
../src/factory/sudoku_factory_stack.o: ../src/game/sudoku_board.h
../src/factory/sudoku_factory_stack.o: ../src/util/sudoku_defn.h
../src/factory/sudoku_factory_stack.o: ../src/game/sudoku_move.h
../src/factory/sudoku_factory_stack.o: ../src/game/sudoku_id.h
../src/factory/sudoku_factory_stack.o: ../src/game/sudoku_cell.h
../src/factory/sudoku_factory_stack.o: ../src/util/sudoku_math.h
../src/factory/sudoku_factory_stack.o: ../src/util/sudoku_log.h
../src/factory/sudoku_factory_stack.o: ../src/util/sudoku_variadic.h
../src/factory/sudoku_factory_stack.o: ../src/util/sudoku_system.h
../src/factory/sudoku_factory_stack.o: ../src/system/sudoku_generic.h
../src/factory/sudoku_factory_stack.o: ../src/system/sudoku_linux.h
../src/factory/sudoku_factory_stack.o: ../src/system/sudoku_macos.h
../src/factory/sudoku_factory_stack.o: ../src/util/sudoku_configuration.h
../src/factory/sudoku_factory_stack.o: ../src/game/sudoku_cells.h
../src/factory/sudoku_factory_stack.o: ../src/util/sudoku_sequence.h

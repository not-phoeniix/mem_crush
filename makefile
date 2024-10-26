# compiler and flags
CXX := g++
PRE_FLAGS := -m64 -g -Wall
POST_FLAGS := -lGL -lglut -lGLEW -lGLU -lGLX

# directories
SRC_DIR := src
BIN_DIR := bin
OBJ_DIR := $(BIN_DIR)/obj
LIB_DIR := include

# files
SRC := $(shell find $(SRC_DIR)/ -type f -iname "*.cpp")
OBJ := $(subst $(SRC_DIR),$(OBJ_DIR),$(foreach file,$(basename $(SRC)),$(file).o))
BIN := $(BIN_DIR)/build

# build tasks
all: $(BIN)

$(BIN): $(OBJ)
	@echo "linking..."
	@$(CXX) $(OBJ) $(POST_FLAGS) -o $(BIN)
	@echo "done :D"

.SECONDEXPANSION:
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $$(dir $$@)
	@echo "compiling $<..."
	@$(CXX) -c $< $(PRE_FLAGS) -I $(LIB_DIR) -o $@

# ensure directories are created via custom task
%/:
	@mkdir -p $@

.PRECIOUS: %/

# other tasks
.PHONY: clean run setup

clean:
	@echo "cleaning project..."
	rm -rf $(BIN) $(OBJ_DIR)/*
	@echo "project cleaned!"

run: $(BIN)
	@echo "running $(BIN)..."
	@exec $(BIN)

# make dirs and create main file
setup:
	mkdir -p $(SRC_DIR) $(BIN_DIR) $(OBJ_DIR) $(LIB_DIR)
	echo "#include <iostream>" >> $(SRC_DIR)/main.cpp
	echo "" >> $(SRC_DIR)/main.cpp
	echo "int main() {" >> $(SRC_DIR)/main.cpp
	echo "	std::cout << \"hello world!!\n\";">> $(SRC_DIR)/main.cpp
	echo "" >> $(SRC_DIR)/main.cpp
	echo "	return 0;" >> $(SRC_DIR)/main.cpp
	echo "}" >> $(SRC_DIR)/main.cpp

	echo "set up project!!"

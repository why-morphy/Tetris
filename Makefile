PROJECT = TETRISter
CXX = g++

SRC_DIR = src
SRC = $(wildcard $(SRC_DIR)/*.cpp)

OBJ_DIR = obj
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

DEP_DIR = dep
DEP = $(OBJ:$(OBJ_DIR)/%.o=$(DEP_DIR)/%.d)

CXXFLAGS = -Wall -Wextra -Werror -Wpedantic -std=c++17
INCLUDE_PATHS = -Iinclude -I/usr/local/include

LDFLAGS = -L/usr/local/lib -Llib

ifeq ($(OS),Windows_NT)
    # Windows (MinGW)
    LIBS = -lraylib -lopengl32 -lgdi32 -lwinmm
    EXT = .exe
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        # Linux
        LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -lm
    endif
    ifeq ($(UNAME_S),Darwin)
        # macOS
        LIBS = -lraylib -framework OpenGL -framework Cocoa -framework IOKit
    endif
    EXT =
endif

BIN_DIR = bin
TARGET = $(BIN_DIR)/$(PROJECT)$(EXT)

all: game

game: $(TARGET)

$(TARGET): $(OBJ) | $(BIN_DIR)
	$(CXX) $(LDFLAGS) $^ $(LIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR) $(DEP_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDE_PATHS) -MMD -MP -MF $(DEP_DIR)/$*.d -c $< -o $@

-include $(DEP)

$(BIN_DIR) $(OBJ_DIR) $(DEP_DIR):
	mkdir -p $@

clean:
	rm -rf $(BIN_DIR) $(OBJ_DIR) $(DEP_DIR)

run: game
	./$(TARGET)

.PHONY: all game clean run
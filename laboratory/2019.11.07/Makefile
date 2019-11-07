PROJ_NAME=triangle

CC=g++
CC_FLAGS=-g -O3 -Wall -std=c++11 -lGL -lglfw -lGLEW
#$(shell pkg-config --cflags --static --libs glfw3 glew)

SRC_PATH = ./src
BUILD_PATH = ./build
BIN_PATH = ./bin

SOURCES = $(shell find $(SRC_PATH) -name '*.cpp' | cut -f2-)
OBJECTS = $(SOURCES:$(SRC_PATH)/%.cpp=$(BUILD_PATH)/%.o)

all: dirs $(PROJ_NAME)

$(PROJ_NAME): $(OBJECTS)
	$(CC) -o bin/$@ $^ $(CC_FLAGS)

dirs:
	@mkdir -p $(BIN_PATH)
	@mkdir -p $(BUILD_PATH)

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.cpp
	$(CC) -c $< -o $@

run:
	@$(BUILD_PATH)/$(PROJ_NAME)

clean:
	@rm -rf $(BUILD_PATH) $(BIN_PATH)

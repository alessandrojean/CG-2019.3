PROJ_NAME=triangle

CC=g++
CC_FLAGS=$(shell pkg-config --cflags --static --libs glfw3 glew)

all: $(PROJ_NAME)

$(PROJ_NAME): main.cpp
	@mkdir -p bin
	@$(CC) -o bin/$@ $^ $(CC_FLAGS)

clean:
	@rm -rf *.o $(PROJ_NAME) *~

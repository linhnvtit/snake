# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall $(shell pkg-config --cflags --libs sdl2)
TARGET = main
SRC = $(shell find . -name "*.cpp" -not -path "./build/*")
PKG_CONFIG = 

run: $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)  && ./$(TARGET)

clean:
	rm -f $(TARGET)
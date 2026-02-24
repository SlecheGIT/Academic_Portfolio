CXX = g++

CXXFLAGS = -Wall -Wextra -std=c++11

#LDLIBS = -lglut -lGL -lGLU -lm

TARGET = app

SRC = escalonador.cpp
OBJ = $(SRC:.cpp=.o)  

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
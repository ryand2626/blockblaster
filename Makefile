CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
LDFLAGS = -lglut -lGL -lGLU

TARGET = blockblaster


all: $(TARGET)

$(TARGET): code.o
	$(CXX) $^ -o $@ $(LDFLAGS)

code.o: code.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(TARGET) code.o

CXX = g++
CXXFLAGS = -std=c++17 -Wall -I include

SRCS = $(wildcard src/**/*.cpp src/*.cpp)
TARGET = app.out

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET) *.o
CXX = g++
CXXFLAGS += -Wall -Wextra -std=c++17 -I.

SRCS = $(wildcard src/*.cpp)
TARGET = app.exe

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET) *.o
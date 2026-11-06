CXX = g++
CXXFLAGS += -Iinclude

SRCS = $(wildcard src/*.cpp)
TARGET = app.out

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET) *.o
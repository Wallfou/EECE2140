CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g -O0

TARGET = routing
OBJS = main.o RoutingEngine.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

main.o: main.cpp RoutingEngine.h
	$(CXX) $(CXXFLAGS) -c main.cpp

RoutingEngine.o: RoutingEngine.cpp RoutingEngine.h
	$(CXX) $(CXXFLAGS) -c RoutingEngine.cpp

asan: CXXFLAGS += -fsanitize=address,undefined -fno-omit-frame-pointer
asan: clean
asan: $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean asan

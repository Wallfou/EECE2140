CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Iinclude
TARGET = denoise

SRC_DIR = src
TEST_DIR = tests
OUTPUT_DIR = output

SOURCES = $(SRC_DIR)/main.cpp $(SRC_DIR)/Image.cpp $(SRC_DIR)/Filter.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "Build successful! Executable: $(TARGET)"

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

test: $(TARGET) $(OUTPUT_DIR)
	@echo "Running tests..."
	./$(TARGET) $(TEST_DIR)/test1_small.txt $(OUTPUT_DIR)/test1_output_mean.txt mean
	@echo ""
	./$(TARGET) $(TEST_DIR)/test2_impulse_noise.txt $(OUTPUT_DIR)/test2_output_median.txt median 2
	@echo ""
	./$(TARGET) $(TEST_DIR)/test3_edges.txt $(OUTPUT_DIR)/test3_output_mean.txt mean 1 clamp
	@echo ""
	./$(TARGET) $(TEST_DIR)/test4_gradient.txt $(OUTPUT_DIR)/test4_output_mean.txt mean
	@echo ""
	@echo "Tests done"

clean:
	rm -f $(OBJECTS) $(TARGET)
	rm -rf $(OUTPUT_DIR)

rebuild: clean all

.PHONY: all test clean rebuild

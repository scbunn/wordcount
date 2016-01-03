#
# Starter Makefile
#
CXX = clang++
BUILD_DIR = ./build
INC = -I .
LDLIBS = 
LDFLAGS =
CXXFLAGS = -std=c++14 -stdlib=libc++ -Wall -pipe -march=native -O2 -funroll-loops
TARGET = wcpp
SOURCES = $(wildcard *.cpp)
OBJ = $(SOURCES:%.cpp=$(BUILD_DIR)/%.o)
DEPS = $(OBJ:%.o=%.d)

$(TARGET) : $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET) : $(OBJ) 
	mkdir -p $(@D)
	$(CXX) $^ -o $@ $(LDFLAGS) $(LDLIBS)

-include $(DEPS)

$(BUILD_DIR)/%.o : %.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@ $(INC)

clean:
	rm -rf build/ 

.PHONY: $(TARGET) clean 

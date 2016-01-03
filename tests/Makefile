#
# make all tests and execute tests
# clang++ test_suite -I gtest/include -pthread *.cc lib/libgtest.a -I . -I ../src
#
CXX = clang++
GTEST_HOME = ~/devel/common/googletest
BUILD_DIR = ./build
INC = -I $(GTEST_HOME) -I $(GTEST_HOME)/include -I . -I ../src
LDLIBS = lib/libgtest.a
LDFLAGS =
CXXFLAGS = -std=c++14 -pthread -stdlib=libc++ -Wall
TARGET = test_suite
TESTS = $(wildcard *.cc)
OBJ = $(TESTS:%.cc=$(BUILD_DIR)/%.o)
DEPS = $(OBJ:%.o=%.d)

$(TARGET) : $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET) : $(OBJ)
	mkdir -p $(@D)
	$(CXX) $^ -o $@ $(LDFLAGS) $(LDLIBS)

-include $(DEPS)

$(BUILD_DIR)/%.o : %.cc gtestlib
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@ $(INC)

gtestlib: lib/libgtest.a

lib/libgtest.a: lib/gtest-all.o
	cd lib && ar -rv libgtest.a gtest-all.o

lib/gtest-all.o:
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INC) -c $(GTEST_HOME)/src/gtest-all.cc -o lib/gtest-all.o

clean:
	rm -rf build/ lib/

.PHONY: clean gtestlib $(TARGET)

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
SRCDIR = numerical_lib/src
TESTDIR = numerical_lib/tests
INCDIR = numerical_lib/include

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
TESTS = $(wildcard $(TESTDIR)/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

all: library tests

library: $(OBJECTS)
	ar rcs libnumerical.a $(OBJECTS)

tests: $(TESTS) library
	$(CXX) $(CXXFLAGS) -I$(INCDIR) $(TESTS) $(OBJECTS) -o test_all

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

test: tests
	./test_all

clean:
	rm -f $(OBJECTS) libnumerical.a test_all

.PHONY: all library tests test clean
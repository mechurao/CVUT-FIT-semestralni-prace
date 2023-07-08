.PHONY: all compile run doc clean
.DEFAULT_GOAL = all

CXX = g++
CXXFLAGS = -std=c++17 -fsanitize=address -Wall -pedantic
LDFLAGS = -lncurses
EXECUTABLE = mechuon1
SOURCES:=  $(wildcard src/*.cpp src/*/*.cpp src/*/*/*.cpp)


all: doc compile

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c -o $@ -c $<
	@$(CXX) $(CXXFLAGS) -MM -MT $*.o $*.cpp > $*.d



compile: $(SOURCES:.cpp=.o)
	@$(CXX) $(CXXFLAGS) $(SOURCES:.cpp=.o) -o $(EXECUTABLE) $(LDFLAGS)

run: compile
	@./$(EXECUTABLE)

clean:
	@rm -f -- src/*.o src/*/*.o src/*/*/*.o
	@rm -f -- src/*.d src/*/*.d src/*/*/*.d
	@rm -f ./$(EXECUTABLE)
	@rm -rf -- doc/

doc:
	doxygen Doxyfile
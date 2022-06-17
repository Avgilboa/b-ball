#!make -f
# This Makefile can handle any set of cpp and hpp files.
# To use it, you should put all your cpp and hpp files in the SOURCE_PATH folder.

CXX=clang++-9
CXXVERSION=c++2a
CXXFLAGS=-std=$(CXXVERSION) -Wsign-conversion
TIDY_FLAGS=-extra-arg=-std=$(CXXVERSION) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=*
TEST_SOURCES=Schedule.cpp League.cpp Game.cpp Team.cpp test.cpp
TEST_O=Schedule.o League.o Game.o Team.o

run: test demo

files:
	$(CXX) $(CXXFLAGS) $(TEST_SOURCES) -c

demo:files
	@echo "Running demo..."
	@$(CXX) $(CXXFLAGS) $(TEST_O) -o demo demo.cpp
	@./demo


test:files TestCounter.o Test.o
	@echo "Running tests..."
	@$(CXX) $(CXXFLAGS) -o test $(TEST_O)   test.cpp TestCounter.o Test.o
	@./test

TestCounter.o:
	@echo "Compiling TestCounter.cpp..."
	@$(CXX) $(CXXFLAGS) -c TestCounter.cpp

Test.o:
	@echo "Compiling Test.cpp..."
	@$(CXX) $(CXXFLAGS) -c Test.cpp


tidy:
	clang-tidy $(SOURCES) $(HEADERS) $(TIDY_FLAGS) --

valgrind: test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

clean:
	rm -f *.o test
	rm -f StudentTest*
	rm -f demo

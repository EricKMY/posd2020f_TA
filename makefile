.PHONY: clean  
SRC = ./src/shape.h ./src/ellipse.h ./src/rectangle.h ./src/triangle.h ./src/two_dimensional_coordinate.h ./src/sort.h
TEST = ./test/ut_ellipse.h ./test/ut_rectangle.h ./test/ut_triangle.h ./test/ut_sort.h

all:directories ./bin/ut_main

./bin/ut_main: ./test/ut_main.cpp $(TEST) $(SRC)
	g++ -std=c++11 -Wfatal-errors -o $@ $< -lgtest -lpthread

directories:
	mkdir -p ./bin
	mkdir -p ./obj

clean:
	rm -rf ./bin
	rm -rf ./obj

stat:
	wc ./src/* ./test/*
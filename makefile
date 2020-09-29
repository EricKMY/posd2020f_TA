.PHONY: clean  
SRC = src/shape.h src/ellipse.h src/rectangle.h src/triangle.h src/two_dimensional_coordinate.h src/compound_shape.h src/utility.h src/iterator.h src/null_iterator.h
TEST = test/ut_ellipse.h test/ut_rectangle.h test/ut_triangle.h test/ut_compound_shape.h test/ut_iterator.h test/ut_utility.h

all:directories bin/ut_main

bin/ut_main: test/ut_main.cpp $(TEST) obj/shape.o $(SRC)
	g++ -std=c++11 -Wfatal-errors -o $@ $< obj/shape.o -lgtest -lpthread

obj/shape.o: src/shape.cpp src/shape.h
	g++ -std=c++11 -Wfatal-errors -c $< -o $@

directories:
	mkdir -p bin
	mkdir -p obj

clean:
	rm -rf bin
	rm -rf obj

stat:
	wc src/* test/*
.PHONY: clean  

SHAPE = src/shape.h src/ellipse.h src/rectangle.h src/triangle.h src/two_dimensional_coordinate.h src/compound_shape.h
ITERATOR = src/utility.h src/iterator.h src/null_iterator.h src/shape_iterator.h
VISITOR = src/visitor.h src/area_visitor.h src/area_visitor.cpp src/info_visitor.h src/info_visitor.cpp

SRC = $(SHAPE) $(ITERATOR) $(VISITOR)
TEST = test/ut_ellipse.h test/ut_rectangle.h test/ut_triangle.h test/ut_compound_shape.h test/ut_iterator.h test/ut_utility.h test/ut_visitor.h
OBJ = obj/shape.o obj/area_visitor.o obj/info_visitor.o

all:directories bin/ut_main

bin/ut_main: test/ut_main.cpp $(TEST) $(OBJ) $(SRC)
	g++ -std=c++11 -Wfatal-errors -o $@ $< $(OBJ) -lgtest -lpthread

obj/shape.o: src/shape.cpp src/shape.h
	g++ -std=c++11 -Wfatal-errors -c $< -o $@

obj/info_visitor.o: src/info_visitor.cpp src/info_visitor.h
	g++ -std=c++11 -Wfatal-errors -c $< -o $@

obj/area_visitor.o: src/area_visitor.cpp src/area_visitor.h
	g++ -std=c++11 -Wfatal-errors -c $< -o $@

directories:
	mkdir -p bin
	mkdir -p obj

clean:
	rm -rf bin
	rm -rf obj

stat:
	wc src/* test/*
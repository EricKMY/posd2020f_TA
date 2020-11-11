.PHONY: clean  

SHAPE = src/shape.h src/ellipse.h src/rectangle.h src/triangle.h \
		src/compound_shape.h src/two_dimensional_coordinate.h
ITERATOR = src/iterator.h src/null_iterator.h src/shape_iterator.h src/utility.h
VISITOR = src/visitor.h src/area_visitor.h src/info_visitor.h 

BUILDER = src/scanner.h

SRC = $(SHAPE) $(ITERATOR) $(VISITOR) $(BUILDER)



TEST = test/ut_ellipse.h test/ut_rectangle.h test/ut_triangle.h test/ut_compound_shape.h \
		test/ut_iterator.h test/ut_utility.h test/ut_visitor.h test/ut_scanner.h
OBJ = obj/shape.o
all:directories bin/ut_main

bin/ut_main: test/ut_main.cpp $(TEST) $(SRC) $(OBJ)
	g++ -std=c++11 -Wfatal-errors test/ut_main.cpp $(OBJ) -o bin/ut_main -lgtest -lpthread

obj/shape.o: src/shape.cpp src/shape.h
	g++ -std=c++11 -Wfatal-errors -c src/shape.cpp -o obj/shape.o

directories:
	mkdir -p bin
	mkdir -p obj

clean:
	rm -rf bin
	rm -rf obj

stat:
	wc src/* test/*

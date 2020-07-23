
.PHONY: clean  
BIN=bin
SRC=src
TEST=test

all: $(TEST)/ut_main.cpp  $(TEST)/ut_circle.h $(TEST)/ut_sort.h $(SRC)/circle.h $(SRC)/convex_polygon.h $(SRC)/measurable.h  $(SRC)/rectangle.h $(SRC)/triangle.h $(SRC)/two_dimensional_vector.h
	g++ -std=c++11 -Wfatal-errors $(TEST)/ut_main.cpp -o $(BIN)/ut_all  -lgtest -lpthread

clean: 
	rm -r bin/*

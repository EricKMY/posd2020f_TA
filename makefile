
.PHONY: clean  
BIN=bin
SRC=src
TEST=test

all: $(TEST)/ut_main.cpp $(TEST)/ut_ellipse.h $(TEST)/ut_rectangle.h $(TEST)/ut_triangle.h $(TEST)/ut_two_dimensional_vector.h $(TEST)/ut_sort.h  $(SRC)/ellipse.h $(SRC)/shape.h $(SRC)/rectangle.h $(SRC)/triangle.h $(SRC)/two_dimensional_vector.h $(SRC)/sort.h
	g++ -std=c++11 -Wfatal-errors $(TEST)/ut_main.cpp -o $(BIN)/ut_all  -lgtest -lpthread

clean: 
	rm -r bin/*
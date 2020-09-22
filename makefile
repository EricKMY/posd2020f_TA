.PHONY: clean  
CC = g++
SRC = ./src
BIN = ./bin
OBJ = ./obj
TEST = ./test
LIB = -lgtest -lpthread
CFLAGS = -std=c++11
FERROE = -Wfatal-errors

all:directories $(BIN)/ut_main

$(BIN)/ut_main: $(TEST)/ut_main.cpp $(TEST)/ut_ellipse.h $(TEST)/ut_rectangle.h $(TEST)/ut_triangle.h $(TEST)/ut_sort.h  $(SRC)/ellipse.h $(SRC)/shape.h  $(SRC)/rectangle.h $(SRC)/triangle.h $(SRC)/two_dimensional_coordinate.h $(SRC)/sort.h
	$(CC) $(CFLAGS) ${FERROE} -o $@ $< $(LIB)


directories:
	mkdir -p $(BIN)
	mkdir -p $(OBJ)

clean:
	rm -rf $(BIN)
	rm -rf $(OBJ)

stat:
	wc $(SRC)/* $(TEST)/*
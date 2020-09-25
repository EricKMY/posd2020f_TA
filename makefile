CC = g++
SRC = ./src
BIN = ./bin
OBJ = ./obj
TEST = ./test
LIB = -lgtest -lpthread
CFLAGS = -std=c++11
FERROE = -Wfatal-errors

all:directories $(BIN)/ut_main

$(BIN)/ut_main: $(TEST)/ut_main.cpp $(TEST)/ut_rectangle.h $(TEST)/ut_ellipse.h $(TEST)/ut_triangle.h $(TEST)/ut_complex_shape.h  $(OBJ)/shape.o $(SRC)/rectangle.h $(SRC)/ellipse.h $(SRC)/triangle.h $(SRC)/complex_shape.h $(SRC)/two_dimensional_coordinate.h $(SRC)/iterator.h $(SRC)/utility.h
	$(CC) $(CFLAGS) ${FERROE} -o $@ $< $(OBJ)/* $(LIB)

$(OBJ)/shape.o: $(SRC)/shape.cpp $(SRC)/shape.h
	$(CC) $(CFLAGS) ${FERROE} -c $< -o $@

directories:
	mkdir -p $(BIN)
	mkdir -p $(OBJ)

clean:
	rm -rf $(BIN)/*
	rm -rf $(OBJ)/*

run:
	$(BIN)/ut_main

stat:
	wc $(SRC)/* $(TEST)/*
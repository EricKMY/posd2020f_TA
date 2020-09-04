CC = g++
SRC = ./src
BIN = ./bin
OBJ = ./obj
TEST = ./test
LIB = -lgtest -lpthread
CFLAGS = -std=c++11
FERROE = -Wfatal-errors

all:clean directories 

$(BIN)/ut_all: $(TEST)/ut_main.cpp $(TEST)/ut_rectangle.h $(TEST)/ut_ellipse.h $(TEST)/ut_triangle.h $(TEST)/ut_complex_shape.h $(TEST)/ut_sort.h $(TEST)/ut_terminal.h $(OBJ)/shape.o $(SRC)/rectangle.h $(SRC)/ellipse.h $(SRC)/triangle.h $(SRC)/complex_shape.h $(SRC)/two_dimensional_coordinate.h $(SRC)/sort.h $(SRC)/terminal.h
	$(CC) $(CFLAGS) ${FERROE} -o $@ $< $(OBJ)/* $(LIB)

$(OBJ)/shape.o: $(SRC)/shape.cpp $(SRC)/shape.h
	$(CC) $(CFLAGS) ${FERROE} -c $< -o $@

directories:
	mkdir -p $(BIN)
	mkdir -p $(OBJ)

clean:
	rm -rf $(BIN)
	rm -rf $(OBJ)

run:
	$(BIN)/ut_all

stat:
	wc $(SRC)/* $(TEST)/*
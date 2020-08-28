
CC = g++
SRC = ./src
BIN = ./bin
OBJ = ./obj
TEST = ./test
LIB = -lgtest -lpthread
CFLAGS = -std=c++11
FERROE = -Wfatal-errors


# all: $(TEST)/ut_main.cpp $(TEST)/ut_complex_shape.h $(TEST)/ut_rectangle.h $(TEST)/ut_triangle.h $(TEST)/ut_two_dimensional_vector.h $(SRC)/shape.h $(SRC)/complex_shape.h $(SRC)/rectangle.h $(SRC)/triangle.h $(SRC)/two_dimensional_vector.h
# 	g++ -std=c++11 -Wfatal-errors $(TEST)/ut_main.cpp -o $(BIN)/ut_all  -lgtest -lpthread


# all: ut

all:clean directories $(BIN)/ut_all run

$(BIN)/ut_all: $(TEST)/ut_main.cpp $(TEST)/ut_rectangle.h $(TEST)/ut_ellipse.h $(TEST)/ut_triangle.h $(TEST)/ut_sort.h $(TEST)/ut_terminal.h $(OBJ)/shape.o $(SRC)/rectangle.h $(SRC)/ellipse.h $(SRC)/triangle.h $(SRC)/two_dimensional_coordinate.h $(SRC)/sort.h $(SRC)/terminal.h
	$(CC) $(CFLAGS) ${FERROE} -o $@ $< $(OBJ)/* $(LIB)

$(OBJ)/shape.o: $(SRC)/shape.cpp $(SRC)/shape.h
	$(CC) $(CFLAGS) ${FERROE} -c $< -o $@

# sort: $(SRC)/main.cpp $(SRC)/ellipse.h $(SRC)/shape.h $(SRC)/rectangle.h $(SRC)/triangle.h $(SRC)/two_dimensional_coordinate.h $(SRC)/sort.h $(SRC)/terminal.h
# 	g++ -std=c++11 -Wfatal-errors $(SRC)/main.cpp -o $(BIN)/sort  -lgtest -lpthread

# execute:
# 	bin/sort input.txt info_output.txt perimeter des info
# 	bin/sort input.txt area_output.txt perimeter des area
# 	bin/sort input.txt permiter_output.txt perimeter des perimeter

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


# touch:
# 	touch info_output.txt area_output.txt perimeter_output.txt
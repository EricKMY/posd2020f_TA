
.PHONY: clean 
BIN=bin
SRC=src
TEST=test

all: clean mkdir touch ut sort execute
ut: $(TEST)/ut_main.cpp $(TEST)/ut_ellipse.h $(TEST)/ut_rectangle.h $(TEST)/ut_triangle.h $(TEST)/ut_two_dimensional_vector.h $(TEST)/ut_sort.h $(TEST)/ut_terminal.h  $(SRC)/ellipse.h $(SRC)/shape.h $(SRC)/rectangle.h $(SRC)/triangle.h $(SRC)/two_dimensional_vector.h $(SRC)/sort.h $(SRC)/terminal.h
	g++ -std=c++11 -Wfatal-errors $(TEST)/ut_main.cpp -o $(BIN)/ut_all -lgtest -lpthread

sort: $(SRC)/main.cpp $(SRC)/ellipse.h $(SRC)/shape.h $(SRC)/rectangle.h $(SRC)/triangle.h $(SRC)/two_dimensional_vector.h $(SRC)/sort.h $(SRC)/terminal.h
	g++ -std=c++11 -Wfatal-errors $(SRC)/main.cpp -o $(BIN)/sort  -lgtest -lpthread

execute:
	bin/sort input.txt info_output.txt perimeter dec info
	bin/sort input.txt area_ouput.txt perimeter dec area
	bin/sort input.txt permiter_ouput.txt perimeter dec perimeter

clean: 
	rm -f $(BIN)/* rm -f info_output.txt area_output.txt perimeter_output.txt

mkdir:
	mkdir -p $(BIN)

touch:
	touch info_output.txt area_output.txt perimeter_output.txt
CXX = g++
CPPFLAGS = -g -Wall
BIN_DIR = bin

all: $(BIN_DIR)/stack
	./$(BIN_DIR)/stack

$(BIN_DIR)/stack: $(BIN_DIR)/.dirstamp $(BIN_DIR)/stackdbl.o
	$(CXX) $(CPPFLAGS) stacktest.cpp ../problem3/src/llistdbl.cpp $(BIN_DIR)/stackdbl.o -o $(BIN_DIR)/stack

$(BIN_DIR)/stackdbl.o: src/stackdbl.cpp lib/stackdbl.h
	$(CXX) $(CPPFLAGS) -c src/stackdbl.cpp -o $(BIN_DIR)/stackdbl.o

.PHONY: clean

clean: 
	rm -rf $(BIN_DIR)

$(BIN_DIR)/.dirstamp:
	mkdir -p $(BIN_DIR)
	touch $(BIN_DIR)/.dirstamp
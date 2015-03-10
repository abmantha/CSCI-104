CXX = g++
CPPFLAGS = -g -Wall
BIN_DIR = bin

all: $(BIN_DIR)/copytest
	./$(BIN_DIR)/copytest

$(BIN_DIR)/copytest: $(BIN_DIR)/.dirstamp $(BIN_DIR)/llistint.o
	$(CXX) $(CPPFLAGS) copytest.cpp $(BIN_DIR)/llistint.o -o $(BIN_DIR)/copytest

$(BIN_DIR)/llistint.o: $(BIN_DIR)/.dirstamp src/llistint.cpp lib/llistint.h
	$(CXX) $(CPPFLAGS) -c src/llistint.cpp -o $(BIN_DIR)/llistint.o

.PHONY: clean

clean: 
	rm -rf $(BIN_DIR)

$(BIN_DIR)/.dirstamp:
	mkdir -p $(BIN_DIR)
	touch $(BIN_DIR)/.dirstamp
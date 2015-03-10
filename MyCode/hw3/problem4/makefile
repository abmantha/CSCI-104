# makefile for pgindex
CXX = g++
CPPFLAGS = -g -Wall
BIN_DIR = bin

all: $(BIN_DIR)/pgindex

pgindex: $(BIN_DIR)/.dirstamp
	$(CXX) $(CPPFLAGS) pgindex.cpp ../problem3/src/setint.cpp ../problem2/src/llistint.cpp -o $(BIN_DIR)/pgindex

.PHONY: clean

clean: 
	rm -rf $(BIN_DIR)

$(BIN_DIR)/.dirstamp:
	mkdir -p $(BIN_DIR)
	touch $(BIN_DIR)/.dirstamp
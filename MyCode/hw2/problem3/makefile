CXX = g++
CPPFLAGS = -g -Wall
BIN_DIR = bin

all: $(BIN_DIR)/llist
	./$(BIN_DIR)/llist

$(BIN_DIR)/llist: $(BIN_DIR)/.dirstamp $(BIN_DIR)/llistdbl.o
	$(CXX) $(CPPFLAGS) listtest.cpp $(BIN_DIR)/llistdbl.o -o $(BIN_DIR)/llist

$(BIN_DIR)/llistdbl.o: $(BIN_DIR)/.dirstamp src/llistdbl.cpp lib/llistdbl.h
	$(CXX) $(CPPFLAGS) -c src/llistdbl.cpp -o $(BIN_DIR)/llistdbl.o

.PHONY: clean

clean: 
	rm -rf $(BIN_DIR)

$(BIN_DIR)/.dirstamp:
	mkdir -p $(BIN_DIR)
	touch $(BIN_DIR)/.dirstamp



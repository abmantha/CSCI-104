CXX = g++
CPPFLAGS = -g -Wall
BIN_DIR = bin

all: $(BIN_DIR)/alist
	./$(BIN_DIR)/alist

$(BIN_DIR)/alist: $(BIN_DIR)/.dirstamp $(BIN_DIR)/alistint.o
	$(CXX) $(CPPFLAGS) alisttest.cpp $(BIN_DIR)/alistint.o -o $(BIN_DIR)/alist

$(BIN_DIR)/alistint.o: src/alistint.cpp lib/alistint.h
	$(CXX) $(CPPFLAGS) -c src/alistint.cpp -o $(BIN_DIR)/alistint.o

.PHONY: clean

clean: 
	rm -rf $(BIN_DIR)

$(BIN_DIR)/.dirstamp:
	mkdir -p $(BIN_DIR)
	touch $(BIN_DIR)/.dirstamp
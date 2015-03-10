CXX = g++
CPPFLAGS = -g -Wall
BIN_DIR = bin

all: $(BIN_DIR)/settest
	./$(BIN_DIR)/settest

$(BIN_DIR)/settest: $(BIN_DIR)/.dirstamp $(BIN_DIR)/setint.o
	$(CXX) $(CPPFLAGS) settest.cpp ../problem2/src/llistint.cpp $(BIN_DIR)/setint.o -o $(BIN_DIR)/settest

$(BIN_DIR)/setint.o: $(BIN_DIR)/.dirstamp src/setint.cpp lib/setint.h
	$(CXX) $(CPPFLAGS) -c src/setint.cpp -o $(BIN_DIR)/setint.o

.PHONY: clean

clean:
	rm -rf $(BIN_DIR)

$(BIN_DIR)/.dirstamp:
	mkdir -p $(BIN_DIR)
	touch $(BIN_DIR)/.dirstamp
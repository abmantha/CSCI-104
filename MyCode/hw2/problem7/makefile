CXX = g++
CPPFLAGS = -g -Wall
BIN_DIR = bin

all: $(BIN_DIR)/postfix
	./$(BIN_DIR)/postfix postfix.in postfix.out

$(BIN_DIR)/postfix: $(BIN_DIR)/.dirstamp 
	$(CXX) $(CPPFLAGS) postfix.cpp ../problem3/src/llistdbl.cpp ../problem5/src/stackdbl.cpp -o $(BIN_DIR)/postfix

.PHONY: clean

clean: 
	rm -rf $(BIN_DIR)

$(BIN_DIR)/.dirstamp:
	mkdir -p $(BIN_DIR)
	touch $(BIN_DIR)/.dirstamp
CC=g++

SRC_DIR=./src
SRC_FILES=$(SRC_DIR)/main.cpp \
					$(SRC_DIR)/Common/LinkedList.cpp \
					$(SRC_DIR)/Common/HashTable.cpp

OUT_DIR=./build
OUT_FILE=$(OUT_DIR)/escale

build:
	mkdir -p $(OUT_DIR)
	$(CC) $(SRC_FILES) -o $(OUT_FILE)

clean:
	rm -rf $(OUT_DIR)

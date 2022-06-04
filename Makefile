CC=g++

SRC_DIR=./src
SRC_FILES=$(SRC_DIR)/main.cpp \
					$(SRC_DIR)/Common/LinkedList.cpp

OUT_DIR=./build
OUT_FILE=$(OUT_DIR)/eslcale

build:
	mkdir -p $(OUT_DIR)
	$(CC) $(SRC_FILES) -o $(OUT_FILE)

clean:
	rm -rf $(OUT_DIR)

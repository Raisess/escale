CC=g++
FLAGS=-Wno-deprecated

SRC_DIR=./src
SRC_FILES=$(SRC_DIR)/Common/LinkedList.cpp \
					$(SRC_DIR)/Common/HashTable.cpp \
					$(SRC_DIR)/File.cpp \
					$(SRC_DIR)/Cache.cpp \

SERVER_FILES=$(SRC_FILES) \
						 $(SRC_DIR)/Socket.cpp \
						 $(SRC_DIR)/server.cpp

TEST_FILES=$(SRC_FILES) \
					 $(SRC_DIR)/main.cpp

OUT_DIR=./build
OUT_FILE=$(OUT_DIR)/escale.o

build:
	mkdir -p $(OUT_DIR)
	$(CC) $(FLAGS) $(SERVER_FILES) -o $(OUT_FILE)

build_test:
	mkdir -p $(OUT_DIR)
	$(CC) $(FLAGS) $(TEST_FILES) -o $(OUT_DIR)/test

clean:
	rm -rf $(OUT_DIR)

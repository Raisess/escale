CXX=g++

SRC_DIR=./src
SRC_FILES=$(SRC_DIR)/Common/LinkedList.cpp \
					$(SRC_DIR)/Common/HashTable.cpp \
					$(SRC_DIR)/Cache.cpp \
					$(SRC_DIR)/File.cpp \
					$(SRC_DIR)/main.cpp

OUT_DIR=./build
OUT_FILE=$(OUT_DIR)/escale.o

build:
	mkdir -p $(OUT_DIR)
	$(CXX) $(SRC_FILES) -o $(OUT_FILE)

clean:
	rm -rf $(OUT_DIR)

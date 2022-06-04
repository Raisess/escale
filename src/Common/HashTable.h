#pragma once

#include <iostream>
#include <functional>
#include "LinkedList.h"

#define TABLE_SIZE 100

namespace Common {

class HashTable {
public:
  HashTable();

  unsigned int hash(std::string data);
  void for_each(std::function<void(std::string, int)> callback);

private:
  LinkedList<std::string>* table[TABLE_SIZE] = {};
};

}

#pragma once

#include <iostream>
#include <functional>
#include "hash_types.h"
#include "LinkedList.h"

#define TABLE_SIZE 100

namespace Common {

class HashTable {
public:
  HashTable();
  ~HashTable() {}

  void append(std::string key, std::string value, const long int duration);
  void remove(std::string key);
  void for_each(std::function<void(HashBlock, int)> callback);
  HashBlock find(std::string key);

private:
  LinkedList<HashBlock>* table[TABLE_SIZE] = {};

  unsigned int hash(std::string key);
};

}

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
  ~HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
      delete this->table[i];
    }
  }

  void append(const std::string& key, const std::string& value, const long int duration);
  void remove(const std::string& key);
  void for_each(std::function<void(HashBlock&, int)> callback);
  HashBlock find(const std::string& key);

private:
  LinkedList<HashBlock>* table[TABLE_SIZE] = {};

  unsigned int hash(const std::string& key);
};

}

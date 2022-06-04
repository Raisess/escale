#include "HashTable.h"

Common::HashTable::HashTable() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    this->table[i] = new LinkedList<HashBlock>();
  }
}

unsigned int Common::HashTable::hash(std::string key, std::string value) {
  unsigned int hash = 0;

  for (int i = 0; i < value.size(); i++) {
    hash += key[i];
    hash += hash * key[i];
    hash = hash % TABLE_SIZE;
  }

  this->table[hash]->create_node({ key, value });

  return hash;
}

void Common::HashTable::for_each(std::function<void(HashBlock, int)> callback) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    this->table[i]->for_each([&](Node<HashBlock>* node) -> void {
      callback(node->data, i);
    });
  }
}

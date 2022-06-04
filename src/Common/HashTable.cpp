#include "HashTable.h"

Common::HashTable::HashTable() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    this->table[i] = new LinkedList<std::string>();
  }
}

unsigned int Common::HashTable::hash(std::string value) {
  unsigned int key = 0;

  for (int i = 0; i < value.size(); i++) {
    key += value[i];
    key += key * value[i];
    key = key % TABLE_SIZE;
  }

  this->table[key]->create_node(value);

  return key;
}

void Common::HashTable::for_each(std::function<void(std::string, int)> callback) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    this->table[i]->for_each([&](Node<std::string>* node) -> void {
      callback(node->data, i);
    });
  }
}

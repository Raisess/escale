#include "HashTable.h"

Common::HashTable::HashTable() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    this->table[i] = new LinkedList<HashBlock>();
  }
}

unsigned int Common::HashTable::hash(const std::string& key) {
  unsigned int hash = 0;

  for (int i = 0; i < key.size(); i++) {
    hash += key[i];
    hash += hash * key[i];
    hash = hash % TABLE_SIZE;
  }

  return hash;
}

void Common::HashTable::append(const std::string& key, const std::string& value, const long int duration) {
  unsigned int hash = this->hash(key);
  this->table[hash]->create_node({ key, value, time(nullptr) + duration });
}

void Common::HashTable::remove(const std::string& key) {
  unsigned int hash = this->hash(key);

  this->table[hash]->for_each([&](Node<HashBlock>* node) -> void {
    if (node->data.key == key) {
      this->table[hash]->remove_node(node);
      return;
    }
  });
}

void Common::HashTable::for_each(std::function<void(HashBlock&, int)> callback) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    this->table[i]->for_each([&](Node<HashBlock>* node) -> void {
      callback(node->data, i);
    });
  }
}

HashBlock Common::HashTable::find(const std::string& key) {
  unsigned int hash = this->hash(key);
  HashBlock hash_block;

  this->table[hash]->for_each([&](Node<HashBlock>* node) -> void {
    if (node->data.key == key) {
      hash_block = node->data;
      return;
    }
  });

  return hash_block;
}

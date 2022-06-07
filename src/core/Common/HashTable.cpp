#include "HashTable.h"

Common::HashTable::HashTable() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    this->table[i] = new LinkedList<HashBlock>();
  }
}

unsigned int Common::HashTable::hash(std::string key) {
  unsigned int hash = 0;

  for (int i = 0; i < key.size(); i++) {
    hash += key[i];
    hash += hash * key[i];
    hash = hash % TABLE_SIZE;
  }

  return hash;
}

void Common::HashTable::append(std::string key, std::string value, unsigned long int duration) {
  unsigned int hash = this->hash(key);
  this->table[hash]->create_node({ key, value, time(NULL) + duration });
}

void Common::HashTable::remove(std::string key) {
  unsigned int hash = this->hash(key);
  Node<HashBlock>* ptr;

  this->table[hash]->for_each([&](Node<HashBlock>* node) -> void {
    if (node->data.key == key) {
      ptr = node;
    }
  });

  this->table[hash]->remove_node(ptr);
}

void Common::HashTable::for_each(std::function<void(HashBlock, int)> callback) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    this->table[i]->for_each([&](Node<HashBlock>* node) -> void {
      callback(node->data, i);
    });
  }
}

HashBlock Common::HashTable::find(std::string key) {
  unsigned int hash = this->hash(key);
  HashBlock hash_block;

  this->table[hash]->for_each([&](Node<HashBlock>* node) -> void {
    if (node->data.key == key) {
      hash_block = node->data;
    }
  });

  return hash_block;
}

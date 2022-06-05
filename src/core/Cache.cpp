#include "Cache.h"

Cache::Cache() {
  this->hash_table = new Common::HashTable();
  this->file = new File(CACHE_FILE);
}

void Cache::set(std::string key, std::string value) {
  this->hash_table->append(key, value);
}

std::string Cache::get(std::string key) {
  HashBlock hash_block = this->hash_table->find(key);
  return hash_block.value;
}

void Cache::save_on_disk() {}

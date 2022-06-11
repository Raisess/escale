#pragma once

#include "./Common/HashTable.h"
#include "File.h"

#define CACHE_FILE "tmp"

class Cache {
public:
  Cache();

  void set(std::string key, std::string value, unsigned int ttl_sec) const;
  std::string get(std::string key) const;
  void remove(std::string key) const;
  unsigned long int ttl(std::string key);
  void save_on_disk();
  void read_from_disk();

private:
  Common::HashTable* hash_table;
  File* file;
};

#pragma once

#include "./Common/HashTable.h"
#include "File.h"

#define CACHE_FILE "tmp"

class Cache {
public:
  Cache();

  void set(std::string key, std::string value);
  std::string get(std::string key);
  void save_on_disk();
  void read_from_disk();

private:
  Common::HashTable* hash_table;
  File* file;
};

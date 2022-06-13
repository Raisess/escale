#pragma once

#include "./Common/HashTable.h"
#include "File.h"

#define CACHE_FILE "tmp"

class Cache {
public:
  Cache();
  ~Cache() {}

  static Cache* SingleInstance();

  void set(const std::string key, const std::string value, const unsigned int ttl_sec) const;
  const std::string get(const std::string key) const;
  void remove(const std::string key) const;
  unsigned long int ttl(const std::string key);
  void save_on_disk();
  void read_from_disk();

private:
  static Cache* unique_instance;
  Common::HashTable* hash_table;
  File* file;
};

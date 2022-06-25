#pragma once

#include <mutex>
#include "./Common/HashTable.h"
#include "File.h"

#define CACHE_FILE "tmp"

class Cache {
public:
  Cache();
  ~Cache() {
    delete this->hash_table;
    delete this->file;
  }

  static Cache* SingleInstance();

  void set(const std::string& key, const std::string& value, const unsigned int ttl_sec) const;
  const std::string get(const std::string& key) const;
  void remove(const std::string& key) const;
  unsigned long int ttl(const std::string& key);
  void save_on_disk();
  void read_from_disk();

private:
  mutable std::mutex set_lock;
  mutable std::mutex sod_lock;

  static Cache* unique_instance;
  Common::HashTable* hash_table;
  File* file;
};

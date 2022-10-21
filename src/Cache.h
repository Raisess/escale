#pragma once

#include <memory>
#include <mutex>
#include "./Common/HashTable.h"
#include "File.h"

#define CACHE_FILE "tmp"

class Cache {
public:
  Cache();
  ~Cache();

  static std::shared_ptr<Cache> SingleInstance();

  void set(const std::string& key, const std::string& value, const unsigned int ttl_sec) const;
  const std::string get(const std::string& key);
  void remove(const std::string& key) const;
  unsigned long int ttl(const std::string& key);
  void save_on_disk();
  void read_from_disk();

private:
  mutable std::mutex set_lock;
  mutable std::mutex sod_lock;

  static std::shared_ptr<Cache> Instance;
  std::unique_ptr<Common::HashTable> hash_table = nullptr;
  std::unique_ptr<File> file = nullptr;
};

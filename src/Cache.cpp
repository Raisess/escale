#include <regex>
#include "Cache.h"

Cache::Cache() {
  this->hash_table = new Common::HashTable();
  this->file = new File(CACHE_FILE);
}

Cache* Cache::unique_instance = NULL;
Cache* Cache::SingleInstance() {
  if (Cache::unique_instance == NULL) {
    Cache::unique_instance = new Cache();
  }

  return Cache::unique_instance;
}

void Cache::set(const std::string& key, const std::string& value, const unsigned int ttl_sec) const {
  std::lock_guard<std::mutex> guard(this->set_lock);
  this->hash_table->append(key, value, ttl_sec);
}

const std::string Cache::get(const std::string& key) const {
  return this->hash_table->find(key).value;
}

void Cache::remove(const std::string& key) const {
  this->hash_table->remove(key);
}

unsigned long int Cache::ttl(const std::string& key) {
  HashBlock hash_block = this->hash_table->find(key);

  if (hash_block.key == "") {
    return 0;
  }

  long int ttl = hash_block.duration - time(NULL);

  if (ttl <= 0) {
    this->hash_table->remove(key);
  }

  return ttl;
}

void Cache::save_on_disk() {
  std::lock_guard<std::mutex> guard(this->sod_lock);
  std::string str;

  this->hash_table->for_each([&](HashBlock hash_block, int) -> void {
    str += hash_block.key + "%" + std::to_string(hash_block.duration) + "|" + hash_block.value + "\n";
  });

  this->file->write(str);
}

void Cache::read_from_disk() {
  std::string data = this->file->read();
  std::string tmp = "";
  std::string key = "";
  std::string value = "";
  int ttl_sec = -1;

  for (int i = 0; i < data.size(); i++) {
    std::string cchar = data.substr(i, 1);

    if (key == "" && std::regex_match(cchar, std::regex("%"))) {
      key = tmp;
      tmp = "";
    } else if (ttl_sec == -1 && std::regex_match(cchar, std::regex("\\|"))) {
      ttl_sec = (long int) tmp.c_str() - time(NULL);
      tmp = "";
    } else if (tmp != "" && std::regex_match(cchar, std::regex("\\n"))) {
      value = tmp;
      this->set(key, value, ttl_sec);

      key = "";
      value = "";
      ttl_sec = -1;
      tmp = "";
    } else {
      tmp += cchar;
    }
  }
}

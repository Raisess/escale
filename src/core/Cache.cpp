#include <regex>
#include "Cache.h"

Cache::Cache() {
  this->hash_table = new Common::HashTable();
  this->file = new File(CACHE_FILE);
}

void Cache::set(std::string key, std::string value, unsigned int ttl_sec) {
  this->hash_table->append(key, value, ttl_sec);
}

std::string Cache::get(std::string key) {
  HashBlock hash_block = this->hash_table->find(key);
  return hash_block.value;
}

void Cache::remove(std::string key) {
  this->hash_table->remove(key);
}

unsigned int Cache::ttl(std::string key) {
  HashBlock hash_block = this->hash_table->find(key);

  if (hash_block.key == "") {
    return 0;
  }

  unsigned int ttl = hash_block.duration - time(NULL);
  return ttl;
}

void Cache::save_on_disk() {
  std::ostrstream ostr;

  this->hash_table->for_each([&](HashBlock hash_block, int) -> void {
    ostr << hash_block.key << ":" << hash_block.value << "\n";
  });

  this->file->write(ostr.str());
}

void Cache::read_from_disk() {
  std::string data = this->file->read();
  std::string tmp;
  std::string key;
  std::string value;

  for (int i = 0; i < data.size(); i++) {
    std::string cchar = data.substr(i, 1);

    if (std::regex_match(cchar, std::regex(":"))) {
      key = tmp;
      tmp = "";
    } else if (std::regex_match(cchar, std::regex("\\n"))) {
      if (tmp != "") {
        value = tmp;
        tmp = "";
        this->set(key, value, 100);
      }
    } else {
      tmp.append(cchar);
    }
  }
}

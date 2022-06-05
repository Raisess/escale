#include <iostream>
#include "Cache.h"

int main() {
  Cache* cache = new Cache();
  cache->read_from_disk();

  /*cache->set("Key", "Value");
  cache->set("Test", "Test");
  cache->set("Test2", "Test2");
  cache->set("Test2", "Test2");
  cache->set("Danilo", "Danilo");
  cache->set("Diff", "Key");*/

  std::cout << "Key: " << cache->get("Key") << std::endl;
  std::cout << "Key2: " << cache->get("Key2") << std::endl;
  std::cout << "Test: " << cache->get("Test") << std::endl;
  std::cout << "Test2: " << cache->get("Test2") << std::endl;
  std::cout << "Diff: " << cache->get("Diff") << std::endl;
  std::cout << "Danilo: " << cache->get("Danilo") << std::endl;

  //cache->save_on_disk();

  return 0;
}

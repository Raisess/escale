#include <iostream>
#include "Cache.h"

int main() {
  Cache* cache = new Cache();

  cache->read_from_disk();
  cache->set("A random key", "A random value", 10);

  std::cout << "A random key: " << cache->get("A random key") << " | ttl: " << cache->ttl("A random key") << std::endl;
  std::cout << "Key: " << cache->get("Key") << std::endl;
  std::cout << "Key2: " << cache->get("Key2") << std::endl;
  std::cout << "Test: " << cache->get("Test") << std::endl;
  std::cout << "Test2: " << cache->get("Test2") << std::endl;
  std::cout << "Diff: " << cache->get("Diff") << std::endl;
  std::cout << "Danilo: " << cache->get("Danilo") << std::endl;

  cache->remove("A random key");
  cache->remove("Test");
  cache->remove("Danilo");

  std::cout << "A random key: " << cache->get("A random key") << " | ttl: " << cache->ttl("A random key") << std::endl;
  std::cout << "Key: " << cache->get("Key") << std::endl;
  std::cout << "Key2: " << cache->get("Key2") << std::endl;
  std::cout << "Test: " << cache->get("Test") << std::endl;
  std::cout << "Test2: " << cache->get("Test2") << std::endl;
  std::cout << "Diff: " << cache->get("Diff") << std::endl;
  std::cout << "Danilo: " << cache->get("Danilo") << std::endl;

  return 0;
}

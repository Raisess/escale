#include <iostream>
#include <memory>
#include "Cache.h"

int main() {
  Cache cache;

  cache.set("A random key", "A random value", 10);
  cache.set("Test", "Test Value", 10);

  std::cout << "A random key: " << cache.get("A random key") << " | ttl: " << cache.ttl("A random key") << std::endl;
  std::cout << "Test: " << cache.get("Test") << std::endl;

  cache.save_on_disk();

  cache.remove("A random key");
  cache.remove("Test");

  std::cout << "A random key: " << cache.get("A random key") << " | ttl: " << cache.ttl("A random key") << std::endl;
  std::cout << "Test: " << cache.get("Test") << std::endl;

  // TODO: fix ttl when read from disk
  cache.read_from_disk();

  std::cout << "A random key: " << cache.get("A random key") << " | ttl: " << cache.ttl("A random key") << std::endl;
  std::cout << "Test: " << cache.get("Test") << std::endl;

  auto cache_two = Cache::SingleInstance();

  cache_two->set("Unique key", "Unique value", 10);
  std::cout << "Unique key: " << cache_two->get("Unique key") << std::endl;

  auto cache_tree = Cache::SingleInstance();

  std::cout << "Unique key: " << cache_tree->get("Unique key") << std::endl;

  return 0;
}

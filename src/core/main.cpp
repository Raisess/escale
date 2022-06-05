#include <iostream>
#include "Common/LinkedList.h"
#include "Common/HashTable.h"

int main() {
  Common::HashTable* hash_table = new Common::HashTable();

  std::cout << "Test: " << hash_table->hash("Test", "Test") << std::endl;
  std::cout << "Test2: " << hash_table->hash("Test2", "Test2") << std::endl;
  std::cout << "Test2: " << hash_table->hash("Test2", "Test2") << std::endl;
  std::cout << "Danilo: " << hash_table->hash("Danilo", "Danilo") << std::endl;
  std::cout << "Diff Key: " << hash_table->hash("Diff", "Key") << std::endl;

  hash_table->for_each([](HashBlock hash_block, int table_key) -> void {
    std::cout << table_key << ": " << "(" << hash_block.key << ") " << hash_block.value << std::endl;
  });

  return 0;
}

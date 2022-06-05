#include <iostream>
#include "Common/LinkedList.h"
#include "Common/HashTable.h"

int main() {
  Common::HashTable* hash_table = new Common::HashTable();

  hash_table->append("Test", "Test");
  hash_table->append("Test2", "Test2");
  hash_table->append("Test2", "Test2");
  hash_table->append("Danilo", "Danilo");
  hash_table->append("Diff", "Key");

  hash_table->for_each([](HashBlock hash_block, int table_key) -> void {
    std::cout << table_key << ": " << "(" << hash_block.key << ") " << hash_block.value << std::endl;
  });

  return 0;
}

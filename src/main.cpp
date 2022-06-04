#include <iostream>
#include "Common/LinkedList.h"
#include "Common/HashTable.h"

int main() {
  Common::HashTable* hash_table = new Common::HashTable();

  std::cout << "Test: " << hash_table->hash("Test") << std::endl;
  std::cout << "Test2: " << hash_table->hash("Test2") << std::endl;
  std::cout << "Test2: " << hash_table->hash("Test2") << std::endl;
  std::cout << "Danilo: " << hash_table->hash("Danilo") << std::endl;

  hash_table->for_each([](std::string value, int table_key) -> void {
    std::cout << table_key << ": " << value << std::endl;
  });

  return 0;
}

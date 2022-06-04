#include <iostream>
#include "Common/LinkedList.h"

int main() {
  Common::LinkedList<int>* linked_list = new Common::LinkedList<int>();

  linked_list->create_node(1);
  linked_list->create_node(2);
  linked_list->create_node(3);

  linked_list->for_each([](Common::Node<int>* node) -> void {
    std::cout << node->data << std::endl;
  });

  return 0;
}

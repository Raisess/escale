#pragma once

#include <iostream>
#include <functional>

namespace Common {

template<typename T>
class Node {
public:
  T data;
  Node* next = NULL;

  Node(T data) {
    this->data = data;
  }
  ~Node() {}
};

template<typename T>
class LinkedList {
public:
  Node<T>* create_node(T data);
  void remove_node(Node<T>* ptr);
  void for_each(std::function<void(Node<T>*)> callback);

private:
  Node<T>* head = NULL;
};

}

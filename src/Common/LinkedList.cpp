#include "LinkedList.h"
#include "hash_types.h"

template class Common::LinkedList<int>;
template class Common::LinkedList<std::string>;
template class Common::LinkedList<HashBlock>;

template<typename T>
Common::Node<T>* Common::LinkedList<T>::create_node(const T& data) {
  Node<T>* node = new Node<T>(data);

  if (this->head != NULL) {
    Node<T>* tmp = this->head;

    while (tmp->next != NULL) {
      tmp = tmp->next;
    }

    tmp->next = node;
  } else {
    this->head = node;
  }

  return node;
}

template<typename T>
void Common::LinkedList<T>::remove_node(Node<T>* ptr) {
  Node<T>* tmp = this->head;

  if (this->head == ptr) {
    Node<T>* curr = this->head;
    this->head = this->head->next;
    delete curr;
    return;
  }

  while (tmp != NULL) {
    if (tmp->next == ptr) {
      Node<T>* curr = tmp->next;
      tmp->next = tmp->next->next;
      delete curr;
      return;
    }

    tmp = tmp->next;
  }
}

template<typename T>
void Common::LinkedList<T>::for_each(std::function<void(Node<T>*)> callback) {
  Node<T>* tmp = this->head;

  while (tmp != NULL) { 
    callback(tmp);
    tmp = tmp->next;
  }
}

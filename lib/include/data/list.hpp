#pragma once

namespace oh {
  namespace data {

template<typename T>
class List
{
public:
  List()
    : head_(nullptr), size_(0) {}

  T Head() const;
  List<T> Tail() const;
  void Append(T element);
  bool IsEmpty() const { return head_ == nullptr; }
  unsigned Size() const;

private:

  struct Node {
    Node(T val, Node* nxt)
      : value(val), next(nxt) {}

    T value;
    Node* next;
  };

  List(Node* head)
    : head_(head) {}

  Node* head_;
  unsigned size_;
};

template<typename T>
T List<T>::Head() const
{
  if (head_ == nullptr) throw T(); // TODO: throw proper exception
  return head_->value;
}

template<typename T>
List<T> List<T>::Tail() const
{
  if (head_ == nullptr) throw T(); // TODO: throw proper exception
  return List<T>(head_->next);
}

template<typename T>
void List<T>::Append(T element)
{
  if (IsEmpty()) {
    head_ = new Node(element, nullptr);
  }
  else {
    Node* current = head_;
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = new Node(element, nullptr);
  }
}

template<typename T>
unsigned List<T>::Size() const
{
  unsigned size = 0;
  Node* current = head_;
  while (current != nullptr) {
    ++size;
    current = current->next;
  }
  return size;
}

}}
// ~~ oh::data::List

#pragma once

#include <exception>

namespace oh {
  namespace data {

template<typename T>
class BinaryTree
{
public:
  BinaryTree()
    : root_(nullptr) {}
  BinaryTree(T value)
    : root_(new Node(value, nullptr, nullptr)) {}

  struct Node;

  Node* Root() const { return root_; }
  bool IsEmpty() const { return root_ == nullptr; }
  bool IsLeaf() const;

  // Need deep copy here (!)
  BinaryTree<T> LeftSubtree() const;
  BinaryTree<T> RightSubtree() const;

  void AddLeftChild(Node* leaf);
  void AddLeftChild(BinaryTree subtree);

  void AddRightChild(Node* leaf);
  void AddRightChild(BinaryTree subtree);

  void Print();

  struct Node {
    Node(T val, Node* l, Node* r)
      : value(val), left(l), right(r) {}

    T value;
    Node *left, *right;
  };

private:
  BinaryTree(Node* root)
    : root_(root) {}

  void Print(Node* node, int level);

  Node* root_;
};

template<typename T>
void BinaryTree<T>::Print(Node* node, int level)
{
  if (node != nullptr) {
    Print(node->left, ++level);
    for (unsigned i = 0; i < level; ++i) {
      std::cout << "--";
    }
    std::cout << node->value << std::endl;
    Print(node->right, ++level);
  }
}

template<typename T>
void BinaryTree<T>::Print()
{
  Print(root_, 0);
}

template<typename T>
void BinaryTree<T>::AddRightChild(BinaryTree subtree)
{
  if (IsEmpty()) return;
  root_->right = subtree.Root();
}

template<typename T>
void BinaryTree<T>::AddRightChild(Node* leaf)
{
  if (IsEmpty()) return;
  root_->right = leaf;
}

template<typename T>
void BinaryTree<T>::AddLeftChild(BinaryTree subtree)
{
  if (IsEmpty()) return;
  root_->left = subtree.Root();
}

template<typename T>
void BinaryTree<T>::AddLeftChild(Node* leaf)
{
  if (IsEmpty()) return;
  root_->left = leaf;
}

template<typename T>
bool BinaryTree<T>::IsLeaf() const
{
  return !IsEmpty() && root_->left == nullptr && root_->right == nullptr;
}

template<typename T>
BinaryTree<T> BinaryTree<T>::RightSubtree() const
{
  if (!IsEmpty() && root_->right != nullptr)
    return BinaryTree(root_->right);
  else
    return BinaryTree<T>();
}

template<typename T>
BinaryTree<T> BinaryTree<T>::LeftSubtree() const
{
  if (!IsEmpty() && root_->left != nullptr)
    return BinaryTree(root_->left);
  else
    return BinaryTree<T>();
}

}}
// ~~ oh::data::

#include"doubly_linked_list.h"
#include "gtest/gtest.h"

TEST(LinkedListTest,  createNode) {
  using namespace linked_list;

  NodePtr node = createNode("Apple");
  ASSERT_EQ(node->data, "Apple");
  ASSERT_EQ(node->next, nullptr);
  ASSERT_EQ(node->prev, nullptr);
  delete node;
}

TEST(LinkedListTest,  insert) {
  using namespace linked_list;

  NodePtr node = createNode("Apple");
  node = insert(node, createNode("Banana"));
  node = insert(node, createNode("Cherry"));
  NodePtr current = node;
  ASSERT_EQ(current->data, "Cherry");
  ASSERT_EQ(current->next->data, "Banana");
  ASSERT_EQ(current->prev, nullptr);
  current = current->next;
  ASSERT_EQ(current->next->data, "Apple");
  ASSERT_EQ(current->prev->data, "Cherry");
  current = current->next;

  ASSERT_EQ(current->prev->data, "Banana");
  ASSERT_EQ(current->next, nullptr);
  // Free all
  while (node != nullptr) {
    NodePtr temp = node;
    node = node->next;
    delete temp;
  }
}

TEST(LinkedListTest,  erase) {
  using namespace linked_list;

  Node* node = createNode("Apple");
  auto banana = add(node, createNode("Banana"));
  node = add(banana, createNode("Cherry"));
  Node* current = node;
  current = erase(banana);
  delete banana;
  ASSERT_EQ(current->data, "Cherry");
  ASSERT_EQ(current->next, nullptr);
  ASSERT_EQ(current->prev->data, "Apple");
  // Free all
  while (node != nullptr) {
    Node* temp = node;
    node = node->prev;
    delete temp;
  }
}

TEST(LinkedListTest,  add) {
  using namespace linked_list;

  Node* node = createNode("Apple");
  node = add(node, createNode("Banana"));
  node = add(node, createNode("Cherry"));
  Node* current = node;
  ASSERT_EQ(current->data, "Cherry");

  ASSERT_EQ(current->next, nullptr);
  current = current->prev;
  ASSERT_EQ(current->data, "Banana");
  ASSERT_EQ(current->next->data, "Cherry");
  current = current->prev;
  ASSERT_EQ(current->data, "Apple");
  ASSERT_EQ(current->next->data, "Banana");
  ASSERT_EQ(current->prev, nullptr);
  // Free all
  while (node != nullptr) {
    Node* temp = node;
    node = node->prev;
    delete temp;
  }
}

#include<string>
namespace linked_list{
  // Define the structure for a node in the doubly linked list
  using Value = std::string;

  struct Node {
    Value data;
    Node* next;
    Node* prev;
  };

  using NodePtr = Node*;

  /*
   * @brief Create a new node with the given value
   * @param value The value to store in the node
   * @return The new node
   */
  NodePtr createNode(Value value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
  }

  /*
   * @brief Insert a node before a given node. If the given node is nullptr, insert at the beginning.
   * @param p The node before which to insert
   * @param n The node to insert
   * @return The inserted node
   */
  NodePtr insert(NodePtr p, NodePtr n){
    if(n == nullptr) return p;
    if(p == nullptr) return n;
    n->next = p;
    if(p->prev) p->prev->next = n;
    n->prev = p->prev;
    p->prev = n;
    return n;
  }

  /*
   * @brief Add a node after a given node.
   * @param p The node after which to add
   * @param n The node to add
   * @return The added node
   */
  Node* add(Node* p, Node* n){
    if(n == nullptr) return p;
    if(p == nullptr) return n;
    n->prev = p;
    if(p->next) p->next->prev = n;
    n->next = p->next;
    p->next = n;
    return n;
  }

  /*
   * @brief Remove a node from the list
   * @param p The node to remove
   * @return The next node
   */
  Node* erase(Node* p){
    if(p == nullptr) return nullptr;
    if(p->next) p->next->prev = p->prev;
    if(p->prev) p->prev->next = p->next;
    Node* next = p->next;
    return next;
  }

}

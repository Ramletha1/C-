// self-referential structure
#include <iomanip>
class Node {
private:
  int value;
  string name;
  Node *nextPtr;
  Node *prevPtr;

public:
  Node(int x=0, string y="");
  ~Node();
  Node* get_next();

  int get_data();
  void set_next(Node* t) ; 
  void print();
  void set_prev(Node* t);
  Node* get_prev();

  // for doubly linked list
  /*
  Node * get_prev();
  /* create another set_prev function or modify set_next to set previous at the same time
  void set_prev(Node* t); 
  */
};

typedef Node *NodePtr; // synonym for Node*

Node::Node(int x, string y) {
  value = x;
  name = y;
  nextPtr = NULL;
}

Node::~Node() { cout << value << " deleted" << endl; }

NodePtr Node::get_next() { return nextPtr; }

int Node::get_data() { return value; }
/*
          previousPtr->set_next(newPtr);
         newPtr->set_next(currentPtr);
*/
void Node::set_next(NodePtr t) {
       this->nextPtr = t; 
  /* or use set next to set previous too*/
      
}

void Node::set_prev(NodePtr t){
  this->prevPtr = t;
}

NodePtr Node::get_prev(){
  return prevPtr;
}

void Node::print(){
  cout << setw(3) << value << " " << name;
}
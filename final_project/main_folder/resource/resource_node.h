#include <iomanip>

class Node {
private:
  string name;
  int value;
  Node *nextPtr;
public:
  Node(int x=0,string n ="NA");
  ~Node();
  Node* get_next();
  int get_data();
  int set_data(int);
  string get_name() { return name; }
  void set_next(Node* t) ; 
};
typedef Node* NodePtr;


Node::Node(int x,string n) {
  value = x;
  name = n;
  nextPtr = NULL;
}

Node::~Node() {}

NodePtr Node::get_next(){
  return nextPtr;
}

int Node::get_data(){
  return value;
}

int Node::set_data(int x) { 
    value = x;
    return x; 
}

void Node::set_next(NodePtr t) {
    this->nextPtr = t; 
}
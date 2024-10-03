#include "resource_node.h"

class resourcesList {
  NodePtr hol;
  int size;
public:
  resourcesList();
  ~resourcesList();
  void insertResource(string ,int);
  void addQuantity(int ,int);
  int isEmpty();
  string deletes(string);
  void printList();
  int getData(string);
  string getString(int x);
};

resourcesList::resourcesList() {
  this->hol = NULL;
  size = 0;
}

resourcesList::~resourcesList() {
  NodePtr t;
  t = hol;
  int i;
  for (i = 0; i < size; i++) {
    t = hol->get_next();
    delete hol;
    hol = t;
  }
}

void resourcesList::insertResource(string n, int value) {
  NodePtr newPtr;    
  NodePtr currentPtr;

  newPtr = new Node(value,n);

  if (hol == NULL) {
      hol = newPtr;
  } 
  else{
      currentPtr = hol;
      while(currentPtr->get_next() != NULL){
          currentPtr=currentPtr->get_next();
      }
      currentPtr->set_next(newPtr);
  }
  ++size;
}

void resourcesList::addQuantity(int n, int value) {
    NodePtr currentPtr;
    currentPtr = hol;
    for (int i=1;i!=n;i++){
        currentPtr = currentPtr->get_next();
    }
    
    currentPtr->set_data(currentPtr->get_data()+value);
    if( currentPtr->get_data() < 0) currentPtr->set_data(0);
}

string resourcesList::deletes(string n) {
  NodePtr currentPtr;
  NodePtr tempPtr;

  // delete first node
  if (n == hol->get_name()) {
    tempPtr = hol;
    hol = hol->get_next();

    size--;
    delete tempPtr;
    return n;
  }
  else {
    currentPtr = hol->get_next();

    while (currentPtr->get_next() != NULL && currentPtr->get_next()->get_name() != n) {
      currentPtr = currentPtr->get_next();
    }

    if (currentPtr->get_next() != NULL) {
      tempPtr = currentPtr->get_next();
      currentPtr ->set_next(tempPtr->get_next());
    
      delete tempPtr;
      size--;
      return n;
    }
  }
    return "N/A";
}

// return 1 if the list is empty, 0 otherwise
int resourcesList::isEmpty() { return hol == NULL; }

void resourcesList::printList() {
  NodePtr currentPtr = hol;
  if (isEmpty()) {
    cout << "Resource is empty." << endl;
  }
  else {
    int i;
    for (i=0;i<size;i++) {
      if(currentPtr->get_name()!="Population") cout << setw(10) << currentPtr->get_name() << setw(10) << floor(currentPtr->get_data()/10) << endl;
      else cout << endl << currentPtr->get_name() << ": " << floor(currentPtr->get_data()/10) << endl;
      currentPtr = currentPtr->get_next();
    }
  }
}

int resourcesList::getData(string n){
  NodePtr currentPtr;
  currentPtr = hol;
  while (currentPtr->get_name()!= n){
    currentPtr= currentPtr->get_next();
  }
  return currentPtr->get_data();
}

string resourcesList::getString(int x){
  NodePtr current = hol;
  for(int i=1;i<x;i++){
      current = current->get_next();
  }
  return current->get_name();
}
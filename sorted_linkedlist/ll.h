#include "node.h"

class LL {
  private:
  NodePtr hol; // head of linked list
  int size;

public:
  LL();
  int deletes(int value);
  int isEmpty();
  void insert(int value,string name);
  void printList();
  void printListR();
  ~LL();

};

LL::LL() {
  this->hol = NULL;
  size = 0;
}

LL::~LL() {
  cout << "deleting all nodes" << endl;
  NodePtr t;
  t = hol;
  int i;
  for (i = 0; i < size; i++) {
    t = hol->get_next();
    delete hol;
    hol = t;
  }
}

// insert a new value into the list in sorted order
void LL::insert(int value,string name) {
  NodePtr newPtr;      // pointer to new node
  NodePtr previousPtr; // pointer to previous node in list
  NodePtr currentPtr;  // pointer to current node in list

  newPtr = new Node(value,name);

  if (newPtr != NULL) { // is space available
    int count = 0;
    previousPtr = NULL;
    currentPtr = hol;
    // loop to find the correct location in the list
    while (currentPtr != NULL && value > currentPtr->get_data()) {
      previousPtr = currentPtr;            // walk to ...
      currentPtr = currentPtr->get_next(); // ... next node
      count++;                                    
    } // end while

    // insert new node at beginning of list
    if (previousPtr == NULL) {
        if(size!=0){
          hol->set_prev(newPtr);
        }
        newPtr->set_next(hol); cout << "First LL";
        hol = newPtr;
      }  // end if
    else if(count==size){
      previousPtr->set_next(newPtr); cout << "Highest Value";
      newPtr->set_next(NULL);
      newPtr->set_prev(previousPtr);
    }
    else { 
      // insert new node between previousPtr and currentPtr
      previousPtr->set_next(newPtr); cout << "Inbetween LL";
      newPtr->set_prev(previousPtr);
      newPtr->set_next(currentPtr);
      currentPtr->set_prev(newPtr);
        } // end else
      size++;
  } // end if
  else {
    cout << value << " not inserted. No memory available." << endl;
  } // end else
} // end function insert

// delete a list element
int LL::deletes(int value) {
  NodePtr previousPtr; // pointer to previous node in list
  NodePtr currentPtr;  // pointer to current node in list
  NodePtr tempPtr;     // temporary node pointer

  // delete first node
  if (value == hol->get_data()) {
    tempPtr = hol;  // hold onto node being removed
    hol = hol->get_next(); // de-thread the nodes
    hol->set_prev(NULL);
 
    size--;

    delete tempPtr; // free the de-threaded node

    return value;
  } // end if
  else {
    previousPtr = hol;
    currentPtr = hol->get_next();

    // loop to find the correct location in the list
    while (currentPtr != NULL && currentPtr->get_data() != value) {
      previousPtr = currentPtr;            // walk to ...
      currentPtr = currentPtr->get_next(); // ... next node
      if (currentPtr == hol)
        currentPtr = NULL;
    } // end while

    // delete node  currentPtr
    if (currentPtr != NULL) {
      tempPtr = currentPtr;
      currentPtr = currentPtr->get_next();
      previousPtr->set_next(currentPtr);
      currentPtr->set_prev(previousPtr);
    
      delete tempPtr;
      size--;
      return value;
    } // end if
  }   // end else

  return '\0';
} // end function delete

// return 1 if the list is empty, 0 otherwise
int LL::isEmpty() { return hol == NULL; } // end function isEmpty

// print the list
void LL::printList() {
  NodePtr currentPtr = hol;
  // if list is empty
  if (size == 0) {
    cout << "List is empty." << endl;
  } // end if
  else {
    cout << "The list is:" << endl;

    // while not the end of the list
    // while ( currentPtr != NULL ) {
    int i;
    for (i = 0; i < size; i++) {  // while(currentPtr!=NULL)
      currentPtr->print();
      cout << " --> ";
      currentPtr = currentPtr->get_next();
    } // end while

    puts("NULL\n");
  } // end else
} // end function printList

void LL::printListR() {
  int i;
  NodePtr currentPtr = hol;
  for (i=0;i<size-1;i++) {
    currentPtr = currentPtr->get_next();
  } // Move to last node.

  // if list is empty
  if (size == 0) {
    cout << "List is empty." << endl;
  } // end if
  else {
    cout << "The Reversed list is:" << endl;

    // while not the end of the list
    // while ( currentPtr != NULL ) {
    cout << "NULL";
    while(currentPtr!=NULL){
      cout << " <-- ";
      currentPtr->print();
      currentPtr = currentPtr->get_prev();
       // end while
    } // end else
  }
} // end function printListR

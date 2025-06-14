#include <iostream>      // For input/output stream operations
#include <stdlib.h>      // For rand() and abort()
#include <string>        // For using std::string

using namespace std;     // Use the standard namespace

// Forward declaration of template class TList
template <class T> class TList;

// Template class for a node in the list
template <class T>
class TNode {
  friend class TList<T>; // TList<T> can access private members of TNode<T>
private:
  T value;               // Data stored in node
  TNode * next;          // Pointer to the next node
public:
  TNode() : next(NULL) {}                // Default constructor, next is NULL
  TNode( const T & val );                // Constructor with value
  TNode<T> * getNext() const;            // Get pointer to next node
  template <class X> friend ostream & operator <<(ostream &, const TNode<X> & node); // Output operator
};

// Constructor: initializes value and sets next to NULL
template <class T> TNode<T>::TNode(const T & val) {
  value = val;
  next = NULL;
}

// Returns pointer to next node
template <class T> TNode<T> * TNode<T>::getNext() const { return next; }

// Output operator for TNode
template <class T> 
ostream & operator <<(ostream & os, const TNode<T> & node) {
  os << node.value << "->";
  return os;
}

// Template class for singly linked list
template <class T> class TList {
  TNode<T> * head;     // Dummy head node
  TNode<T> * tail;     // Dummy tail node
  TNode<T> * current;  // Current position in the list
public:
  TList();             // Constructor
  ~TList();            // Destructor
  int advance();       // Move current to next node, return 1 if successful, 0 if at end
  void append( const T & nodeVal );  // Add node to end
  void clear();        // Remove all nodes
  T get() const;       // Get value at current node
  void goLast();       // Move current to last node
  void goTop();        // Move current to head node
  void insertAfter( const T & nodeVal ); // Insert after current
  int isEmpty() const; // Return 1 if list is empty, else 0
  void prepend( const T & nodeVal );     // Insert at beginning
  void replace( const T & newVal );      // Replace value at current
  template <class X> friend ostream & operator <<(ostream & os, const TList<X> & list); // Output operator
};
 
// Constructor: initializes dummy head and tail, links them, sets current to head
template <class T> TList<T>::TList() {  
  head = new TNode<T>;
  tail = new TNode<T>;
  head->next = tail;
  tail->next = head;
  current = head;
}

// Destructor: clears list and deletes dummy nodes
template <class T> TList<T>::~TList() {  
  clear();
  delete head;
  delete tail;
}

// Returns 1 if list is empty (head points directly to tail)
template <class T> int TList<T>::isEmpty() const {  
  return head->next == tail;
}

// Removes all nodes except dummy head and tail
template <class T> void TList<T>::clear() {  
  current = head->next;
  while( current != tail ) {	 
    head->next = current->next;
    delete current;
    current = head->next;
  }
  current = head;
  head->next = tail;
}

// Advances current to next node if not at end, returns 1 if moved, 0 otherwise
template <class T> int TList<T>::advance() {
  if( !current ) abort();
  if( current->next != tail ) { 
    current = current->next;
     return 1;  
  }
  return 0;
}

// Moves current to last node before tail
template <class T> void TList<T>::goLast() {  
  if (!current) abort();
  while (current->next != tail)
    current = current->next;
}

// Moves current to head node
template <class T> void TList<T>::goTop() {  
  current = head;
}

// Returns value at current node
template <class T> T TList<T>::get() const {  
  if (!current) abort();
  return current->value;
}

// Replaces value at current node
template <class T> void TList<T>::replace (const T & newVal) {  
  if( !current ) abort();
  current->value = newVal;
}

// Inserts new node after current, moves current to new node
template <class T> void TList<T>::insertAfter (const T & nodeVal) {  
  if (!current) abort();
  TNode<T> * p = new TNode<T>( nodeVal );
  p->next = current->next;
  current->next = p;
  current = p;
}

// Appends node to end of list
template <class T> void TList<T>::append (const T & nodeVal) { 
  goLast();
  insertAfter( nodeVal );
}

// Prepends node to beginning of list
template <class T> void TList<T>::prepend (const T & nodeVal) {  
  goTop();
  insertAfter( nodeVal );
}

// Output operator for TList: prints all nodes
template <class T> 
ostream & operator <<( ostream & os, const TList<T> & list) {  
  if (list.isEmpty()) return os;
  TNode<T> * p = list.head->getNext();
  while( p != list.tail ) {	
    os << *p;
    p = p->getNext();  
  }
  os << endl;
  return os;
}

// Function to create and manipulate a list of random scores
void createRandomScores() {
  TList<int> scores;
  cout << "Creating a random list of scores: \n";
  for (int i = 0; i < 10; i++) {
    int n = rand() % 100;
    scores.append(n);
  }
  
  cout << scores << endl;
  
  scores.goLast();
  cout << "Last item: " << scores.get() << endl;
  scores.goTop();
  scores.advance();
  cout << "First item: " << scores.get() << endl;
  cout << "\nReplacing first node with value 101...\n";
  scores.replace( 101 );
  cout << scores;
  cout << "\nClearing the list..." ;
  scores.clear();
  if (scores.isEmpty())
  cout << "the list is now empty.\n\n";
  
}

// Function to create and manipulate a list of names
void createNameList() {
  TList<string> names;
  names.append( "Nam" );
  names.append( "Huy" );
  names.append( "Kh�nh" );
  names.append( "Ngoc" );
  names.append( "Son" );
  names.append( "Hung" );
  names.append( "Thao" );
  names.append( "Thuy" );
  names.append( "Bao Tran" );
  names.append( "Mai Trinh" );
  names.append( "Nhat Nam" );
  names.append( "Tuan" );
  names.append( "Nga" );

  cout << "current: " << names.get() << endl;
  cout << names;
  names.goTop();
  names.advance();
  names.replace( "To Nguyen Minh Nhat" );
  names.goLast();
  names.insertAfter( "Cong" );
  names.prepend( "Cao Minh Tuan" );
  cout << names << endl;
  cout << "Clearing the list...";
  names.clear();
  if (names.isEmpty())
    cout << "the list is now empty\n\n";
                
}

// Main function: runs both test functions
int main() {
  createRandomScores();
  createNameList();
  return 0;
} // Lec12_ex1-template-list.cpp

/*
This program demonstrates the implementation and usage of a generic singly linked list in C++ using templates.

Highlights:

- The TNode<T> class defines a node that stores a value of type T and a pointer to the next node.
- The TList<T> class manages the linked list, providing operations such as append, prepend, insert after, replace, clear, and traversal.
- Dummy head and tail nodes are used to simplify list operations and edge cases.
- Two test functions are included:
    • createRandomScores: Builds a list of random integers, then demonstrates appending, traversing, replacing, and clearing nodes.
    • createNameList: Builds a list of names (strings), then demonstrates various list operations.
- The main() function runs both test functions, showing that the list works with both int and string types.

Purpose:
To illustrate how to build and use a reusable, type-safe singly linked list in C++ with templates, and to demonstrate basic list operations for different data types.
*/
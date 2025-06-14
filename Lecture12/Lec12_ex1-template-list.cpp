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
  head = new TNode<T>;           // Create dummy head node
  tail = new TNode<T>;           // Create dummy tail node
  head->next = tail;             // Head points to tail (empty list)
  tail->next = head;             // Tail points back to head (not used, but for structure)
  current = head;                // Current starts at head
}

// Destructor: clears list and deletes dummy nodes
template <class T> TList<T>::~TList() {  
  clear();                       // Remove all nodes except dummy head/tail
  delete head;                   // Delete dummy head
  delete tail;                   // Delete dummy tail
}

// Returns 1 if list is empty (head points directly to tail)
template <class T> int TList<T>::isEmpty() const {  
  return head->next == tail;     // True if no real nodes between head and tail
}

// Removes all nodes except dummy head and tail
template <class T> void TList<T>::clear() {  
  current = head->next;          // Start at first real node
  while( current != tail ) {     // While not at dummy tail
    head->next = current->next;  // Bypass current node
    delete current;              // Delete current node
    current = head->next;        // Move to next node
  }
  current = head;                // Reset current to head
  head->next = tail;             // Head points to tail (empty list)
}

// Advances current to next node if not at end, returns 1 if moved, 0 otherwise
template <class T> int TList<T>::advance() {
  if( !current ) abort();        // Abort if current is null
  if( current->next != tail ) {  // If not at last node
    current = current->next;     // Move to next node
    return 1;                    // Indicate success
  }
  return 0;                      // At end, can't advance
}

// Moves current to last node before tail
template <class T> void TList<T>::goLast() {  
  if (!current) abort();         // Abort if current is null
  while (current->next != tail)  // While not at last node
    current = current->next;     // Move to next node
}

// Moves current to head node
template <class T> void TList<T>::goTop() {  
  current = head;                // Set current to dummy head
}

// Returns value at current node
template <class T> T TList<T>::get() const {  
  if (!current) abort();         // Abort if current is null
  return current->value;         // Return value at current node
}

// Replaces value at current node
template <class T> void TList<T>::replace (const T & newVal) {  
  if( !current ) abort();        // Abort if current is null
  current->value = newVal;       // Replace value at current node
}

// Inserts new node after current, moves current to new node
template <class T> void TList<T>::insertAfter (const T & nodeVal) {  
  if (!current) abort();         // Abort if current is null
  TNode<T> * p = new TNode<T>( nodeVal ); // Create new node with value
  p->next = current->next;       // New node points to next node
  current->next = p;             // Current node points to new node
  current = p;                   // Move current to new node
}

// Appends node to end of list
template <class T> void TList<T>::append (const T & nodeVal) { 
  goLast();                      // Move current to last node
  insertAfter( nodeVal );        // Insert new node after current
}

// Prepends node to beginning of list
template <class T> void TList<T>::prepend (const T & nodeVal) {  
  goTop();                       // Move current to head
  insertAfter( nodeVal );        // Insert new node after head
}

// Output operator for TList: prints all nodes
template <class T> 
ostream & operator <<( ostream & os, const TList<T> & list) {  
  if (list.isEmpty()) return os; // If list is empty, do nothing
  TNode<T> * p = list.head->getNext(); // Start at first real node
  while( p != list.tail ) {      // While not at dummy tail
    os << *p;                    // Print node (uses TNode's <<)
    p = p->getNext();            // Move to next node
  }
  os << endl;                    // End line after printing list
  return os;                     // Return output stream
}

// Function to create and manipulate a list of random scores
void createRandomScores() {
  TList<int> scores;             // Create a list of integers
  cout << "Creating a random list of scores: \n";
  for (int i = 0; i < 10; i++) {
    int n = rand() % 100;        // Generate random number 0-99
    scores.append(n);            // Add to end of list
  }
  
  cout << scores << endl;        // Print the list
  
  scores.goLast();               // Move to last node
  cout << "Last item: " << scores.get() << endl; // Print last value
  scores.goTop();                // Move to head
  scores.advance();              // Move to first real node
  cout << "First item: " << scores.get() << endl; // Print first value
  cout << "\nReplacing first node with value 101...\n";
  scores.replace( 101 );         // Replace first node's value with 101
  cout << scores;                // Print updated list
  cout << "\nClearing the list..." ;
  scores.clear();                // Remove all nodes
  if (scores.isEmpty())
    cout << "the list is now empty.\n\n"; // Confirm list is empty
}

// Function to create and manipulate a list of names
void createNameList() {
  TList<string> names;           // Create a list of strings
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

  cout << "current: " << names.get() << endl; // Print value at current (last inserted)
  cout << names;                // Print the list
  names.goTop();                // Move to head
  names.advance();              // Move to first real node
  names.replace( "To Nguyen Minh Nhat" ); // Replace first node's value
  names.goLast();               // Move to last node
  names.insertAfter( "Cong" );  // Insert "Cong" after last node
  names.prepend( "Cao Minh Tuan" ); // Insert at beginning
  cout << names << endl;        // Print updated list
  cout << "Clearing the list...";
  names.clear();                // Remove all nodes
  if (names.isEmpty())
    cout << "the list is now empty\n\n"; // Confirm list is empty
}

// Main function: runs both test functions
int main() {
  createRandomScores();         // Test with integer list
  createNameList();             // Test with string list
  return 0;                     // End program
} // Lec12_ex1-template-list.cpp

/*
This program in Lec12_ex1-template-list.cpp demonstrates how to implement and use a generic singly linked list in C++ using templates.

Key points:

The TNode<T> class represents a node in the list, storing a value of type T and a pointer to the next node.
The TList<T> class manages the linked list, supporting operations like append, prepend, insert, replace, clear, and traversal.
The list uses dummy head and tail nodes to simplify edge cases.
The program provides two test functions:
createRandomScores: creates a list of random integers, demonstrates appending, traversing, replacing, and clearing.
createNameList: creates a list of names (strings), demonstrates various list operations.
The main() function runs both test functions to show the list working with both int and string types.
Purpose:
To teach how to build and use a reusable, type-safe, singly linked list in C++ using templates, and to demonstrate basic list operations with different data types.

*/
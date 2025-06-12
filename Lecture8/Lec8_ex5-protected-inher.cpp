#include <iostream>      // Include input/output stream library
#include <assert.h>      // Include assert for debugging

using namespace std;     // Use the standard namespace

// Definition of the Item class
class Item {
  Item * ptr;            // Pointer to the next Item (for linked list)
  int data;              // Data stored in the Item
public:
  Item() {               // Default constructor
    data = 0; 
    ptr = NULL; 
  }
  Item(int i) {          // Constructor with data initialization
    data = i; 
    ptr = NULL; 
    cout << "Item::Item" << i << endl; // Print when constructed
  }

  void setItem(int i) {  // Set the data value
    data = i;
    cout << "Item::setItem" << i << endl;
  }

  void setPtr(Item * i) { // Set the pointer to another Item
    ptr = i;
    cout << "Item::setPtr" << endl;
  }

  int getData() { return data; }      // Get the data value

  Item * getPtr() { return ptr; }     // Get the pointer to next Item
  
};

// Definition of the List class (singly linked list)
class List {
  Item *head, *first, *last;          // Pointers to manage the list

public:
  List() {                            // Constructor initializes pointers
    head = NULL;
    first = head;
    last = head;
  }
  Item * removeLast();                // Remove last item from list
  Item * removeFirst();               // Remove first item from list
  void putFirst( Item *i );           // Insert item at the beginning
  void putLast( Item *i );            // Insert item at the end

protected:
  int isEmpty() const { return (head == NULL); } // Check if list is empty
};

// Remove and return the first item in the list
Item * List::removeFirst() {
  Item *temp;
  temp = first;                       // Save pointer to first item
  first = first->getPtr();            // Move first to next item
  cout << "List::removeFirst() " << endl;
  return temp;                        // Return removed item
}

// Remove and return the last item in the list
Item * List::removeLast() {
  Item *temp;
  temp = last;                        // Save pointer to last item
  last = last->getPtr();              // Move last to previous item (not correct for singly linked list)
  cout << "List::removeLast() " << endl;
  return temp;                        // Return removed item
}

// Insert an item at the beginning of the list
void List::putFirst(Item *i) {
  i->setPtr(first);                   // Point new item to current first
  first = i;                          // Update first to new item
  cout << "List::putFirst() " << i->getData() << endl;
}

// Insert an item at the end of the list
void List::putLast(Item *i) {
  i->setPtr(last);                    // Point new item to current last
  last = i;                           // Update last to new item
}

// Definition of Stack1 class, inherits List as protected
class Stack1 :protected List {
public:
  void push( Item * i );              // Push item onto stack
  Item * pop();                       // Pop item from stack
};

// Push item onto stack (add to front)
void Stack1::push(  Item * i ) {
  putFirst( i );                      // Use List's putFirst
  cout << "Stack1::push() "<< i->getData() <<endl;
}

// Pop item from stack (remove from front)
Item * Stack1::pop() {
  cout << "Stack1::pop()" << endl;
  return removeFirst();               // Use List's removeFirst
}

// Main function to test the classes
int main() {
  Item anItem(50), *p;                // Create an Item with data 50
  Stack1 aStack1;                     // Create a Stack1 object
  aStack1.push( &anItem );            // Push the item onto the stack
  p = aStack1.pop();                  // Pop the item from the stack
  cout <<" aStack1.pop" << p->getData() << endl << endl;
  anItem.setItem(100);                // Change the data in the item
  aStack1.push( &anItem );            // Push the item again
  // Try uncomment the below to see the effect: the compiler will complain
  //p = aStack1.removeFirst(); //Error // Can't access protected member
  return 0;                           // End of program
}

/*
This program demonstrates inheritance and encapsulation in C++ by implementing a simple singly linked list and a stack.

Key Components:
---------------
1. Item class:
   - Represents a node in a linked list.
   - Stores an integer value and a pointer to the next Item.

2. List class:
   - Implements a singly linked list using Item nodes.
   - Provides methods to insert at the front (putFirst), insert at the end (putLast),
     remove from the front (removeFirst), and remove from the end (removeLast).
   - Includes a protected isEmpty() method to check if the list is empty.

3. Stack1 class:
   - Inherits from List using protected inheritance.
   - Exposes push (adds to front) and pop (removes from front) methods, making the list behave as a stack (LIFO).
   - Hides the underlying list operations from users, enforcing encapsulation.

Program Flow:
-------------
- Creates an Item with value 50.
- Creates a Stack1 object.
- Pushes the item onto the stack and pops it off, printing the value.
- Changes the item's value to 100 and pushes it again.
- Demonstrates that direct access to List methods (like removeFirst) is not allowed from outside Stack1 due to protected inheritance.

Concepts Demonstrated:
----------------------
- Protected inheritance: Stack1 inherits List, but List's public/protected members become protected in Stack1.
- Encapsulation: Users interact with the stack only through push/pop, not the underlying list.
- Stack implementation: Uses a singly linked list for LIFO operations.

Summary:
--------
The program shows how to build a stack using a linked list, how protected inheritance restricts access to base class methods, and how encapsulation is enforced in C++.
*/

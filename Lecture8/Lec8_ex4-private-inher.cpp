#include <iostream>           // Include input/output stream library
#include <assert.h>           // Include assert library for debugging

using namespace std;          // Use the standard namespace

// Define the Item class
class Item {
  Item * ptr;                 // Pointer to another Item (for linking)
  int data;                   // Data stored in the Item
public:
  Item() { data = 0; ptr = NULL; }   // Default constructor, initializes data and ptr
  Item(int i) { 
    data = i; ptr = NULL; 
    cout << "Item::Item" << i << endl;   // Constructor with data, prints message
  }

  void setItem(int i) { 
    data = i;
    cout << "Item::setItem" << i << endl; // Set data and print message
  }

  void setPtr(Item * i) {
    ptr = i;
    cout << "Item::setPtr" << endl;      // Set pointer and print message
  }

  int getData() { return data; }         // Get the data value

  Item * getPtr() { return ptr; }        // Get the pointer value
  
};

// Define the List class
class List {
  Item *head, *first, *last;             // Pointers for managing the list

public:
  List() {
    head = NULL;
    first = head;
    last = head;
  }
  Item * removeLast();                   // Remove last item
  Item * removeFirst();                  // Remove first item
  void putFirst( Item *i );              // Add item to the front
  void putLast( Item *i );               // Add item to the end

protected:
  int isEmpty() const { return (head == NULL); } // Check if list is empty
};

// Remove the first item from the list
Item * List::removeFirst() {
  Item *temp;
  temp = first;
  first = first->getPtr();
  cout << "List::removeFirst() " << endl;
  return temp;
}

// Remove the last item from the list
Item * List::removeLast() {
  Item *temp;
  temp = last;
  last = last->getPtr();
  cout << "List::removeLast() " << endl;
  return temp;
}

// Add an item to the front of the list
void List::putFirst(Item *i) {
  i->setPtr(first);
  first = i;
  cout << "List::putFirst() " << i->getData() << endl;
}

// Add an item to the end of the list
void List::putLast(Item *i) {
  last->setPtr(i);//i->setPtr(last);
  last = i;
}

// Define the Stack class, privately inheriting from List
class Stack : private List {
public:
  void push(Item *i);        // Push item onto stack
  Item * pop();              // Pop item from stack
};

// Push an item onto the stack (add to front)
void Stack::push(Item *i) {
  cout << "**** Stack::push() " << i->getData() << endl;
  putFirst(i);
}

// Pop an item from the stack (remove from front)
Item * Stack::pop() {
  cout << "**** Stack::pop()" << endl;
  return removeFirst();
}

// Main function
int main() {
  cout << "****** Creating an Item" << endl << endl;
  Item anItem(50), *p;                       // Create an Item with data 50
  cout << "******* Creating a Stack" << endl << endl;
  Stack aStack;                              // Create a Stack
  aStack.push( &anItem );                    // Push the item onto the stack
  p = aStack.pop();                          // Pop the item from the stack
  cout << "aStack.pop() " << p->getData() << endl << endl;

  anItem.setItem(100);                       // Change the item's data to 100
  aStack.push( &anItem );                    // Push it again onto the stack
  cout << "Calling removeFirst() from aStack" << endl;
  p = aStack.removeFirst(); //=> Error        // Try to call removeFirst() directly (should cause error)
  cout <<"aStack.removeFirst() " << p->getData() << endl << endl;
  return 0;
}


/*
This program demonstrates the use of private inheritance and encapsulation in C++ by implementing a simple stack using a singly linked list as the underlying data structure.

Summary of Components:
----------------------
1. Item class:
   - Represents a node in a singly linked list.
   - Contains an integer value (data) and a pointer to the next Item (ptr).
   - Provides methods to set/get data and pointer, with debug output.

2. List class:
   - Implements a basic singly linked list using Item nodes.
   - Provides methods to add (putFirst, putLast) and remove (removeFirst, removeLast) items from the list.
   - Maintains pointers to the head, first, and last elements.
   - isEmpty() checks if the list is empty (protected).

3. Stack class:
   - Inherits privately from List.
   - Only exposes stack-specific operations: push (add to front) and pop (remove from front).
   - All List methods become private in Stack, enforcing encapsulation.

4. main function:
   - Demonstrates stack usage by creating an Item and a Stack.
   - Shows pushing and popping an item.
   - Attempts to call removeFirst() directly on the Stack object, which causes a compilation error due to private inheritance (intentionally included to illustrate access control).

Purpose and Learning Points:
---------------------------
- Shows how private inheritance hides base class methods from users of the derived class, enforcing encapsulation.
- Illustrates how a stack can be implemented using a linked list, but only exposes stack operations to the user.
- Demonstrates what happens if you try to access a base class method that is not meant to be public in the derived class.
- Useful as a teaching example for C++ inheritance, encapsulation, and stack implementation.

Note:
-----
The line 'p = aStack.removeFirst();' will not compile, as removeFirst() is not accessible from outside the Stack class due to private inheritance.
*/
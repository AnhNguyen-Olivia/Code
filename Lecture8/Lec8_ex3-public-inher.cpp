#include <iostream>
#include <assert.h>

using namespace std;

class Item {
  Item * ptr;
  int data;
public:
  Item() { data = 0; ptr = NULL; }
  Item(int i) { 
    data = i; ptr = NULL; 
    cout << "Item::Item" << i << endl;
  }

  void setItem(int i) { 
    data = i;
    cout << "Item::setItem" << i << endl;
  }

  void setPtr(Item * i) {
    ptr = i;
    cout << "Item::setPtr" << endl;
  }

  int getData() { return data; }

  Item * getPtr() { return ptr; }
  
};

class List {
  Item *head, *first, *last;

public:
  List() {
    head = NULL;         // Initialize head pointer to NULL (empty list)
    first = head;        // Set first pointer to head (also NULL)
    last = head;         // Set last pointer to head (also NULL)
  }
  Item * removeLast();   // Declaration: removes and returns the last item in the list
  Item * removeFirst();  // Declaration: removes and returns the first item in the list
  void putFirst( Item *i ); // Declaration: inserts item at the front of the list
  void putLast( Item *i );  // Declaration: inserts item at the end of the list

protected:
  int isEmpty() const { return (head == NULL); } // Returns true if the list is empty

};

Item * List::removeFirst() {
  Item *temp;                   // Declare a temporary pointer
  temp = first;                 // Store the current first item
  first = first->getPtr();      // Move first to the next item in the list
  cout << "List::removeFirst() " << endl; // Print debug message
  return temp;                  // Return the removed item
}

Item * List::removeLast() {
  Item *temp;
  temp = last;
  last = last->getPtr();
  cout << "List::removeLast() " << endl; // Print debug message for removing last item
  return temp;                           // Return the removed last item
}

void List::putFirst(Item *i) {
  i->setPtr(first);                    // Set the new item's pointer to the current first item
  first = i;                           // Update first to point to the new item
  cout << "List::putFirst() " << i->getData() << endl; // Print debug message with item data
}

void List::putLast(Item *i) {
  last->setPtr(i);                     // Set the current last item's pointer to the new item
  last = i;                            // Update last to point to the new item
}

class Stack : public List {             // Define Stack class inheriting from List
public:
  void push(Item *i);                  // Declaration: push item onto the stack
  Item * pop();                        // Declaration: pop item from the stack
};


/*

This program demonstrates how to implement a simple singly linked list and a stack in C++ using classes and public inheritance.

- Item class:
  Represents a node in the linked list.
  Contains an integer value (data) and a pointer to the next Item (ptr).
  Provides methods to set and get its data and pointer.
  Prints debug messages when its methods are called for easier tracing.

- List class:
  Manages a linked list of Item objects.
  Maintains pointers to the head, first, and last items in the list.
  Provides methods to:
    * Add an item to the front (putFirst) or end (putLast) of the list.
    * Remove and return the first (removeFirst) or last (removeLast) item.
    * Check if the list is empty (isEmpty).
  Prints debug messages to show when list operations are performed.

- Stack class:
  Inherits publicly from List.
  Implements stack-specific methods:
    * push: Adds an item to the top of the stack (front of the list).
    * pop: Removes and returns the item from the top of the stack (front of the list).
  Reuses the linked list operations from the List class to implement stack behavior.

Purpose:
The program illustrates how inheritance allows code reuse by building a stack on top of a linked list implementation. 
Debug messages are included throughout to help trace the flow of operations and changes to the data structure.
*/
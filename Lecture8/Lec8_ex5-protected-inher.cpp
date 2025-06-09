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
    head = NULL;
    first = head;
    last = head;
  }
  Item * removeLast();
  Item * removeFirst();
  void putFirst( Item *i );
  void putLast( Item *i );

protected:
  int isEmpty() const { return (head == NULL); }
};

Item * List::removeFirst() {
  Item *temp;
  temp = first;
  first = first->getPtr();
  cout << "List::removeFirst() " << endl;
  return temp;
}

Item * List::removeLast() {
  Item *temp;
  temp = last;
  last = last->getPtr();
  cout << "List::removeLast() " << endl;
  return temp;
}

void List::putFirst(Item *i) {
  i->setPtr(first);
  first = i;
  cout << "List::putFirst() " << i->getData() << endl;
}

void List::putLast(Item *i) {
  i->setPtr(last);
  last = i;
}

class Stack1 :protected List {
public:
  void push( Item * i );
  Item * pop();
};

void Stack1::push(  Item * i ) {
  putFirst( i );
  cout << "Stack1::push() "<< i->getData() <<endl;
}

Item * Stack1::pop() {
  cout << "Stack1::pop()" << endl;
  return removeFirst();
}


int main() {
  Item anItem(50), *p;
  Stack1 aStack1;
  aStack1.push( &anItem );
  p = aStack1.pop();
  cout <<" aStack1.pop" << p->getData() << endl << endl;
  anItem.setItem(100);
  aStack1.push( &anItem );
  // Try uncomment the below to see the effect: the compiler will complain
  //p = aStack1.removeFirst(); //Error
  return 0;
}


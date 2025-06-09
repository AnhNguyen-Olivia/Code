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
  last->setPtr(i);//i->setPtr(last);
  last = i;
}


class Stack : public List {
public:
  void push(Item *i);
  Item * pop();
};

void Stack::push(Item *i) {
  cout << "**** Stack::push() " << i->getData() << endl;
  putFirst(i);
}

Item * Stack::pop() {
  cout << "**** Stack::pop()" << endl;
  return removeFirst();
}


int main() {
  cout << "****** Creating an Item" << endl << endl;
  Item anItem(50), *p;
  cout << "******* Creating a Stack" << endl << endl;
  Stack aStack;
  aStack.push( &anItem );
  p = aStack.pop();
  cout << "aStack.pop() " << p->getData() << endl << endl;

  anItem.setItem(100);
  aStack.push( &anItem );
  cout << "Calling removeFirst() from aStack" << endl;
  p = aStack.removeFirst();
  cout <<"aStack.removeFirst() " << p->getData() << endl << endl;
  return 0;
}

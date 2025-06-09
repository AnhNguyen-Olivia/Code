#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

template <class T> class TList;

template <class T>
class TNode {
  friend class TList<T>;
private:
  T value; // data stored in node
  TNode * next; // points to the next node
public:
  TNode() : next(NULL) {} // next point is NULL
  TNode( const T & val );
  TNode<T> * getNext() const;
  template <class X> friend ostream & operator <<(ostream &, const TNode<X> & node);
};

template <class T> TNode<T>::TNode(const T & val) {
  value = val;
  next = NULL;
}

template <class T> TNode<T> * TNode<T>::getNext() const { return next; }

template <class T> 
ostream & operator <<(ostream & os, const TNode<T> & node) {
  os << node.value << "->";
  return os;
}

template <class T> class TList {
  TNode<T> * head; // dummy head node
  TNode<T> * tail; // dummy tail node
  TNode<T> * current; // current position
public:
  TList();
  ~TList();
  int advance();  // Return 0 if current is already at the end of the list; 
  //otherwise, current will point to the next node and return 1.
  void append( const T & nodeVal );  // Add a new node to the end of the list
  void clear(); // Remove all nodes.
  T get() const;  // Get the data at the current position.
  void goLast();  // Set current to the last node in the list.
  void goTop();	  // Set current to the head node.
  void insertAfter( const T & nodeVal ); // Insert new node after current one.
  int isEmpty() const; // Return 1 if the list is empty; otherwise,return 0.
  void prepend( const T & nodeVal );
  // Insert a node at the beginning of the list.
  void replace( const T & newVal );
  // Replace the data in the current node.
  template <class X> friend ostream & operator <<(ostream & os, const TList<X> & list);
};
 
template <class T> TList<T>::TList() {  
  head = new TNode<T>;
  tail = new TNode<T>;
  head->next = tail;
  tail->next = head;
  current = head;
}

template <class T> TList<T>::~TList() {  
  clear();
  delete head;
  delete tail;
}

template <class T> int TList<T>::isEmpty() const {  
  return head->next == tail;
}


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

template <class T> int TList<T>::advance() {
  if( !current ) abort();
  if( current->next != tail ) { 
    current = current->next;
     return 1;  
  }
  return 0;
}

template <class T> void TList<T>::goLast() {  
  if (!current) abort();
  while (current->next != tail)
	current = current->next;
}

template <class T> void TList<T>::goTop() {  
  current = head;
}

template <class T> T TList<T>::get() const {  
  if (!current) abort();
  return current->value;
}

template <class T> void TList<T>::replace (const T & newVal) {  
  if( !current ) abort();
  current->value = newVal;
}

template <class T> void TList<T>::insertAfter (const T & nodeVal) {  
  if (!current) abort();
  TNode<T> * p = new TNode<T>( nodeVal );
  p->next = current->next;
  current->next = p;
  current = p;
}

template <class T> void TList<T>::append (const T & nodeVal) { 
  goLast();
  insertAfter( nodeVal );
}

template <class T> void TList<T>::prepend (const T & nodeVal) {  
  goTop();
  insertAfter( nodeVal );
}

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

void createNameList() {
  TList<string> names;
  names.append( "Hieu" );
  names.append( "Vu" );
  names.append( "Nha" );
  names.append( "Huy" );
  names.append( "Khanh" );
  names.append( "Binh" );
  names.append( "Hoang" );
  names.append( "Tuan Anh" );
  names.append( "Thanh" );
  names.append( "Kiet" );
  names.append( "Quang" );
  names.append( "Minh" );
  names.append( "Thang" );

  cout << "current: " << names.get() << endl;
  cout << names;
  names.goTop();
  names.advance();
  names.replace( "To Phan Trung Hieu" );
  names.goLast();
  names.insertAfter( "Chuong" );
  names.prepend( "AAAAAA" );
  cout << names << endl;
  cout << "Clearing the list...";
  names.clear();
  if (names.isEmpty())
    cout << "the list is now empty\n\n";			    
}


// this is an abstract class
class DblNode {
  friend class DblList;
  virtual void printOn (ostream & os) const = 0;
  virtual void readFrom (istream & is) = 0;
  DblNode * next;     // pointer to next node
  DblNode * prev;     // pointer to previous node
public:
  DblNode();
  virtual ~DblNode() {  }
  DblNode * getNext() const;  // Return pointer to next node.
  DblNode * getPrev() const; // Return pointer to previous node.
  DblNode * detach();  // Detach node from its neighbors.
  virtual int operator ==( const DblNode & N ) const = 0;
  friend ostream & operator << (ostream & os, const DblNode & N );
  friend istream & operator >> (istream & inp, DblNode & N );
};


DblNode::DblNode() {  next = prev = NULL; }
DblNode * DblNode::getNext() const { return next; }
DblNode * DblNode::getPrev() const { return prev; }

// detach from surrounding nodes
DblNode * DblNode::detach() {  
  if (next)             // any next node?
    next->prev = prev;  // let it point to previous node
  if (prev)             // any previous node?
    prev->next = next;  // let it point to next node
  prev = NULL;          // detach current node
  next = NULL;
  return this;
}

ostream & operator << (ostream & os, const DblNode & n) { 
  n.printOn(os); return os;  
}

istream & operator >> (istream & is, DblNode & n) {  
  n.readFrom(is); return is;  
}


class DblList {    
  virtual void printOn (ostream &) const;
  DblNode * first;  // first node in the list
  DblNode * last;   // last node in the list
  long size;        // number of elements
public:
  DblList();  // Construct an empty list.
  ~DblList();  // Destructor: delete all nodes.
  void append (DblNode * n);  // Add node to end of the list.
  void deleteAll ();  // Delete all nodes in the list.
  DblNode *find (const DblNode & n) const; // Find a node in the  list.
  DblNode * remove (DblNode * n);  // Remove a node from the list.
  int isEmpty() const;  // Return 1 if the list is empty.
  DblNode * getFirst() const;  // Return pointer to first node.
  DblNode * getLast() const;  // Return pointer to last node.
  long getSize() const;  // Return the number of nodes.
  friend ostream & operator <<(ostream &, const DblList &);  
};

DblList::DblList() { first = NULL; last = NULL; size = 0; }

DblList::~DblList() { deleteAll(); }

int DblList::isEmpty() const { return first == NULL; }

long DblList::getSize() const { return size; }

DblNode * DblList::getFirst() const { return first; }

DblNode * DblList::getLast() const { return last; }

void DblList::printOn (ostream & os) const {  
  DblNode * n = first;
  while (n) { os << (*n); n = n->next; }
}

ostream & operator << (ostream & os, const DblList & aList) {  
  aList.printOn(os);
  return os;
}

void DblList::append (DblNode * p) {   
  if (!p) return;
  if (last) {     // is there a last node?
    last->next = p;  // yes: attach new node to it
    p->prev = last;
  } else {  first = p; }      // no: attach new node to first
  last = p;        // last points to appended node
  size++;          // increment size of list
}

// assumption: p is a node in the list
DblNode * DblList::remove(DblNode * p) {  
  if (!p) return NULL;
  if (p == first)      // removing the first node?
    first = first->next;
  if (p == last)       // removing the last node?
    last = last->prev;
  p->detach();   // detach node from its neighbors
  size--;        // decrement list size
  return p;
}

void DblList::deleteAll() {  
  while (first)
    delete remove (first);
}

DblNode * DblList::find(const DblNode & n) const { 
  DblNode * p = first;
  while (p) {    
    if (n == *p) return p;  // note: "==" is an overloaded operator 
    p = p->next;
  }
  return 0;
}


class Student : public DblNode {
  long id;
public:
  Student() { id = 0; }
  Student(long idNum) { id = idNum; }
  void setId(long idNum) {id = idNum; }
  int operator ==( const DblNode &) const;
  friend ostream & operator <<(ostream &, const Student *);
  void printOn (ostream & os) const { os << id; }
  void readFrom (istream & is) { is >> id; }
};

int Student::operator ==(const DblNode & p) const {  
  return id == ((Student &) p).id;
}

ostream & operator << (ostream & os, const Student * n) {	
  os << n->id;
  return os; 
}

int registerStudents( TList<Student *> & classRoll, const DblList & college ) { 
  Student student; long id;
  cout << "Enter student id: "; cin >> id;
  if (id == -1) return 0;
  student.setId(id);
  Student * p = (Student *) college.find(student);
  if (p) { 
    cout << "Adding student to the class roll.\n";
    classRoll.append(p);
  } else cout << "Student not found in college list!!!\n";
  return 1;
}


int main() { 
  Student * sp; DblList college; long i;
  for(i = 10000; i < 10050; i++) { 
    sp = new Student(i);
    college.append(sp);
  }
  TList<Student *> classRoll;
  cout << "Register students for a class.\n"
       << "(enter -1 to quit)\n\n";
  while ( registerStudents(classRoll, college) )
    continue;
  cout << "Finished.\n"; cout << classRoll << endl;
  return 0;
} //Lec12_ex2-double-llist.cpp

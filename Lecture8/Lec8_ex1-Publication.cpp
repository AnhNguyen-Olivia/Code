#include <iostream>
using namespace std;

class Publication {
private:
  string publisher;
  unsigned long date;
public:
  Publication() { }
  void setPublisher( string p ) {
    publisher = p; 
  }
  void setDate( unsigned long dt ) {
    date = dt;
  }
  string getPublisher() { return publisher; }
  unsigned long getDate() { return date; }
};

class Magazine : public Publication {
private:
  unsigned issuesPerYear;
  unsigned long circulation;
public:
  void setIssuesPerYear( unsigned n ) {
    issuesPerYear = n;
  }
  void setCirculation(unsigned long n) {
    circulation = n;
  }
  unsigned getIssuesPerYear() { return issuesPerYear; }
  unsigned long getCirculation() { return circulation; }
};

class Book : public Publication {
private:
  string ISBN;
public:
  void setISBN( string s ) {
    ISBN = s;
  }
  string getISBN() { return ISBN; }
};

main() {
  Book b;
  b.setPublisher( "Prentice Hall" );
  b.setDate( 970101L );
  b.setISBN( "0-02-359852-2" );
  cout << b.getPublisher() << endl;
  cout << b.getDate() << endl;
  cout << b.getISBN() << endl;
}


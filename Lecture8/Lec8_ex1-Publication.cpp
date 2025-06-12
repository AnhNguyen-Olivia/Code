#include <iostream> // Includes the standard input/output stream library
using namespace std; // Allows usage of standard library names without 'std::' prefix

class Publication { // Defines a base class named Publication
private:
  string publisher; // Private member to store the publisher's name
  unsigned long date; // Private member to store the publication date
public:
  Publication() { } // Default constructor
  void setPublisher( string p ) { // Setter for publisher
    publisher = p; 
  }
  void setDate( unsigned long dt ) { // Setter for date
    date = dt;
  }
  string getPublisher() { return publisher; } // Getter for publisher
  unsigned long getDate() { return date; } // Getter for date
};

class Magazine : public Publication { // Magazine inherits from Publication
private:
  unsigned issuesPerYear; // Number of issues per year
  unsigned long circulation; // Circulation number
public:
  void setIssuesPerYear( unsigned n ) { // Setter for issuesPerYear
    issuesPerYear = n;
  }
  void setCirculation(unsigned long n) { // Setter for circulation
    circulation = n;
  }
  unsigned getIssuesPerYear() { return issuesPerYear; } // Getter for issuesPerYear
  unsigned long getCirculation() { return circulation; } // Getter for circulation
};

class Book : public Publication { // Book inherits from Publication
private:
  string ISBN; // Private member to store the ISBN
public:
  void setISBN( string s ) { // Setter for ISBN
    ISBN = s;
  }
  string getISBN() { return ISBN; } // Getter for ISBN
};

main() { // Main function (should be 'int main()' in standard C++)
  Book b; // Create a Book object
  b.setPublisher( "Prentice Hall" ); // Set the publisher
  b.setDate( 970101L ); // Set the date
  b.setISBN( "0-02-359852-2" ); // Set the ISBN
  cout << b.getPublisher() << endl; // Output the publisher
  cout << b.getDate() << endl; // Output the date
  cout << b.getISBN() << endl; // Output the ISBN
}

/*
This code demonstrates basic object-oriented programming concepts in C++ by modeling different types of publications.

Class Hierarchy:
----------------
1. Publication (Base Class)
   - Stores the publisher's name and the publication date.
   - Provides setter and getter methods for both fields.

2. Magazine (Derived from Publication)
   - Adds fields for the number of issues per year and circulation.
   - Provides setter and getter methods for these additional fields.

3. Book (Derived from Publication)
   - Adds a field for the ISBN.
   - Provides setter and getter methods for the ISBN.

Main Function:
--------------
- Creates a Book object.
- Sets its publisher, date, and ISBN using the setter methods.
- Outputs the publisher, date, and ISBN to the console using the getter methods.

Notes:
------
- The code illustrates inheritance (Magazine and Book inherit from Publication), encapsulation (private data members with public accessors), and method usage.
- For standard C++, the main function should be declared as 'int main()'.
*/
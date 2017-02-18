#ifndef STRING_H
#define STRING_H
#include <iostream>
using namespace std;

//Above and beyond: implementation of -= operator

class String {

// Friend declarations:
//
// returns a String object representing the concatenation
// of its two arguments
friend String operator+(const String&, const String&);

// appends second argument, char, to the set in the first argument
friend void operator+=(String&, const char);

// appends second argument, string, to the set in the first argument
friend void operator+=(String&, const String&);

//removes second argument, string, from the set in the first argument
friend void operator-=(String&, const String&);


// prints out the String to the terminal, no new line
friend ostream& operator<<(ostream&, const String&);

// returns true if the strings are equal char-by-char, false otherwise.
friend bool operator==(const String&, const String&);

public:

 // Constructor, sets size to zero, allocates array of size 10,
 // sets array_size to 10
 String();

 // Constructor, builds a String containing the chars in the array
 // referenced by the first argument, with length indicated by the second
 // argument
 String(const char*, unsigned int);

 // Copy constructor.
 String(const String&);

 // Destructor.  Deletes allocated memory.
 ~String();

 //Not our friends --------
 // Assignment operator overload.
 String& operator=(const String&);

 // return/set char at index
 char& operator[](unsigned int);

 // returns the number of chars, size, in the String
 unsigned int length() const;

 // Starting at index location indicated by first arg, insert the String
 // specified by the second argument
 void insert(unsigned int, const String&);

 // Starting at index location indicated by first arg, remove number of
 // chars specified by the second argument, return the deleted section as a
 // new String
 String remove(unsigned int, unsigned int);

 // Return the starting index of the first case-sensitive match of the
 // provided String inside the larger string. If no match, return -1.
 int find(const String&);

 // Makes all the letters in the string lowercase
 void lower();

 //Reverses the String
 void reverse();

private:

 // reference to an array holding the chars of the String
 char *s;

 // holds the current number of chars in the String
 unsigned int size;

 // holds the current dynamic array size
 unsigned int array_size;

 // shrink the char array by amount
 void shrink(unsigned int);

 // grow the char array by amount
 void grow(unsigned int);

};
#endif

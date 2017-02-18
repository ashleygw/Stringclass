//George Ashley and Melissa Kohl
//Above and beyond: implementation of -= operator, .lower(), .reverse()
#include "String.h"

// Constructor, sets size to zero, allocates array of size 10,
// sets array_size to 10
String::String()
{
	size = 0;
	array_size = 10;
	s = new char[array_size];
	//cout << "Default Constructor called. " << endl;
}

// Constructor, builds a String containing the chars in the array
// referenced by the first argument, with length indicated by the second
// argument
String::String(const char *barbra, unsigned int jimbo)
{
	size = jimbo;
	array_size = jimbo + 10;
	s = new char[jimbo + 10];
	for(unsigned x = 0; x < jimbo; x++)
	{
		s[x] = barbra[x];
	}
	//cout << "Main constructor called." << endl;
}

//Copy Constructor
String::String(const String& cawpo)
{
	//cout << "Copy Constructor called." << endl;
	size = cawpo.size;
	array_size = cawpo.array_size;
	s = new char[array_size];
	for (unsigned x = 0; x < size; x++)
		s[x] = cawpo.s[x];
}

//Destructor. Deletes allocated memory.
String::~String()
{
	//cout << " Destroyed." << endl;
	delete [] s;
}

// Assignment operator overload.
String & String::operator=(const String& pizza)
{
	//cout << "Equality called" << endl;
	if (this == &pizza) return *this;
	size = pizza.size;
	array_size = pizza.array_size;
	delete[] s;
	s = new char[array_size];
	for (unsigned x = 0; x < size; x++)
	{
		s[x] = pizza.s[x];
	}
	return *this;
}

// return/set char at index
// [] Does not throw an exception... at() does
char & String::operator[](unsigned int index)
{
	return s[index];
}

// returns the number of chars, size, in the String
unsigned int String::length() const
{
	return size;
}

// Starting at index location indicated by first arg, insert the String
// specified by the second argument
void String::insert(unsigned int location, const String &spaghetti)
{
	unsigned x = 0;
	grow(spaghetti.size);
	for (x = size - location + 1; x > 0; x--)
	{
		s[x + spaghetti.size] = s[x];
	}
	for (unsigned i = 0; i < spaghetti.size; i++)
	{
		s[location + i] = spaghetti.s[i];
	}
	size += spaghetti.size;
}

// Starting at index location indicated by first arg, remove number of
// chars specified by the second argument, return the deleted section as a
// new String
String String::remove(unsigned int location, unsigned int length)
{
	for (unsigned x = 0; x < size - length; x++)
	{
		s[location + x] = s[location + length + x];
	}
	shrink(length);
	size -= length;
	return *this;
}

// Return the starting index of the first case-sensitive match of the
// provided String inside the larger string. If no match, return -1.
int String::find(const String &car)
{
	for (unsigned x = 0; x < size; x++)
	{
		if (s[x] == car.s[0])
		{
			unsigned i = 0;
			while (i < car.size) 
			{
				if (s[x + i] != car.s[i]) 
					break;
				i++;
			}
			if (i == car.size)
				return x;
		}
	}
	return -1;
}

//removes second argument, string, from the set in the first argument
void operator-=(String& pizza2, const String& spgahtei2)
{
	int die = pizza2.find(spgahtei2);
	if (die != -1)
	{
		pizza2.remove(die, spgahtei2.size);
	}
}

// shrink the char array by amount
void String::shrink(unsigned int amount)
{
	array_size -= amount;
	char *temp = new char[array_size];
	for (unsigned x = 0; x < size; x++)
	{
		temp[x] = s[x];
	}
	delete[] s;
	s = temp;
}

// grow the char array by amount
void String::grow(unsigned int amount)
{
	array_size += amount;
	char *temp = new char[array_size];
	for (unsigned x = 0; x < size; x++)
	{
		temp[x] = s[x];
	}
	delete[] s;
	s = temp;
}

// Friend declarations:
//
// returns a String object representing the concatenation
// of its two arguments
String operator+(const String& uno, const String& dos)
{
	String bob = String("", uno.size + dos.size);
	for (unsigned x = 0; x < uno.size; x++)
	{
		bob.s[x] = uno.s[x];
	}
	for (unsigned x = 0; x < dos.size; x++)
	{
		bob.s[x+uno.size] = dos.s[x];
	}
	return bob;
}

// appends second argument, char, to the set in the first argument
void operator+=(String& fuzz, const char football)
{
	fuzz.grow(1);
	fuzz.s[fuzz.size] = football;
	fuzz.size += 1;
}

// appends second argument, string, to the set in the first argument
void operator+=(String& light, const String& dark)
{
	light = light + dark;
}



// prints out the String to the terminal, no new line
ostream& operator<<(ostream& out, const String& bloof)
{
	for (unsigned i = 0; i < bloof.size; i++)
	{
		out << bloof.s[i];
	}
	return out;
}

// returns true if the strings are equal char-by-char, false otherwise.
bool operator==(const String& shirt, const String& pants)
{
	for (unsigned x = 0; x < shirt.size; x++)
	{
		if (shirt.s[x] != pants.s[x])
		{
			return false;
		}
	}
	return true;
}

// Makes all the letters in the string lowercase
void String::lower()
{
	for (unsigned x = 0; x < size; x++)
	{
		if ('A' <= s[x] && s[x]<= 'Z')
		{
			s[x] += 32;
		}
	}
}

//Reverses the String
void String::reverse()
{
	for (unsigned x = 0; x < size/2; x++)
	{
		char temp = s[size - x - 1];
		s[size - x - 1] = s[x];
		s[x] = temp;
	}

}

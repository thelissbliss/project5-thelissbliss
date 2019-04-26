#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "BowCollection.hpp"

using std::string;
using std::ifstream;
using std::cout;
using std::endl;

// function to return the hash value based on the first digit
unsigned int hashfct1(unsigned int barcode) {
  unsigned int d = barcode/10000;
  d = d%10;
  return d;
}

// function to return the hash value based on the second digit
unsigned int hashfct2(unsigned int barcode) {
  // TO BE COMPLETED
}

// function to return the hash value based on the third digit
unsigned int hashfct3(unsigned int barcode) {
  // TO BE COMPLETED
}

// function to return the hash value based on the fourth digit
unsigned int hashfct4(unsigned int barcode) {
  // TO BE COMPLETED
}

// function to return the hash value based on the fifth digit
unsigned int hashfct5(unsigned int barcode) {
  // TO BE COMPLETED
}

// Constructor for struct Bow
Bow::Bow(string bowColor, string bowShape, string bowTexture,
		 unsigned int barcode):bowColor_(bowColor),bowShape_(bowShape),
				       bowTexture_(bowTexture),
				       barcode_(barcode)
{};

// Load information from a text file with the given filename
// THIS FUNCTION IS COMPLETE
void BowCollection::readTextfile(string filename) {
  ifstream myfile(filename);

  if (myfile.is_open()) {
    cout << "Successfully opened file " << filename << endl;
    string bowColor;
    string bowShape;
    string bowTexture;
    unsigned int barcode;
    while (myfile >> bowColor >> bowShape >> bowTexture >> barcode) {
			if (bowColor.size() > 0)
      	addBow(bowColor, bowShape, bowTexture, barcode);
    }
    myfile.close();
  }
  else
    throw std::invalid_argument("Could not open file " + filename);
}

void BowCollection::addBow(string bowColor, string bowShape, string bowTexture, unsigned int barcode) {
  // TO BE COMPLETED
  // function that adds the specified bow to Minnie's collection of bows (i.e., to all hash tables)

}

bool BowCollection::removeBow(unsigned int barcode) {
  // TO BE COMPLETED
  // function that removes the bow specified by the barcode from the collection
  // if bow is found, then it is removed and the function returns true
  // else returns false

}

unsigned int BowCollection::bestHashing() {
  // TO BE COMPLETED
  // function that decides the best has function, i.e. the ones among
  // fct1-fct5 that creates the most balanced hash table for the current
  // bowCollection data member allBows

	// Hints:
	// Calculate the balance of each hashtable, one by one.
	/*
	 for (unsigned i=0; i<10; ++i) {
    cout << hT1.bucket_size(i); // Call bucket_size() to get the size of each bucket
  }
	*/
	// Then, calculate the lowest balance

}

// ALREADY COMPLETED
size_t BowCollection::size() {
	if ((hT1.size() != hT2.size()) || (hT1.size() != hT3.size()) || (hT1.size() != hT4.size()) || (hT1.size() != hT5.size()))
  	throw std::length_error("Hash table sizes are not the same");
	return hT1.size();
}

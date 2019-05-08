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
  unsigned int d = barcode/1000;
  d = d%10;
  return d;
}

// function to return the hash value based on the third digit
unsigned int hashfct3(unsigned int barcode) {
  // TO BE COMPLETED
  unsigned int d = barcode/100;
  d = d%10;
  return d;
}

// function to return the hash value based on the fourth digit
unsigned int hashfct4(unsigned int barcode) {
  // TO BE COMPLETED
  unsigned int d = barcode/10;
  d = d%10;
  return d;
}

// function to return the hash value based on the fifth digit
unsigned int hashfct5(unsigned int barcode) {
  // TO BE COMPLETED
  unsigned int d = barcode/1;
  d = d%10;
  return d;
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
  // key = barcode
  Bow newBow(bowColor, bowShape, bowTexture, barcode);

  hT1[barcode] = newBow;
  hT2[barcode] = newBow;
  hT3[barcode] = newBow;
  hT4[barcode] = newBow;
  hT5[barcode] = newBow;
}

bool BowCollection::removeBow(unsigned int barcode) {
  // TO BE COMPLETED
  // function that removes the bow specified by the barcode from the collection
  // if bow is found, then it is removed and the function returns true
  // else returns false

    if (hT1.find(barcode) == hT1.end())
        { return false; }
    else {
      hT1.erase(barcode);
      hT2.erase(barcode);
      hT3.erase(barcode);
      hT4.erase(barcode);
      hT5.erase(barcode);
      return true;
       }

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
  int smallest = hT1.bucket_size(0); //initialize with a real bucket value
  int balance = 0;
  int balance_temp = 0;
  int largest = 0;
  int best_table = 1;

// find balance of hT1
  for (unsigned i=0; i<10; ++i) { // i = index
    int size = hT1.bucket_size(i);
    if (size > largest)
      largest = size;
    if (size < smallest)
      smallest = size;
    }

  balance = largest - smallest;

  // find balance of hT2
smallest = hT2.bucket_size(0);
largest = 0;

    for (unsigned i=0; i<10; ++i) { // i = index
      int size = hT2.bucket_size(i);
      if (size > largest)
        largest = size;
      if (size < smallest)
        smallest = size;
      }

    balance_temp = largest - smallest;
    if (balance_temp < balance) {
      balance = balance_temp;
      best_table = 2;
    }

      // find balance of hT3
      smallest = hT3.bucket_size(0);
      largest = 0;

        for (unsigned i=0; i<10; ++i) { // i = index
          int size = hT3.bucket_size(i);
          if (size > largest)
            largest = size;
          if (size < smallest)
            smallest = size;
          }

        balance_temp = largest - smallest;
        if (balance_temp < balance) {
          balance = balance_temp;
          best_table = 3;
        }

          // find balance of hT4
          smallest = hT4.bucket_size(0);
          largest = 0;

            for (unsigned i=0; i<10; ++i) { // i = index
              int size = hT4.bucket_size(i);
              if (size > largest)
                largest = size;
              if (size < smallest)
                smallest = size;
              }

            balance_temp = largest - smallest;
            if (balance_temp < balance) {
              balance = balance_temp;
              best_table = 4;
            }

              // find balance of hT5
              smallest = hT5.bucket_size(0);
              largest = 0;

                for (unsigned i=0; i<10; ++i) { // i = index
                  int size = hT5.bucket_size(i);
                  if (size > largest)
                    largest = size;
                  if (size < smallest)
                    smallest = size;
                  }

                balance_temp = largest - smallest;
                if (balance_temp < balance) {
                  balance = balance_temp;
                  best_table = 5;
                }

  return best_table;

}

// ALREADY COMPLETED
size_t BowCollection::size() {
	if ((hT1.size() != hT2.size()) || (hT1.size() != hT3.size()) || (hT1.size() != hT4.size()) || (hT1.size() != hT5.size()))
  	throw std::length_error("Hash table sizes are not the same");
	return hT1.size();
}

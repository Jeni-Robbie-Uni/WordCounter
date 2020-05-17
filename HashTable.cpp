#pragma once
#include "HashTable.h"
#include "NumUtils.h"
#include <iostream>
using namespace std;

//Contructors
HashTable::HashTable() {	
	arraySize = 7;			//prime number to reduces collisions

	content = new HashNode[arraySize];	//create array of 7 nodes
}

HashTable::HashTable(int size) {
	arraySize = size;										
	content = new HashNode[arraySize];

}

//destructor
HashTable::~HashTable() {
	delete[] content;
}

//Returns pointer to new table of increased size
HashTable* HashTable::ReSizeHashTable(HashTable* old) {

	int newArrSize = (old->arraySize) * 2;		//double the old tables size
	newArrSize = NumUtils::NextPrime(newArrSize);		// set arraysize to the nearest prime number
	

	HashTable* newPointer = new HashTable(newArrSize);		//create new bigger table


	//loop through all slots and copy 
	for (int s = 0; s < old->arraySize; s++)
	{
		newPointer->Copy(old, newPointer, s);		

	}

	old->~HashTable(); //delete the old table
	old = nullptr;		//asssihn the pointer to null just in case
	return newPointer;


}

//returns size of array
int HashTable::GetArraySize() {
	return arraySize;
}



//double hash function for strings
int HashTable::DoubleHash(string word) {							

	int num = GetAsciiTotal(word);			//get ascii value
	int arrayPosition1 = Hash1(num);				//get first array position 
	
	
	if (!IsEmpty(arrayPosition1) && !IsPresent(word, arrayPosition1)) {	//If the first array position causes clashes do second hash
		
		
		int arrayPosition2 = Hash2(num);		//calculates second arrary number 
		int i = 1;				
		int newArrPos = 0;
		
		do
		{

			newArrPos = (arrayPosition1 +i + arrayPosition2) % arraySize;		//calculate new array index using values from both hashes
			i++;

		} while (!IsEmpty(newArrPos) && !IsPresent(word, newArrPos));		//If it is not empty or present add 1 to calculation

		return newArrPos;
	}
	else
		return arrayPosition1;	
}
//first hash function
int HashTable::Hash1(int total) {

	return (total % arraySize);		//return remainder of total/ arraysize
}
//Second Hash function
int HashTable::Hash2(int total) {

	return (3 - (total % 3));		//Needs to be a prome number smaller than start table
}




//insert unqie word or increment existing one in array
void HashTable::Insert(string word,  HashTable* v) {
	int attempts = 0;
	int arrPos=0;

	arrPos= DoubleHash( word);			//hash word to get array position

	if (IsEmpty(arrPos)) {		//if empty, reassign values to new word
		content[arrPos].key = word;
		content[arrPos].value = 1;
		numInserts++;
	}
	else if (IsPresent(word, arrPos)) {		//if founf in array, increment occurences
		content[arrPos].value++;
	}

}

//copy contents of 1 table to another
void HashTable::Copy(HashTable* old, HashTable* newTable, const int index) {

	
	int arrPos = 0;
	string word = old->content[index].key;		//assigns old table element to temp variable
	
	do {
		arrPos = newTable->DoubleHash( word);	//rehash to new table size
	} while (!IsEmpty(arrPos));

	//assign old table node content to new tables
	newTable->content[arrPos]= old->content[index];	
	newTable->content[arrPos].key = old->content[index].key;
	newTable->numInserts++;

}

//Checks where word in slot is input word
bool HashTable::IsPresent(string word, int index) {

	if (content[index].key == word)
		return true;
	else
		return false;

}

//Checks if number of words added is the same as arraysize
bool HashTable::IsArrayFull() {
	if (arraySize ==numInserts)
		return true;
	else
		return false;
}

//Checks if slot is empty
bool HashTable::IsEmpty(int index) {

	if (content[index].key=="EMPTY")
		return true;
	else
		return false;

}
//Calculates the ASCII total for a string
int HashTable::GetAsciiTotal(string word) {
	int total = 0;
	for (int i = 0; i < word.length(); i++) {

		total += (int)word[i];		
	}
	return total;
}


// returns number of unique words that have been added 
int HashTable::GetNumOfInserts() {
	return numInserts;
}

// returns key (word) held by node in specific index of array
string HashTable::GetKey(int i) {
	string key = content[i].key;
	return key;
}

// returns value held by node in specific index of array
int HashTable::GetValue(int i) {
	
	int val = content[i].value;
	return val;
}
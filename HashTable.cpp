#pragma once
#include "HashTable.h"
#include "Word.h"
#include <iostream>
using namespace std;

HashTable::HashTable() {	
	arraySize = 4;	
	content = new HashNode[arraySize];
}


HashTable::HashTable(int size) {
	arraySize = size;
	content = new HashNode[arraySize];

}


HashTable::~HashTable() {
	delete[] content;
}


void HashTable::ReSizeHashTable(HashTable* old) {

	int newArrSize = (old->arraySize) * 2;
	HashTable* newPointer = new HashTable(newArrSize);		//create new bigger table

	for (int s = 0; s < old->arraySize; s++)
	{
		newPointer->copy(old, newPointer, s);

	}

	HashTable* temp = old;		//will call hashtable destructor to delete this when I exit the function
	*old = *newPointer;


}


int HashTable::GetArraySize() {
	return arraySize;
}




int HashTable::hash(int attempts, string word) {								//Hash function for strings

	int total = 0;

	for (int i = 0; i < word.length(); i++) {

		total += (int)word[i];
	};
	
	int arrPos = (total + attempts) % arraySize;
	return arrPos;
}




void HashTable::insert(string word,  HashTable* v) {
	int attempts = 0;
	int arrPos=0;

	do{
		arrPos= hash(attempts, word);
		attempts++;


	} while (!isEmpty(arrPos) && !isPresent(word,arrPos));
	

	if (isEmpty(arrPos)) {
		content[arrPos].element = word;
		content[arrPos].count = 1;
		numInserts++;
	}
	else if (isPresent(word, arrPos)) {
		content[arrPos].count++;
	}

}


void HashTable::copy(HashTable* old, HashTable* newTable, const int index) {

	int attempts = 0;
	int arrPos = 0;
	string word = old->content[index].element;
	
	do {
		arrPos = newTable->hash(attempts, word);
		attempts++;
	} while (!isEmpty(arrPos));

	content[arrPos].count = old->content[index].count;
	content[arrPos].element = old->content[index].element;
	newTable->numInserts++;

}


bool HashTable::isPresent(string word, int index) {

	if (content[index].element == word)
		return true;
	else
		return false;

}

bool HashTable::isArrayFull() {
	if (arraySize == numInserts)
		return true;
	else
		return false;
}

bool HashTable::isEmpty(int index) {

	if (content[index].element=="EMPTY")
		return true;
	else
		return false;

}
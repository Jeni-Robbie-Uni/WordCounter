#pragma once
#include "HashTable.h"
#include "Word.h"
#include <iostream>
using namespace std;

HashTable::HashTable() {	
	arraySize = 5;	
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
	int p;
	
	for (int i = 0; i < word.length(); i++) {

		total += (int)word[i];		//Make distribution more random
	};
	
	p = (total + attempts) % arraySize;
	
	if (!isEmpty(p) && !isPresent(word,p))
		p=hash((attempts+1), word);
	
	return p;
}

int HashTable::hash2(int total) {

	return 0;
}



void HashTable::insert(string word,  HashTable* v) {
	int attempts = 0;
	int arrPos;

		arrPos= hash(attempts, word);

	if (isEmpty(arrPos)) {
		content[arrPos].key = word;
		content[arrPos].value = 1;
		numInserts++;
	}
	else if (isPresent(word, arrPos)) {
		content[arrPos].value++;
	}

}


void HashTable::copy(HashTable* old, HashTable* newTable, const int index) {

	int attempts = 0;
	int arrPos = 0;
	string word = old->content[index].key;
	
	do {
		arrPos = newTable->hash(attempts, word);
		attempts++;
	} while (!isEmpty(arrPos));

	content[arrPos].value = old->content[index].value;
	content[arrPos].key = old->content[index].key;
	newTable->numInserts++;

}


bool HashTable::isPresent(string word, int index) {

	if (content[index].key == word)
		return true;
	else
		return false;

}

bool HashTable::isArrayFull() {
	if (arraySize ==numInserts)
		return true;
	else
		return false;
}

bool HashTable::isEmpty(int index) {

	if (content[index].key=="EMPTY")
		return true;
	else
		return false;

}
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

HashTable* HashTable::ReSizeHashTable(HashTable* old) {

	int newArrSize = (old->arraySize) * 2;
	HashTable* newPointer = new HashTable(newArrSize);		//create new bigger table

	for (int s = 0; s < old->arraySize; s++)
	{
		newPointer->copy(old, newPointer, s);

	}

	old->~HashTable();
	old = nullptr;		
	return newPointer;


}


int HashTable::GetArraySize() {
	return arraySize;
}




int HashTable::DoubleHash(string word) {								//Hash function for strings

	int num = GetAsciiTotal(word);
	int index1 = Hash1(num);
	
	
	if (!isEmpty(index1) && !isPresent(word, index1)) {
		int index2 = Hash2(num);
		int i = 1;
		int newIndex = 0;
		
		do
		{

			newIndex = (index1 +i + index2) % arraySize;
			i++;

		} while (!isEmpty(newIndex) && !isPresent(word, newIndex));

		return newIndex;
	}
	else
		return index1;
}
int HashTable::Hash1(int total) {

	return (total % arraySize);
}
int HashTable::Hash2(int total) {

	return (3 - (total % 3));		//Needs to be a prome number smaller than start table
}





void HashTable::insert(string word,  HashTable* v) {
	int attempts = 0;
	int arrPos=0;

	arrPos= DoubleHash( word);

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

	
	int arrPos = 0;
	string word = old->content[index].key;
	
	do {
		arrPos = newTable->DoubleHash( word);
	} while (!isEmpty(arrPos));

	newTable->content[arrPos].value = old->content[index].value;
	newTable->content[arrPos].key = old->content[index].key;
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

int HashTable::GetAsciiTotal(string word) {
	int total = 0;
	for (int i = 0; i < word.length(); i++) {

		total += (int)word[i];		//Make distribution more random
	}
	return total;
}

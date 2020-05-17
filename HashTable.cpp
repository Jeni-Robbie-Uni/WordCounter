#pragma once
#include "HashTable.h"
#include "NumUtils.h"
#include <iostream>
using namespace std;

HashTable::HashTable() {	
	arraySize = 7;			//prime number
	
	
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
	if (!NumUtils::IsPrime(newArrSize)) {
		newArrSize = NumUtils::NextPrime(newArrSize);
	}

	HashTable* newPointer = new HashTable(newArrSize);		//create new bigger table

	for (int s = 0; s < old->arraySize; s++)
	{
		newPointer->Copy(old, newPointer, s);

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
	
	
	if (!IsEmpty(index1) && !IsPresent(word, index1)) {
		int index2 = Hash2(num);
		int i = 1;
		int newIndex = 0;
		
		do
		{

			newIndex = (index1 +i + index2) % arraySize;
			i++;

		} while (!IsEmpty(newIndex) && !IsPresent(word, newIndex));

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





void HashTable::Insert(string word,  HashTable* v) {
	int attempts = 0;
	int arrPos=0;

	arrPos= DoubleHash( word);

	if (IsEmpty(arrPos)) {
		content[arrPos].key = word;
		content[arrPos].value = 1;
		numInserts++;
	}
	else if (IsPresent(word, arrPos)) {
		content[arrPos].value++;
	}

}


void HashTable::Copy(HashTable* old, HashTable* newTable, const int index) {

	
	int arrPos = 0;
	string word = old->content[index].key;
	
	do {
		arrPos = newTable->DoubleHash( word);
	} while (!IsEmpty(arrPos));

	newTable->content[arrPos].value = old->content[index].value;
	newTable->content[arrPos].key = old->content[index].key;
	newTable->numInserts++;

}


bool HashTable::IsPresent(string word, int index) {

	if (content[index].key == word)
		return true;
	else
		return false;

}

bool HashTable::IsArrayFull() {
	if (arraySize ==numInserts)
		return true;
	else
		return false;
}

bool HashTable::IsEmpty(int index) {

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



int HashTable::GetNumOfInserts() {
	return numInserts;
}

string HashTable::GetKey(int i) {
	string key = content[i].key;
	return key;
}
int HashTable::GetValue(int i) {
	
	int val = content[i].value;
	return val;
}
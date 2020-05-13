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
void HashTable::ReSizeHashTable( HashTable*old ) {

	int newArrSize = (old->arraySize) * 2;
	HashTable* newPointer = new HashTable(newArrSize);		//create new bigger table
	int tempPos = 0;
	HashTable* temp;
	string tempWord;
	int tempASCII;

	for (int s = 0; s < old->arraySize; s++)
	{
		tempWord = old->content[s].element;
		tempPos=newPointer->insert(tempWord, newPointer);
		newPointer->content[tempPos].count = old->content[s].count;

	}
	temp = old; 

	*old = *newPointer;
	temp = nullptr;
}

int HashTable::GetArraySize() {
	return arraySize;
}




int HashTable::hash(int attempts, string word) {								//Hasg function for strings
	
	int length = word.length();
	int total = 0;

	for (int i = 0; i < word.length(); i++) {

		total += (int)word[i];
	};
	
	int arrPos = (total + attempts) % arraySize;
	return arrPos;
}




int HashTable::insert(string word,  HashTable* v) {
	int attempts = 0;
	int arrPos=0;
	//while isPresent=false || isEmpty==false

	do{
		arrPos= hash(attempts, word);
		attempts++;




	} while (v->isEmpty(arrPos)==false && isPresent(word,arrPos)==false);
	

	if (v->isEmpty(arrPos) == true) {
		content[arrPos].element = word;
		content[arrPos].count = 1;
		numInserts++;
	}
	else if (v->isPresent(word, arrPos) == true) {
		content[arrPos].count++;
	}
	return arrPos;
}


bool HashTable::isPresent(string word, int index) {

	if (content[index].element == word)
	{
		return true;

	}
	else
	{
		return false;
	}

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
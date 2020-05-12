#pragma once
#include "HashTable.h"

#include <iostream>
using namespace std;

HashTable::HashTable() {
	
	arraySize = 30;	
	content = new HashNode[arraySize];


}


HashTable::HashTable(int size) {
	arraySize = size;

}
int HashTable::GetArraySize() {
	return arraySize;
}




int HashTable::hash(int attempts, const int number) {								//Hasg function for strings
	int arrPos = (number + attempts) % arraySize;
	return arrPos;
}




void HashTable::insert(string word, const int num, HashTable v) {
	int attempts = 0;
	int arrPos=0;
	//while isPresent=false || isEmpty==false

	do{
		arrPos= hash(attempts, num);
		attempts++;




	} while (v.isEmpty(arrPos, v)==false && isPresent(word,arrPos)==false);
	

	if (v.isEmpty(arrPos, v) == true) {
		content[arrPos].element = word;
		content[arrPos].count = 1;
		numInserts++;
	}
	else if (v.isPresent(word, arrPos) == true) {
		content[arrPos].count++;
	}

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
	return false;
}

bool HashTable::isEmpty(int index, HashTable v) {



	if (content[index].element=="EMPTY")
		return true;
	else
		return false;

}
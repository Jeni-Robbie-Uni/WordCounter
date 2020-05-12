#pragma once
#include "HashTable.h"

#include <string>
using namespace std;


HashTable::HashTable() {
	
	arraySize = 30;
	content[arraySize];


}


HashTable::HashTable(int size) {
	arraySize = size;

}





int HashTable::hash(int attempts, const int number) {								//Hasg function for strings
	int arrPos = number + attempts % arraySize;
	return arrPos;
}




void HashTable::insert(string word, const int num, HashTable x) {
	int attempts = 0;
	int arrPos=0;
	//while isPresent=false || isEmpty==false

	do{
		arrPos= hash(attempts, num);
		attempts++;

	} while (!isEmpty(arrPos, x) || isPresent(word));



}


bool HashTable::isPresent(string) {
	return true;
}

bool HashTable::isArrayFull() {
	return false;
}

bool HashTable::isEmpty(int index, HashTable x) {

	content[index];
	
	

	return true;
}
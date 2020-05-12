#pragma once
#include "HashTable.h"
#include <string>
using namespace std;


HashTable::HashTable() {
	arraySize = 30;

	HashNode* content = new HashNode[arraySize];


}


HashTable::HashTable(int size) {
	arraySize = size;

}


HashTable::HashTable(const HashTable* oldTable) {

}



int HashTable::hash(int attempts, const int number) {								//Hasg function for strings
	int arrPos = number + attempts % arraySize;
	return arrPos;
}




void HashTable::insert(string word, const int num) {
	int attempts = 0;

	//while isPresent=false || isEmpty==false


	hash(attempts, num);
	attempts++;





}


bool HashTable::isPresent(string) {
	return true;
}

bool HashTable::isArrayFull() {
	return false;
}
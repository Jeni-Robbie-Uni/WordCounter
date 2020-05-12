#pragma once
#include "HashNode.h"

using namespace std;



class HashTable
{
	public:
		int arraySize=0;
		int attempts = 0;
		int numInserts = 0;
		HashNode* content=nullptr;

	public:
		HashTable();
		HashTable(int);


		bool isPresent(string, int);
		bool isEmpty(int, HashTable);
		bool isArrayFull();

		int GetArraySize();
		int hash(int, const int);

		void insert(string,const int num, HashTable);
};


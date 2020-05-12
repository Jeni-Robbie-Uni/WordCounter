#pragma once
#include <string>
#include "HashNode.h"

using namespace std;



class HashTable
{






	public:
		int arraySize;
		int attempts = 0;
		int numInserts = 0;
		static HashNode content[];




	public:
		HashTable();
		HashTable(int);


		static bool isPresent(string);
		static bool isEmpty(int, HashTable);
		static bool isArrayFull();


		int hash(int, const int);

		void insert(string,const int num, HashTable x);

	




};


#pragma once

#include <string>
using namespace std;



class HashTable
{



		protected:
			class HashNode
			{

			public:
				string key;     //holds word value

				int value = 0;          //hold number of occurences of word

				HashNode() {
					key = "EMPTY"; //will never match caUSE READ FILE always converts to lowercase
					value = 0;
				}

			};



	public:
		int arraySize;
		int attempts = 0;
		int numInserts;
		HashNode* content;

	public:
		HashTable();
		HashTable(int);
		~HashTable();

		void ReSizeHashTable(HashTable*);

		bool isPresent(string, int);
		bool isEmpty(int);
		bool isArrayFull();

		int GetArraySize();
		int hash(int, string);
		int hash2(int);

		void copy(HashTable*, HashTable*, int index);
		void insert(string, HashTable*);



};


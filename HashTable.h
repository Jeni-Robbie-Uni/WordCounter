#pragma once

#include <string>
using namespace std;



class HashTable
{



		protected:
			class HashNode
			{

			public:
				string element;     //holds word value

				int count = 0;          //hold number of occurences of word

				HashNode() {
					element = "EMPTY"; //will never match caUSE READ FILE always converts to lowercase
					count = 0;
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

		void copy(HashTable*, HashTable*, int index);
		void insert(string, HashTable*);



};


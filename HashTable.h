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



	private:
		int arraySize;
		int numInserts=0;
		HashNode* content;

	public:
		HashTable();
		HashTable(int);
		~HashTable();

		int GetNumOfInserts();
		string GetKey(int);
		int GetValue(int);

		HashTable* ReSizeHashTable(HashTable*);		
		void Copy(HashTable*, HashTable*, int);
		void Insert(string, HashTable*);

		bool IsPresent(string, int);
		bool IsEmpty(int);
		bool IsArrayFull();

		int GetArraySize();

		int DoubleHash( string);
		int Hash1(int);
		int Hash2(int);
		int GetAsciiTotal(string);

		
};


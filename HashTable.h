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
		int numInserts=0;	//number of unique words in hashtable 
		HashNode* content;			

	public:
		//constructors
		HashTable();
		HashTable(int);
		//destructor
		~HashTable();


		int GetNumOfInserts(); //returns number of unique words
		string GetKey(int);		//returns the key i.e. the string 
		int GetValue(int);				//returns the number of occurences

		HashTable* ReSizeHashTable(HashTable*);		//returns pointer to new bigger hash table with rehashed content
		void Copy(HashTable*, HashTable*, int);			//copies old table node values to new at newly rehashed values
		void Insert(string, HashTable*);			//inserts or increments word in table

		bool IsPresent(string, int);		//checks if the word is present in specific table slot
		bool IsEmpty(int);				//Checks if the array is an empty slot
		bool IsArrayFull();		//checks if the number of inserts is the same as arraysize i.e. its full

		int GetArraySize();		//returns table size

		int DoubleHash( string);		//controls hashing and collision handlling 
		int Hash1(int);					//first hash function
		int Hash2(int);					//second hash function
		int GetAsciiTotal(string);		//calculates the ASCII total of characters in a string for hashing

		
};


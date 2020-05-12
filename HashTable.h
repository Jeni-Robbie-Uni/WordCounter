#pragma once
#include <string>
using namespace std;



class HashTable
{
	private:
		int arraySize;
		
		int attempts = 0;
		int numInserts = 0;


protected:
	class HashNode
	{
	public:
		string element;     //holds word value
		string* pElement = &element;		//Create pointer so I can set string to null as cant otherwise
		int count = 0;          //hold number of occurences of word

		HashNode() : pElement(NULL), count(1) {}     //Constructor

	};

	public:
		HashTable();
		HashTable(int);
		HashTable(const HashTable*);

		bool isPresent(string);
		bool isArrayFull();


		int hash(int, const int);

		void insert(string,const int num);

	




};


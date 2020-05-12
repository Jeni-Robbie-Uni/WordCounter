#pragma once
#include <string>
using namespace std;
class HashNode
{

	public:
		string element;     //holds word value
		string* pElement = &element;		//Create pointer so I can set string to null as cant otherwise
		int count = 0;          //hold number of occurences of word

		HashNode() {
			pElement = NULL;
			count = 0;
		}

	};




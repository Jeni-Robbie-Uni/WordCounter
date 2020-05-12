#pragma once
#include <string>
using namespace std;
static class HashNode
{

	public:
		string element;     //holds word value

		int count = 0;          //hold number of occurences of word

		HashNode() {
			element = "EMPTY"; //will never match caUSE READ FILE always converts to lowercase
			count = 0;
		}

	};




#pragma once
#include <fstream>
#include <string>
using namespace std;
 class InputUtils
{

	 int value;
	 string key;

public:

	InputUtils();
		static string ConvertToLowerCase(string);
		static string ValidateWord(string);
		static string ReadWord(ifstream&);

		void setKey(string);
		void setValue(int);
		string GetKey();
		int GetValue();
		

};


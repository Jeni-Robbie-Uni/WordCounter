#pragma once
#include <fstream>
#include <string>
using namespace std;
 class InputUtils
{

public:

	InputUtils();
		static string ConvertToLowerCase(string);
		static string ValidateWord(string);
		static string ReadWord(ifstream&);

		/*void setKey(string);
		void setValue(int);
		string GetKey();
		int GetValue();*/



		

};

struct wordCount {

	 public:
	 int count=0;
	 string word;

 };
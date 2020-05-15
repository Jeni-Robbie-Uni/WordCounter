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
		


		

};

struct wordCount {

	 public:
	 int count=0;
	 string word;

 };
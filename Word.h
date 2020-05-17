#pragma once
#include <fstream>
#include <string>
using namespace std;

//input utility class deals with formatting, validating and reading strings from a text file
 class InputUtils
{

public:

		static string ConvertToLowerCase(string);
		static string ValidateWord(string);
		static string ReadWord(ifstream&);

};

struct WordCount {

	 public:
	 int count=0;
	 string word;

 };
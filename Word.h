#pragma once
#include <fstream>
#include <string>
using namespace std;

class Word
{
	private:
		string word;


public:
		
	Word();
	Word(string);

		string GetWord();
		void SetWord(string);

		static string ConvertToLowerCase(string);
		static string ValidateWord(string);


		string ReadWord(ifstream&);
		int getASCIItotal();

};


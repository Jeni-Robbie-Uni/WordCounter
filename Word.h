#pragma once
#include <fstream>
#include <string>
using namespace std;

class Word
{
	private:
		string word = "";
		int frequency = 0;

public:
		string GetWord();
		void SetWord(string);

		int GetFrequency();
		void incrementFrequency();

		static string ConvertToLowerCase(string);
		static string ValidateWord(string);


		string ReadWord(ifstream&);
		

};


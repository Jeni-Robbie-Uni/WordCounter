#pragma once
#include <fstream>
#include <string>
using namespace std;
 class InputUtils
{



public:

		static string ConvertToLowerCase(string);
		static string ValidateWord(string);


		static string ReadWord(ifstream&);
		

};


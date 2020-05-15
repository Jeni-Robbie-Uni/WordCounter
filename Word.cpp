#include "Word.h"

InputUtils::InputUtils() {
    value = 0;
    key = "";
}

void InputUtils::setKey(string input) {
    key = input;
}

void InputUtils::setValue(int val) {
    value = val;
}

string InputUtils::GetKey() {
    return key;
}
int InputUtils::GetValue() {
    return value;
}



string InputUtils::ConvertToLowerCase(string input) {
	for (int i = 0; i < input.length(); i++)
	{
		//Convert all characters to lower case
		input[i] = tolower(input[i]);
	}

	return input;

}
 string InputUtils::ValidateWord(string input) {
    for (int i = 0; i < input.length(); i++)
    {
        //Check if character is alphabetical character
        if (!isalpha(input[i]))
        {
            //If not, remove 1 character position i in string
            input.erase(i, 1);
            //Move the back to correct position to account for new length
            i = i - 1;
        }
    }
    return input;
}


 string InputUtils::ReadWord(ifstream& file) {
     string word;

         //get string 
         file >> word;

         //Convert word to correct format
         word = ConvertToLowerCase(word);

         word = ValidateWord(word);

     return word;
 }


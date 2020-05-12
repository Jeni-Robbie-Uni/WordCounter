#include "Word.h"
string Word::GetWord() {

	return word;
}
void Word::SetWord(string input) {
	word = input;
}

int Word::GetFrequency() {
	return frequency;
}

void Word::incrementFrequency() {
	frequency++;
}

string Word::ConvertToLowerCase(string input) {
	for (int i = 0; i < input.length(); i++)
	{
		//Convert all characters to lower case
		input[i] = tolower(input[i]);
	}

	return input;

}

string Word::ValidateWord(string input) {
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
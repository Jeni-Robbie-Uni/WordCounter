// WordFrequency.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <string>
#include <fstream>
using namespace std;





int main()

{
    string word;        //Word to be read from file
    bool isDuplicate;         //hold whether word is unique
    string fileName;        //Name of file to be opened and read
    ifstream readFile;


    //Until exit condition is reached
    while (fileName != "0")
    {
        //Instructions
        cout << "Please enter name of text file user wishes to word count. For Example \"test.txt\"" << endl;
        cin >> fileName;    //get name of file to be opened
        if (fileName == "0")        //If exit condition is reached
            continue;               //leave loop

        readFile.open(fileName);    //Open file

        //Check if file has opened correct
        if (!readFile.is_open())
        {
            while ((!readFile.is_open()) && (fileName != "0"))        //Until file can be opened or user wants to exit
            {
                cout << "Error. Could not open file." << endl;
                cout << "Please enter file name again or 0 to exit." << endl;


                cin >> fileName;    //get name of file to be opened

            }
            if (fileName == "0")    //break loop if exit condition met
                break;
        }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

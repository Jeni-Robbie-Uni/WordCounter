// WordFrequency.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <string>
#include <fstream>
#include "HashTable.h"
#include "Word.h"
using namespace std;





int main()

{

    HashTable hTable;



    string readWord;
    Word currentWord; //word being read
    
    string fileName;        //Name of file to be opened and read
    ifstream file;
    bool exit;
    string const exitCondition = "0";

    //Until exit condition is reached
    do
    {
        exit = false;   //reset exit to false


        //Instructions
        cout << "Please enter name of text file user wishes to word count. For Example \"test.txt\"" << endl;
        cin >> fileName;    //get name of file to be opened

        file.open(fileName);    //Open file

        //Check if file has opened correct
        while (!file.is_open() && exit ==false)
        {

                cout << "Error. Could not open file." << endl;
                cout << "Please enter file name again or 0 to exit." << endl;


                cin >> fileName;    //get name of file to be opened
                file.open(fileName);    //Open file
            
                if (fileName == exitCondition)    //break loop if exit condition met
                {
                    exit = true;
                }

        }
       
        if (exit == true)
            continue;



        while (!file.eof())
        {

            currentWord.SetWord(currentWord.ReadWord(file));
           
            hTable.insert(currentWord.GetWord(), currentWord.getASCIItotal(), hTable);


        }
        
        for (int i = 0; i < hTable.GetArraySize(); i++)
        {
            cout << hTable.content[i].element<<endl;
        }

            
        cout << endl;
        file.close();

    }while (exit == false);
   
}
















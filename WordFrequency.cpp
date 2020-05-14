// WordFrequency.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include <string>
#include <fstream>
#include "HashTable.h"
#include "Word.h"
using namespace std;





int main()
{
    string readWord;    
    string fileName;        //Name of file to be opened and read
    ifstream file;
    bool exit;
    string const exitCondition = "0";

    //Until exit condition is reached
    do
    {
        exit = false;   //reset exit to false
        HashTable* hTable = new HashTable;

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



        do
        {

            readWord = InputUtils::ReadWord(file);
            
            if (readWord == "")         //if file finished has a new line or space it'll try and read word that isn't there so you have to ignore it
                continue;
           
            hTable->insert(readWord, hTable);
            
            
            
            if (hTable->isArrayFull())
            {
                hTable->ReSizeHashTable(hTable);
            }
        } while (!file.eof());
        
        for (int i = 0; i < hTable->GetArraySize(); i++)
        {
            cout << hTable->content[i].key<< " " << hTable->content[i].value << endl;
        }

            
        cout << endl;
        file.close();

    }while (exit == false);
   
    //_CrtDumpMemoryLeaks();

}
















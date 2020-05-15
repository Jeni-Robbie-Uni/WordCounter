// WordFrequency.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include <string>
#include <fstream>
#include "SortList.h"
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
                hTable= hTable->ReSizeHashTable(hTable);
            }

        } while (!file.eof());
        

        int size = hTable->GetArraySize();
            
        file.close();
        
        ;
        

        int newArrSize = hTable->GetNumOfInserts();
        wordCount* arr = new wordCount[newArrSize];


  
        int index2 = 0;
        for (int i = 0;i < size;i++) {
           
            if (hTable->GetKey(i) != "EMPTY")
            {
                arr[index2].word= hTable->GetKey(i); 
                arr[index2].count=(hTable->GetValue(i));
                index2++;
            }
            else
                continue;
        }

        SortList::Quicksort(newArrSize, arr);

        for (int i = 0; i < newArrSize; i++)
        {
            cout << arr[i].word << " " << arr[i].count <<endl;
        }
        
    }while (exit == false);
   
    
}









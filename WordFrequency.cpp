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











void Swap(wordCount& a, wordCount& b)
{
    wordCount temp = a;
    a = b;
    b = temp;
}

void Split(const int first, const int last, int& split_index, wordCount Element[])
{
    int left, right;  // Markers for searching from left and right


    wordCount pivot = Element[first];
    left = first;
    right = last;
    while (left < right)   // While markers have not met
    {
        // Search from the right for element <= pivot

        while (Element[right].element > pivot.element)
            right = right - 1;

        // Search from the left for element > pivot

        while ((left < right) && (Element[left].element <= pivot.element))
            left = left + 1;

        // If markers have not met, interchange elements

        if (left < right)
            Swap(Element[left], Element[right]);
    };

    // Searches complete; now place pivot in correct place

    split_index = right;
    Element[first] = Element[split_index];
    Element[split_index] = pivot;
}

void Quicksort(const int first, const int last, wordCount Element[])

// Sorts portion of array Element between
// Element[first] and Element[last]

{
    int split_index;     // Final position of pivot

    if (first < last)           // List has at least two elements
    {
        Split(first, last, split_index, Element);      // Split into two sublists
        Quicksort(first, split_index - 1, Element);   // Sort left sublist
        Quicksort(split_index + 1, last, Element);     // Sort right sublist
    }
    // else list has 0 or 1 elements and needs no sorting
}

void Quicksort(int ArraySize, wordCount Element[])
{
    Quicksort(0, ArraySize - 1, Element);
}






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
                arr[index2].element= hTable->GetKey(i); 
                arr[index2].value=(hTable->GetValue(i));
                index2++;
            }
            else
                continue;
        }

        Quicksort(newArrSize, arr);

        


        for (int i = 0; i < newArrSize; i++)
        {
            cout << arr[i].element << " " << arr[i].value <<endl;
        }
        
    }while (exit == false);
   
    
}









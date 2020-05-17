#include "Sortlist.h"



void SortList::Swap(WordCount& a, WordCount& b){

    WordCount temp = a;
    a = b;
    b = temp;
}

void SortList::Split(const int first, const int last, int& split_index, WordCount Element[])
{
    int left, right;  // Markers for searching from left and right


    WordCount pivot = Element[first];
    left = first;
    right = last;
    while (left < right)   // While markers have not met
    {
        // Search from the right for element <= pivot

        while (Element[right].word > pivot.word)
            right = right - 1;

        // Search from the left for element > pivot

        while ((left < right) && (Element[left].word <= pivot.word))
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

void SortList::Quicksort(const int first, const int last, WordCount Element[])

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

void SortList::Quicksort(int ArraySize, WordCount Element[])
{
    Quicksort(0, ArraySize - 1, Element);
}



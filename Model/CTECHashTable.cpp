//
//  CTECHashTable.cpp
//  NodeProjectXCode
//
//  Created by Hodsdon, Trevor on 5/5/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "CTECHashTable.h"
#include <iostream>
using namespace std;

/*
 * Constructor for the CTECHashTable. Initialzes all data members.
 * Sets the capacity of the base storage to 101.
 */
template <class Type>
CTECHashTable<Type> :: CTECHashTable()
{
    this->size = 0;
    this->capacity = 101;
    this->efficiencyPercentage = 0.667;
    this->internalStorage = new Type[capacity];
}

/*
 * Deallocates all memory attached to thinternal storage.
 */
template <class Type>
CTECHashTable<Type> :: ~CTECHashTable<Type>()
{
    delete [] internalStorage;
}

/*
 * return the size of the da structure.
 */
template <class Type>
int CTECHashTable<Type> :: getSize()
{
    return this->size;
}

/*
 * Check if the value exists. If so it will update the size if needed,
 * then find the place for the item in the table, if that location is
 * filled it will loop over or around until it finds an empty location.
 * then it will assign that to the array location and update the
 * size of the structure.
 */
template <class Type>
void CTECHashTable<Type> :: add(const Type& value)
{
    if(!contains(value))
    {
        //resize if needed
        if(size / capacity >= this->efficiencyPercentage)
        {
            updateSize();
        }
        int insertionIndex = findPosition(value);
        
        if(internalStorage[insertionIndex]!= nullptr)
        {
            while(internalStorage[insertionIndex] != nullptr)
            {
                insertionIndex = (insertionIndex + 1) % capacity;
            }
        }
        
        internalStorage[insertionIndex] = value;
        size++;
    }
}
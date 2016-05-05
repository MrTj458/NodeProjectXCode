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
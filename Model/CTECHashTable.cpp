//
//  CTECHashTable.cpp
//  NodeProjectXCode
//
//  Created by Hodsdon, Trevor on 5/5/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "CTECHashTable.h"
#include <cmath>
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
    this->internalStorage = new HashNode<Type>[capacity];
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
void CTECHashTable<Type> :: add(HashNode<Type> currentNode)
{
    if(!contains(currentNode))
    {
        //resize if needed
        if(size / capacity >= this->efficiencyPercentage)
        {
            updateCapacity();
        }
        int insertionIndex = findPosition(currentNode);
        
        if(internalStorage[insertionIndex]!= nullptr)
        {
            while(internalStorage[insertionIndex] != nullptr)
            {
                insertionIndex = (insertionIndex + 1) % capacity;
            }
        }
        
        internalStorage[insertionIndex] = currentNode;
        size++;
    }
}

/*
 * Finds the simplest hash for the associated key/value pair.
 * Uing a modlo of the key by the capacity.
 */
template <class Type>
int CTECHashTable<Type> :: findPosition(HashNode<Type> currentNode)
{
    int position = 0;
    
    position = currentNode.getKey() % capacity;
    
    return position;
}

template <class Type>
int CTECHashTable<Type> :: getNextPrime()
{
    int nextPrime = capacity;
    
    nextPrime *= 2;
    nextPrime++;
    
    while(!isPrime(nextPrime))
    {
        nextPrime += 2;
    }
    
    return nextPrime;
}

template <class Type>
bool CTECHashTable<Type> :: isPrime(int candidateNumber)
{
    bool isPrime = true;
    
    if(candidateNumber <= 1)
    {
        isPrime = false;
    }
    else if(candidateNumber == 2 || candidateNumber == 3)
    {
        isPrime = true;
    }
    else if(candidateNumber % 2 == 0)
    {
        isPrime = false;
    }
    else
    {
        for(int spot = 3; spot < sqrt(candidateNumber) + 1; spot += 2)
        {
            if(candidateNumber % spot == 0)
            {
                isPrime = false;
                break;
            }
        }
    }
    
    return isPrime;
}
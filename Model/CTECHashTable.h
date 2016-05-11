//
//  CTECHashTable.hpp
//  NodeProjectXCode
//
//  Created by Hodsdon, Trevor on 5/5/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef CTECHashTable_hpp
#define CTECHashTable_hpp

#include "HashNode.cpp"
#include "CTECList.cpp"
#include <stdio.h>

template <class Type>
class CTECHashTable
{
private:
    int size;
    int capacity;
    HashNode<Type> * internalStorage;
    void updateTableCapacity();
    
    int chainedCapacity;
    int chainedSize;
    CTECList<HashNode<Type>> * chainedStorage;
    void updateChainedCapacity();
    
    double efficiencyPercentage;
    
    int findPosition(HashNode<Type> currentNode);
    int handleCollision(HashNode<Type> currentNode);
    void updateCapacity();
    
    int getNextPrime();
    bool isPrime(int candidateNmber);
public:
    CTECHashTable();
    ~CTECHashTable();
    
    void add(HashNode<Type> currentNode);
    void addChained(HashNode<Type> currentNode);
    bool remove(HashNode<Type> currentNode);
    bool contains(HashNode<Type> currentNode);
    int getSize();
};

#endif /* CTECHashTable_hpp */

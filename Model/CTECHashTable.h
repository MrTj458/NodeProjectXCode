//
//  CTECHashTable.hpp
//  NodeProjectXCode
//
//  Created by Hodsdon, Trevor on 5/5/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef CTECHashTable_hpp
#define CTECHashTable_hpp

#include <stdio.h>

template <class Type>
class CTECHashTable
{
private:
    int size;
    int capacity;
    Type * internalStorage;
    double efficiencyPercentage;
    
    int findPosition(const Type& value);
    int hangleCollision(const Type& value);
    void updateSize();
public:
    CTECHashTable();
    ~CTECHashTable();
    
    void add(const Type& value);
    bool remove(const Type& value);
    bool contains(const Type& value);
    int getSize();
};

#endif /* CTECHashTable_hpp */

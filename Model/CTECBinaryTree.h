//
//  BinaryTree.hpp
//  NodeProjectXCode
//
//  Created by Hodsdon, Trevor on 4/11/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include "TreeNode.h"

template <class Type>
class CTECBinaryTree
{
private:
    int size;
    TreeNode<Type> * root;
    int height;
    bool balanced;
    bool contains(Type value, CTECBinaryTree<Type> * currentTree);  //done
public:
    CTECBinaryTree();
    ~CTECBinaryTree();
    bool insert(const Type& value);
    Type remove(const Type& value);
    bool contains(Type value);  //done
    int getSize();
    TreeNode<Type> * getRoot();
    int getHeight();
    bool isBalanced();
    void preorderTransversal(TreeNode<Type> * currentNode); //done
    void inorderTransversal(TreeNode<Type> * currentNode);  //done
    void postorderTransversal(TreeNode<Type> * currentNode);//done
};

#endif /* BinaryTree_hpp */

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
    TreeNode<Type> * root;                                          //done
    int height;                                                     //done
    bool balanced;                                                  //done
    bool contains(Type value, TreeNode<Type> * currentTree);  //done
    void calculateSize(TreeNode<Type> * currentNode);               //done
    void remove(TreeNode<Type> * nodeToBeRemoved);
    TreeNode<Type> * getRightMostChild(TreeNode<Type> * leftSubTree);
    TreeNode<Type> * getLeftMostChild(TreeNode<Type> * rightSubTree);
public:
    CTECBinaryTree();                                               //done
    ~CTECBinaryTree();
    bool insert(const Type& value);                                 //done
    void remove(const Type& value);
    bool contains(Type value);                                      //done
    int getSize();                                                  //done
    TreeNode<Type> * getRoot();                                     //done
    int getHeight();
    bool isBalanced();
    void preorderTransversal(TreeNode<Type> * currentNode);         //done
    void inorderTransversal(TreeNode<Type> * currentNode);          //done
    void postorderTransversal(TreeNode<Type> * currentNode);        //done
};

#endif /* BinaryTree_hpp */

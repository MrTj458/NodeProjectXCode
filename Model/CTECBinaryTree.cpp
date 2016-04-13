//
//  BinaryTree.cpp
//  NodeProjectXCode
//
//  Created by Hodsdon, Trevor on 4/11/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "CTECBinaryTree.h"
#include <iostream>
using namespace std;

template<class Type>
CTECBinaryTree<Type>::CTECBinaryTree()
{
    this->root = nullptr;
    this->balanced = true;
    this->size = 0;
    this->height = 0;
}

template <class Type>
int CTECBinaryTree<Type>::getSize()
{
    size = 0;
    size = calculateSize(root);
    return size;
}

template <class Type>
void CTECBinaryTree<Type>::calculateSize(TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        calculateSize(currentNode->getLeftChild());
        calculateSize(currentNode->getLeftChild());
        size++;
    }
}

template <class Type>
TreeNode<Type> * CTECBinaryTree<Type>::getRoot()
{
    return root;
}

template <class  Type>
void CTECBinaryTree<Type>::preorderTransversal(TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        cout << currentNode->getValue() << " ";
        preorderTransrsal(currentNode->getLeftChild());
        preorderTransrsal(currentNode->getRightChild());
    }
}

template <class  Type>
void CTECBinaryTree<Type>::inorderTransversal(TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        inorderTransrsal(currentNode->getLeftChild());
        cout << currentNode->getValue() << " ";
        inorderTransrsal(currentNode->getRightChild());
    }
}

template <class  Type>
void CTECBinaryTree<Type>::postorderTransversal(TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        postorderTransrsal(currentNode->getLeftChild());
        postorderTransrsal(currentNode->getRightChild());
        cout << currentNode->getValue() << " ";
    }
}

template <class Type>
bool CTECBinaryTree<Type>::contains(Type value)
{
    bool isInTree = false;
    
    if(root != nullptr)
    {
        if(root->getValue() == value)
        {
            isInTree = true;
        }
        else
        {
            if(value < root->getValue())
            {
                isInTree = contains(value, root->getLeftChild());
            }
            else
            {
                isInTree = contains(value, root->getRightChild());
            }
        }
    }
    
    return isInTree;
}

template <class Type>
bool CTECBinaryTree<Type>::contains(Type value, CTECBinaryTree<Type> * currentTree)
{
    bool isInTree = false;
    
    if(currentTree != nullptr)
    {
        if(currentTree->getRoot()->getValue() == value)
        {
            isInTree = true;
        }
        else
        {
            if(value < currentTree->getRoot()->getValue())
            {
                isInTree = contains(value, currentTree->getRoot()->getLeftChild());
            }
            else
            {
                isInTree = contains(value, currentTree->getRoot()->getRightChild());
            }
        }
    }
    
    return isInTree;
}
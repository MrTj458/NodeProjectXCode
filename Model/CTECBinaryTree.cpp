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
bool CTECBinaryTree<Type>::insert(const Type& value)
{
    if(contains(value))
    {
        return false;
    }
    else
    {
        TreeNode<Type> current = root;
        TreeNode<Type> previous;
        
        if(root == nullptr)
        {
            root = new TreeNode<Type>(value);
        }
        else
        {
            while(current != nullptr)
            {
                previous = current;
                
                if(current->getValue() > value)
                {
                    current = current->getLeftChild();
                }
                else
                {
                    current = current->getRightChild();
                }
            }
            
            if(previous->getValue() > value)
            {
                previous->setLeftChild(new TreeNode<Type>(value, previous));
            }
            else
            {
                previous->setRightChild(new TreeNode<Type>(value, previous));
            }
        }
    }
    return true;
}

template <class Type>
void CTECBinaryTree<Type>::remove(TreeNode<Type> * nodeToBeRemoved)
{
    TreeNode<Type> * current;
    TreeNode<Type> * previous;
    TreeNode<Type> * temp;
    
    if(nodeToBeRemoved == nullptr)
    {
        cerr << "Cannot remove null from the list";
    }
    else if(nodeToBeRemoved->getLeftChild() == nullptr && nodeToBeRemoved->getRightChild() == nullptr)
    {
        temp = nodeToBeRemoved;
        nodeToBeRemoved = nullptr;
        delete temp;
    }
    else if(nodeToBeRemoved->getLeftChild() == nullptr)
    {
        temp = nodeToBeRemoved;
        nodeToBeRemoved = temp->getRightChild();
        delete temp;
    }
    else if(nodeToBeRemoved->getRightChild() == nullptr)
    {
        temp = nodeToBeRemoved;
        nodeToBeRemoved = temp->getLeftChild();
        delete temp;
    }
    else
    {
        current = nodeToBeRemoved->getLeftChild();
        previous = nullptr;
        
        while(current->getRightChild() != nullptr)
        {
            previous = current;
            current = current->getRightChild();
        }
        
        nodeToBeRemoved->setValue(current->getValue());
        
        if(previous == nullptr)
        {
            nodeToBeRemoved->setLeftChild(current->getLeftChild());
        }
        else
        {
            previous->setRightChild(current->getLeftChild());
        }
        
        delete current;
    }
}

template <class Type>
void CTECBinaryTree<Type>::remove(const Type& value)
{
    TreeNode<Type> * current;
    TreeNode<Type> * previous;
    
    if(!contains(value))
    {
        return;
    }
    else
    {
        current = root;
        previous = root;
        
        while(current != nullptr && current->getValue() != value)
        {
            previous = current;
                
            if(current->getValue() > value)
            {
                current = current->getLeftChild();
            }
            else
            {
                current = current->getRightChild();
            }
        }
        
        if(current == root)
        {
            remove(root);
        }
        else if(previous->getValue() > value)
        {
            remove(previous->getLeftChild());
        }
        else
        {
            remove(previous->getRightChild());
        }
    }
}

template <class Type>
TreeNode<Type> * CTECBinaryTree<Type>::getRightMostChild(TreeNode<Type> * leftSubTree)
{
    TreeNode<Type> * rightNode = leftSubTree->getRoot();
    
    while(rightNode->getLeftChild() != nullptr)
    {
        rightNode = rightNode->getRightChild();
    }
    
    return rightNode;
}

template <class Type>
TreeNode<Type> * CTECBinaryTree<Type>::getLeftMostChild(TreeNode<Type> * rightSubTree)
{
    TreeNode<Type> * leftNode = rightSubTree->getRoot();
    
    while(leftNode->getRightChild() != nullptr)
    {
        leftNode = leftNode->getleftChild();
    }
    
    return leftNode;
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
bool CTECBinaryTree<Type>::contains(Type value, TreeNode<Type> * currentTree)
{
    bool isInTree = false;
    
    if(currentTree != nullptr)
    {
        if(currentTree->getValue() == value)
        {
            isInTree = true;
        }
        else
        {
            if(value < currentTree->getValue())
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
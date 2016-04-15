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
        TreeNode<Type> newNode = new TreeNode<Type>(value);
        TreeNode<Type> current = root;
        TreeNode<Type> previous = current;
        
        if(root == nullptr)
        {
            
        }
        else
        {
            while(current != nullptr)
            {
                previous = current;
                
                if(current->getValue == newNode->getValue)
                {
                    cerr << "Duplicate item on the list" << endl;
                    return false;
                }
                else if(current->getValue() > newNode->getValue)
                {
                    current = current->getLeftChild();
                }
                else
                {
                    current = current->getRightChild();
                }
            }
            
            if(previous->getValue > newNode->getValue())
            {
                previous->setLeftChild(newNode);
            }
            else
            {
                previous->setRightChild(newNode);
            }
        }
    }
}

template <class Type>
void CTECBinaryTree<Type>::deleteFromTree(TreeNode<Type> * toDelete)
{
    TreeNode<Type> current;
    TreeNode<Type> previous;
    TreeNode<Type> temp;
    
    if(toDelete == nullptr)
    {
        cerr << "Cannot remove null from the list";
    }
    else if(toDelete->getRightLink == nullptr && toDelete->getLeftLink == nullptr)
    {
        temp = toDelete;
        toDelete = nullptr;
        delete temp;
    }
    else if(toDelete->getLeftChild == nullptr)
    {
        temp = toDelete;
        toDelete = temp->getRightChild();
        delete temp;
    }
    else if(toDelete->getRightChild == nullptr)
    {
        temp = toDelete;
        toDelete = temp->getLeftChild();
        delete temp;
    }
    else
    {
        current = toDelete->getLeftChild();
        previous = nullptr;
        
        while(current->getRightChild != nullptr)
        {
            previous = current;
            current = current->getRightChild;
        }
        
        toDelete->getValue = current->getValue;
        
        if(previous == nullptr)
        {
            toDelete->getLeftChild = current->getLeftChild;
        }
        else
        {
            previous->getRightChild = current->getLeftChild;
        }
        
        delete current;
    }
}

template <class Type>
Type CTECBinaryTree<Type>::remove(const Type& value)
{
    TreeNode<Type> current;
    TreeNode<Type> previous;
    bool found = false;
    
    if(root == nullptr)
    {
        cout << "Cannot delete from an empty tree." << endl;
    }
    else
    {
        current = root;
        previous = root;
        
        while(current != NULL && !found)
        {
            if(current->getValue == value)
            {
                found = true;
            }
            else
            {
                previous = current;
                
                if(current->getValue > value)
                {
                    current = current->getLeftChild;
                }
                else
                {
                    current = current->getRightChild;
                }
            }
        }
        
        if(current == NULL)
        {
            cout << "The delete item is not in the tree" << endl;
        }
        else if(found)
        {
            if(current == root)
            {
                deleteFromTree(root);
            }
            else if(previous->getValue > value)
            {
                deleteFromTree(previous->getLeftChild);
            }
            else
            {
                deleteFromTree(previous->getRightChild);
            }
        }
    }
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
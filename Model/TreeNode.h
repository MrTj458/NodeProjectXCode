//
//  TreeNode.hpp
//  NodeProjectXCode
//
//  Created by Hodsdon, Trevor on 4/11/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef TreeNode_hpp
#define TreeNode_hpp

#include "node.h"

template <class Type>
class TreeNode : public Node<Type>
{
private:
    TreeNode<Type> * leftChild;
    TreeNode<Type> * rightChild;
    TreeNode<Type> * parent;
public:
    TreeNode();
    TreeNode(const Type& value);
    TreeNode(const Type& value, TreeNode<Type> * parent);
    void setLeftchild(TreeNode<Type> * leftChild);
    void setRightChild(TreeNode<Type> * rightChild);
    void setParent(TreeNode<Type> * parent);
    TreeNode<Type> * getLeftChild();
    TreeNode<Type> * getRightChild();
    TreeNode<Type> * getParent();
};

#endif /* TreeNode_hpp */

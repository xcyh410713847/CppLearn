/*************************************************************************
**文件: BinaryTree\BinaryTree\BinaryTree.cpp
**作者: shyfan
**日期: 2024/07/11 16:30:33
**功能: 二叉树的实现
*************************************************************************/

#include "BinaryTree.h"

#include <iostream>
#include <queue>

BinaryTree::BinaryTree() { Root = nullptr; }

BinaryTree::~BinaryTree() {}

void BinaryTree::Insert(const int &InValue)
{
    TreeNode *node = new TreeNode;
    node->Value = InValue;
    node->Left = nullptr;
    node->Right = nullptr;

    if (Root == nullptr)
    {
        Root = node;
        return;
    }

    TreeNode *current = Root;
    TreeNode *parent = nullptr;
    while (current != nullptr)
    {
        parent = current;
        if (InValue < current->Value)
        {
            current = current->Left;
        }
        else
        {
            current = current->Right;
        }
    }

    if (InValue < parent->Value)
    {
        parent->Left = node;
    }
    else
    {
        parent->Right = node;
    }
}

void BinaryTree::Delete(const int &InValue)
{
    TreeNode *current = Root;
    TreeNode *parent = nullptr;
    while (current != nullptr && current->Value != InValue)
    {
        parent = current;
        if (InValue < current->Value)
        {
            current = current->Left;
        }
        else
        {
            current = current->Right;
        }
    }

    if (current == nullptr)
    {
        return;
    }

    if (current->Left == nullptr)
    {
        if (parent == nullptr)
        {
            Root = current->Right;
        }
        else
        {
            if (current == parent->Left)
            {
                parent->Left = current->Right;
            }
            else
            {
                parent->Right = current->Right;
            }
        }
        delete current;
    }
    else if (current->Right == nullptr)
    {
        if (parent == nullptr)
        {
            Root = current->Left;
        }
        else
        {
            if (current == parent->Left)
            {
                parent->Left = current->Left;
            }
            else
            {
                parent->Right = current->Left;
            }
        }
        delete current;
    }
    else
    {
        TreeNode *successor = current->Right;
        TreeNode *successorParent = current;
        while (successor->Left != nullptr)
        {
            successorParent = successor;
            successor = successor->Left;
        }

        current->Value = successor->Value;
        if (successor == successorParent->Left)
        {
            successorParent->Left = successor->Right;
        }
        else
        {
            successorParent->Right = successor->Right;
        }
        delete successor;
    }
}

TreeNode *BinaryTree::Search(const int &InValue)
{
    TreeNode *current = Root;
    while (current != nullptr && current->Value != InValue)
    {
        if (InValue < current->Value)
        {
            current = current->Left;
        }
        else
        {
            current = current->Right;
        }
    }
    return current;
}

void BinaryTree::PreOrder(TreeNode *node)
{
    if (node == nullptr)
    {
        return;
    }

    std::cout << node->Value << " ";
    PreOrder(node->Left);
    PreOrder(node->Right);
}

void BinaryTree::InOrder(TreeNode *node)
{
    if (node == nullptr)
    {
        return;
    }

    InOrder(node->Left);
    std::cout << node->Value << " ";
    InOrder(node->Right);
}

void BinaryTree::PostOrder(TreeNode *node)
{
    if (node == nullptr)
    {
        return;
    }

    PostOrder(node->Left);
    PostOrder(node->Right);
    std::cout << node->Value << " ";
}

void BinaryTree::LevelOrder(TreeNode *node)
{
    if (node == nullptr)
    {
        return;
    }

    std::queue<TreeNode *> q;
    q.push(node);
    while (!q.empty())
    {
        TreeNode *current = q.front();
        q.pop();
        std::cout << current->Value << " ";
        if (current->Left != nullptr)
        {
            q.push(current->Left);
        }
        if (current->Right != nullptr)
        {
            q.push(current->Right);
        }
    }
}

int BinaryTree::GetHeight(TreeNode *node)
{
    if (node == nullptr)
    {
        return 0;
    }

    int leftHeight = GetHeight(node->Left);
    int rightHeight = GetHeight(node->Right);
    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

int BinaryTree::GetSize(TreeNode *node)
{
    if (node == nullptr)
    {
        return 0;
    }

    return GetSize(node->Left) + GetSize(node->Right) + 1;
}

TreeNode *BinaryTree::GetRoot()
{
    return Root;
}

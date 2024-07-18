/*************************************************************************
**文件: BinaryTree\BinaryTree\BinaryTree.cpp
**作者: shyfan
**日期: 2024/07/11 16:30:33
**功能: 二叉树的实现
*************************************************************************/

#include "BinaryTree.h"

#include <iomanip>
#include <queue>

BinaryTree::BinaryTree() { Root = nullptr; }

BinaryTree::~BinaryTree() {}

void BinaryTree::Insert(const int &InValue)
{
    /*
        说明：插入节点的思路
        1. 如果根节点为空，则直接将新节点作为根节点
        2. 如果新节点的值小于当前节点的值，则继续遍历左子树
        3. 如果新节点的值大于等于当前节点的值，则继续遍历右子树
        4. 直到找到一个空节点，将新节点插入到该空节点
    */
    TreeNode *node = new TreeNode;
    node->Value = InValue;
    node->Left = nullptr;
    node->Right = nullptr;

    // 如果根节点为空，则直接将新节点作为根节点
    if (Root == nullptr)
    {
        Root = node;
        return;
    }

    // 遍历二叉树，找到新节点的插入位置
    TreeNode *current = Root;
    TreeNode *parent = nullptr;
    while (current != nullptr)
    {
        parent = current;
        // 如果新节点的值小于当前节点的值，则继续遍历左子树
        if (InValue < current->Value)
        {
            current = current->Left;
        }
        // 如果新节点的值大于等于当前节点的值，则继续遍历右子树
        else
        {
            current = current->Right;
        }
    }

    // 如果新节点的值小于父节点的值，则将新节点插入到父节点的左子树
    if (InValue < parent->Value)
    {
        parent->Left = node;
    }
    // 如果新节点的值大于等于父节点的值，则将新节点插入到父节点的右子树
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

void BinaryTree::PrintTree(TreeNode *node, int level)
{
    if (Root == nullptr)
    {
        return;
    }

    // 计算树的高度
    int height = calculateHeight(Root);
    int maxWidth = std::pow(2, height) - 1; // 最底层的宽度

    // 使用队列实现层次遍历
    std::queue<TreeNode *> q;
    q.push(Root);

    for (int level = 0; level < height; ++level)
    {
        int levelSize = q.size();
        int spaces = (maxWidth - (std::pow(2, level) - 1)) / (std::pow(2, level + 1));

        for (int i = 0; i < levelSize; ++i)
        {
            TreeNode *node = q.front();
            q.pop();

            if (i == 0)
            {
                std::cout << std::setw(spaces) << "";
            }
            else
            {
                std::cout << std::setw(spaces * 2 + 1) << "";
            }

            if (i % 2 == 0)
            {
                std::cout << "[";
            }

            if (node != nullptr)
            {
                std::cout << node->Value;
                q.push(node->Left);
                q.push(node->Right);
            }
            else
            {
                std::cout << std::setw(3) << "*";
                q.push(nullptr);
                q.push(nullptr);
            }

            if (i % 2 != 0)
            {
                std::cout << "]";
            }

            std::cout << std::setw(spaces * 2 + 1) << "";
        }
        std::cout << '\n';
    }
}
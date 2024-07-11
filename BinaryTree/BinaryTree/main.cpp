/*************************************************************************
**文件: BinaryTree\BinaryTree\main.cpp
**作者: shyfan
**日期: 2024/07/11 16:35:55
**功能: 二叉树的测试
*************************************************************************/

#include <iostream>

#include "BinaryTree.h"

int main()
{
    BinaryTree tree;
    tree.Insert(5);
    tree.Insert(3);
    tree.Insert(7);
    tree.Insert(2);
    tree.Insert(4);
    tree.Insert(6);
    tree.Insert(8);

    tree.PreOrder(tree.GetRoot());
    std::cout << std::endl;

    tree.InOrder(tree.GetRoot());
    std::cout << std::endl;

    tree.PostOrder(tree.GetRoot());
    std::cout << std::endl;

    return 0;
}

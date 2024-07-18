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
    // 初始化一个有31个节点的二叉树
    BinaryTree tree;
    tree.Insert(50);
    tree.Insert(30);
    tree.Insert(70);
    tree.Insert(10);
    tree.Insert(40);
    tree.Insert(60);
    tree.Insert(80);
    tree.Insert(5);
    tree.Insert(20);
    tree.Insert(35);
    tree.Insert(45);
    tree.Insert(55);
    tree.Insert(65);
    tree.Insert(75);
    tree.Insert(85);
    tree.Insert(1);
    tree.Insert(8);
    tree.Insert(15);
    tree.Insert(25);
    tree.Insert(32);
    tree.Insert(38);
    tree.Insert(42);
    tree.Insert(48);
    tree.Insert(52);
    tree.Insert(58);
    tree.Insert(62);
    tree.Insert(68);
    // tree.Insert(72);
    tree.Insert(78);
    tree.Insert(82);
    tree.Insert(88);

    // 打印二叉树
    tree.PrintTree(tree.GetRoot(), 0);

    tree.PreOrder(tree.GetRoot());
    std::cout << std::endl;

    tree.InOrder(tree.GetRoot());
    std::cout << std::endl;

    tree.PostOrder(tree.GetRoot());
    std::cout << std::endl;

    tree.LevelOrder(tree.GetRoot());
    std::cout << std::endl;

    return 0;
}

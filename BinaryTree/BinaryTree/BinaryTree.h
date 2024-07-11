/*************************************************************************
**文件: BinaryTree\BinaryTree\BinaryTree.h
**作者: shyfan
**日期: 2024/07/11 16:36:05
**功能: 二叉树的头文件
*************************************************************************/

#pragma once

/**
 * 二叉树节点结构体
 */
struct TreeNode
{
    int Value;       // 节点值
    TreeNode *Left;  // 左节点指针
    TreeNode *Right; // 右节点指针
};

/**
 * 二叉树类
 */
class BinaryTree
{
public:
    BinaryTree();                         // 构造函数
    ~BinaryTree();                        // 析构函数
    void Insert(const int &InValue);      // 插入节点
    void Delete(const int &InValue);      // 删除节点
    TreeNode *Search(const int &InValue); // 查找节点
    void PreOrder(TreeNode *node);        // 前序遍历
    void InOrder(TreeNode *node);         // 中序遍历
    void PostOrder(TreeNode *node);       // 后序遍历
    void LevelOrder(TreeNode *node);      // 层序遍历
    int GetHeight(TreeNode *node);        // 获取树的高度
    int GetSize(TreeNode *node);          // 获取树的节点数
    TreeNode *GetRoot();                  // 获取根节点
private:
    TreeNode *Root; // 根节点
};

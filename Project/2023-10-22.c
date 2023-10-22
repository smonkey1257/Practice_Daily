#include <stdio.h>
#include <stdlib.h>

typedef char Datatype;
typedef struct TreeNode
{
    Datatype val;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

// 遍历数组先序构建二叉树
TreeNode* CreateTreeByPrevorder(Datatype str[], int* pindex)
{
    if (str[*pindex] == '#')
    {
        (*pindex)++;
        return NULL;
    }

    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = str[(*pindex)++];

    root->left = CreateTreeByPrevorder(str, pindex);
    root->right = CreateTreeByPrevorder(str, pindex);

    return root;
}

// 中序遍历输出结点
void Inorder(TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }

    Inorder(root->left);
    printf("%c ", root->val);
    Inorder(root->right);
}

int main() {
    // 输入
    Datatype str[100];
    scanf("%s", str);

    // 先序创建子树
    int index = 0;
    TreeNode* tree = CreateTreeByPrevorder(str, &index);

    // 中序遍历
    Inorder(tree);

    return 0;
}



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);

    // 默认返回左右子树的较小深度
    if (leftDepth > 0 && rightDepth > 0)
        return leftDepth > rightDepth ? rightDepth + 1 : leftDepth + 1;
    // 如果左右子树中有一方深度为0，说明有一方为空，返回较大值
    else
        return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;

}
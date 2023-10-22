#include <stdio.h>
#include <stdlib.h>

typedef char Datatype;
typedef struct TreeNode
{
    Datatype val;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

// �����������򹹽�������
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

// �������������
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
    // ����
    Datatype str[100];
    scanf("%s", str);

    // ���򴴽�����
    int index = 0;
    TreeNode* tree = CreateTreeByPrevorder(str, &index);

    // �������
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

    // Ĭ�Ϸ������������Ľ�С���
    if (leftDepth > 0 && rightDepth > 0)
        return leftDepth > rightDepth ? rightDepth + 1 : leftDepth + 1;
    // ���������������һ�����Ϊ0��˵����һ��Ϊ�գ����ؽϴ�ֵ
    else
        return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;

}
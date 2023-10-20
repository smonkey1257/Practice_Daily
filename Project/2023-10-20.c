/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isUnivalTree(struct TreeNode* root) {
    if (root == NULL)
        return true;

    // 满足的情况不能说明什么，但是不满足的情况可以直接得出结论
    if ((root->left && root->val != root->left->val) ||
        (root->right && root->val != root->right->val))
    {
        return false;
    }

    // 返回值为布尔类型，左右子树都为单值二叉树，才返回true
    return isUnivalTree(root->left) && isUnivalTree(root->right);
}



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* tree1, struct TreeNode* tree2) {
    // 两棵树都为空
    if (tree1 == NULL && tree2 == NULL)
        return true;

    // 其中一棵树为空
    if (tree1 == NULL || tree2 == NULL)
        return false;

    // 两棵树都不为空
    return tree1->val == tree2->val
        && isSameTree(tree1->left, tree2->left)
        && isSameTree(tree1->right, tree2->right);
}



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool _isSymmetric(struct TreeNode* tree1, struct TreeNode* tree2) {
    // 两棵树都为空
    if (tree1 == NULL && tree2 == NULL)
        return true;

    // 其中一棵树为空
    if (tree1 == NULL || tree2 == NULL)
        return false;

    // 两棵树都不为空
    return tree1->val == tree2->val
        && _isSymmetric(tree1->left, tree2->right)
        && _isSymmetric(tree1->right, tree2->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL)
        return true;

    return _isSymmetric(root->left, root->right);
}
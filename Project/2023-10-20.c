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

    // ������������˵��ʲô�����ǲ�������������ֱ�ӵó�����
    if ((root->left && root->val != root->left->val) ||
        (root->right && root->val != root->right->val))
    {
        return false;
    }

    // ����ֵΪ�������ͣ�����������Ϊ��ֵ���������ŷ���true
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
    // ��������Ϊ��
    if (tree1 == NULL && tree2 == NULL)
        return true;

    // ����һ����Ϊ��
    if (tree1 == NULL || tree2 == NULL)
        return false;

    // ����������Ϊ��
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
    // ��������Ϊ��
    if (tree1 == NULL && tree2 == NULL)
        return true;

    // ����һ����Ϊ��
    if (tree1 == NULL || tree2 == NULL)
        return false;

    // ����������Ϊ��
    return tree1->val == tree2->val
        && _isSymmetric(tree1->left, tree2->right)
        && _isSymmetric(tree1->right, tree2->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL)
        return true;

    return _isSymmetric(root->left, root->right);
}
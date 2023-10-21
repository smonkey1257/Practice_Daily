/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */
void _preorder(struct TreeNode* root, int* array, int* returnSize)
{
    if (root == NULL)
        return;

    array[(*returnSize)++] = root->val;
    _preorder(root->left, array, returnSize);
    _preorder(root->right, array, returnSize);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    // ����������ǰ��������
    int* array = (int*)malloc(sizeof(int) * 100);

    // ǰ�����
    *returnSize = 0;
    _preorder(root, array, returnSize);

    return array;
}



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */
  /**
   * Definition for a binary tree node.
   * struct TreeNode {
   *     int val;
   *     struct TreeNode *left;
   *     struct TreeNode *right;
   * };
   */
   /**
    * Note: The returned array must be malloced, assume caller calls free().
    */
void _inorder(struct TreeNode* root, int* array, int* returnSize)
{
    if (root == NULL)
        return;

    _inorder(root->left, array, returnSize);
    array[(*returnSize)++] = root->val;
    _inorder(root->right, array, returnSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    // ����������ǰ��������
    int* array = (int*)malloc(sizeof(int) * 100);

    // ǰ�����
    *returnSize = 0;
    _inorder(root, array, returnSize);

    return array;
}



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */

  /**
   * Definition for a binary tree node.
   * struct TreeNode {
   *     int val;
   *     struct TreeNode *left;
   *     struct TreeNode *right;
   * };
   */


   /**
    * Note: The returned array must be malloced, assume caller calls free().
    */
    /**
     * Definition for a binary tree node.
     * struct TreeNode {
     *     int val;
     *     struct TreeNode *left;
     *     struct TreeNode *right;
     * };
     */
     /**
      * Note: The returned array must be malloced, assume caller calls free().
      */
void _postorder(struct TreeNode* root, int* array, int* returnSize)
{
    if (root == NULL)
        return;

    _postorder(root->left, array, returnSize);
    _postorder(root->right, array, returnSize);
    array[(*returnSize)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    // ����������ǰ��������
    int* array = (int*)malloc(sizeof(int) * 100);

    // ǰ�����
    *returnSize = 0;
    _postorder(root, array, returnSize);

    return array;
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

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    // �������ĸ���Ϊ��
    if (root == NULL && subRoot == NULL)
        return true;

    // ����һ����Ϊ��
    if (root == NULL || subRoot == NULL)
        return false;

    // ����������Ϊ��
    // ����������������һ��������
    return isSameTree(root, subRoot)
        || isSubtree(root->left, subRoot)
        || isSubtree(root->right, subRoot);
}
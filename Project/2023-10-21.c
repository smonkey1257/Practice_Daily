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
    // 开辟数组存放前序遍历结果
    int* array = (int*)malloc(sizeof(int) * 100);

    // 前序遍历
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
    // 开辟数组存放前序遍历结果
    int* array = (int*)malloc(sizeof(int) * 100);

    // 前序遍历
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
    // 开辟数组存放前序遍历结果
    int* array = (int*)malloc(sizeof(int) * 100);

    // 前序遍历
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

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    // 两颗树的根都为空
    if (root == NULL && subRoot == NULL)
        return true;

    // 其中一颗树为空
    if (root == NULL || subRoot == NULL)
        return false;

    // 两颗树都不为空
    // 三个条件任意满足一就是子树
    return isSameTree(root, subRoot)
        || isSubtree(root->left, subRoot)
        || isSubtree(root->right, subRoot);
}
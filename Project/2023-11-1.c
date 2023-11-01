// 2235. 两整数相加
int sum(int num1, int num2) {
    return num1 + num2;
}



// 2469. 温度转换
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* convertTemperature(double celsius, int* returnSize) {
    double kelvin = celsius + 273.15;
    double fahrenheit = celsius * 1.80 + 32.00;

    *returnSize = 2;
    double* ans = (double*)malloc(sizeof(double) * (*returnSize));
    ans[0] = kelvin;
    ans[1] = fahrenheit;

    return ans;
}



// 2413. 最小偶倍数
int smallestEvenMultiple(int n) {
    if (n % 2 == 0)
        return n;

    return n * 2;
}



// 2236. 判断根结点是否等于子结点之和
bool checkTree(struct TreeNode* root) {
    return root->val == (root->left->val + root->right->val);
}



// 1486. 数组异或操作
int xorOperation(int n, int start) {
    int retXOR = 0;
    for (int i = 0; i < n; i++)
    {
        retXOR ^= start + 2 * i;
    }
    return retXOR;
}



// 1512. 好数对的数目
int numIdenticalPairs(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] == nums[j])
            {
                sum++;
            }
        }
    }
    return sum;
}



// 1534. 统计好三元组
int countGoodTriplets(int* arr, int arrSize, int a, int b, int c) {
    int sum = 0;
    for (int i = 0; i < arrSize; i++)
    {
        for (int j = i + 1; j < arrSize; j++)
        {
            for (int k = j + 1; k < arrSize; k++)
            {
                if (abs(arr[i] - arr[j]) <= a &&
                    abs(arr[j] - arr[k]) <= b &&
                    abs(arr[i] - arr[k]) <= c)
                {
                    sum++;
                }
            }
        }
    }
    return sum;
}
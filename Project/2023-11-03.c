// 1470. 重新排列数组
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;

    int x = 0;
    int y = x + n;
    int index = 0;
    while (y < numsSize)
    {
        result[index++] = nums[x++];
        result[index++] = nums[y++];
    }
    return result;
}



// 867. 转置矩阵
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** matrix, int matrixSize, int* matrixColSize,
    int* returnSize, int** returnColumnSizes) {
    int row = matrixSize;
    int col = matrixColSize[0];

    int** ret = (int**)malloc(sizeof(int*) * col);
    *returnSize = col;
    *returnColumnSizes = (int*)malloc(sizeof(int) * col);
    for (int i = 0; i < col; i++)
    {
        ret[i] = (int*)malloc(sizeof(int) * row);
        (*returnColumnSizes)[i] = row;
        for (int j = 0; j < row; j++)
        {
            ret[i][j] = matrix[j][i];
        }
    }
    return ret;
}
// 283. �ƶ���
void moveZeroes(int* nums, int numsSize) {
    int p1 = 0;
    int p2 = 0;
    while (p2 < numsSize)
    {
        if (nums[p2] != 0)
        {
            nums[p1] = nums[p2];
            ++p1;
            ++p2;
        }
        else
        {
            ++p2;
        }
    }
    while (p1 < numsSize)
    {
        nums[p1++] = 0;
    }
}



// 66. ��һ
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    for (int i = digitsSize - 1; i >= 0; i--)
    {
        ++digits[i];
        // �����磺129 �Ȳ���Ϊ9�����
        if (digits[i] == 10)
        {
            digits[i] = 0;
        }
        else
        {
            *returnSize = digitsSize;
            return digits;
        }
    }

    // ����ȫΪ9�����
    *returnSize = digitsSize + 1;
    int* ret = (int*)calloc((*returnSize), sizeof(int));
    ret[0] = 1;
    return ret;
}



// 1822. ����Ԫ�ػ��ķ���
int arraySign(int* nums, int numsSize) {
    int countMinus = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] < 0)
            ++countMinus;
        else if (nums[i] == 0)
            return 0;
    }

    return countMinus % 2 == 0 ? 1 : -1;
}



// 1502. �ж��ܷ��γɵȲ�����
int cmp(const void* value1, const void* value2)
{
    return *((int*)value1) - *((int*)value2);
}

bool canMakeArithmeticProgression(int* arr, int arrSize) {
    qsort(arr, arrSize, sizeof(int), cmp);

    int d = arr[0] - arr[1];
    for (int i = 1; i < arrSize - 1; i++)
    {
        if (arr[i] - arr[i + 1] != d)
            return false;
    }
    return true;
}



// 896. ��������
bool isMonotonic(int* nums, int numsSize) {
    bool UP = false;
    bool DOWN = false;

    for (int i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] < nums[i + 1])
            UP = true;  // ���ֵ�������
        else if (nums[i] > nums[i + 1])
            DOWN = true;// ���ֵ����ݼ�
    }

    if (UP && DOWN)
        return false;   // ͬʱ����˵��������

    return true;
}
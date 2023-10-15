#define _CRT_SECURE_NO_WARNINGS 1

// LeetCode27. 移除元素
int removeElement(int* nums, int numsSize, int val) {
    int p1 = 0, p2 = 0;

    // 索引变量p2遍历数组
    while (p2 < numsSize)
    {
        // p2指向的值 == val，不处理
        if (nums[p2] == val)
        {
            ++p2;
        }
        // p2指向的值 != val，形成一个新数组
        else
        {
            nums[p1++] = nums[p2++];
        }
    }
    // 新数组的长度为p1
    return p1;
}



// LeetCode26. 删除有序数组中的重复项
int removeDuplicates(int* nums, int numsSize) {
    // p2用于遍历数组，p1用于判断是否重复
    int p1 = 0, p2 = 0;

    while (p2 < numsSize)
    {
        // p1指向的元素是不重复的，如果p2遇到的元素和nums[p1]相等，说明重复了
        if (nums[p1] == nums[p2])
        {
            ++p2;
        }
        // 遇到nums[p1] != nums[p2]，不重复数据+1
        else
        {
            nums[++p1] = nums[p2++];
        }
    }
    return p1 + 1;
}



// LeetCode88. 合并两个有序数组
// 从前向后合并会导致元素被覆盖，正确的步骤是从后向前合并
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int end1 = m - 1;
    int end2 = n - 1;
    int end = nums1Size - 1;

    while (end1 >= 0 && end2 >= 0)
    {
        if (nums1[end1] <= nums2[end2])
        {
            nums1[end--] = nums2[end2--];
        }
        else
        {
            nums1[end--] = nums1[end1--];
        }
    }

    // 如果end2 == -1，说明整体已经有序
    // ...

    // 如果end1 == -1，把nums2剩下的元素拷贝到num1
    while (end2 >= 0)
    {
        nums1[end--] = nums2[end2--];
    }
}
#define _CRT_SECURE_NO_WARNINGS 1

// LeetCode27. �Ƴ�Ԫ��
int removeElement(int* nums, int numsSize, int val) {
    int p1 = 0, p2 = 0;

    // ��������p2��������
    while (p2 < numsSize)
    {
        // p2ָ���ֵ == val��������
        if (nums[p2] == val)
        {
            ++p2;
        }
        // p2ָ���ֵ != val���γ�һ��������
        else
        {
            nums[p1++] = nums[p2++];
        }
    }
    // ������ĳ���Ϊp1
    return p1;
}



// LeetCode26. ɾ�����������е��ظ���
int removeDuplicates(int* nums, int numsSize) {
    // p2���ڱ������飬p1�����ж��Ƿ��ظ�
    int p1 = 0, p2 = 0;

    while (p2 < numsSize)
    {
        // p1ָ���Ԫ���ǲ��ظ��ģ����p2������Ԫ�غ�nums[p1]��ȣ�˵���ظ���
        if (nums[p1] == nums[p2])
        {
            ++p2;
        }
        // ����nums[p1] != nums[p2]�����ظ�����+1
        else
        {
            nums[++p1] = nums[p2++];
        }
    }
    return p1 + 1;
}



// LeetCode88. �ϲ�������������
// ��ǰ���ϲ��ᵼ��Ԫ�ر����ǣ���ȷ�Ĳ����ǴӺ���ǰ�ϲ�
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

    // ���end2 == -1��˵�������Ѿ�����
    // ...

    // ���end1 == -1����nums2ʣ�µ�Ԫ�ؿ�����num1
    while (end2 >= 0)
    {
        nums1[end--] = nums2[end2--];
    }
}
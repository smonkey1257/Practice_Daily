// 1422. �ָ��ַ��������÷�
int maxScore(char* s) {
    int score0 = 0;
    int score1 = 0;
    for (int i = 1; s[i]; i++)// �������n-1���ַ��еġ�1��
    {
        if (s[i] == '1')
            ++score1;
    }

    if (s[0] == '0') // ���⴦���һ���ַ�
        ++score0;
    int max = score0 + score1;
    for (int i = 1; i < strlen(s) - 1; i++)
    {
        if (s[i] == '0') // �ӵ�2�����±�Ϊ1����ʼ
        {
            ++score0;
        }
        else
        {
            --score1;
        }
        if (score0 + score1 > max)   // �����������max�͸���max
        {
            max = score0 + score1;
        }
    }
    return max;
}



// 2586. ͳ�Ʒ�Χ�ڵ�Ԫ���ַ�����
// ����Ԫ���ַ����Ķ��壬ʹ�ÿ⺯��strchr������λ�ַ��Ƿ���"aeiou"��
int vowelStrings(char** words, int wordsSize, int left, int right) {
    int count = 0;
    for (int i = left; i <= right; ++i)
    {
        int len = strlen(words[i]);
        if ((strchr("aeiou", words[i][0]) != NULL) &&
            (strchr("aeiou", words[i][len - 1]) != NULL))
        {
            count++;
        }
    }
    return count;
}



// 852. ɽ������ķ嶥����
// ע��㣺��Ч�±�ȡֵΪ[1, arrSzie-2],��֤�����ɵ�����ݼ�
int peakIndexInMountainArray(int* arr, int arrSize) {
    int left = 1;
    int right = arrSize - 2;
    int mid = 0;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1])
            left = mid + 1;
        else if (arr[mid - 1] > arr[mid] && arr[mid] > arr[mid + 1])
            right = mid - 1;
        else
            break;
    }
    return mid;
}
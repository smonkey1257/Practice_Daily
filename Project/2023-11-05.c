// 1422. 分割字符串的最大得分
int maxScore(char* s) {
    int score0 = 0;
    int score1 = 0;
    for (int i = 1; s[i]; i++)// 计算后面n-1个字符中的‘1’
    {
        if (s[i] == '1')
            ++score1;
    }

    if (s[0] == '0') // 额外处理第一个字符
        ++score0;
    int max = score0 + score1;
    for (int i = 1; i < strlen(s) - 1; i++)
    {
        if (s[i] == '0') // 从第2个（下标为1）开始
        {
            ++score0;
        }
        else
        {
            --score1;
        }
        if (score0 + score1 > max)   // 如果分数大于max就更新max
        {
            max = score0 + score1;
        }
    }
    return max;
}



// 2586. 统计范围内的元音字符串数
// 根据元音字符串的定义，使用库函数strchr查找首位字符是否在"aeiou"中
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



// 852. 山脉数组的峰顶索引
// 注意点：有效下标取值为[1, arrSzie-2],保证三个成递增或递减
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
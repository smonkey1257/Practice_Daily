// 58. 最后一个单词的长度
int lengthOfLastWord(char* s) {
    int sum = 0;
    for (int i = strlen(s) - 1; i >= 0; i--)
    {
        if (s[i] == ' ' && sum != 0)
            break;

        if (s[i] != ' ')
            ++sum;
    }
    return sum;
}



// 709. 转换成小写字母
char* toLowerCase(char* s) {
    for (int i = 0; i < strlen(s); i++)
    {
        s[i] = tolower(s[i]);
    }
    return s;
}



// 50. Pow(x, n)
double myPow(double x, int n) {
    if (x == 1 || n == 0)
        return 1;

    long long n1 = n;
    double ret = 1.0;
    if (n < 0)
    {
        n1 *= (-1);
        x = 1.0 / x;
    }
    while (n1 > 1)
    {
        if (n1 % 2)
            ret *= x;
        x *= x;
        n1 /= 2;
    }

    return ret *= x;
}
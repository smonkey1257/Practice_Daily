// 258. 各位相加
int addDigits(int num) {
    int sum = 0;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;

        if (num == 0 && sum > 9)
        {
            num = sum;
            sum = 0;
        }
    }
    return sum;
}



// 1281. 整数的各位积和之差
int subtractProductAndSum(int n) {
    int sum = 0;
    int mul = 1;
    while (n > 0)
    {
        int temp = n % 10;
        n /= 10;

        sum += temp;
        mul *= temp;
    }
    return mul - sum;
}



// 231. 2 的幂
// 2^0 == 1 (n=0,x=0)
// 2^1 == 2 (n=2,x=1)
// 2^2 == 4 (n=4,x=2)
// 2^3 == 8 (n=8,x=3)
// ...
// n一定是正整数，n的取值范围为[2^32, 2^31-1]
// 在这个范围内，n的最高次幂为30，如果n能被2^30整除，说明n是2的幂次方
bool isPowerOfTwo(int n) {
    return (n > 0 && (int)pow(2, 30) % n == 0);
}



// 326. 3 的幂
// 跟n是2的幂次方类似，这里就要找出[2^32, 2^31-1]中3的最高次幂
bool isPowerOfThree(int n) {
    return (n > 0 && (int)pow(3, 19) % n == 0);
}



// 263. 丑数
// 总结一下，丑数的定义为 n = 2^a * 3^b * 5^c
bool isUgly(int n) {
    // a = 0, b = 0, c = 0
    if (n == 1)
        return true;

    // 除干净2，3，5，最后的结果如果不为1（不能整除）说明不是丑数
    int factor[3] = { 2, 3, 5 };
    for (int i = 0; i < 3; i++)
    {
        while (n != 0 && n % factor[i] == 0)
        {
            n /= factor[i];
        }
    }
    return n == 1;
}
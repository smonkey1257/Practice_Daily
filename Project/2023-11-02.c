// 258. ��λ���
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



// 1281. �����ĸ�λ����֮��
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



// 231. 2 ����
// 2^0 == 1 (n=0,x=0)
// 2^1 == 2 (n=2,x=1)
// 2^2 == 4 (n=4,x=2)
// 2^3 == 8 (n=8,x=3)
// ...
// nһ������������n��ȡֵ��ΧΪ[2^32, 2^31-1]
// �������Χ�ڣ�n����ߴ���Ϊ30�����n�ܱ�2^30������˵��n��2���ݴη�
bool isPowerOfTwo(int n) {
    return (n > 0 && (int)pow(2, 30) % n == 0);
}



// 326. 3 ����
// ��n��2���ݴη����ƣ������Ҫ�ҳ�[2^32, 2^31-1]��3����ߴ���
bool isPowerOfThree(int n) {
    return (n > 0 && (int)pow(3, 19) % n == 0);
}



// 263. ����
// �ܽ�һ�£������Ķ���Ϊ n = 2^a * 3^b * 5^c
bool isUgly(int n) {
    // a = 0, b = 0, c = 0
    if (n == 1)
        return true;

    // ���ɾ�2��3��5�����Ľ�������Ϊ1������������˵�����ǳ���
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
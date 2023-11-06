// 6-1 简单输出整数
void PrintN(int N)
{
    for (int i = 1; i <= N; i++)
    {
        printf("%d\n", i);
    }
}



// 6-2 多项式求值
double f(int n, double a[], double x)
{
    double sum = 0.0;
    for (int i = 0; i <= n; i++)
    {
        sum += a[i] * pow(x, i);
    }
    return sum;
}



// 6-3 简单求和
int Sum(int List[], int N)
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += List[i];
    }
    return sum;
}



// 6-4 求自定类型元素的平均
ElementType Average(ElementType S[], int N)
{
    ElementType sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += S[i];
    }
    return (sum / N);
}



// 6-5 求自定类型元素的最大值
ElementType Max(ElementType S[], int N)
{
    ElementType max = S[0];
    for (int i = 1; i < N; i++)
    {
        if (max < S[i])
            max = S[i];
    }
    return max;
}



// 6-6 求单链表结点的阶乘和
int fac(int n)
{
    int mul = 1;
    for (int i = 1; i <= n; i++)
    {
        mul *= i;
    }
    return mul;
}

int FactorialSum(List L)
{
    List cur = L;
    int sum = 0;
    while (cur)
    {
        sum += fac(cur->Data);
        cur = cur->Next;
    }
    return sum;
}



// 6-7 统计某类完全平方数
#include <stdbool.h>
bool DigitEqualLessTwo(int num)
{
    int n = (int)log10(num) + 1;    // 计算啊数字位数
    bool digit[10] = { false };     // int最大10位，每位初始化位false
    for (int i = 0; i < n; i++)
    {
        int d = (num / (int)pow(10, i)) % 10;    // 得到num每一位
        if (digit[d])
            return true;
        digit[d] = true;
    }
    return false;
}

int IsTheNumber(const int N)
{
    int sqrtN = sqrt(N);
    if (sqrtN * sqrtN == N &&
        DigitEqualLessTwo(N))
        return 1;
    else
        return 0;
}




// 6-8 简单阶乘计算
int Factorial(const int N)
{
    if (N < 0)
    {
        return 0;
    }
    else
    {
        int mul = 1;
        for (int i = 1; i <= N; i++)
        {
            mul *= i;
        }
        return mul;
    }
}



// 6-9 统计个位数字
#include <math.h>
int Count_Digit(const int N, const int D)
{
    if (N == 0 && D == 0)
        return 1;
    int num = N;

    if (N < 0) num *= -1;
    int digit[10] = { 0 };
    int n = (int)log10(num) + 1;
    for (int i = 0; i < n; i++)
    {
        int d = (num / (int)pow(10, i)) % 10;
        digit[d]++;
    }
    return digit[D];

}



// 6-10 阶乘计算升级版
#define MAXSIZE 3000
static int ans[MAXSIZE] = { 0 };
void _Factorial(int n)
{
    ans[0] = 1;
    int c = 0;
    for (int i = 2; i <= n; i++)
    {
        int carry = 0;
        for (int j = 0; j < MAXSIZE; j++)
        {
            c = ans[j] * i + carry;    // j == 0 ---> c = i!
            ans[j] = c % 10;
            carry = c / 10;
        }
    }
}
void _Print()
{
    int end = MAXSIZE - 1;
    while (end >= 0 && ans[end] == 0) end--;
    if (end == -1) printf("0\n");
    else
        while (end >= 0) printf("%d", ans[end--]);
    printf("\n");
}
void Print_Factorial(const int N)
{
    if (N < 0)
    {
        printf("Invalid input\n");
    }
    else
    {
        _Factorial(N);
        _Print();
    }
}



// 6-11 求自定类型元素序列的中位数
typedef int DataType;
void ShellSort(DataType* a, int left, int right)
{
    int gap = right;
    while (gap > 1)
    {
        // 当 gap > 1 时进行的就是预排序
        // 当 gap = 1 时进行的就是直接插入排序
        gap /= 2;

        int i = 0;
        // 对分别划分出的gap组数据进行直接插入排序
        for (i = 0; i < gap; i++)
        {
            int end = i;
            // 每组数据中，定义变量end来遍历有序区间，进行数据挪动
            // 注意间隔为gap，不再是1
            for (end = i; end < right - gap; end += gap)
            {
                // 临时变量temp保存无序区间的第一个值
                int temp = a[end + gap];
                while (end >= 0)
                {
                    if (a[end] > temp)
                    {
                        a[end + gap] = a[end];
                    }
                    else
                    {
                        break;
                    }
                    end -= gap;
                }
                a[end + gap] = temp;
            }
        }
    }
}

ElementType Median(ElementType A[], int N)
{
    ShellSort(A, 0, N);
    return A[N / 2];
}



// 6-12 判断奇偶性
int even(int n)
{
    return n % 2 == 0 ? 1 : 0;
}



// 6-13 折半查找
int  Search_Bin(SSTable T, KeyType k)
{
    int left = 1;
    int right = T.length;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (T.R[mid].key < k)
        {
            left = mid + 1;
        }
        else if (k < T.R[mid].key)
        {
            right = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return 0;
}
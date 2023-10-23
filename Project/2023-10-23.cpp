/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param n int整型 最大位数
 * @return int整型一维数组
 * @return int* returnSize 返回数组行数
 */
int* printNumbers(int n, int* returnSize) {
    // 最大的 n 位十进制整数
    int maxNum = pow(10, n) - 1;

    // 堆区开辟数组，栈区开辟会被资源回收
    int* ret = (int*)malloc(sizeof(int) * maxNum);
    *returnSize = maxNum;
    for (int i = 1; i <= maxNum; i++)
    {
        ret[i - 1] = i;
    }

    return ret;
}



#include <stdio.h>

int main() {
    // 输入
    int year = 0;
    int month = 0;
    int day = 0;

    scanf("%d %d %d", &year, &month, &day);

    // 计算天数
    int sum = day;
    int months[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        months[2] += 1;
    }

    for (int i = 1; i < month; i++)
    {
        sum += months[i];
    }

    //输出
    printf("%d\n", sum);
    return 0;
}


#include <iostream>
using namespace std;

int main() {
    // 定义变量
    char val1 = 0;
    int val2 = 0;
    long val3 = 0;
    double val4 = 0.0;

    // 输出
    cout << sizeof(char) << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(long) << endl;
    cout << sizeof(double) << endl;

    return 0;
}



#include <iostream>
using namespace std;
/*
* C语言中对于浮点数输出的四舍五入是自动进行的。在浮点数的有效位数范围内，
* 当要求保留小数点后n位时，系统会自动根据第n+1的值自动进行四舍五入操作。
*/
int main() {
    float num = 0.0;
    cin >> num;
    printf("%.0f", num);
}



#include <iostream>
using namespace std;

int main() {
    int a = 0;
    int b = 0;

    cin >> a >> b;
    cout << (a + b) << endl;

    return 0;
}



#include <iostream>
using namespace std;

int main() {
    int a = 0;
    int b = 0;

    cin >> a >> b;
    cout << (a > b ? a : b) << endl;

    return 0;
}
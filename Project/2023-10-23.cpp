/**
 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
 *
 *
 * @param n int���� ���λ��
 * @return int����һά����
 * @return int* returnSize ������������
 */
int* printNumbers(int n, int* returnSize) {
    // ���� n λʮ��������
    int maxNum = pow(10, n) - 1;

    // �����������飬ջ�����ٻᱻ��Դ����
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
    // ����
    int year = 0;
    int month = 0;
    int day = 0;

    scanf("%d %d %d", &year, &month, &day);

    // ��������
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

    //���
    printf("%d\n", sum);
    return 0;
}


#include <iostream>
using namespace std;

int main() {
    // �������
    char val1 = 0;
    int val2 = 0;
    long val3 = 0;
    double val4 = 0.0;

    // ���
    cout << sizeof(char) << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(long) << endl;
    cout << sizeof(double) << endl;

    return 0;
}



#include <iostream>
using namespace std;
/*
* C�����ж��ڸ���������������������Զ����еġ��ڸ���������Чλ����Χ�ڣ�
* ��Ҫ����С�����nλʱ��ϵͳ���Զ����ݵ�n+1��ֵ�Զ������������������
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
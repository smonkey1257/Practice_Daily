// CPP56 �ַ��ĸ���
#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    // write your code here......
    int counta = 0;
    int countb = 0;
    int countc = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a')         ++counta;
        else if (s[i] == 'b')    ++countb;
        else                    ++countc;
    }

    cout << counta << " " << countb << " " << countc << endl;

    return 0;
}



// CPP57 ������ά��̬����
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    // write your code here......
    int** arr = new int* [n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = i + j;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }

    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }

    arr = nullptr;

    return 0;
}



// CPP31 �Ƚ��ַ�����С
#include <iostream>
using namespace std;

int mystrcmp(const char* src, const char* dst);

int main() {

    char s1[100] = { 0 };
    char s2[100] = { 0 };

    cin.getline(s1, sizeof(s1));
    cin.getline(s2, sizeof(s2));

    int ret = mystrcmp(s1, s2);

    cout << ret << endl;

    return 0;
}

int mystrcmp(const char* src, const char* dst) {

    // write your code here......
    // ���Ƚϱ���
    int i = 0;
    while (src[i] && dst[i] && src[i] == dst[i])
    {
        ++i;
    }

    // ��Ӧλ�õ��ַ���asciiֵ����ͬ
    if (src[i] > dst[i])
        return 1;
    else if (src[i] < dst[i])
        return -1;
    else
        return 0;

}



// CPP32 ��д����ʵ������������ָ�뷽ʽ��
#include <iostream>
using namespace std;

// write your code here......
void Swap(int* m, int* n)
{
    int temp = *m;
    *m = *n;
    *n = temp;
}

int main() {

    int m, n;
    cin >> m;
    cin >> n;

    // write your code here......
    Swap(&m, &n);

    cout << m << " " << n << endl;

    return 0;
}



// CPP33 ͳ���ַ������Ӵ����ֵĴ���
#include <iostream>
#include <cstring>
using namespace std;

int CountCubstr(const char* str, const char* substr)
{
    int count = 0;
    int traversal = 0;
    while (str[traversal])
    {
        if (str[traversal] == *substr)
        {
            int cmp = 0;
            while (str[traversal + cmp] && substr[cmp] &&
                str[traversal + cmp] == substr[cmp])
            {
                ++cmp;
            }
            if (substr[cmp] == '\0')
                ++count;
        }
        ++traversal;
    }
    return count;
}

int main() {

    char str[100] = { 0 };
    char substr[100] = { 0 };

    cin.getline(str, sizeof(str));
    cin.getline(substr, sizeof(substr));

    int count = 0;

    // write your code here......
    count = CountCubstr(str, substr);

    cout << count << endl;

    return 0;
}



// CPP34 ʹ���ַ�����ͳ���ַ����и������ַ��ĸ���
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {

    string str;
    getline(cin, str);

    int whitespace = 0;
    int digits = 0;
    int chars = 0;
    int others = 0;

    // write your code here......
    for (int i = 0; str[i]; i++)
    {
        if (isspace(str[i]))
            ++whitespace;
        else if (isdigit(str[i]))
            ++digits;
        else if (isalpha(str[i]))
            ++chars;
        else
            ++others;
    }

    cout << "chars : " << chars
        << " whitespace : " << whitespace
        << " digits : " << digits
        << " others : " << others << endl;

    return 0;
}



// CPP35 ����ʵ�ּ���һ�����Ľ׳�
#include <iostream>
using namespace std;

long long factorial(int n);

int main() {

    int n;
    cin >> n;

    cout << factorial(n) << endl;

    return 0;
}

long long factorial(int n) {

    // write your code here......
    if (n <= 1)
        return 1;

    return n * factorial(n - 1);

}
// CPP21
#include <iostream>
using namespace std;

void Bubble(int* arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int flag = 1;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                flag = 0;
            }
        }
        if (flag == 1)
        {
            break;
        }
    }
}

int main() {

    int arr[6] = { 0 };
    int len = sizeof(arr) / sizeof(int);

    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }

    Bubble(arr, 6);

    for (int i : arr)
    {
        cout << i << " ";
    }


    return 0;
}



// CPP22
#include <iostream>
#include <valarray>
using namespace std;

void SelectSort(int* arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int mini = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[mini] > arr[j])
            {
                mini = j;
            }
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}

int main() {

    int arr[6] = { 0 };
    int len = sizeof(arr) / sizeof(int);

    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }

    SelectSort(arr, 6);

    for (int i : arr)
    {
        cout << i << " ";
    }

    return 0;
}



// CPP23
#include <iostream>
using namespace std;

int main() {

    int arr[4][3] = {
        {22, 66, 44},
        {77, 33, 88},
        {25, 45, 65},
        {11, 66, 99}
    };

    int sum = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            sum += arr[i][j];
        }
    }

    cout << sum << endl;

    return 0;
}



// CPP24
#include <iostream>
#include <string>
using namespace std;

int main() {

    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    // write your code here......
    cout << s1 << s2;

    return 0;
}



// CPP25
#include <iostream>
#include <string>
using namespace std;

struct student {
    // write your code here......
    string _name;
    int _age;
    double _height;

    void Print()
    {
        cout << _name << " " << _age << " " << _height;
    }
};

int main() {

    // write your code here......
    student s;
    cin >> s._name >> s._age >> s._height;
    s.Print();

    return 0;
}



// CPP26
#include <iostream>
using namespace std;

int main() {

    int arr[6] = { 0 };
    int* ptr = arr;

    int len = sizeof(arr) / sizeof(int);

    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }

    // write your code here......
    for (int i = 0; i < len; i++)
    {
        cout << *(ptr + i) << " ";
    }

    return 0;
}



// CPP27
#include <iostream>
using namespace std;

int main() {

    char str[100] = { 0 };
    cin.getline(str, sizeof(str));

    // write your code here......
    int len = 0;
    char* pstr = str;
    while (*pstr)
    {
        ++len;
        ++pstr;
    }

    cout << len;

    return 0;
}



// CPP28
#include <iostream>
using namespace std;

int main() {

    char str[30] = { 0 };
    cin.getline(str, sizeof(str));

    int m;
    cin >> m;

    // write your code here......
    char* pstr = str + m - 1;
    while (*pstr)
    {
        cout << *pstr++;
    }

    return 0;
}



// CPP29
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {

    int n;
    cin >> n;

    // write your code here......
    int* array = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        array[i] = n + i;
        cout << array[i] << " ";
    }

    return 0;
}



// CPP30
#include <iostream>
using namespace std;

void func(int* p, int n);

int main() {

    int arr[6] = { 0 };
    for (int i = 0; i < 6; i++) {
        cin >> arr[i];
    }

    func(arr, 6);

    for (int i = 0; i < 6; i++) {
        if (i == 5) {
            cout << arr[i] << endl;
        }
        else {
            cout << arr[i] << " ";
        }
    }

    return 0;
}

void func(int* p, int n) {

    // write your code here......
    int ptr1 = 0;
    int ptr2 = ptr1;

    // 非0元素全放前面
    while (ptr2 < n)
        if (p[ptr2] != 0)
            p[ptr1++] = p[ptr2++];
        else
            ++ptr2;

    // ptr1后的元素全置为0
    while (ptr1 < n)
        p[ptr1++] = 0;
}
#include <iostream>
using namespace std;

bool IsNarcissisticNumber(int x)
{
    int a = x % 10;
    int b = (x / 10) % 10;
    int c = x / 100;

    return a * a * a + b * b * b + c * c * c == x;
}

int main() {

    for (int i = 100; i < 1000; i++)
    {
        if (IsNarcissisticNumber(i))
            cout << i << endl;
    }

    return 0;
}



#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d * %d = %d    ", j, i, i * j);
        }
        cout << '\n';
    }

    return 0;
}



#include <iostream>
using namespace std;

int main() {
    // 数字过大，会溢出，选用long long 类型
    long long ret = 0;
    long long sum = 0;
    for (int i = 1; i <= 10; i++)
    {
        ret = ret * 10 + 9;
        sum += ret;
    }

    cout << sum << endl;

    return 0;
}



#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    // 下落的高度和落地的次数
    double h;
    int n;

    cin >> h;
    cin >> n;

    // 100 50*2 25*2 12.5*2
    //   1    2    3      4
    //  50   25 12.5 
    // h/2  h/4  h/8
    double s = h;
    for (int i = 2; i <= n; i++)
    {
        s += (h / 2) * 2;
        h /= 2;
    }
    printf("%.1lf %.1lf", s, h / 2);
    return 0;
}



#include <iostream>
#include <math.h>
using namespace std;

bool IsPrime(int x)
{
    for (int i = 3; i < sqrt(x) + 1; i += 2)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main() {

    int num = 0;

    cin >> num;

    if (IsPrime(num))
        cout << "是质数" << endl;
    else
        cout << "不是质数" << endl;

    return 0;
}



#include <iostream>
using namespace std;

int main() {

    int arr[6] = { 0 };
    int len = sizeof(arr) / sizeof(int);

    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }

    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < 6; i++)
    {
        if (max < arr[i])
            max = arr[i];

        if (min > arr[i])
            min = arr[i];
    }

    cout << min << " " << max << endl;

    return 0;
}



#include <iostream>
using namespace std;

int main() {

    int arr[6] = { 0 };

    int len = sizeof(arr) / sizeof(int);

    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }

    cout << "[";
    for (int i = 0; i < len; i++) {
        if (i == len - 1) {
            cout << arr[i] << "]" << endl;
            break;
        }
        cout << arr[i] << ", ";
    }

    int left = 0;
    int right = 5;
    while (left < right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        ++left;
        --right;
    }


    cout << "[";
    for (int i = 0; i < len; i++) {
        if (i == len - 1) {
            cout << arr[i] << "]" << endl;
            break;
        }
        cout << arr[i] << ", ";
    }

    return 0;
}
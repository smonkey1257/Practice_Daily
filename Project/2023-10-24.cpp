#include <iostream>
using namespace std;

int main() {

    int a = 0;
    int b = 0;

    cin >> a;
    cin >> b;

    if (a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    cout << (a + b) << " ";
    cout << (a - b) << " ";
    cout << (a * b) << " ";
    cout << (a / b) << " ";
    cout << (a % b) << " ";

    return 0;
}



#include <iostream>
using namespace std;

int main() {

    int a = 0;
    int b = 0;
    cin >> a;
    cin >> b;

    int temp = a;
    a = b;
    b = temp;

    cout << a << " " << b << endl;

    return 0;
}



#include <iostream>
using namespace std;

int main() {

    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;

    int max1 = a > b ? a : b;
    int max2 = max1 > c ? max1 : c;

    cout << max2 << endl;

    return 0;
}



#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float money = 0.0f;
    cin >> money;
    if (100 <= money && money < 500)
        money *= 0.9;
    else if (500 <= money && money < 2000)
        money *= 0.8;
    else if (2000 <= money && money < 5000)
        money *= 0.7;
    else if (money >= 5000)
        money *= 0.6;
    else
        money = money;
    printf("%.1f", money);
    return 0;
}



#include <iostream>
using namespace std;

int main() {

    double weight;
    double height;

    cin >> weight;
    cin >> height;

    double BMI = weight / (height * height);

    if (BMI < 18.5)
        cout << "ƫ��" << endl;
    else if (18.5 <= BMI && BMI < 20.9)
        cout << "����" << endl;
    else if (20.9 <= BMI && BMI <= 24.9)
        cout << "����" << endl;
    else if (24.9 < BMI)
        cout << "ƫ��" << endl;

    return 0;
}



#include <iostream>
using namespace std;

int main() {

    int score;
    cin >> score;

    if (90 <= score && score <= 100)
        cout << "����" << endl;
    else if (80 <= score && score <= 89)
        cout << "��" << endl;
    else if (70 <= score && score <= 79)
        cout << "��" << endl;
    else if (60 <= score && score <= 69)
        cout << "����" << endl;
    else if (0 <= score && score <= 59)
        cout << "��" << endl;
    else
        cout << "�ɼ����Ϸ�" << endl;
   
    return 0;
}



#include <iostream>
using namespace std;

int main() {

    int month;
    cin >> month;

    if (3 <= month && month <= 5)
        cout << "����";
    else if (6 <= month && month <= 8)
        cout << "�ļ�";
    else if (9 <= month && month <= 11)
        cout << "�＾";
    else if (13 <= month || month <= 0)
        cout << "���Ϸ�";
    else
        cout << "����";
 
    return 0;
}



#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;
    int sum = 0;

    for (int i = 2; i <= n; i += 2)
        sum += i;

    cout << sum << endl;

    return 0;
}



#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;
    long long factorial = 1;

    for (int i = 1; i <= n; i++)
        factorial *= i;

    cout << factorial << endl;

    return 0;
}
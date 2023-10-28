// CPP36 ������������
#include <iostream>
using namespace std;

int getSum(int n);

int main() {

    int n;
    cin >> n;

    cout << getSum(n) << endl;

    return 0;
}

int getSum(int n) {

    // write your code here......
    if(n == 1 || n == 2)
        return 1;
    
    int ret = 0;
    for(int fib1 = 1, fib2 = 1; n > 2; n--)
    {
        ret = fib1 + fib2;
        fib1 = fib2;
        fib2 = ret;
    }
    return ret;
}



// CPP37 ��д����ʵ���������������÷�ʽ��
#include <iostream>
using namespace std;

// write your code here......
void Swap(int& num1, int& num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

int main() {

    int m, n;
    cin >> m;
    cin >> n;

    // write your code here......
    Swap(n, m);

    cout << m << " " << n << endl;

    return 0;
}



// CPP58 ��д����ʵ���ַ�����ת�����÷�ʽ��
#include<bits/stdc++.h>
#include <cstddef>
#include <cstring>
using namespace std;

// write your code here......
// rs means references to s
void StringInversion(string& rs)
{
    size_t left = 0;
    size_t right = rs.length()-1;
    while(left < right)
    {
        char temp = rs[left];
        rs[left] = rs[right];
        rs[right] = temp;
        ++left;
        --right;
    }
}

int main(){
    string s;
    getline(cin,s);
    
    // write your code here......
    StringInversion(s);
    
    cout<<s;
    return 0;
}



// CPP43 �Ӻ���������� 
#include <iostream>
using namespace std;

class Time {

    public:
        int hours;      // Сʱ
        int minutes;    // ����

        Time() {
            hours = 0;
            minutes = 0;
        }

        Time(int h, int m) {
            this->hours = h;
            this->minutes = m;
        }

        void show() {
            cout << hours << " " << minutes << endl;
        }

        // write your code here......
        Time operator+(Time& t2) {
            Time temp;
            temp.minutes = minutes + t2.minutes;
            temp.hours = hours + t2.hours;

            while(temp.minutes > 59)
            {
                ++temp.hours;
                temp.minutes -= 60;
            }
            
            return temp;
        }

};

int main() {

    int h, m;
    cin >> h;
    cin >> m;

    Time t1(h, m);
    Time t2(2, 20);

    Time t3 = t1 + t2;
    t3.show();
    
    return 0;
}



// CPP40 ���캯��
#include <iostream>
#include <string>

using namespace std;

// Person��
class Person {
    public:
        string name;    // ����
        int age;    // ����

        // write your code here......
        Person(string name, int age)
        {
            this->name = name;
            this->age = age;
        }

        void showPerson() {
            cout << name << " " << age << endl;
        }
};

int main() {

    string name;
    int age;

    cin >> name;
    cin >> age;

    Person p(name, age);
    p.showPerson();

    return 0;
}



// CPP64 ����С�ں�
#include <iostream>
using namespace std;

class Time {

    public:
        int hours;      // Сʱ
        int minutes;    // ����

        Time() {
            hours = 0;
            minutes = 0;
        }

        Time(int h, int m) {
            this->hours = h;
            this->minutes = m;
        }

        void show() {
            cout << hours << " " << minutes << endl;
        }

        // write your code here......
        bool operator<(Time& t)
        {
            if(hours < t.hours)
                return true;
            else if(hours == t.hours && minutes < t.minutes)
                return true;
            else
                return false;
        }

};

int main() {
    int h, m;
    cin >> h;
    cin >> m;

    Time t1(h, m);
    Time t2(6, 6);
	
    if (t1<t2) cout<<"yes"; else cout<<"no";
    return 0;
}



// CPP41 ǳ���������
#include <iostream>
#include <cstring>
#pragma warning(disable : 4996)
using namespace std;

class Person {

    public:
        char* name; // ����
        int age;    // ����

        Person(const char* name, int age) {
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);
            this->age = age;
        }

        // write your code here......
        Person(Person& rp1) {
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, rp1.name);
            this->age = rp1.age;
        }

        void showPerson() {
            cout << name << " " << age << endl;
        }

        ~Person() {
            if (name != nullptr) {
                delete[] name;
                name = nullptr;
            }
        }

};

int main() {

    char name[100] = { 0 };
    int age;

    cin >> name;
    cin >> age;

    Person p1(name, age);
    Person p2 = p1;

    p2.showPerson();

    return 0;
}

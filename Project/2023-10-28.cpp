// CPP36 不死神兔问题
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



// CPP37 编写函数实现两数交换（引用方式）
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



// CPP58 编写函数实现字符串翻转（引用方式）
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



// CPP43 加号运算符重载 
#include <iostream>
using namespace std;

class Time {

    public:
        int hours;      // 小时
        int minutes;    // 分钟

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



// CPP40 构造函数
#include <iostream>
#include <string>

using namespace std;

// Person类
class Person {
    public:
        string name;    // 姓名
        int age;    // 年龄

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



// CPP64 重载小于号
#include <iostream>
using namespace std;

class Time {

    public:
        int hours;      // 小时
        int minutes;    // 分钟

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



// CPP41 浅拷贝和深拷贝
#include <iostream>
#include <cstring>
#pragma warning(disable : 4996)
using namespace std;

class Person {

    public:
        char* name; // 姓名
        int age;    // 年龄

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

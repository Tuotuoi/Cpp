/*************************************************************************
	> File Name: 15.inherit_permission.cpp
	> Author: LuoJinXv 
	> Mail: m18999624868_1@163.com 
	> Created Time: 2020年07月28日 星期二 16时53分22秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <string>

using namespace std;

class Animal {
public :
    Animal(string name, int age): __name(name), age(age){}
    void say() {
        cout << "my name is " << __name << endl;
    }
protected:
    string __name;
private:
    int age;

};

class Cat : public Animal {
public:
    Cat() = delete;
    Cat(string name, int age) : Animal(name, age) {}
};

class Bat : protected Animal {
public:
    Bat() = delete;
    Bat(string name, int age) : Animal(name, age) {}
    void say() { //在这必须要以方法访问父类say（）方法
        Animal::say();//在这已经输出了我的__name
        
        cout << "my class is Bat my name is "<< __name  << endl;

        //在这不能访问age因为在父类里是private的
    }
};

int main() {
    Cat a("dd", 10);
    a.say();
    Bat b("LuoJinXv", 1111);
    b.say();

    return 0;
}


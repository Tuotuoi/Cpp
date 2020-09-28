/*************************************************************************
	> File Name: 16.inherit_constuctor.cpp
	> Author: LuoJinXv 
	> Mail: m18999624868_1@163.com 
	> Created Time: 2020年07月28日 星期二 17时55分32秒
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

class A {
public:
    A() {cout << "A constructor" << endl;}
};
class B {
public:
    B() {cout << "B constructor" << endl;}
};

class C {
public:
    C():b(),a() {cout << "C constructor" << endl;}
private:
    B b;
    A a;
};

int main() {
   C c;




    return 0;
}

/*************************************************************************
	> File Name: 19.inherit_problem.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 六  8/ 1 15:12:48 2020
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

struct A { 
    int x; 
};

struct B : virtual public A {
    void set(int x) {
        this->x = x;
        cout << "set : " << &this->x << endl;
    }
};

struct C : virtual public A {
    int get() { 
        cout << "get : " << &this->x << endl;
        return this->x;
    }
};

struct D : public B, public C {};

int main() {
    D d;
    cout << sizeof(d) << endl;
    d.set(9973);
    cout << d.get() << endl;
    return 0;
}

/*************************************************************************
	> File Name: 14.operator3.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 一  7/27 20:04:16 2020
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

class A {
public :
    A() {
        arr = new int[10];
    }
    A(const A &a) : A() {
        for (int i = 0; i < 10; i++) {
            this->arr[i] = a.arr[i];
        }
        this->x = a.x;
        this->y = a.y;
        return ;
    }
    int x, y;
    int *arr;
};

class B {
public :
    B() : obj(nullptr) {
        arr = new int[10];
        arr[3] = 9973;
    }
    B(A *obj) : B() {
        this->obj = obj;
    }
    int operator()(int a, int b) {
        return a + b;
    }
    int &operator[](int ind) {
        return arr[ind];
    }
    void operator[](const char *msg) {
        cout << msg << endl;
        return ;
    }
    A *operator->() {
        return obj;
    }
    A &operator*() {
        return *obj;
    }

    ~B() {
        delete arr;
    }
private:
    int *arr;
    A *obj;
};

ostream &operator<<(ostream &out, const A &a) {
    out << "A(" << a.x << ", " << a.y << ")";
    return out;
}

int main() {
    B add;
    cout << add(3, 4) << endl;
    cout << add[3] << endl;
    add[3] = 8876;
    cout << add[3] << endl;
    add["hello world"];
    A a, b(a);
    a.x = 67, a.y = 99;
    B p = &a;
    cout << p->x << " " << p->y << endl;
    cout << *p << endl;

    a.arr[3] = 9973;
    b.arr[3] = 6687;
    cout << a.arr[3] << endl;
    cout << b.arr[3] << endl;
    cout << sizeof(A) << endl;
    return 0;
}

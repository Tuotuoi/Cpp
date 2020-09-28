/*************************************************************************
	> File Name: 27.left_right_value.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 日  8/ 2 20:23:56 2020
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
#define TEST(a, f) { \
    cout << #a <<  " : " << #f << " "; \
    f(a); \
}

void f2(int &x) {
    cout << "left value" << endl;
}

void f2(int &&x) {
    cout << "right value" << endl;
}

void f(int &x) {
    cout << "left value" << endl;
    TEST(x, f2);
}

void f(int &&x) {
    cout << "right value" << endl;
    TEST(x, f2);
}

int main() {
    int a, b = 1, c = 3;
    (++a) = b + c;
    cout << a << endl;
    (a++);
    (a = b) = c;
    cout << a << " " << b << endl;
    int arr[10];
    arr[3] = 12;
    (a += 3) = 67;
    cout << a << endl;
    TEST(a += 3, f);
    TEST(1 + 4, f);
    TEST(b + c, f);
    TEST(a++, f);
    TEST(++a, f);
    return 0;
}

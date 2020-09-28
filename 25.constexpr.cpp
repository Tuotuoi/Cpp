/*************************************************************************
	> File Name: 24.constexpr.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 日  8/ 2 18:56:18 2020
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

constexpr int f(int x) {
    return 3 * x * x + x;
}

class A {
public :
    constexpr A(int x, int y) : x(x), y(y) {}
    int x, y;
};

int main() {
    int n;
    cin >> n;
    cout << f(n) << endl;
    constexpr int m = f(12);
    cout << m << endl;
    constexpr A a(2, 3);
    cout << a.x << ", " << a.y << endl;
    return 0;
}

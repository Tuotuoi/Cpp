/*************************************************************************
	> File Name: 13.operator2.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 一  7/27 19:20:34 2020
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

class Point {
public :
    Point() : __x(0), __y(0) {}
    Point(int x, int y) : __x(x), __y(y) {}
    int x() const { return __x; }
    int y() const { return __y; }
    
    Point operator+(const Point &a) {
        return Point(x() + a.x(), y() + a.y());
    }
    Point &operator+=(const Point &a) {
        __x += a.x();
        __y += a.y();
        return *this;
    }
    Point &operator++() {
        __x += 1;
        __y += 1;
        return *this;
    }
    Point operator++(int) {
        Point temp(*this);
        __x += 1;
        __y += 1;
        return temp;
    }

private:
    int __x, __y;
};

ostream &operator<<(ostream &out, const Point &a) {
    out << "Point (" << a.x() << ", " << a.y() << ")";
    return out;
}

int main() {
    Point a(4, 5), b(3, 4), c(1, 1);
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << a + b << endl;
    cout << "pre incr : " << ++(c += b) << endl;
    cout << c << endl;
    cout << "after incr : " << c++ << endl;
    cout << c << endl;
    int n = 6, m = 7;
    (n += m)++;
    cout << n << endl;
    return 0;
}

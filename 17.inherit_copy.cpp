/*************************************************************************
	> File Name: 17.inherit_copy.cpp
	> Author: LuoJinXv 
	> Mail: m18999624868_1@163.com 
	> Created Time: 2020年07月28日 星期二 18时45分07秒
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
    A() {
        cout << "class A constructor" << endl;
        this->x = 0x01020304;
    }
    A(const A &a) {
        cout << "class A copy constructor:"<< this << endl;
    }
    int x;
};

class B : public A {
    public :
    B() {
        cout << "class B constructor" << endl;
        this->y = 0x05060708;
    }
    B(const B &b) : A(b){
        cout << "class B copy constructor:"<< this << endl;
    }
    int y;
};

int main() {
    B b1;
    B b2(b1);
    const char *msg = (const char *)(&b1);
    for (int i = 0; i  <sizeof(B); i++) {
        printf("%X",msg[i]);
    }
    cout << endl;
    return 0;
}

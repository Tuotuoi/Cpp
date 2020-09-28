/*************************************************************************
	> File Name: a.cpp
	> Author: LuoJinXv 
	> Mail: m18999624868_1@163.com 
	> Created Time: 2020年08月06日 星期四 13时07分03秒
 ************************************************************************/

#include "a.h"
using namespace std;

int return_int(int a) {
    return a;
}
double return_double(double a) {
    return a;
}
string return_str(string a) {
    return a;
}


int main() {
    int a = 10;
    double b = 111.63;
    string c = "hello world";
    cout << "return_int: " << return_int(a) << endl;
    cout << "return_double: " << return_double(b) << endl;
    cout << "return_char: " << return_str(c) << endl;
    cout << a / 0 << endl;


    return 0;
}

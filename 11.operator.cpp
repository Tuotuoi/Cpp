/*************************************************************************
	> File Name: 11.operator.cpp
	> Author: LuoJinXv 
	> Mail: m18999624868_1@163.com 
	> Created Time: 2020年07月27日 星期一 17时34分37秒
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
/*
实现c += b
c, b = class::point
c = c + b
c + b已重载
point &operator+=(const point &b){
    __x += b.x();
    __y += b.y();
    return *this;
}

实现++c
point &operator++() {
    __x ++;
    __y ++;
    return *this;
}
实现c++
point operator++(int) { (后++加一个int，无意义)
    point temp(*this); 返回加1之前的值.
    __x += 1;
    __y += 1;
    return temp;
}

*/

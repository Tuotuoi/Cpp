/*************************************************************************
	> File Name: 36.sort.cpp
	> Author: LuoJinXv 
	> Mail: m18999624868_1@163.com 
	> Created Time: 2020年08月17日 星期一 12时42分20秒
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

template<typename T>
struct greater{
    bool operator()(const T &a,const T &b) {
        return a > b;
    }
};

/*************************************************************************
	> File Name: 23.auto.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 日  8/ 2 18:39:53 2020
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

int main() {
    auto a = 123;
    cout << sizeof(a) << endl;
    map<int, int> arr;
    arr[71264716] = 1387183;
    arr[45612] = 712;
    arr[999] = 10000;
    for (auto iter = arr.begin(); iter != arr.end(); iter++) {
        cout << iter->first << " " << iter->second << endl;
    }
    for (auto x : arr) {
        cout << x.first << ", " << x.second << endl;
    }
    return 0;
}

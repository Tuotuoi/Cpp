/*************************************************************************
	> File Name: 40.singleton.cpp
	> Author: LuoJinXv 
	> Mail: m18999624868_1@163.com 
	> Created Time: 2020年08月22日 星期六 14时10分43秒
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
class Singleton{
public:
    static Singleton *getInstance() {
        if(single == nullptr) {
            single = new Singleton();
        }
        return single;
        
    }
private:
    static Singleton *single;
    Singleton() = default;
    ~Singleton(){}
    Singleton(const Singleton &) = default;
};

Singleton *Singleton::single = nullptr;

int main() {
    


    return 0;
}

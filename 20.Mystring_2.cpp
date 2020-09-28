/*************************************************************************
	> File Name: 20.Mystring_2.cpp
	> Author: LuoJinXv 
	> Mail: m18999624868_1@163.com 
	> Created Time: 2020年08月01日 星期六 12时32分28秒
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

namespace haizei {
class string {
public:
    string() {
        cout << "默认构造函数"<< endl;
        this->__buff_size = 10;
        this->buff = new char[this->__buff_size];
        this->__length = 0;
    }
    string(const char *str) { //传参数时第一个因该是this指针参数,他是隐藏的
        cout << "传参构造函数"<< endl;
        this->__buff_size = strlen(str) + 1;
        this->buff = new char[this->__buff_size];
        strcpy(this->buff, str);
        this->__length = this->__buff_size - 1;
    }
    string (const string &s) {
        this->__length = s.__length;
        this->__buff_size = s.__buff_size;
        this->buff = new char[this->__buff_size];
        strcpy(this->buff, s.buff);
    }
    char &at(int ind) {
        if (ind < 0 || ind >= __length) {
            cout << "string Error: out of range" << endl;
            return __end;
        }
        return this->operator[](ind);
    }
    char &operator[](int ind) {
        return buff[ind];
    }
    const char *c_str() const{
        return buff;
    }
    string operator+(const string &s) {
        cout << "重载+" << endl;
        int size = this->__length + s.__length  + 1;
        char *temp = new char[size];
        strcpy(temp, this->buff);
        strcat(temp, s.buff);
        return temp;
    }


private:
    char *buff;
    int __length, __buff_size;
    char __end;
};
};

ostream &operator<<(ostream &out, const haizei::string &s) {
    out << s.c_str();
    return out;
}


int main() {
   // haizei::string s = "hello world"; 
    //cout << s << endl;


    haizei::string s1 = "6666", s2 = "7777", s3 = "8888";
    haizei::string s4 = s1 + s2 + s3;
    cout << s4 << endl;
    haizei::string s5 = s4;
    cout << "s4 = " << s4 << "  s5 = " << s5 << endl;
    s4[3] = '=';
    cout << "s4 = " << s4 << "  s5 = " << s5 << endl;

    return 0;
}

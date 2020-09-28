/*************************************************************************
	> File Name: 18.mystring.cpp
	> Author: LuoJinXv 
	> Mail: m18999624868_1@163.com 
	> Created Time: 2020年07月30日 星期四 09时53分29秒
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

class MyString {
public:
    MyString() {
	    this->length = 0;
	    this->str = NULL;
    }

    MyString(int len) {
	    this->length = len;
	    this->str = new char[len];
	    memset(this->str, 0, len);

    }
    MyString(const char* str) {
	    if (str == NULL) {
		    this->length = 0;
		    this->str = new char[1];
		    strcpy(this->str, "");
		    return;
	    }
	    this->length = strlen(str);
	    this->str = new char[this->length + 1];
	    strcpy(this->str, str);

    }
    MyString(const MyString &next) {
	    this->length = next.length;
	    this->str = new char[this->length+1];
	    strcpy(this->str, next.str);
    }

    MyString &operator=(const MyString &next) {
	    //赋值运算符 
	    // 防止自身赋值
	    if (this == &next) {
		    return *this;
	    }
	    // 如果自身原来有空间，先释放
	    if (this->str != NULL) {
		    delete[] this->str;
		    this->str = NULL;
		    this->length = 0;
	    }
	    // 新开辟空间进行内容拷贝
	    this->length = next.length;
	    this->str = new char[this->length + 1];
	    strcpy(this->str, next.str);
	    return *this;

    }
    char &operator[](int index) {
	    return (this->str[index]);
    }


    bool operator==(MyString &next) {
	    if (this == &next) {
		    return true;
	    }
	    if (this->length != next.length) {
		    return false;
	    }
	    if (strcmp(this->str, next.str) != 0) {
		    return false;
	    }
	    return true;
}
    bool operator!=(MyString &next) {
	    return !(*this==next);
    }
    friend ostream &operator<<(ostream &cout, MyString &myString);
    friend istream &operator>>(istream &cin, MyString &myString);

    ~MyString() {
	    if (this->str != NULL) {
		    delete[] this->str;
		    this->str = NULL;
		    this->length = 0;
	    }
    }

private:
	int length;//实际字符个数
	char* str;
};

ostream &operator<<(ostream &cout, MyString &myString) {
	if(myString.str!=NULL)
		cout << myString.str;
	return cout;
}

istream &operator>>(istream &cin, MyString &myString) {
	if (myString.str != NULL) {
		delete[] myString.str;
		myString.str = NULL;
		myString.length = 0;
	}
	char temp[1024] = {0};
	cin >> temp;
	int len = strlen(temp);
	myString.length = len;
	myString.str = new char[len + 1];
	strcpy(myString.str, temp);

	return cin;
}

int main(int argc, char *argv[]) {
	MyString str1("hello");
	MyString str2("world");
	MyString str3 = str1;
	cout << str3 <<endl;
	str3 = str2;
	cout << str3 << endl;
    MyString str4;
    MyString str5;
    cout << "请输入两个待比较的数" << endl;
    cin >> str5 >> str4;
    if (str5 == str4) {
        cout << str5 << "与" << str4 << "相等" << endl;
    } else {
        cout << str5 << "与" << str4 << "不相等" << endl;

    }
	return 0;
}

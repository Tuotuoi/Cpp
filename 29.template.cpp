/*************************************************************************
	> File Name: 29.template.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  8/ 6 11:45:58 2020
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

class A {
public :
    A(int x) : x(x) {}
    int x;
};

class B {
public: 
    B(int y) : y(y) {}
    int y;
};

int operator+(const A &a, const B &b) {
    return a.x + b.y;
}

namespace haizei {

template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
    return a + b;
}

template<>
int add(int a, int b) {
    cout << "add int : "<< a << " " << b << endl;
    return a + b;
}

template<typename T, typename U>
auto add(T *a, U *b) -> decltype(*a + *b) {
    return add(*a, *b);
}

template<typename T, typename U>
auto max(T a, U b) -> decltype(a + b) {
    return a < b ? b : a;
}

template<typename T, typename U>
auto min(T a, U b) -> decltype(a + b) {
    return a < b ? a : b;
}

class PrintAny {
public :
    template<typename T>
    void operator()(const T &a) {
        cout << a << endl;
    }
};

template<typename T>
class FoolPrintAny {
public:
    void operator()(const T &a) {
        cout << a << endl;
    }
};

template<>
class FoolPrintAny<int> {
public:
    void operator()(const int &a) {
        cout << "naughty : " << 2 * a << endl;
    }
};

template<typename T>
void printAny(const T &a) {
    cout << a << endl;
    return ;
}


template<typename T, typename ...ARGS>
void printAny(const T &a, ARGS...args) {
    cout << a << " ";
    printAny(args...);
    return ;
}

template <int n, typename T, typename ...ARGS>
struct ARG{
    typedef typename ARG<n - 1, ARGS...>:: __type __type;
};

template<typename T, typename ...ARGS> //递归到0调用这个
struct ARG<0, T, ARGS...> {
    typedef T __type;
    
};

template <typename T> //偏特化
struct ARG<0, T>{
typedef T __type;
};

template<typename T, typename ...ARGS> class Test;
template<typename T, typename ...ARGS>

class Test<T(ARGS...)> {
public :
    T operator()(ARGS... args) {
        return add<T>(args...);
    }
private:
    template<typename T1, typename U, typename ...US>
    T1 add(U a, US ...args){
        return a + add<T1>(args...);
    }
    template<typename T1, typename U>
    T1 add(U a) {
        return a;
    }

};
template <typename T> struct remove_reference {
    typedef T type;
};
template <typename T> struct remove_reference<T &> {
    typedef T type;
};
template <typename T> struct remove_reference<T &&> {
    typedef T type;
};

template<typename T> 
typename remove_reference<T>::type add2(T &&a, T &&b) {
    typename remove_reference<T>::type c = a + b;
    return c;
}

}

int main() {
    A a(1000);
    B b(645);
    int inta = 123, intb = 234;
    cout << haizei::add2(inta, intb) << endl;
    cout << a + b << endl;
    cout << haizei::add(2, 3) << endl;
    cout << haizei::add(2.3, 4.3) << endl;
    cout << haizei::add(2.3, 5) << endl;
    cout << haizei::add(5, 2.3) << endl;
    cout << haizei::add(string("hello"), "hello world") << endl;
    cout << haizei::add(a, b) << endl;
    cout << haizei::max(4, 3) << endl;
    cout << haizei::max(4.3, 3) << endl;
    cout << haizei::min(4, 3) << endl;
    cout << haizei::min(4.3, 3) << endl;
    haizei::PrintAny print;
    print(123);
    print(45678);
    print(3.4);
    print("hello world");
    print("hello haizei");
    print(&a);
    haizei::FoolPrintAny<string> f;
    f("hello world");
    haizei::FoolPrintAny<int> f2;
    f2(123);
    int n = 45, m = 67;
    int *p = &n, *q = &m;
    cout << haizei::add(n, m) << endl;
    cout << haizei::add(p, q) << endl;
    haizei::printAny(123, 34.5, "hello world", &a);
    //haizei::Test<int(int, int)> f3;
    //cout << f3(3, 4) << endl;
    haizei::Test<int(int, int, int, int)> f4;
    cout << f4(3, 4, 5, 6) << endl;

    return 0;
}

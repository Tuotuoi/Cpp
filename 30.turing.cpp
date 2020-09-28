/*************************************************************************
	> File Name: 33.turing.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 四  8/13 14:25:38 2020
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

template<int n>
struct IsEven {
    static constexpr int r = !(n % 2);
};

template<int a, int b>
struct Add {
    static constexpr int r = a + b;
};

template<int n>
struct Sum {
    static constexpr int r = n + Sum<n - 1>::r;
};
template<>
struct Sum<0> {
    static constexpr int r = 0;
};

template<int n>
struct Factorial {
    static constexpr int r = n * Factorial<n - 1>::r;
};
template<>
struct Factorial<0> {
    static constexpr int r = 1;
};

template<int n, int i>
struct getNextN {
    static constexpr int r = (i * i > n ? 0 : n);
};

template<int n, int i>
struct getNextI {
    static constexpr int r = (n % i == 0 ? 0 : i + 1);
};

template<int n, int i>
struct IsTest {
    static constexpr int r = IsTest<getNextN<n, i>::r, getNextI<n, i>::r>::r;
};

template<int i>
struct IsTest<2, i> {
    static constexpr int r = 1;
};

template<int i>
struct IsTest<0, i> {
    static constexpr int r = 1;
};

template<int n>
struct IsTest<n, 0> {
    static constexpr int r = 0;
};

template<int n>
struct IsPrime {
    static constexpr int r = IsTest<n, 2>::r;
};

template<int n>
struct SumPrime {
    static constexpr int r = (n * IsPrime<n>::r) + SumPrime<n - 1>::r;
};

template<>
struct SumPrime<1> {
    static constexpr int r = 0;
};

template<int n> 
struct PrintPrime {
    template<int i, int j>
        struct __output {
            static void run() {
                if (IsPrime<i>::r) {
                    cout << i << endl;
                }
                PrintPrime<n>::__output<i + 1, (i + 1 > n ? 0 : 1)>::run();
            }
        };
    template<int i>
        struct __output<i, 0> {
            static void run() {
                return ;
            }
        };
    static void output() {
        PrintPrime<n>::__output<2, 1>::run();
        return ;
    }
};


int main() {
    cout << IsEven<123>::r << endl;
    cout << IsEven<124>::r << endl;
    cout << Add<97, 87>::r << endl;
    cout << Sum<10>::r << endl;
    cout << Sum<100>::r << endl;
    cout << Factorial<5>::r << endl;
    cout << Factorial<10>::r << endl;
    
    cout << IsPrime<9973>::r << endl;
    cout << IsPrime<87>::r << endl;
    cout << IsPrime<1537>::r << endl;
    cout << IsPrime<65>::r << endl;

    cout << SumPrime<10>::r << endl;
    cout << SumPrime<40>::r << endl;

    PrintPrime<10>::output();
    cout << "*****************************************" << endl;
    PrintPrime<50>::output();
    cout << "*****************************************" << endl;
    PrintPrime<100>::output();

    return 0;
}

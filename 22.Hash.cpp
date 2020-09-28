/*************************************************************************
	> File Name: 22.Hash.cpp
	> Author: LuoJinXv 
	> Mail: m18999624868_1@163.com 
	> Created Time: 2020年08月01日 星期六 16时46分16秒
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

class Hash_table {
public:
    Hash_table() = default;
    Hash_table(char s, string hash_func) {
        for (int i = 0; i < hash_func.length(); i++) {
            if (hash_func[i] == '*' || hash_func[i] == '/' || hash_func[i] == '+' || hash_func[i] == '-') {

            }

        }
        __hash[x * y / 6 - 1] = s;

    }
    char out(int ind) {
        return this->__hash[ind];
    }
private:
    char __hash[10000];
};

int main() {
    Hash_table hash1('s');
    cout << hash1.out(50 * 11 / 6 - 1) << endl;

    return 0;
}

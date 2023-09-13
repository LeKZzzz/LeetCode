#include "iostream"
#include "iomanip"  //setprecision() setw() setiosflags()
#include "string"
#include "iterator" //begin() end()
#include "memory"   //auto_ptr<> shared_ptr<> unique_ptr<>
#include "algorithm"    //find()
#include "fstream"
#include "vector"   //向量容器
#include "deque"  //双端队列容器
#include "list" //双向链表容器
#include "utility" //键值对类模板 move()
#include "map"  //映射容器
#include "set"  //集合容器
#include "stdlib.h" //abs()

using namespace std;

class A {
private:

public:
    int a;

    A(A &&b) noexcept {
        cout << "move" << endl;
        a = b.a;
    }

    A() {
        a = 1;
        cout << "constructor" << endl;
    }
};

int main() {
    int result = 0;
    for (int i = 1; (i * (i + 1)) <= 200; ++i) {
        result += i * (i + 1);
    }
    cout << hex << result;
}
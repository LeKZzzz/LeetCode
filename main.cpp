#include "iostream"
#include "iomanip"  //setprecision() setw() setiosflags()
#include "string"
#include "iterator" //begin() end()
#include "memory"   //auto_ptr<> shared_ptr<> unique_ptr<>
#include "algorithm"    //find()
#include "fstream"
#include "vector"   //��������
#include "deque"  //˫�˶�������
#include "list" //˫����������
#include "utility" //��ֵ����ģ�� move()
#include "map"  //ӳ������
#include "set"  //��������
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
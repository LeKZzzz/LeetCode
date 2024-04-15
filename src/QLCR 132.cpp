//2024-04-12 08:48:30
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
// 循环求余
//class Solution {
//public:
//    int cuttingBamboo(int bamboo_len) {
//        if (bamboo_len <= 3) return bamboo_len - 1;
//        int p = 1000000007, b = bamboo_len % 3;
//        long res = 1;
//        for (int i = 0; i < bamboo_len / 3 - 1; ++i) {
//            res = res * 3 % p;
//        }
//        if (b == 0) return (int) (res * 3 % p);
//        else if (b == 1) return (int) (res * 2 * 2 % p);
//        else return (int) (res * 3 * 2 % p);
//    }
//};

//快速幂求余
class Solution {
public:
    int cuttingBamboo(int bamboo_len) {
        if (bamboo_len <= 3) return bamboo_len - 1;
        int p = 1000000007, b = bamboo_len % 3;
        long res = 1, x = 3;

        for (int i = bamboo_len / 3 - 1; i > 0; i /= 2) {
            if (i % 2 == 1) res = res * x % p;
            x = x * x % p;
        }

        if (b == 0) return (int) (res * 3 % p);
        else if (b == 1) return (int) (res * 2 * 2 % p);
        else return (int) (res * 3 * 2 % p);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

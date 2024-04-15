//2024-04-15 20:36:18
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
// n&1
//class Solution {
//public:
//    int hammingWeight(uint32_t n) {
//        int res = 0;
//        while (n != 0) {
//            res += n & 1;
//            n >>= 1;
//        }
//        return res;
//    }
//};

// n&(n-1)
//class Solution {
//public:
//    int hammingWeight(uint32_t n) {
//        int res = 0;
//        while (n != 0) {
//            res++;
//            n = n & (n - 1);
//        }
//        return res;
//    }
//};

// bitset
//class Solution {
//public:
//    int hammingWeight(uint32_t n) {
//        return bitset<32>(n).count();
//    }
//};

// 短除法思想，除以2取余
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n != 0){
            cnt += n % 2;
            n /= 2;
        }
        return cnt;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

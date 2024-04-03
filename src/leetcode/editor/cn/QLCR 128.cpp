//2024-04-02 17:37:31
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int stockManagement(vector<int> &stock) {
        int left = 0, right = stock.size() - 1;
        int mid;
        while (left < right) {
            if (left == right) break;
            mid = (left + right) / 2;
            if (stock[mid] > stock[right]) left = mid + 1;
            else if (stock[mid] < stock[right]) right = mid;
            else right -= 1;
        }
        return stock[left];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

//
// Created by LeK on 2024/4/21.
//

#include "../header.h"

class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> mp;
        int result = 0;
        for (int i = 0; i < word.length(); ++i) {
            if (97 <= word[i] && 122 >= word[i]) {
                if (mp.count(word[i] - 32) && mp[word[i] - 32] == -1 && mp.count(word[i]) &&
                    mp[word[i]] == -1) {  // 特殊之后第一次
                    result--;
                    mp[word[i] - 32] = 0;
                    mp[word[i]] = 0;
                } else if (mp.count(word[i] - 32) && mp[word[i] - 32] == 0 && mp.count(word[i]) && mp[word[i]] == 0) {
                    continue;
                } else if (mp.count(word[i] - 32) && mp[word[i] - 32] == 1) {    // 大后第一次
                    mp[word[i]] = 0;
                    mp[word[i] - 32] = 0;
                } else {    //大前第一次
                    mp[word[i]] = 1;
                }

            } else if (65 <= word[i] && 90 >= word[i]) {
                if (mp.count(word[i] + 32) && mp[word[i] + 32] == 1) {
                    result++;
                    mp[word[i] + 32] = -1;
                    mp[word[i]] = -1;
                } else if (mp.count(word[i] + 32)) {
                    continue;
                } else {
                    mp[word[i]] = 1;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    cout << sol.numberOfSpecialChars("dDbbDcdDe") << endl;
    return 0;
}
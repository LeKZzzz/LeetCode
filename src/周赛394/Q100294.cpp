//
// Created by LeK on 2024/4/21.
//

#include "../header.h"

class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, bool> mp;
        int result = 0;
        for (int i = 0; i < word.length(); ++i) {
            if (97 <= word[i] && 122 >= word[i])
                mp[word[i]] = true;
            else if (65 <= word[i] && 90 >= word[i])
                mp[word[i]] = true;
        }
        for (auto it: mp) {
            if (it.first >= 97 && it.second && mp[it.first - 32]) {
                mp[it.first] = false;
                result++;
            } else if (it.first >= 65 && it.second && mp[it.first + 32]) {
                mp[it.first] = false;
                result++;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    cout << sol.numberOfSpecialChars("DdaAeAAecbADbda") << endl;
    return 0;
}
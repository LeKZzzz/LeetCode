//2023-07-24 19:50:21
#include "header.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> m_words;
    vector<char> m_letters;
    vector<int> m_score;
    int count[26], tmp[26];
    int best = 0, curbest = 0;
    bool flag[26];
//    int x[5];

    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score) {
        m_words = words;
        m_letters = letters;
        m_score = score;

        for (int i = 0; i < 25; ++i) {
            count[i] = 0;
        }
        for (int i = 0; i < letters.size(); ++i) {
            count[letters[i] - 97]++;
        }

        backtrack(0, words.size());
        return best;
    }

    void backtrack(int i, int n) {
        if (i == n) best = curbest >= best ? curbest : best;
        else {
            if (check(i)) {
//                x[i] = 1;
                cost(i);
                backtrack(i + 1, n);
                reset(i);
            }
//            x[i] = 0;
            backtrack(i + 1, n);
        }
    }

    bool check(int n) {
        for (int i = 0; i < 26; ++i) {
            flag[i] = false;
        }
        for (int i = 0; i < m_words[n].size(); ++i) {
            if (!flag[m_words[n][i] - 97]) {
                flag[m_words[n][i] - 97] = true;
                tmp[m_words[n][i] - 97] = 1;
            } else {
                tmp[m_words[n][i] - 97]++;
            }
            if (count[m_words[n][i] - 97] < tmp[m_words[n][i] - 97])
                return false;
        }
        return true;
    }

    void cost(int n) {
        for (int i = 0; i < m_words[n].size(); ++i) {
            count[m_words[n][i] - 97]--;
            curbest += m_score[m_words[n][i] - 97];
        }
    }

    void reset(int n) {
        for (int i = 0; i < m_words[n].size(); ++i) {
            count[m_words[n][i] - 97]++;
            curbest -= m_score[m_words[n][i] - 97];
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution sol;
    vector<string> m_words = {"da", "ac", "aba", "abcc", "cadc"};
    vector<char> m_letters = {'a', 'a', 'a', 'a', 'b', 'c', 'c', 'c', 'd', 'd', 'd'};
    vector<int> m_score = {3, 7, 9, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    cout<<sol.maxScoreWords(m_words, m_letters, m_score);
    return 0;
}
/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */
class Solution {
   public:
    void reverse(string& str, int start, int end) {
        while (start < end) {
            char temp = str[start];
            str[start] = str[end];
            str[end] = temp;
            start++;
            end--;
        }
    }

    string reverseStr(string s, int k) {
        int length = s.length();
        for (int i = 0; i < length; i += 2 * k) {
            if (i + k >= length) {
                reverse(s, i, length - 1);
            } else {
                reverse(s, i, i + k - 1);
            }
        }
        return s;
    }

    string reverseStrDead(string s, int k) {
        int length = s.size();
        if (k >= length)
            return string(s.rbegin(), s.rend());

        string res;
        if (k <= length && length < 2 * k) {
            string part1(s.rbegin() + (s.size() - k), s.rend());
            string part2(s.begin() + k, s.end());
            return part1 + part2;
        }
        string tmp;
        int step = 2 * k;               // 4
        int numOfPart = length / step;  // 1

        for (int i = 0; i < length && i / step < numOfPart; i += step) {
            string tmp = s.substr(i, k);
            string part1(tmp.rbegin(), tmp.rend());
            string part2 = s.substr(i + k, k);
            res += (part1 + part2);
        }

        if (length - numOfPart * step >= k) {
            string tmp = s.substr(numOfPart * step, k);
            res += string(tmp.rbegin(), tmp.rend());
            res += string(s.begin() + numOfPart * step + k, s.end());
        } else {
            res += string(s.begin() + numOfPart * step, s.end());
        }

        return res;
    }
};

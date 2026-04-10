//IAI
/* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.*/
/* Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"] */

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        func(0, 0, n, "", res);
        return res;
    }
    void func(int open, int close, int n, string cur, vector<string>& result) {
        if (cur.length() == 2 * n) {
            result.push_back(cur);
            return;
        }

        if (open < n) {
            func(open + 1, close, n, cur + '(', result);
        }

        if (close < open) {
            func(open, close + 1, n, cur + ')', result);
        }
    }
};
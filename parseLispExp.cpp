/* You are given a string expression representing a Lisp-like expression to return the integer value of.*/

/* Input: expression = "(let x 2 (mult x (let x 3 y 4 (add x y))))"
Output: 14*/

#include <string>
#include <unordered_map>
#include <vector>
#include <cctype>
using namespace std;

class Solution {
public:
    unordered_map<string, vector<int>> scope;

    int evaluate(string expression) {
        int pos = 0;
        return parse(expression, pos);
    }

private:
    int parse(const string& s, int& pos) {
        if (s[pos] == '(') {
            ++pos; // skip '('

            if (s.compare(pos, 3, "add") == 0) {
                pos += 4; // skip "add "
                int a = parse(s, pos);
                ++pos;    // skip space
                int b = parse(s, pos);
                ++pos;    // skip ')'
                return a + b;
            }

            if (s.compare(pos, 4, "mult") == 0) {
                pos += 5; // skip "mult "
                int a = parse(s, pos);
                ++pos;    // skip space
                int b = parse(s, pos);
                ++pos;    // skip ')'
                return a * b;
            }

            // let
            pos += 4; // skip "let "
            vector<string> assigned;

            while (true) {
                if (s[pos] == '(' || s[pos] == '-' || isdigit(s[pos])) {
                    int result = parse(s, pos);
                    ++pos; // skip ')'
                    rollback(assigned);
                    return result;
                }

                string name = parseVar(s, pos);

                if (s[pos] == ')') {
                    int result = scope[name].back();
                    ++pos; // skip ')'
                    rollback(assigned);
                    return result;
                }

                ++pos; // skip space

                // If after the variable comes the final expression, not assignment
                if (s[pos] == '(' || s[pos] == '-' || isdigit(s[pos])) {
                    int val = parseAtomOrExpr(s, pos);
                    rollback(assigned);
                    return val;
                }

                // Need to distinguish between:
                // variable as final expr
                // variable followed by assignment value
                int save = pos;
                string nextToken = parseVar(s, save);

                if (save >= (int)s.size() || s[save] == ')') {
                    int result = scope[name].back();
                    rollback(assigned);
                    return result;
                }

                int val = parse(s, pos);
                scope[name].push_back(val);
                assigned.push_back(name);

                if (s[pos] == ' ')
                    ++pos;
            }
        }

        return parseAtomOrExpr(s, pos);
    }

    int parseAtomOrExpr(const string& s, int& pos) {
        if (s[pos] == '(') {
            return parse(s, pos);
        }

        if (s[pos] == '-' || isdigit(s[pos])) {
            return parseInt(s, pos);
        }

        string var = parseVar(s, pos);
        return scope[var].back();
    }

    int parseInt(const string& s, int& pos) {
        int sign = 1;
        if (s[pos] == '-') {
            sign = -1;
            ++pos;
        }

        int num = 0;
        while (pos < (int)s.size() && isdigit(s[pos])) {
            num = num * 10 + (s[pos] - '0');
            ++pos;
        }
        return sign * num;
    }

    string parseVar(const string& s, int& pos) {
        string var;
        while (pos < (int)s.size() && s[pos] != ' ' && s[pos] != ')') {
            var += s[pos++];
        }
        return var;
    }

    void rollback(const vector<string>& assigned) {
        for (const string& var : assigned) {
            scope[var].pop_back();
        }
    }
};
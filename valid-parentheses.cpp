//IAI
/* Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.*/

/*Input: s = "([)]"
Output: false*/

class Solution {
public:
    bool isValid(string s) {
        stack<char>paren;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                paren.push(s[i]);
            }
            else{
                if(paren.empty()) return false;
                if(s[i]==')' && paren.top()!='(') return false;
                if(s[i]==']' && paren.top()!='[') return false;
                if(s[i]=='}' && paren.top()!='{') return false;
                paren.pop();
            }
        }
        if(paren.empty()) return true;
        return false;
    }
};
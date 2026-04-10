//Wix
/* Given two strings s and t, return true if t is an anagram of s, and false otherwise.*/
/* Input: s = "anagram", t = "nagaram"

Output: true*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector <int> sChars(26,0);
        vector <int> tChars(26,0);
        for(int i=0; i<s.length(); i++){
            if(int(s[i]>=97)) sChars[s[i]-97]++;
            else sChars[s[i]-65]++;
        }
        for(int i=0;i<t.length();i++){
            if(int(t[i]>=97)) tChars[t[i]-97]++;
            else tChars[t[i]-65]++;
        }
        for(int i=0;i<sChars.size(); i++){
            if(sChars[i]!=tChars[i]) return false;
        }
        return true;

    }
};
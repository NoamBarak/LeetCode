//Wix
class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m = { {'I', 1}, {'V', 5}, {'X', 10},
        {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
        int res=0;
        if(s.size()==0) return 0;
        if (s.size()==1) return m[s[0]];
        for(int i=0;i<s.size(); i++){
            if(i<s.size()-1){
                if(m[s[i]]< m[s[i+1]]){
                    res+=(m[s[i+1]]-m[s[i]]);
                    i++;
                    continue;
                }
            }
            res+=m[s[i]];
        }
        return res;
        
    }
};
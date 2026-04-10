//Wix
/* Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it */

/* Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==0) return {{}};
        if(numRows==1) return {{1}};
        if(numRows==2) return {{1}, {1,1}};
        vector<vector<int>> res= {{1}, {1,1}};
        for(int r=2; r<numRows; r++){
            res.push_back({});
            for(int i=0;i<=r; i++){
                if(i==0 || i==r){
                    res[r].push_back(1);
                }
                else {
                    res[r].push_back(res[r-1][i-1] + res[r-1][i]);
                }
            }
        }
        return res;
    }
};
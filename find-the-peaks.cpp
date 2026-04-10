/* You are given a 0-indexed array mountain. Your task is to find all the peaks in the mountain array.

Return an array that consists of indices of peaks in the given array in any order.*/

/* Input: mountain = [1,4,3,8,5]
Output: [1,3]*/
class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        if(mountain.size()<=1) return {};
        if(mountain.size()==2){
            if(mountain[0]<mountain[1]) return {1};
            if(mountain[1]>mountain[0]) return {0};
            return {}; //same value
        }
        vector<int> res;
        for(int i=1;i<mountain.size()-1;i++){
            if(mountain[i-1]<mountain[i] && mountain[i]>mountain[i+1]){
                res.push_back(i);
                i++; //the next one is for sure NOT a peak
            }
        }
        return res;
    }
};
//Wix
/* Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.*/
/* Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true*/
/* more efficient approach:
1. If the board does not contain enough of some character from word, return false immediately.
2. Sometimes reverse the word first if the last character is rarer than the first.
Why?
Because DFS branching becomes smaller if you start from a rarer letter.*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i=0; i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    if(func(board, word, 0, i, j, visited))
                        return true;
                }

            }
        }
        return false;
    }

    bool func(vector<vector<char>>& board, string word, int wordIdx, int i, int j, vector<vector<bool>>& visited){
        if(i>=board.size() || j>=board[0].size() || i<0 || j<0 ) return false;
        if(visited[i][j]) return false;
        if(board[i][j]!=word[wordIdx]) return false;
        if(wordIdx == word.length()-1) return true; //last char
        visited[i][j]= true;
        bool found = (func(board, word, wordIdx+1, i+1, j, visited) ||
            func(board, word, wordIdx+1, i, j+1, visited) ||
            func(board, word, wordIdx+1, i-1, j, visited) ||
            func(board, word, wordIdx+1, i, j-1, visited));
        visited[i][j]= false;
        return found;
    }
};
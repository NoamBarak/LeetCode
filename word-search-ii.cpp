/* Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.*/

/* Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]*/

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;

        for (int w = 0; w < words.size(); w++) {
            bool isFound = false;
            string word = words[w];

            vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

            for (int i = 0; i < board.size() && !isFound; i++) {
                for (int j = 0; j < board[0].size() && !isFound; j++) {
                    if (findWord(board, word, 0, i, j, visited)) {
                        res.push_back(word);
                        isFound = true;
                    }
                }
            }
        }

        return res;
    }

    bool findWord(vector<vector<char>>& board, string word, int idx, int row, int col, vector<vector<bool>>& visited) {
        if (row < 0 || row >= board.size()) return false;
        if (col < 0 || col >= board[0].size()) return false;
        if (visited[row][col]) return false;
        if (board[row][col] != word[idx]) return false;

        if (idx == word.length() - 1) return true;

        visited[row][col] = true;

        bool found = findWord(board, word, idx + 1, row + 1, col, visited) ||
                     findWord(board, word, idx + 1, row - 1, col, visited) ||
                     findWord(board, word, idx + 1, row, col + 1, visited) ||
                     findWord(board, word, idx + 1, row, col - 1, visited);

        visited[row][col] = false;

        return found;
    }
};
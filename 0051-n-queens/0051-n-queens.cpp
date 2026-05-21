class Solution {
public:
    vector<vector<string>> ans;

    void solve(int row, int n, vector<string>& board,
               unordered_set<int>& col,
               unordered_set<int>& diag1,
               unordered_set<int>& diag2) {

        // Base case
        if(row == n) {
            ans.push_back(board);
            return;
        }

        for(int c = 0; c < n; c++) {

            // Check if safe
            if(col.count(c) || 
               diag1.count(row - c) || 
               diag2.count(row + c)) {
                continue;
            }

            // Place queen
            board[row][c] = 'Q';

            col.insert(c);
            diag1.insert(row - c);
            diag2.insert(row + c);

            // Recursive call
            solve(row + 1, n, board, col, diag1, diag2);

            // Backtracking
            board[row][c] = '.';

            col.erase(c);
            diag1.erase(row - c);
            diag2.erase(row + c);
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        unordered_set<int> col;
        unordered_set<int> diag1;
        unordered_set<int> diag2;

        solve(0, n, board, col, diag1, diag2);

        return ans;
    }
};
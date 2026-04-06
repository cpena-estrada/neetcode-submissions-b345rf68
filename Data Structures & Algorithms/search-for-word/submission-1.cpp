class Solution {
public:

    set<pair<int,int>> visited;

    bool dfs(int i, int j, int idx, vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        cout << "row: " << i << " | " << "col: " << j << " | " << "idx: " << idx << "\n";

        if (i < 0 || i >= row || j < 0 || j >= col) { cout << "oob\n"; return false; } // out of bounds
        if (visited.count(make_pair(i,j))) { return false; } // already visited
        if (board[i][j] != word[idx]) { return false; } // not a match
        if (idx == word.length() - 1 && board[i][j] == word[idx]) { return true; }

        // at this point, it's a match, mark as visited and explore
        visited.insert(make_pair(i,j));

        bool ok = dfs(i - 1, j, idx + 1, board, word) || /* up */
             dfs(i + 1, j, idx + 1, board, word) || /* down */
             dfs(i, j + 1, idx + 1, board, word) || /* right */
             dfs(i, j - 1, idx + 1, board, word);   /* left */      
        
        visited.erase(make_pair(i,j));
        return ok;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                if (board[i][j] == word[0]) {
                    if (dfs(i, j, 0, board, word)) { return true; } // let it run through all and only retrun true if it is ever true
                }
            }
        }
        return false;
    }
};

/*

if within grid bounds

    if board board[i][j] != word[idx] {
        retrun false
    }

    if the board[i][j] == word[idx] && idx < word.lenght()
        retrun left || right || top || down
    

for i in rows
    for j in cols
        if the board[i][j] == word[0]({
            explore it
        }


why you need a visited: 
A A
A A

Word = "AAA"
Without visited:
    Start at (0,0) = A, idx=0 
    Go to (0,1) = A, idx=1 
    From (0,1) you can go back to (0,0) (since you don’t track visited), and it’s A, idx=2 
    You think you matched "AAA" ... but actually you reused (0,0) twice.
    That’s an invalid path according to the rules, but your DFS would return true.

*/
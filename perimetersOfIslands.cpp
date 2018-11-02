int islands = 0;
int adjac = 0;

public int findlongest(vector<vector<char>> &board) {
    if (board.size() == 0 || board[0].size() == 0) {
      return 0;
    }
    int maxperi = 0;
    for (int row = 0; row < board.size(); row++) {
      for (int col = 0; col < board[0].size(); col++) {
        if (board[row][col] == '1') {
          dfs(board,col,row);
          maxperi = Math.max(maxperi, 4 * islands - 2 * adjac);
          islands = 0;
          adjac = 0;
        }
      }
    }
    return maxperi;
}
public void dfs(vector<vector<char>>& board, int row, int col) {
    board[row][col] = '0';
    islands ++;
    int[] row_move = {0,0,1,-1};
    int[] col_move = {1,-1,0,0};
    for (int i = 0; i < 4; i++) {
      int newRow = row + row_move[i];
      int newCol = col + col_move[i];
      if (check(board,newRow,newCol)) {
        adjac ++;
        dfs(board,newRow,newCol);
      }
    }
  }
  private boolean check(vector<vector<char>>& board, int row, int col) {
    return row >= 0 && row < board.size() && col >= 0 && col < board[0].size() && board[row][col] == '1';
  }
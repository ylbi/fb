public List<List<Point>> getPath(int[][] board) {
    List<List<Point>> res = new ArrayList<>();
    int rowlen = board.length;
    int collen = board[0].length;
    boolean[][] visited = new boolean[rowlen][collen];
    Point start = new Point(0,0);
    visited[0][0] = true;
    dfs(start,board,new ArrayList<Point>(), res,visited);
    return res;
  }
  public void dfs(Point curt, int[][] board, List<Point> temp, List<List<Point>> res, boolean[][] visited) {
    if (curt.row == board.length - 1 && curt.col == board[0].length - 1) {
      res.add(new ArrayList<>(temp));
      return;
    }
    int row_move[] = {0,0,1,-1};
    int col_move[] = {1,-1,0,0};
    for (int i = 0; i < 4; i++) {
      int newRow = curt.row + row_move[i];
      int newCol = curt.col + col_move[i];
      if (!isValid(newRow,newCol,board) || visited[newRow][newCol]) {
        continue;
      }
      visited[newRow][newCol] = true;
      temp.add(new Point(newRow,newCol));
      dfs(new Point(newRow,newCol), board, temp,res,visited);
      temp.remove(temp.size() - 1);
      visited[newRow][newCol] = false;
    }
  }